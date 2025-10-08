#include <stdio.h>


void permute(int *a, int *b, int *c){
    int temp = *a; //guardar valor de a para depois dar ao b
    *a = *c; //o valor de c vai para a 
    *c = *b; //valor de b para o c
    *b = temp;
}


int main(void){
    int x, y, z;
    printf("insere 3 numeros com um espaco entre cada um: ");
    scanf("%d %d %d", &x, &y, &z);
    printf("Antes: x=%d, y=%d, z=%d\n", x, y, z);
    permute(&x, &y, &z);
    printf("Depois: x=%d, y=%d, z=%d\n", x, y, z);
    return 0;
}

