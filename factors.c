#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void func(long long int ben)
{
        long long int i;

        i = 2;
        while (1)
        {
                if (ben % i == 0)
                {
                        printf("%lld=%lld*%lld\n", ben, ben / i, i);
                        break;
                }
                else
                        i++;
        }
}

int main(int argc, char **argv)
{
        if (argc != 2)
        {
                perror("invalid arguement");
                exit(EXIT_FAILURE);
        }

        char *buff;
        size_t len;
        FILE *fp = NULL;
        long long int ben;

        fp = fopen(argv[1], "r");

        if (fp == NULL)
        {
		perror("couldn't open file");
                exit(EXIT_FAILURE);
        }
        else
        {
                while (getline(&buff, &len, fp) != -1)
                {
                        ben = atoll(buff);
                        func(ben);
                }
        }
        fclose(fp);
        return (0);
}
