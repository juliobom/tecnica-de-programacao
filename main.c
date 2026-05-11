#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <conio.h>


//para margen de vencimento estebelecido dia presente em 05/06/2025, sem data for menor receberao um rotulo de ""produto vencido".


typedef struct{
        char nome[50];
        int data_validade,dia,mes,ano,venc;
        float preco;

}produto;

typedef struct{
    int inserir,listar,remover,prog,opcao;
}condicao;


void ordene(produto *p,int tam){


    for(int i=0;i<tam;i++){
    p[i].data_validade = (p[i].ano-2025)*365 + (p[i].mes-1)*30 + p[i].dia;



    }
    
}

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
                if(ano<2025 || (ano==2025 && mes<6) || (ano==2025 && mes==6 && dia<5)){
                    p[count].venc = 1;
                }
                
            
            printf("Digite o preço do produto: ");
            scanf("%f", &p[count].preco);
            p[count].dia = dia;
            p[count].mes = mes;
            p[count].ano = ano;
            printf("%d/%d/%d\n", p[count].dia, p[count].mes, p[count].ano);
            printf("Produto cadastrado com sucesso!\n");
            sleep(1);
            system("cls");
            ordene(p,count);
            count ++;//----> futuramente vou retornar um valor para funcao de listagem ou (criar uma variavel dinamicamente) para saber quantos produtos foram cadastrados no total.
            
        }

        printf("Deseja cadastrar mais produto(s)? (1 - Sim, 0 - Nao): ");
        scanf("%d", &flag->inserir);
    }
}

void listagem(produto *p, int tam, condicao *flag){     // flag vai ser usada para retornar ao menu principal quando nao querer mais listar os produtos.

    for(int i=0;i<tam;i++){

        printf("[%d] [ produto: %s | data de validade: %d/%d/%d | preco: %.2f ]", i+1, p[i].nome, p[i].dia, p[i].mes, p[i].ano, p[i].preco);
        if(p[i].venc==1){
            printf(" (Produto vencido)\n");
        }
        printf("\n");
    }



}

int main(){

    int count;
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
                system("cls");
                count = 0;              
                cadastrar_produto(a, 10, &flag); //vai receber um ponteiro para uma variavel limite para saber quantos produtos foram cadastrados na hora de listar-los.
                break;
            case 2:
                listagem(a, 10, &flag);
                break;
            case 3:
                //vai remover um produto cadastrado
                break;
            case 0:
                count =0;
                while (count<1)
                {
                    printf("Saindo do programa.");
                    sleep(1);
                    system("cls");
                    printf("Saindo do programa..");
                    sleep(1);
                    system("cls");
                    printf("Saindo do programa...");
                    sleep(1);
                    system("cls");
                    count++;
                }
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