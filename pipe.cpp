#include <stdio.h>
#include <stdlib.h>
#include <string>

class Pipe
{
    private:
        FILE* fp;
        char* buf;
        std::string result;

    public:
        bool open(const char* command)
        {
            if ((fp = popen(command, "r")) == NULL)
            {
                fprintf(stderr, "パイプのオープンに失敗しました！: argv[1]=%s", command);
                return false;
            }

            return true;
        }

        std::string getResult()
        {
            buf = (char*)malloc(256);
            while (fgets(buf, sizeof(buf), fp) != NULL) 
            {
                result += buf;
            }
            pclose(fp);

            return result;
        }
};