//
// TO DO : desenvolva um algoritmo para verificar se um numero inteiro positivo
//         e uma capicua
//         Exemplos: 12321 e uma capiacua, mas 123456 nao e
//         USE uma PILHA DE INTEIROS (STACK) e uma FILA DE INTEIROS (QUEUE)
//
// TO DO : design an algorithm to check if the digits of a positive decimal
//         integer number constitue a palindrome
//         Examples: 12321 is a palindrome, but 123456 is not
//         USE a STACK of integers and a QUEUE of integers
//

#include <stdio.h>

#include "IntegersQueue.h"
#include "IntegersStack.h"

int main(void) { 
    Stack *s = StackCreate(10);
    Queue *q = QueueCreate(10);
    int num = 0;
    int d = 0;
    printf("enter your number: ");
    scanf("%d", &num);

    while (num > 0) {
        d = num % 10;
        num = num / 10;
        StackPush(s, d);
        QueueEnqueue(q, d);
    }

    int isPalindrome = 1; // 1=true, 0=false
    
    while (!StackIsEmpty(s) && !QueueIsEmpty(q)) {
        if (StackPop(s) != QueueDequeue(q)) {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome) {
        printf("the number is a palindrome\n");
    } else {
        printf("the number is not a palindrome\n");
    }

    //clean
    StackDestroy(&s);
    QueueDestroy(&q);

    return 0;
}
