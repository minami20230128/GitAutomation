#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "pipe.cpp"

int main () 
{
    std::string command;
    scanf("%s", &command);
    
    if (empty(command) || command == NULL) 
    {
        fprintf(stderr, "引数に「コマンド」を入力して下さい！\n");
        return EXIT_FAILURE;
    }
    
    auto pipe = std::make_unique<Pipe>();
    pipe->open(command.c_str());
    pipe->getResult();
    pipe->close();

    return 0;
}

void add()
{
    auto filename = setDirectry();
    auto pipe = std::make_unique<Pipe>();
    std::string command = "add {} main", filename;
    pipe->open(command.c_str());
    pipe->getResult();
    pipe->close();

}

std::string setDirectry(Pipe pipe)
{
    std::string filename;
    auto pipe = std::make_unique<Pipe>();
    char* command = "open /Desktop";
    pipe->open(command);
    pipe->close();
    return filename;
}

void executeCommand()
{

}