#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(void){
    //em casa fazer com funcoes
    char word1[100], word2[100];
    printf("enter one word(up to 100char): ");
    fgets(word1, sizeof(word1)/sizeof(char), stdin);
    word1[strlen(word1)-1] = '\0'; //remover os espacos
    printf("enter another word(up to 100char): ");
    fgets(word2, sizeof(word2)/sizeof(char), stdin);
    word2[strlen(word2)-1] = '\0';
    printf("%s, %s\n", word1, word2);
    int alphaCount = 0;
    /*
    outra maneira de iterar strings
    n=0
    char *p = str;
    while (*p != '\0){
        if (){
            ...        
        }
        p++;
    }
    */
    for (int i = 0; word1[i] != '\0'; i++){ //nao fazer strlen aqui porque pode dar asneira
        if (isalpha(word1[i])){ 
            alphaCount++;
            if(isupper(word1[i])){
                word1[i] = tolower(word1[i]);
            }
        }
    }
    int upperCount=0;
    for (int i = 0; word2[i] != '\0'; i++){
        if(isupper(word2[i])){
            upperCount++;
            word2[i] = tolower(word2[i]);
        }
    }
    if(strcmp(word1, word2) == 0){
        printf("the two strings are the same\n");
    }else{
        printf("the two strings are not the same\n");
    }

    char str[sizeof(word2)]; 
    strcpy(str, word2);

    printf("alphabetic: %d\n", alphaCount);
    printf("upper: %d\n", upperCount);
    printf("str1: %s\n", word1);
    printf("str2: %s\n", word2);
    printf("copy of str2: %s\n", str);
    strcat(str, word2);
    printf("concat: %s\n", str);
    
    return 0;
}