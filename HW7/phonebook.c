#include <stdio.h>
#include <string.h>

struct nameNumber
{
    char name[50];
    char phone[50];
};

int main(void)
{
    printf("~HI! What do you want, my friend?~\n");
    printf("Print \"info\" to show the user's manual.\n");
    printf("Print \"add\" to add a name and a number.\n");
    printf("Print \"remove\" ro remove a name and a number.\n");
    printf("Print \"search\" to search a number in the phonebook.\n");
    printf("Print \"print\" to print all names and numbers added in the phonebook.\n");
    printf("Print \"exit\" to close ~*GNU LIBRE SUPER MEGA PhOnEbOoK PRO v1.123123 alpha*~\n");
    char options[7] = "abcdef\0";
    while(strcmp(options, "exit"))
    {
        printf("(PB)");
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
            fclose(file);
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
        fclose(file);
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
            fclose(file);
        }
        else if(!strcmp(options, "remove"))
        {
            char rStr[102];
            printf("Input a name:");
            scanf("%s", rStr);
            char rNumber[50];
            printf("Input a number:");
            scanf("%s", rNumber);
            strcat(rStr," - ");
            strcat(rStr, rNumber);
            strcat(rStr, "\n");
            FILE *file, *tFile;
            file = fopen("file.txt", "r");
            tFile = fopen("tFile.txt", "w");
            if(file&&tFile)
            {
                char ch[102];
                while(fgets (ch, 102 , file) != NULL)
                {
                    if(strcmp(ch, rStr))
                        fprintf(tFile, "%s", ch);
                }
            }
            remove("file.txt");
            rename("tFile.txt", "file.txt");
            fclose(file);
            fclose(tFile);
        }
        else if(!strcmp(options, "info"))
        {
            printf("Print \"add\" to add a name and a number.\n");
            printf("Print \"remove\" ro remove a name and a number.\n");
            printf("Print \"search\" to search a number in the phonebook.\n");
            printf("Print \"print\" to print all names and numbers added in the phonebook.\n");
            printf("Print \"exit\" to close ~*GNU LIBRE SUPER MEGA iPhOnEbOoK v1.123123 alpha*~\n");    
        }
    }
        return 0;
}
