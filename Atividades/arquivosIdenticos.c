#include <stdio.h>
#include <string.h>

int main(int argc,char **argv){
    int aux, aux2, posicao = 0 , aux3, diferente = 0;
    char caractere;
    char conteudoArquivo[3000001];
    char nomeArquivo[1000], nomeArquivoReserva[1000];
    FILE *pArq;
    for(aux = 1; aux < argc - 1; aux++){

        strcpy(nomeArquivo, argv[aux]);
        
        strcpy(nomeArquivoReserva, argv[aux]); //guarda nome do arquivo sem a extensao
        strcat(nomeArquivo, ".bin");
        //printf("%s\n", nomeArquivo);
       
        pArq = fopen(nomeArquivo , "rb");
        
        if(pArq == NULL){ //nao encontrou o arquivo, entao deve ser arquivo .txt
            strcpy(nomeArquivo, nomeArquivoReserva);
            strcat(nomeArquivo, ".txt");
            pArq = fopen(nomeArquivo , "r");
            
        }
        
        fseek(pArq,0,SEEK_SET);
        while(fread(&caractere, sizeof(caractere),1,pArq)){
            conteudoArquivo[posicao] = caractere;
            posicao++;
        }

        fclose(pArq);
        //printf("conteudo: %s\n", conteudoArquivo);
        
        
        strcpy(nomeArquivo, "");

        for(aux2 = aux+1; aux2 < argc; aux2++){
            
            strcpy(nomeArquivo, argv[aux2]);
            strcpy(nomeArquivoReserva, argv[aux2]);
            strcat(nomeArquivo, ".bin");
            //printf("%s\n", nomeArquivo);
            pArq = fopen(nomeArquivo, "rb");

            if(pArq == NULL){
                strcpy(nomeArquivo, nomeArquivoReserva);
                strcat(nomeArquivo, ".txt");
                pArq = fopen(nomeArquivo, "r");
            }

            fseek(pArq,0,SEEK_SET);

            for(aux3 = 0; aux3 < posicao && fread(&caractere, sizeof(caractere),1,pArq) && diferente == 0; aux3++){
                if(caractere != conteudoArquivo[aux3]){
                    diferente = 1;
                }
                //printf("%c", caractere);
            }
            //printf("\n");

            fclose(pArq);

            strcpy(nomeArquivo, "");

            if(diferente){
                printf("%s %s diferentes\n", argv[aux], argv[aux2]);
            }
            else{
                printf("%s %s iguais\n", argv[aux], argv[aux2]);
            }
            

            


        }
        posicao = 0;
    }
    

    return 0;
}


/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void compara(char **argumentos);

int main (int argc, char **argv) {
    
    argv++;
    compara(argv);

    return 0;
}



void compara(char **argumentos){

    size_t resultadoA;

    char **proximo, **atual;

   
    atual = argumentos;
  
    proximo = argumentos;
    proximo++;

 
    FILE *pArq;
    pArq = fopen(*atual, "r");
    fseek(pArq, 0L, SEEK_END);
   
    long tamanhoA;
    tamanhoA = ftell(pArq);
   
    rewind(pArq);

  
    char *bufferA;
    bufferA = (char *) malloc(sizeof(char)*tamanhoA);

    if(bufferA == NULL) {
        return;
    }
  
    resultadoA = fread(bufferA, 1, tamanhoA, pArq);
    if(resultadoA != tamanhoA) {
        return;
        
    }

    
    while(*proximo != NULL){
        
      
        FILE *arqN;
        arqN = fopen(*proximo, "r");
        
        fseek(arqN, 0L, SEEK_END);
        long szN;
        szN = ftell(arqN);
       
        rewind(arqN);

        
        if(szN != tamanhoA){
            printf("%s %s diferentes\n", *atual, *proximo);
        } else {
           

           
            char *bufferN;
            bufferN = (char *) malloc(sizeof(char)*szN);
            if(bufferN == NULL) {
                return;
            }
          
            size_t resultadoN = fread(bufferN, 1, szN, arqN);
            if(resultadoN != szN) {
                return;
            }

            
            if(memcmp(bufferA, bufferN, resultadoN) == 0){
                printf("%s %s iguais\n", *atual, *proximo);
            } else {
                printf("%s %s diferentes\n", *atual, *proximo);
            }
            
            free(bufferN);
        }

        
        proximo++;
        fclose(arqN);
    }

    
    free(bufferA);
    fclose(pArq);
    
    atual++;
    if(*atual != NULL){
        compara(atual);
    }
    return;
}


*/