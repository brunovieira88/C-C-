#include <stdio.h>

int main (void){
    
    printf("void* %lu\n",sizeof(void*));
    printf("void %lu\n",sizeof(void));
    printf("char %lu\n",sizeof(char));
    printf("short %lu\n",sizeof(short));
    printf("int %lu\n",sizeof(int));
    printf("long %lu\n", sizeof(long));
    printf("long long %lu\n",sizeof(long long));
    printf("float %lu\n",sizeof(float));
    printf("double %lu\n",sizeof(double));
    
    return 0;
}