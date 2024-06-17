#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <vector>
#include <format>
#include <boost/algorithm/string.hpp>
#include "main.h"
#include "pipe.cpp"

int main () 
{
    std::string directry;
    std::cout << "ディレクトリを入力してください" << std::endl;
    std::cin >> directry;

    std::string result;
    result = set_directry(directry);
    std::cout << result << std::endl;

    int choice;
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
    case 3:
        result = push();
    }

    std::cout << result << std::endl;

    return 0;
}

std::string add()
{
    std::string filename;
    std::cout << "addしたいファイル名を入力してください" << std::endl;
    std::cin >> filename;
    std::string command = std::format("git add {} main", filename);
    std::string result = execute_command(command.c_str());

    return result;
}

std::string commit()
{
    std::string message;
    std::cout << "メッセージを入力してください" << std::endl;
    std::cin >> message;
    std::string command = "git commit -m " + message;
    std::string result = execute_command(command.c_str());

    return result;
}

std::string push()
{
    std::string command = "git remote";
    std::string repositry = execute_command(command.c_str());
    command = "git branch";
    std::string result = execute_command(command.c_str());
    std::vector<std::string> branches;
    boost::split(branches, result, boost::is_any_of("¥n"));

    for(auto branch: branches)
    {
        if(branch.find("*")!=-1)
        {
            command = "git push " + repositry + branch;
            result = execute_command(command.c_str());
        }
    }

    return result;
}

std::string set_directry(std::string directry)
{
    std::string filename;
    if (chdir(directry.c_str()) == -1){
        return "such directry does not exist";
    }

    std::string command ="ls";//テストコード
    std::string result = execute_command(command.c_str());//テストコード

    return result;
}

std::string execute_command(std::string command)
{
    auto pipe = std::make_unique<Pipe>();
    pipe->open(command.c_str());
    std::string result = pipe->get_result();

    return result;
}