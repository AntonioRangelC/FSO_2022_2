#include<stdio.h>

int main(int argc, char **argv){
    int aux;
    printf("%d\n" , argc - 1);
    for(aux = 1; aux < argc; aux++){
        printf("%s\n", argv[aux]);
    }
    return 0;
}