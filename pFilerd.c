#include <stdio.h>
#include <string.h>

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
    p.nome[strcspn(p.nome, "\n")] = '\0';
    printf("%s\n",p.nome);

    fscanf(pFile," %d",&p.idade);
    printf("%d\n",p.idade);
    
    fscanf(pFile," %f",&p.peso);
    printf("%.2f kg\n", p.peso);
    fclose(pFile);
    return 0;
}