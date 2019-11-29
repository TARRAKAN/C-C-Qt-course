#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

struct Task
{
    char name[10];
    int time;
    int pointer;
};

struct steck{
    struct Task tasks[10];
    int top;
};

//////////////////////PUSH//////////////////////////////
void push(struct steck *pSteck, char pName[10], int pTime)
{
    if(pSteck->top<=9)
    {
        int sTop = pSteck->top++;
        strcpy(pSteck->tasks[sTop].name,pName);
        pSteck->tasks[sTop].time = pTime;
        printf("~pushed~\n");
    }
    else
        printf("Steck is full!\n");
} 
////////////////////////////////////////////////////////
void init(struct steck *pSteck)
{
    pSteck->top = 0;
    for(int i = 0; i<=9; i++)
    {
    	strcpy(pSteck->tasks[i].name, "");
    	pSteck->tasks[i].time = 0;    
    }
}

//////////////////////////POP///////////////////////////
void pop(struct steck *pSteck)
{
    if(pSteck->top>0)
    {
	printf("~Task \"%s\" poped~\n", pSteck->tasks[0].name);
        for(int i = 0; i < pSteck->top; i++)
        {
            strcpy(pSteck->tasks[i].name, pSteck->tasks[i+1].name);
            pSteck->tasks[i].time = pSteck->tasks[i+1].time;
            
        }
	pSteck->top--;
    }
    else
        printf("Steck is empty!\n");

}

/////////////////////////PEEK//////////////////////////
void pickleRick(struct steck *pSteck)
{
    if(pSteck->top>0)
    {
    printf("Name: %s\n", pSteck->tasks[0].name);
    printf("Time: %d\n", pSteck->tasks[0].time);
    }
    else
        printf("Steck is empty!\n");
}

//////////////////////////TIMER//////////////////////////
void timer(int sec)
{
    int till = clock()+sec*1000000;
    while (clock() < till);
}

int main(void)
{
    struct steck nSteck;
    init(&nSteck);
    char opt[10] = "HiHi\0";
    printf(">flood - add few tasks\n");   
    printf(">start - pop all tasks\n");
    int sizeOfSteck = 0;
    while(strcmp(opt,"exit"))
    {    
        printf(">>");
        scanf("%s", opt);
        if(!strcmp(opt,"flood"))
        {
            printf("Number of tasks in queue now: %d\n", nSteck.top);
            int canAdd = 10 - nSteck.top;
            printf("Input size(%d - MAX):", canAdd);
            scanf("%d", &sizeOfSteck);
            printf("random or manual?\n");
            scanf("%s", opt);
            
            if(!strcmp(opt, "manual"))
            {
                for(int i = 1; (i <= sizeOfSteck)&&(i <= canAdd); i++)
                {
                    printf("Task №%d\n", nSteck.top+1);
                    int iTime = 0;
                    char iName[10];
                    printf("Name:");
                    scanf("%s", iName);
                    printf("Time:");
                    scanf("%d", &iTime);
                    push(&nSteck, iName, iTime);
                }
            }
            else if(!strcmp(opt, "random"))
            {
		        srand(time(NULL));
                for(int i = 1; (i <= sizeOfSteck)&&(i <= canAdd); i++)
                {
                    printf("Task №%d ", nSteck.top+1);
                    int iTime = 1 + random() % 5;
                    char iName[10];
                    for(int j = 0; j < 10; j++)
                        iName[j] = 65 + random() % (123 - 65);      
                    push(&nSteck, iName, iTime);
                    printf("Name: %s\n", nSteck.tasks[i-1].name);
                    printf("Time: %d\n", nSteck.tasks[i-1].time);
                }
            }
            else
                printf("You did it wrong!\n");
            
        }
        else if(!strcmp(opt,"start"))
        {
            int sTop = nSteck.top;
            if(sizeOfSteck!=0)
            {
                for(int i = 1; i<=sTop; i++)
                {
                timer(nSteck.tasks[0].time);
                pop(&nSteck);
                }
            }
            pop(&nSteck);
        }       
    }
    return 0;
}
