#include <stdio.h>

int main(void)
{
    char name[50];  // create space for the name
    int age;

    printf("Enter your name: ");
    scanf("%49s", name);  // %49s = max 49 characters

    printf("Enter your age: ");
    scanf("%d", &age);    // & gives the address of 'age'

    printf("Hello %s! You are %d years old.\n", name, age);
    

}
