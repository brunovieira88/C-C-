#include <stdio.h>

int main(void) {
    int num;
    int numOfNum = 0;
    int biggestNum, lowestNum;
    int sum = 0;

    printf("Enter a number (-1 to terminate): ");
    scanf("%d", &num);

    if (num == -1) {
        printf("No numbers entered.\n");
        return 0;
    }

    biggestNum = num;
    lowestNum = num;
    sum = num;
    numOfNum = 1;

    while (1) {
        printf("Enter a number (-1 to terminate): ");
        scanf("%d", &num);

        if (num == -1) {
            break;
        }

        sum += num;
        numOfNum++;

        if (num > biggestNum) {
            biggestNum = num;
        }
        if (num < lowestNum) {
            lowestNum = num;
        }
    }

    double average = (double) sum / numOfNum;

    printf("Average = %.2f\n", average);
    printf("Biggest = %d\n", biggestNum);
    printf("Lowest  = %d\n", lowestNum);

    return 0;
}
