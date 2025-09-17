#include <stdio.h>
#include <math.h>

int main(void){
    int menor, maior;
    printf("menor angulo: ");
    scanf("%d", &menor);
    printf("maior angulo: ");
    scanf("%d", &maior);
    printf("ang sin(ang)      cos(ang)\n");
    printf("--- ------------  --------\n");
    for (int i = menor; i <= maior; i+=5){
        double ang = i * M_PI/180.0;
        printf("%-5.0f %-12.6f %-12.6f\n", ang, sin(ang), cos(ang));

    }

    return 0;
}