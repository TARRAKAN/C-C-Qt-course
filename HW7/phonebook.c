#include <stdio.h>
#include <string.h>

struct nameNumber
{
    char name[50];
    char phone[50];
};

int main(void)
{
    printf("~What do you want?~\n");
    printf("Print \"add\" to add a name and a number.\n");
    printf("Print \"print\" to print all names and numbers added in the phonebook.\n");
    printf("Print \"search\" to search a number in the phonebook.\n");
    printf("Print \"exit\" to close the ~*GNU LIBRE SUPER MEGA iPhOnEbOoK v1.123123 alpha*~\n");
    char options[7] = "abcdef\0";
    while(strcmp(options, "exit"))
    {
        scanf("%s", options);
        if(!strcmp(options, "add"))// add contacts in the phonebook 
        {
            struct nameNumber phoneBook;
            printf("Print a name:");
            scanf("%s", phoneBook.name);
            printf("Print a phone number:");
            scanf("%s", phoneBook.phone);
            FILE *file;
            file = fopen("file.txt", "a");
            if(file)
            {
                fprintf(file, "%s - %s\n", phoneBook.name, phoneBook.phone);
            }
            fclose(file);
            printf("DONE!\n");
        }
        else if(!strcmp(options, "print"))// print the phonebook
        {
            printf("~YOUR PHONEBOOK~\n");
            FILE *file;
            file = fopen("file.txt", "r");
            if(file)
            {
                int ch = 0;
                while((ch = fgetc(file)) != EOF)
                {
                    printf("%c", ch);
                }
            }
            else
            printf("  ~IS EMPTY~\n");
        }
        else if(!strcmp(options, "search"))// search
        {
            char sName[50];
            printf("Input a name:");
            scanf("%s", sName);
            FILE *file;
            file = fopen("file.txt", "r");
            if(file)
            {
                char str[50];
                while(fscanf(file, "%s", str) != EOF)
                {
                    if(!strcmp(str, sName))
                    {
                        fscanf(file, "%s", str);
                        fscanf(file, "%s", str);
                        printf("The number is: %s\n", str);
                    }
                }
            }
            else
                printf("~YOUR PHONEBOOK~\n  ~IS EMPTY~\n");
        }
    }
        return 0;
}
