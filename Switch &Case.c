//This is code is to check whether if age is 3, 13 or 23.
#include <stdio.h>

int main()
{
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);
    switch (age)
    { 
    case 3:
        printf("The age is 3\n");
        break;
    
    case 13:
        printf("The age is 13\n");
        break;
   
   case 23:
        printf("The age is 23\n");
        break;
    
    default:
    printf("The age is not 3, 13 or 23\n");
        break;
    }    
    return 0;
}
