#include <stdio.h>
#include <stdbool.h> //necessario para usar boolean

int main () {
    //single line comment
    /*
    multi line comment
    */
    printf("hello world nigga\n");

    //DATA TYPES
    int age = 19;
    printf("I am %d years old\n", age); //%d, d for decimal
    
    float weight = 70.2;
    printf("You weight %.1f kilograms\n", weight);
    
    double pi = 3.14159;
    printf("the value of fucking pi is %.3f\n", pi);

    char grade = 'A';
    printf("your grade is %c\n",grade);
    
    char name[] = "Bruno Vieira"; // uma string é um array de char
    printf("My name is %s", name );

    bool isOnline = true;
    printf("%d", isOnline);

    return 0;
}
