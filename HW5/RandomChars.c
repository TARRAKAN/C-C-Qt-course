#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    
    char array[1000];
    srand(time(NULL));
    
    for(int i=0; i<1000; i++)
    {
        array[i]=rand()%128;
        printf("array[%d]=", i);

        if(array[i]=='\n')
            printf("\'\\ n\'\n"); //change '\n' chars to "\n" strings

        else if(array[i]=='\t')
            printf("\'\\ t\'\n"); //change '\t' chars to "\t" strings

        else
            printf("\'%c\'\n", array[i]); //print regular chars

    }
    return 1;
}
