#include <stdio.h>

int main(void){

    int num1, num2;
    double res;
    char op;
    
    printf("Choose the operations (+, −, ×, /): ");
    scanf(" %c", &op);
    printf("Enter the operands separated by a space and then enter: ");
    scanf("%d %d", &num1, &num2);

    switch (op)
    {
    case '+':
        res = num1 + num2;
        break;
    case '-':
        res = num1 - num2;
        break;
    case 'x':
        res = num1 * num2;
        break;
        res = (double)num1 / num2;
        res = num1 / num2;
        break;
    default:
        printf("the operation you chose does not exist");
        return 0;
    }

    printf("%d%c%d = %.1f\n", num1, op, num2, res);

    return 0;
}