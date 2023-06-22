/*
WRITE A PROGRAM TO CHECK WHETHER THE ENTERED
STRING IS PALINDROME OR NOT USING STRING FUNCTIONS.
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int len = 0, i = 0;

    char str[10];

    int flag = 0;

    printf("Enter string");

    scanf("%s", str);

    len = strlen(str);

    while (i < len / 2)
    {

        if (str[i] != str[len - i - 1])

        {

            flag = 1;

            break;
        }

        i++;
    }

    if (flag == 0)

        printf("\n String is a palindrome");

    else

        printf("\n String is not a palindrome");

    return 0;
}
