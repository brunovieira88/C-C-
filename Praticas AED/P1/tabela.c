#include <stdio.h>
#include <math.h>

int main(void){

    int lines;
    printf("How many lines: ");
    scanf("%d", &lines);

    printf("quadrado         |    raiz \n");
    for (int i = 1; i <= lines; i++){
        printf("    %-10d   |   %-9.3f    \n",i, sqrt(i));
    };
    return 0;

}