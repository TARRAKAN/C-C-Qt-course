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
    printf("Print \"print\" to print all names and numbers added in a phonebook.\n");
    char options[7] = "abcdef\0";
    scanf("%s", options);
    if(!strcmp(options, "add"))
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
    else if(!strcmp(options, "print"))
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
}
