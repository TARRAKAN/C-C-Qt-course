#include <stdio.h>

int intSum(int day, int month, int year);

int main(void)
{
    printf("Input a date of birth in dd.mm.yyyy format:");
    int dOfBirth = 0, mOfBirth = 0, yOfBirth = 0;
    scanf("%d.%d.%d", &dOfBirth, &mOfBirth, &yOfBirth);
    printf("%d\n", intSum(dOfBirth, mOfBirth, yOfBirth));
    return 1;
}

int intSum(int day, int month, int year)
{
    if(!(day||month)) 
    {
        return year;
    }
    else
    {
    	if(day)
            return intSum(--day, month,++year);
        else
            return intSum(day, --month,++year);
    }
    
}
