#include <stdio.h>
#include <string.h>

int main(){
    int age = 0;
    char name [30] = "";

    printf("Enter your age: ");
    scanf("%d", &age);
    getchar(); // consume the leftover newline

    printf("Enter your name (30max): ");
    fgets(name, sizeof(name), stdin); //fgets para strings
    name[strlen(name) - 1] = '\0'; //para o ultimo caracter ser uma coisa nula

    printf("Hello %s, you are %d years old.\n", name, age );

    return 0;
}