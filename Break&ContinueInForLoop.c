//In this code if a person is below 18 we will print that he/she can't vote else can vote.
#include <stdio.h>

int main()
{
    int i, age;
    for (i=0; i<10; i++){
        printf("\nEnter your age\n");
        scanf("%d", &age);
        if (age<18 || age>100)
        {
            printf("You are not eligible to vote!");
            break;   
        }
        if (age>=18)
        {
            continue;
        }
        printf("You are eligible & you can vote!\n");
    }
    return 0;
}
