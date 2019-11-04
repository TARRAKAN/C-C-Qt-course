#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void)
{
    char filename[11];
    FILE *fp;
    for(int i = 1; i<=10; i++)
    {
        sprintf(filename, "file%02d.txt", i);
        fp = fopen(filename, "w");
	if(fp)
	{	
		srand(time(NULL));
		for(int j = 0; j<=100; j++) fprintf(fp, "%d", rand()%10);
	}
	fclose(fp);
    }
    
    return 1;
}
