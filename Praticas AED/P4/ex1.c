#include <stdio.h>


int check(int *a, int size){
    int counter = 0;
    for (int i = 1; i < size - 1; i++){
        if (a[i] == a[i-1] + a[i+1]){
            counter++;
        }
    }
    return counter;
}


int main (void){
    int arr1[] = {1,3,2,6,4,10};
    int arr2[] = {0,0,0,0,0,0,0,0,0,0};
    printf("%d \n", check(arr1, sizeof(arr1)/sizeof(arr1[0])));
    printf("%d \n", check(arr2, sizeof(arr2)/sizeof(arr2[0])));
    return 0;
    /*
    numero total de comparacoes n - 2
    nao ha pior ou melhor caso, estamos perante um caso sistematico
    a ordem de complexidade do algoritmo é linear: O(n)
    
    */ 
}

