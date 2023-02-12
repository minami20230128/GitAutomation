#include <iostream>
#include <stdlib.h>
#include "main.h"
#include "pipe.cpp"

int main () 
{
    int choice;
    std::string result;
    std::string directry;

    std::cout << "ディレクトリを入力してください" << std::endl;
    std::cin >> directry;
    result = setDirectry(directry);
    std::cout << result << std::endl;

    std::cout << "実行したいコマンドを選択してください" << std::endl;
    std::cin >> choice;

    switch(choice)
    {
    case 1:
        result = add();
        break;
    case 2:
        result = commit();
        break;
    }

    std::cout << result << std::endl;

    return 0;
}

std::string add()
{
    std::string filename;
    std::cout << "addしたいファイル名を入力してください" << std::endl;
    std::cin >> filename;
    auto pipe = std::make_unique<Pipe>();
    std::string command = "git add " + filename + "  main";
    std::string result = executeCommand(command.c_str());

    return result;
}

std::string commit()
{
    auto pipe = std::make_unique<Pipe>();
    std::string command = "git remote";
    std::string result = executeCommand(command.c_str());

    command = "git branch";
    result = executeCommand(command.c_str());

    return result;
}

std::string setDirectry(std::string directry)
{
    std::string filename;
    auto pipe = std::make_unique<Pipe>();
    std::string command = "cd " + directry;
    std::string result = executeCommand(command.c_str());

    return result;
}

std::string executeCommand(std::string command)
{
    auto pipe = std::make_unique<Pipe>();
    pipe->open(command.c_str());
    std::string result = pipe->getResult();

    return result;
}