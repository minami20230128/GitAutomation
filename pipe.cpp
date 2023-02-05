#include <stdio.h>
#include <stdlib.h>
#include <string>

class Pipe
{
    private:
        FILE* fp;
        char buf[256];

    public:
        bool open(char* command)
        {
            if ((fp = popen(command, "r")) == NULL)
            {
                fprintf(stderr, "パイプのオープンに失敗しました！: argv[1]=%s", command);
                return false;
            }

            return true;
        }

        void getResult()
        {

            while (fgets(buf, sizeof(buf), fp) != NULL) {
                printf("%s", buf);
            }
        }

        void close()
        {
            pclose(fp);
        }
};