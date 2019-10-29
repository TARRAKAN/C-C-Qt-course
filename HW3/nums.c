#include <stdio.h>

int main(void)
{
    int inpNum = 0;
    printf("input a digit: ");
    scanf("%d", &inpNum);
    switch(inpNum)
    {
        case 0:printf("z\n");break;
        case 1:printf("o\n");break;
        case 2:;
        case 3:printf("t\n");break;
        case 4:;
        case 5:printf("f\n");break;
        case 6:;
        case 7:printf("s\n");break;
        case 8:printf("e\n");break;
        case 9:printf("n\n");break;
        default:printf("%d isn't a digit\n", inpNum);
    }
    return 0;
}
