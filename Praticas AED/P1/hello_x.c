#include <stdio.h>

int main(void){
    char name[30] = "";
    printf("Enter your name: ");
    //gets(name); inseguro
    //fgets(name, 30, stdin); este preenche os espacos vazios com " "
    scanf("%s", name); //quando insiro um espaco ele para 
    printf("Hello %s !\n", name);
    return 0;
}