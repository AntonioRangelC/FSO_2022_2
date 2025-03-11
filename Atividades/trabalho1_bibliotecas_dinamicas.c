#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(int argc, char **argv){
    int aux, aux2=0, primInt, segInt;
    double primDouble, auxiliar;

    primDouble = atof(argv[4]);
    primInt = atoi(argv[2]);
    segInt = atoi(argv[3]);
    /*auxiliar = argv[4][2] - '0';
    auxiliar = auxiliar * 10.0;
    auxiliar = auxiliar + (argv[4][3] - '0');
    auxiliar = auxiliar / 100.0;

    primDouble = primDouble + auxiliar;


    primInt = argv[2][0] - '0';
    primInt = primInt * 10;
    aux = argv[2][1] - '0';
    primInt = primInt + aux;

    segInt = argv[3][0] - '0';
    segInt = segInt * 10;
    aux = argv[3][1] - '0';
    segInt = segInt + aux;*/

    //printf("primInt: %d\n segInt %d\n", primInt, segInt);
    //printf("primDouble: %lf\n", primDouble);

    void *pManipulador;
    int (*imprime)(void);
    int (*calcula)(int, int);
    int (*trigo)(double, double*);

    /*char nomeBiblioteca[200];
    char auxiliar[200];
    for(aux = 0; aux < strlen(argv[1]); aux++){
         if(aux > 1){
             auxiliar[aux2] = argv[1][aux];
             aux2++;
         }
    }*/


    pManipulador = dlopen(argv[1], RTLD_LAZY);
    if(!pManipulador){
        printf("nao disponivel\n");
    }
    else{
        imprime = dlsym(pManipulador, "imprime");
        if(!imprime){
            printf("nao implementado\n");
        }
        else{
            printf("%d\n", imprime());
        }

        calcula = dlsym(pManipulador, "calcula");
        if(!calcula){
            printf("nao implementado\n");
        }
        else{
            printf("%d\n", calcula(primInt, segInt));
        }

        trigo = dlsym(pManipulador, "trigo");
        if(!trigo){
            printf("nao implementado\n");
        }
        else{
            printf("%d\n", trigo(primDouble, &primDouble));
        }

    }






    return 0;
}