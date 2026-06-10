#include <stdio.h>
#include <stdlib.h>

typedef struct{

    int mat;
    char nome[50];
    float nota;

}aluno;



int main(){


    FILE * arq;                    //criar uma arquivo binario e ler o arquivo binario  com varias struct
    aluno a;

    
    scanf("%d",&a.mat);

    while(a.mat!=0){

    
        scanf("%s%f",a.nome,&a.nota); 
       arq = fopen ("Alunadoooo2.bin", "wb"); 
        fwrite (&a , sizeof(aluno), 1, arq)==1;
        scanf("%d",&a.mat);
    
    }
    fclose (arq);
    return 0;




}