#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *cFile;
    cFile = fopen("file.txt", "r");
    if(cFile)
    {
	    char cArr[1001] = {0};
	    fgets(cArr, 1001, cFile);
        for(int i = 32; i<=127; i++)
        {
            int chNum = 0;
            for(int j = 0; j < 1000; j++)
            {
                if(cArr[j]==i)
                    chNum++;
            }
            printf("char \"%c\":%d\n", i, chNum);
        }

    }
    else
        printf("Error: there is no such file as \"file.txt\" in current directory\n");
    return 1;
}
