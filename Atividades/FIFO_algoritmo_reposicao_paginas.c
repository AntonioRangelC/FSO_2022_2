#include <stdio.h>


#define MAX_QUADROS 1000000


int main(){

    int quadros[MAX_QUADROS];

    int qtdQuadros;
    int hit = 0;

    scanf("%d", &qtdQuadros);

    int qtdIndices;
    for(int aux = 0; aux < qtdQuadros; aux++){
        quadros[aux] = -1;
    }
    scanf("%d", &qtdIndices);


    for (int i = 0; i < qtdIndices; i++) {
        int indice;
        scanf("%d", &indice);

        // Procura se a pagina esta na memoria
        int page_in_memory = 0;
        for (int j = 0; j < qtdQuadros; j++) {
            if (quadros[j] == indice) {
                page_in_memory = 1;
                hit++;
                break;
            }
        }

        // se nao estiver, utiliza o algoritmo FIFO
        if (!page_in_memory) {
            for (int j = qtdQuadros - 1; j > 0; j--) {
                quadros[j] = quadros[j - 1];
            }
            quadros[0] = indice;
        }
    }


    int num_page_faults = qtdIndices - hit;

    printf("%d\n", num_page_faults);

    return 0;
}


