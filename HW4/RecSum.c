#include <stdio.h>

int intSum(int var1, int var2);

int main(void)
{
    printf("Input a date of birth in dd.mm.yyyy format:");
    int dOfBirth = 0, mOfBirth = 0, yOfBirth = 0;
    scanf("%d.%d.%d", &dOfBirth, &mOfBirth, &yOfBirth);
    printf("%d\n", intSum(intSum(dOfBirth, mOfBirth),yOfBirth));
    return 1;
}

int intSum(int var1, int var2)
{
    if(!var1) 
    {
        return var2;
    }
    else
    {
    
        return intSum(--var1,++var2);
    }
    
}
