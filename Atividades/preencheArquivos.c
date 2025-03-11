#include<stdio.h>

int main(){

    char num = '1';
    char num2 = '2';
    char num3 = '3';
    FILE *pArq;
    pArq = fopen("teste1_txt.txt","w");

    for(int aux = 0; aux < 6; aux++){
        fwrite(&num,sizeof(num),1,pArq);
    }

    fclose(pArq);

    pArq = fopen("teste2_txt.txt","w");
    for(int aux = 0; aux < 6; aux++){
        fwrite(&num2,sizeof(num2),1,pArq);
    }

    fclose(pArq);

    pArq = fopen("teste3_txt.txt","w");
    for(int aux = 0; aux < 6; aux++){
        fwrite(&num3,sizeof(num3),1,pArq);
    }

    fclose(pArq);


    return 0;
}