#include <stdio.h>

int main(int argc, char *argv[]) {
   if (argv[1] == NULL || argv[2] == NULL){
        printf("enter name and surname\n");
        return 0;
   }
    printf("Hello %s %s!\n", argv[1], argv[2]);

    return 0;
}
