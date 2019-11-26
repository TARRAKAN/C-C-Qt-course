#include <stdio.h>
#include <string.h>

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
}

//////////////////////////POP///////////////////////////
void pop(struct steck *pSteck)
{
    if(pSteck->top>0)
    {
        strcpy(pSteck->tasks[pSteck->top-1].name,"");
        pSteck->tasks[pSteck->top-1].time = 0;
        pSteck->top--;
        printf("~poped~\n");
    }
    else
        printf("Steck is empty!\n");
}

/////////////////////////PEEK//////////////////////////
void pickleRick(struct steck *pSteck)
{
    if(pSteck->top>0)
    {
    printf("Name: %s\n", pSteck->tasks[pSteck->top-1].name);
    printf("Time: %d\n", pSteck->tasks[pSteck->top-1].time);
    }
    else
        printf("Steck is empty!\n");
}

int main(void)
{
    struct steck nSteck;
    init(&nSteck);
    char opt[5] = "HiHi\0";
    printf(">push\n");
    printf(">peek\n");
    printf(">pop\n");   
    while(strcmp(opt,"exit"))
    {    
        scanf("%s", opt);
        if(!strcmp(opt,"push"))
        {
            int iTime = 0;
            char iName[10];
            printf("Name:");
            scanf("%s", iName);
            printf("Time:");
            scanf("%d", &iTime);
            push(&nSteck, iName, iTime);
        }
        else if(!strcmp(opt,"peek"))
        {
            pickleRick(&nSteck);
        }
        else if(!strcmp(opt,"pop"))
        {
            pop(&nSteck);
        }
        
    }
    return 0;
}
