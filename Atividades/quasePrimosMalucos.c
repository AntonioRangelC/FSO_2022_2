#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>

typedef struct Parameter{
    int n;
    int resultado;
}parameter;


void* quasePrimos(void* arg);
int quasePrimos2(int n);

int main(void){
    int qtd_num;
    scanf("%d", &qtd_num)==1;

    while (qtd_num > 0){
        if (qtd_num > 2){
            parameter pa, pb, pc;
            pthread_t t1, t2;
            int n1, n2, n3;

            scanf("%d %d %d", &n1, &n2, &n3)==1;

            pa.n = n1;
            pb.n = n2;
            pc.n = n3;

            pthread_create(&t1, NULL, quasePrimos, &pa);
            pthread_create(&t2, NULL, quasePrimos, &pb);
            quasePrimos(&pc);

            pthread_join(t1, NULL);
            pthread_join(t2, NULL);

            printf("%d\n", pa.resultado);
            printf("%d\n", pb.resultado);
            printf("%d\n", pc.resultado);

            qtd_num -= 3;
        } else if (qtd_num == 2){
            parameter pa, pb;
            pthread_t t1, t2;
            int n1, n2;

            scanf("%d %d", &n1, &n2)==1;

            pa.n = n1;
            pb.n = n2;

            pthread_create(&t1, NULL, quasePrimos, &pa);
            pthread_create(&t2, NULL, quasePrimos, &pb);

            pthread_join(t1, NULL);
            pthread_join(t2, NULL);

            printf("%d\n", pa.resultado);
            printf("%d\n", pb.resultado);

            qtd_num -= 2;
        } else {
            int n3;
            parameter pc;
            pthread_t t3;

            scanf("%d", &n3)==1;
            
            pc.n = n3;

            pthread_create(&t3, NULL, quasePrimos, &pc);
            pthread_join(t3, NULL);
            
            printf("%d\n", pc.resultado);
            qtd_num--;
        }
    }
    
    return 0;
}



void* quasePrimos(void* arg){
    parameter *param = (parameter*)arg;
    int num = (param->n)+1;

    if(num <= 508079){
        param->resultado = 508079;
    } 
    else{
        while(1){
            if(quasePrimos2(num)){
                param->resultado = num;
                break;
            }
            num++;
        }
    }
}


int quasePrimos2(int n){
    if(n%2==0) return 0;
   
    int contador = 0, raiz = floor(sqrt(n));
    
    for (int i=3; i<raiz; i+=2){
        if(n%i==0 && i<11) {
            return 0;
        }
        
        if(n%i==0 && i>10){
            contador++;
        } 
        if (contador >= 10){
            return 1;
        } 
    }
    
    return 0;
}