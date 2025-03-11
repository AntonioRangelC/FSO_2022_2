#include<stdio.h>

#define MAX_PAGES 1


typedef struct {
    int pageNumber;
} Page;


typedef struct {
    Page pages[MAX_PAGES];
    int pageCount;
} Memory;


void initMemory(Memory* memory, int pageCount) {
    memory->pageCount = pageCount;
    for (int i = 0; i < pageCount; i++) {
        memory->pages[i].pageNumber = -1;
    }
}

// Função para buscar uma página na memória
int searchPageInMemory(Memory* memory, int pageNumber) {
    for (int i = 0; i < memory->pageCount; i++) {
        if (memory->pages[i].pageNumber == pageNumber) {
            return i;
        }
    }
    return -1;
}


void optimal(Memory* memory, int pageNumber) {
    int pageFaults = 0;
    int indexToReplace = -1;
    int maxSteps = 0;
    for (int i = 0; i < memory->pageCount; i++) {
        int page = memory->pages[i].pageNumber;
        if (page == -1) {
            indexToReplace = i;
            break;
        }
        int steps = 0;
        while (pageNumber != page) {
            steps++;
            page = memory->pages[(i + steps) % memory->pageCount].pageNumber;
        }
        if (steps > maxSteps) {
            maxSteps = steps;
            indexToReplace = i;
        }
    }

    if (memory->pages[indexToReplace].pageNumber != pageNumber) {
        pageFaults++;
    }

    memory->pages[indexToReplace].pageNumber = pageNumber;
}

int main()
{
    int qtdQuadros, qtdIndices,  temp[1000000], flag1, flag2, flag3, i, j, k, pos, max;
    int qtdPageFaults = 0;

    scanf("%d", &qtdQuadros);

    scanf("%d", &qtdIndices);

    int quadros[1000000], indices[1000000];

    for(i = 0; i < qtdIndices; ++i){
        scanf("%d", &indices[i]);
    }

    for(i = 0; i < qtdQuadros; ++i){
        quadros[i] = -1;
    }

    for(i = 0; i < qtdIndices; ++i){
        flag1 = 0;
        flag2 = 0;

        for(j = 0; j < qtdQuadros; ++j){
            if(quadros[j] == indices[i]){
                flag1 = 1;
                flag2 = 1;
                break;
            }
        }

        if(flag1 == 0){
            for(j = 0; j < qtdQuadros; ++j){
                if(quadros[j] == -1){
                    qtdPageFaults++;
                    quadros[j] = indices[i];
                    flag2 = 1;
                    break;
                }
            }
        }

        if(flag2 == 0){
            flag3 =0;

            for(j = 0; j < qtdQuadros; ++j){
                temp[j] = -1;

                for(k = i + 1; k < qtdIndices; ++k){
                    if(quadros[j] == indices[k]){
                        temp[j] = k;
                        break;
                    }
                }
            }

            for(j = 0; j < qtdQuadros; ++j){
                if(temp[j] == -1){
                    pos = j;
                    flag3 = 1;
                    break;
                }
            }

            if(flag3 ==0){
                max = temp[0];
                pos = 0;

                for(j = 1; j < qtdQuadros; ++j){
                    if(temp[j] > max){
                        max = temp[j];
                        pos = j;
                    }
                }
            }
            quadros[pos] = indices[i];
            qtdPageFaults++;
        }


    }

    printf("%d\n", qtdPageFaults);

    return 0;
}