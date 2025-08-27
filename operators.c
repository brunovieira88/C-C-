#include <stdio.h>

int main() {
    // Operadores aritméticos
    int a = 10, b = 3;
    printf("Aritméticos:\n");
    printf("a + b = %d\n", a + b); // Soma
    printf("a - b = %d\n", a - b); // Subtração
    printf("a * b = %d\n", a * b); // Multiplicação
    printf("a / b = %d\n", a / b); // Divisão
    printf("a %% b = %d\n", a % b); // Módulo

    // Operadores de incremento/decremento
    printf("\nIncremento/Decremento:\n");
    printf("a++ = %d\n", a++); // Pós-incremento
    printf("++a = %d\n", ++a); // Pré-incremento
    printf("b-- = %d\n", b--); // Pós-decremento
    printf("--b = %d\n", --b); // Pré-decremento

    // Operadores relacionais
    printf("\nRelacionais:\n");
    printf("a == b: %d\n", a == b); // Igualdade
    printf("a != b: %d\n", a != b); // Diferença
    printf("a > b: %d\n", a > b);   // Maior
    printf("a < b: %d\n", a < b);   // Menor
    printf("a >= b: %d\n", a >= b); // Maior ou igual
    printf("a <= b: %d\n", a <= b); // Menor ou igual

    // Operadores lógicos
    printf("\nLógicos:\n");
    printf("(a > 5 && b < 5): %d\n", (a > 5 && b < 5)); // E lógico
    printf("(a > 5 || b < 2): %d\n", (a > 5 || b < 2)); // OU lógico
    printf("!(a == b): %d\n", !(a == b));               // NÃO lógico

    // Operadores bit a bit
    printf("\nBit a bit:\n");
    printf("a & b = %d\n", a & b); // E bit a bit
    printf("a | b = %d\n", a | b); // OU bit a bit
    printf("a ^ b = %d\n", a ^ b); // XOR bit a bit
    printf("~a = %d\n", ~a);       // NOT bit a bit
    printf("a << 1 = %d\n", a << 1); // Desloca à esquerda
    printf("a >> 1 = %d\n", a >> 1); // Desloca à direita

    // Operadores de atribuição
    printf("\nAtribuição:\n");
    int c = 5;
    c += 2; // c = c + 2
    printf("c += 2: %d\n", c);
    c -= 1; // c = c - 1
    printf("c -= 1: %d\n", c);
    c *= 3; // c = c * 3
    printf("c *= 3: %d\n", c);
    c /= 2; // c = c / 2
    printf("c /= 2: %d\n", c);
    c %= 2; // c = c % 2
    printf("c %%= 2: %d\n", c);

    // Operador condicional (ternário)
    printf("\nCondicional (ternário):\n");
    int max = (a > b) ? a : b;
    printf("max = %d\n", max);

    // Operador de endereço e indireção
    printf("\nEndereço e indireção:\n");
    int d = 42;
    int *ptr = &d;;
    printf("Endereço de d: %p\n", (void*)&d);
    printf("Valor apontado por ptr: %d\n", *ptr);

    // Em C++, também existem operadores como new, delete, ::, ->, etc.
    // Estes não são válidos em C puro.

    return 0;
}