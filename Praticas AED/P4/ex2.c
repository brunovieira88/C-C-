#include <stdio.h>

int checkGeometricProgression(int *a, int size){
    int r  = a[1] / a[0];
    for (int i = 2 ; i < size; i++){
        if(a[i] != r * a[i-1]){
            return 0; //nao e progressao
        }
    }
    return 1;
}

int main(void){
    int arr1[] = {1,2,3,4,5,6,7,8,9,10};
    int arr2[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
    int arr3[] = {3, 9, 27, 81, 243};
    int arr4[] = {5, 5, 5, 5};

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    int size4 = sizeof(arr4) / sizeof(arr4[0]);

    int result1 = checkGeometricProgression(arr1, size1);
    int result2 = checkGeometricProgression(arr2, size2);
    int result3 = checkGeometricProgression(arr3, size3);
    int result4 = checkGeometricProgression(arr4, size4);

    printf("arr1 %s progressao geometrica\n", result1 ? "e" : "nao e");
    printf("arr2 %s progressao geometrica\n", result2 ? "e" : "nao e");
    printf("arr3 %s progressao geometrica\n", result3 ? "e" : "nao e");
    printf("arr4 %s progressao geometrica\n", result4 ? "e" : "nao e");

    return 0;
}
/*
melhor caso : uma multiplicacao + uma divisap, quando nao é logo progressao
pior caso : n - 1 , quando percore ate ao fim (1 divisao + n-1 multi)
caso medio: 
ordem de complexidade : O(n) - linear

*/
