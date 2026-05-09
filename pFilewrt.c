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
    pFile = fopen("cadastro.txt","w");
    int flag = 1;
    while(flag==1){

        printf("digite o nome:\n");
        fgets(p.nome,50,stdin);
        p.nome[strcspn(p.nome, "\n")] = '\0'; //vai remosver o ' \n ' que o fgets coloca no final da string.
        fprintf(pFile,"%s\n",p.nome);

        printf("digite a idade:\n");
        scanf("%d",&p.idade);
        fprintf(pFile,"%d\n",p.idade);

        printf("digite o peso:\n");
        scanf("%f",&p.peso);
        fprintf(pFile,"%.2f\n", p.peso);


        printf("Deseja cadastrar mais pessoas? (1 - Sim, 0 - Nao): ");
        scanf("%d", &flag);
        getchar();
    }
    fclose(pFile);
}