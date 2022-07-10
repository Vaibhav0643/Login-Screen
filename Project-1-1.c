#include <stdio.h>
#include <conio.h>
#include <string.h> //strcmp()
#include <stdlib.h> //system()

int main()
{
    system("cls");
    char ch;
    char pass[20], saved_pass[20];
start:

    printf("Enter your password  : ");
    int i = 0;
    while (1)
    {
        ch = getch();
        if (ch == 13)
        {
            pass[i] = '\0';
            break;
        }
        else
            pass[i++] = ch;
        printf("*");
    }

    printf("\nYou Entered : %s\n", pass);

    FILE *ptr;
    ptr = fopen("password.txt", "r");
    fscanf(ptr, "%s", saved_pass);

    // Make sure your cursor is in the first line of your text or binary file.Otherwise it'll
    // take input from other line also.
    // There should be no space after the password.

    fclose(ptr);

    printf("Password : %s ", saved_pass);

    int l = strcmp(pass, saved_pass);

    if (l == 0)
    {
        printf("\n\n******LOGIN SUCCESSFUL******\n");
    }
    else
    {
        printf("\n\n******INCORRECT PASSWORD******\nPlease Try again...\n\n");
        goto start;
    }

    return 0;
}