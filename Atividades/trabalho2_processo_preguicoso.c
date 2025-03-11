#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include<signal.h>

int contadorSinais = 0;

void lidarComSinal(int sinal);

int main(){

    signal(SIGUSR1, lidarComSinal);
    signal(SIGALRM, lidarComSinal);

    while(1){
        pause();
    }
}

void lidarComSinal(int sinal){
    if(sinal == SIGUSR1){
        printf("SIGUSR1 eh para aproveitar mais um pouco\n");
    }
    else if(contadorSinais < 2){
        printf("Ai que sono, quero dormir mais um pouco\n");
        contadorSinais++;
    }
    else{
        printf("Os incomodados que se mudem, tchau\n");
        exit(0);
    }
}



