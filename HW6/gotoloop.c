#include <stdio.h>

int main(void)
{
    int var = 1;
    loop:
        printf("%d\n", var);
        var++;
        if(var<=100)
            goto loop; 
    return 0;
}
