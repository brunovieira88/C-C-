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


}