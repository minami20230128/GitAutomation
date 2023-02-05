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
    
    Pipe pipe;
    pipe.open(command.c_str());
    pipe.getResult();
    pipe.close();

    return 0;
}

void add()
{
    setDirectry();
}

void setDirectry(Pipe pipe)
{
    char* command = "open /Desktop";
    pipe.open(command);
    pipe.close();
}

void executeCommand()
{

}