#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int primVetor[10000000];
int segundoVetor[10000000];
// gcc -g -o trabalho2_vetores_identicos trabalho2_vetores_identicos.c -pthread
struct thread_st{
    int *vetorThread;
    int tamanho;
    pthread_t idThread;
};

struct thread_compar{
    int ini;
    int fim;
    pthread_t idThread;
    int resultado;
};

int compar(const void *a, const void *b);
void *threadfunc(void *p);
void *threadcompar(void *p);
void quicksortM3(int *vetor, int comeco, int fim);
int separa(int *vetor, int comeco, int fim);

int main(){
    int tamanhoPrimVetor, tamanhoSegVetor, i;
    scanf("%d", &tamanhoPrimVetor); //tamanho vetor1
    tamanhoSegVetor = tamanhoPrimVetor;
    for(i = 0; i < tamanhoPrimVetor; i++){
        scanf("%d", &primVetor[i]);
    }

    for(i = 0; i < tamanhoSegVetor; i++){
        scanf("%d", &segundoVetor[i]);
    }

    struct thread_st thread1, thread2;
    thread1.vetorThread = primVetor;
    thread1.tamanho = tamanhoPrimVetor;
    thread2.vetorThread = segundoVetor;
    thread2.tamanho = tamanhoSegVetor;
    
    pthread_create(&thread1.idThread, NULL, threadfunc, (void*)&thread1);
    pthread_create(&thread2.idThread, NULL, threadfunc, (void*)&thread2);
    
    pthread_join(thread1.idThread, NULL);
    pthread_join(thread2.idThread, NULL);

    struct thread_compar comparThread1, comparThread2;
    comparThread1.ini = 0;
    comparThread1.fim = tamanhoPrimVetor/2;
    comparThread2.ini = tamanhoPrimVetor/2;
    comparThread2.fim = tamanhoPrimVetor;
    pthread_create(&comparThread1.idThread, NULL, threadcompar, (void*)&comparThread1);
    pthread_create(&comparThread2.idThread, NULL, threadcompar, (void*)&comparThread2);
    pthread_join(comparThread1.idThread, NULL);
    pthread_join(comparThread2.idThread, NULL);

    if(comparThread1.resultado == 1 && comparThread2.resultado == 1){
        printf("Mesmos elementos\n");
    }
    else{
        printf("Diferentes\n");
    }

    return 0;
}

int compar(const void *a, const void *b){

    if(*(int*)a > *(int*)b){
        return 1;
    }

    if(*(int*)a < *(int*)b){
        return -1;
    }

    return 0;
}

void *threadfunc(void *p){
    struct thread_st *a=(struct thread_st*)p;
    qsort(a->vetorThread, a->tamanho, sizeof(int), compar);
    //quicksortM3(a->vetorThread, 0, a->tamanho);
}

void *threadcompar(void *p){
    struct thread_compar *a = (struct thread_compar*)p;
    for(int i = a->ini; i < a->fim; i++){
        if(primVetor[i] != segundoVetor[i]){
            a->resultado = 0;
            return NULL;
        }
    }
    a->resultado = 1;
}

void quicksortM3(int *vetor, int comeco, int fim){
    int temp,j, meio = (fim+comeco)/2;
    if(fim<=comeco){
        return;
    }
    temp = vetor[fim-1];
    vetor[fim-1] = vetor[meio];
    vetor[meio] = temp;

    if(vetor[fim] < vetor[meio]){
        temp = vetor[fim];
        vetor[fim] = vetor[meio];
        vetor[meio] = temp;
        if( vetor[meio] < vetor[comeco]){
            temp = vetor[comeco];
            vetor[comeco] = vetor[meio];
            vetor[meio] = temp;
            if(vetor[meio] < vetor[fim]){
                temp = vetor[fim];
                vetor[fim] = vetor[meio];
                vetor[meio] = temp;
            }
        }
    }


    j = separa(vetor, comeco, fim);
    quicksortM3(vetor, comeco, j-1);
    quicksortM3(vetor, j+1, fim);
}

int separa(int *vetor, int comeco, int fim){
    int pivo = vetor[fim];
    int j = comeco, aux,temp;
    for(aux=comeco; aux<fim; aux++){
        if(vetor[aux] < pivo){
            temp = vetor[aux];
            vetor[aux] = vetor[j];
            vetor[j] = temp;
            j++;
        }

    }
    temp = vetor[j];
    vetor[j] = vetor[fim];
    vetor[fim] = temp;
    return j;

}


