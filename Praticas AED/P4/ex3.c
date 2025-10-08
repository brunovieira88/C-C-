#include <stdio.h>

int checKProperty(int *a, int size, long long *comparisonCount){
    if (size < 3){
        return 0;
    }

    long long comparisons = 0;
    int counter = 0;

    for (int i = 0; i < size - 2; i++){
        for (int j = i + 1; j < size - 1; j++){
            for (int k = j + 1; k < size; k++){
                comparisons++;
                if (a[k] == a[i] + a[j]){
                    counter++;
                }
            }
        }
    }

    if (comparisonCount != NULL){
        *comparisonCount = comparisons;
    }

    return counter;
}

int main(void){
    int arr5[] = {1, 2, 4, 7, 9};
    int arr10_e1a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr10_e1b[] = {3, 5, 8, 13, 21, 1, 2, 34, 55, 89};
    int arr20[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19,
                   21, 23, 25, 27, 29, 31, 33, 35, 37, 39};
    int arr30[] = {1, 4, 6, 9, 10, 12, 15, 18, 20, 22,
                   25, 27, 30, 31, 33, 36, 38, 39, 41, 44,
                   46, 48, 51, 52, 54, 57, 60, 62, 63, 65};
    int arr40[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
                   31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
                   73, 79, 83, 89, 97, 101, 103, 107, 109, 113,
                   127, 131, 137, 139, 149, 151, 157, 163, 167, 173};

    int *arrays[] = {arr5, arr10_e1a, arr10_e1b, arr20, arr30, arr40};
    const char *labels[] = {"arr5", "arr10_e1a", "arr10_e1b", "arr20", "arr30", "arr40"};
    int sizes[] = {
        (int)(sizeof(arr5) / sizeof(arr5[0])),
        (int)(sizeof(arr10_e1a) / sizeof(arr10_e1a[0])),
        (int)(sizeof(arr10_e1b) / sizeof(arr10_e1b[0])),
        (int)(sizeof(arr20) / sizeof(arr20[0])),
        (int)(sizeof(arr30) / sizeof(arr30[0])),
        (int)(sizeof(arr40) / sizeof(arr40[0]))
    };

    long long comparisons10 = 0;
    long long comparisons20 = 0;

    for (int idx = 0; idx < 6; idx++){
        int size = sizes[idx];
        long long comparisons = 0;
        int matches = checKProperty(arrays[idx], size, &comparisons);

        printf("%s -> n=%d, termos=%d, comparacoes=%lld\n",
               labels[idx], size, matches, comparisons);

        if (size == 10){
            comparisons10 = comparisons;
        } else if (size == 20){
            comparisons20 = comparisons;
        }
    }

    printf("\nComparacoes medidos: n=10 -> %lld, n=20 -> %lld\n", comparisons10, comparisons20);
    printf("Algoritmo sistematico com complexidade O(n^3) em comparacoes.\n");

    return 0;
}
/*
nao ha pior nem melhor caso, é sempre sistematico
a ordem é O(n^3)

*/
