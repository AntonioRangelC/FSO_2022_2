#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#include <signal.h>

int temErro = 0;

void cuidaSinal(int numeroSinal);
double diferencaTempo(struct timeval *comeco, struct timeval *fim);
void cuidaProcessoPai();
void cuidaProcessoFilho(const char *path, const char *args);
void lidarComSinal(int sinal);

int main () {
    char path[255], args[255];
    int aux, auxiliar, aux2=0;

    struct timeval tempoTotalInicial, tempoTotalFinal;

    signal(SIGUSR1, cuidaSinal);

    gettimeofday(&tempoTotalInicial, NULL);

    while (scanf("%s %[^\n]", path, args) == 2) { 
        temErro = 0;
        pid_t pid = fork();

        if (pid == 0) { 
            cuidaProcessoFilho(path, args);
        }
        else if (pid > 0) {
            cuidaProcessoPai();
        }
    }

    gettimeofday(&tempoTotalFinal, NULL);

    printf(">> O tempo total foi de %0.1lf segundos\n", diferencaTempo(&tempoTotalInicial , &tempoTotalFinal));

    return 0;
}

void cuidaSinal(int numeroSinal) {
    if (numeroSinal == SIGUSR1) {
        temErro = 1;
    }   
}

double diferencaTempo(struct timeval *comeco, struct timeval *fim) {
    return (fim->tv_sec - comeco->tv_sec) + 1e-6*(fim->tv_usec - comeco->tv_usec);
}

void cuidaProcessoPai() {
    int statusFilho;
    struct timeval comeco, fim;

    gettimeofday(&comeco, NULL);
    pid_t p = wait(&statusFilho);
    gettimeofday(&fim, NULL);

    if (temErro == 1) {
        printf("> Erro: %s\n", strerror(WEXITSTATUS(statusFilho)));
    }
    
    printf("> Demorou %0.1lf segundos, retornou %d\n", diferencaTempo(&comeco , &fim), WEXITSTATUS(statusFilho));
    fflush(stdout);
    
}

void cuidaProcessoFilho(const char *path, const char *args) {
    execl(path, path, args, NULL);

    kill(getppid(), SIGUSR1);
    
    _exit(errno);
}

/*void lidarComSinal(int sinal){
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
}*/