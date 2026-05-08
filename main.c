#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <conio.h>



typedef struct{
        char nome[50];
        int data_validade,dia,mes,ano;
        float preco;

}produto;

typedef struct{
    int inserir,listar,remover,prog,opcao;
}condicao;


void cadastrar_produto(produto *p,int tam, condicao *flag){
    int dia,mes,ano,count=0;
    flag->inserir = 1;
    while(flag->inserir != 0){
        int qtd;
        printf("Quantos produtos deseja cadastrar?\n");
        scanf("%d", &qtd);
        system("cls");
        for(int i=0;i<qtd;i++){
            printf("Digite o nome do produto: ");
            scanf("%s", p[count].nome);
            printf("Digite a data de validade (formato dia / mes / ano): ");
            scanf("%d / %d / %d", &dia, &mes, &ano);
            printf("Digite o preço do produto: ");
            scanf("%f", &p[count].preco);
            p[count].dia = dia;
            p[count].mes = mes;
            p[count].ano = ano;
            printf("%d/%d/%d\n", p[count].dia, p[count].mes, p[count].ano);
            printf("Produto cadastrado com sucesso!\n");
            sleep(1);
            system("cls");
            count ++;//----> futuramente vou retornar um valor para funcao de listagem ou (criar uma variavel dinamicamente) para saber quantos produtos foram cadastrados no total.
        }
        
        printf("Deseja cadastrar mais produto(s)? (1 - Sim, 0 - Nao): ");
        scanf("%d", &flag->inserir);
    }
}

void listagem(produto *p, int tam, condicao *flag){

    for(int i=0;i<tam;i++){

        printf("[%d] [ produto: %s | data de validade: %d/%d/%d | preco: %.2f ]\n", i+1, p[i].nome, p[i].dia, p[i].mes, p[i].ano, p[i].preco);
    }



}

int main(){

    produto a[10];
    condicao flag;
    flag.prog = 1;
    while(flag.prog != 0){

        printf("\n1 - cadastrar um produto\n\n2 - listar os produtos\n\n3 - remover um produto\n\n0 - sair\n\nDigite a opcao desejada:  ");
        scanf("%d", &flag.prog);
        system("cls");
        switch (flag.prog){
            case 1:
                printf("Cadastro de produto\n\n");
                sleep(1);
                cadastrar_produto(a, 10, &flag);
                break;
            case 2:
                listagem(a, 10, &flag);
                break;
            case 3:
                //vai remover um produto cadastrado
                break;
            case 0:
                printf("Saindo do programa...\n");
                sleep(2);
                break;
        }
    }
      
    return 0;
}


/*
git init    // inicializa o repositório git

git add (nome do arquivo)    //adiciona o arquivo para o próximo commit, ou seja, para o próximo ponto de salvamento do código.

git status   //mostra o status do repositório, ou seja, quais arquivos foram modificados, quais estão prontos para o commit, etc.

git commit -m / git commit -am (ja adiciona commitando) "mensagem do commit"   //cria um commit com as alterações adicionadas e a mensagem fornecida. O commit é um ponto de salvamento no histórico do projeto.

git log / git log --oneline   //mostra o histórico de commits do repositório. O comando "git log" exibe detalhes completos de cada commit, enquanto "git log --oneline" mostra uma versão resumida, com apenas o hash do commit e a mensagem.

git restore (nome do arquivo)   //desfaz as alterações feitas no arquivo

git push -u origin main   //envia os commits locais para o repositório remoto, associando a branch local "main" com a branch remota "origin/main". O comando "git push" é usado para compartilhar as alterações com outros colaboradores ou para atualizar o repositório remoto.

git branch   (nome do branch) -M (novo nome do branch) //renomeia a branch atual para o novo nome especificado. O comando "git branch" é usado para criar, listar ou renomear branches no repositório.

git branch   //mostra a lista de branches no repositório, indicando qual branch está atualmente ativa com um asterisco (*). O comando "git branch" é usado para gerenciar as branches do projeto.*/