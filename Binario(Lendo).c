#include <stdio.h>
#include <stdlib.h>

typedef struct{

    int mat;
    char nome[50];
    float nota;

}aluno;



int main(){
                        //criar uma arquivo binario e ler o arquivo binario  com varias struct
    aluno a[5];

    FILE * arq;
  
    arq = fopen ("Alunadoooo2.bin", "rb");
    while(fread (a , sizeof(aluno), 1, arq)==1);  //aqui vai gravar na struct aluno presente em --> "a", lendo de 1 em 1, com tamanha predefinido de 1 voltada.
                              
    for(int i=0;i<1;i++){
        
        printf("%s\n%d\n%f\n",a[i].nome,a[i].mat,a[i].nota);
        
    }
    fclose (arq);
    return 0;




}