#include <stdio.h>

int contagem = 0;

int recursiveFunction(int num){
    contagem++;   
    if (num < 1){
        return 0;
    }
    if (num == 1){
        return 1;
    }
    return recursiveFunction(num/2) + recursiveFunction((num + 1 )/2) + num ; 
}

int main(void) {
    for (int i = 0; i <= 128; i++){
        printf("T(%d) = %d; N chamadas = %d\n", i, recursiveFunction(i), contagem);
        contagem = 0;
    }
    return 0;
}
