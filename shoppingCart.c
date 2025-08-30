#include <stdio.h>
#include <string.h>

int main() {
    
    char item[50] = "";
    float price = 0.0f; //f no final para avisar que é float;
    int quantity = 0;
    char currency[] = "€";
    float total = 0.0f;

    printf("What item do you want to buy?: ");
    fgets(item, sizeof(item), stdin);
    item[strlen(item) -1 ] = '\0' ;

    printf("how does one unity cost: ");
    scanf("%f", &price);

    printf("how many you would like to purchase: ");
    scanf("%d", &quantity);

    total = price * quantity;

    printf("%d %s costs %.2f%s \n", quantity, item, total
        , currency);
    
    return 0;
}