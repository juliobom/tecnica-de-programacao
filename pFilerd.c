#include <stdio.h>

typedef struct {

    char nome [50];
    int idade;
    float peso;
}Pessoa;

int main(){

    Pessoa p;
    FILE * pFile;
    pFile = fopen("cadastro.txt","r");

    fgets(p.nome,50,pFile);
    printf("%s",p.nome);
    fscanf(pFile," %d",&p.idade);
    printf("%d",p.idade);
    fscanf(pFile," %f",&p.peso);
    printf("%.2fkg", p.peso);
    getchar();
    fclose(pFile);

}