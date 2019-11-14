#include <stdio.h>

int main(void)
{
    FILE *fl;
    fl = fopen("text.txt", "r");
    if(fl)
    {
        int sizeOfFile = 0;

        while(fgetc(fl)!=EOF)
        {
	    sizeOfFile++;
        }
        printf("Size of file: %d bytes\n", sizeOfFile);
    }
    return 1;
}
