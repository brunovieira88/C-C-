#include <stdio.h>

void printArray(const char *s, int a[], int size) { //const porque é so de leitura e nao vai ser modificado
    printf("%s:\n", s);
    for (int i = 0; i < size; i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

void cumSum(int a[], int b[], int size){
    int c = 0;
    for (int i = 0; i < size; i++){
        c+=a[i];
        b[i] = c;
    }

}

int main(void) {
    int a[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    printArray("a", a, 12);
    int b[12];
    cumSum(a, b, 12);
    printArray("b", b, 12);
    return 0;
}
