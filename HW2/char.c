#include <stdio.h>  
int main()
{
    char x = 127; 
    printf("was x: %d \n", x);
    printf("was x: %c \n", x);
    x = x + 1; 
    printf("x is now: %d \n", x);
    printf("x is now: %c \n", x);
    return 0;
}
