#include <stdio.h>
#include <string.h>
#include <ctype.h>


char *cutFreeSpace(char *str){
    str[strlen(str)-1] = '\0';
    return str;
}
int countAlphaChar(char *str){
    int alphaCount=0;
    for (int i = 0; str[i] != '\0'; i++){ //nao fazer strlen aqui porque pode dar asneira
        if (isalpha(str[i])){ 
            alphaCount++;
        }
    }
    return alphaCount;
}
int countUpperChar(char *str){
    int upperCount=0;
    for (int i =0; str[i] != '\0'; i++){
        if (isupper(str[i])){
            upperCount++;
        }
    }
    return upperCount;
}
char *convertUpperToLowerChar(char *str){
    for (int i = 0; str[i]!='\0'; i++){
        if (isupper(str[i])){
            str[i]=tolower(str[i]);
        }
    }
    return str;
}
int main(void){
    //em casa fazer com funcoes
    char word1[100], word2[100];
    printf("enter one word(up to 100char): ");
    fgets(word1, sizeof(word1)/sizeof(char), stdin);
    cutFreeSpace(word1); //remover os espacos

    printf("enter another word(up to 100char): ");
    fgets(word2, sizeof(word2)/sizeof(char), stdin);
    cutFreeSpace(word2);
    printf("%s, %s\n", word1, word2);
    int alphaCount = countAlphaChar(word1);
    /*
    outra maneira de iterar strings
    n=0
    char *p = str;
    while (*p != '\0' ){
        if (){
            ...        
        }
        p++;
    }
    */
    int upperCount = countUpperChar(word2);
    convertUpperToLowerChar(word1);
    convertUpperToLowerChar(word2);
    //see if the two string are the same using the strcmp function 
    if(strcmp(word1, word2) == 0){
        printf("the two strings are the same\n");
    }else{
        printf("the two strings are not the same\n");
    }

    char str[sizeof(word2) + 100]; 
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