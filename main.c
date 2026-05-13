#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>


//para margen de vencimento, estebelecido dia presente em 05/06/2025, se data for menor recebera um rotulo de ""produto vencido".

typedef struct{
        char nome[50];
        int data_validade,dia,mes,ano,venc,id;
        float preco;

}produto;

typedef struct{
    int inserir,listar,remover,prog,opcao;
}condicao;


void ordeneId(int *tam,produto *key2){
    
    produto aux;
    int i,j;
    for(i=1;i<*tam;i++){
        aux=key2[i];
        for(j=i-1;j>=0&&key2[j].id>aux.id;j--){

            key2[j+1]=key2[j];

        }
        key2[j+1] = aux;
    }
}


void ordeneNome(int *tam,produto *key1){     
    
    produto aux;
    int i,j;
    for(i=1;i<*tam;i++){
        
        aux=key1[i];
        for(j=i-1;j>=0&&strcmp(key1[j].nome,aux.nome)>0;j--){

            key1[j+1]=key1[j];

        }
        key1[j+1] = aux;
    }
}


void buscador(produto *prod, int *list){



}

void cadastrar_produto(produto *prod, condicao *flag, int *list,produto *key1,produto *key2){      
    int dia,mes,ano;
    flag->inserir = 1;
    while(flag->inserir != 0){

        int qtd;

        printf("Quantos produtos deseja cadastrar?\n");
        scanf("%d", &qtd);
            system("cls");

        for(int i=0;i<qtd;i++){

            printf("Digite o nome do produto: ");
            scanf("%s", prod[*list].nome);

            printf("Digite a data de validade (formato dia / mes / ano): ");
            scanf("%d / %d / %d", &dia, &mes, &ano);
                if(ano<2025 || (ano==2025 && mes<6) || (ano==2025 && mes==6 && dia<5)){
                    prod[*list].venc = 1;
                }else{
                    prod[*list].venc = 0;
                }
                
            printf("Digite o preço do produto: ");
            scanf("%f", &prod[*list].preco);

            prod[*list].dia = dia;
            prod[*list].mes = mes;
            prod[*list].ano = ano;
            prod[*list].id=rand()%1000;

            {
                key1[*list] = prod[*list];
                key2[*list] = prod[*list];
            }  

            printf("Produto cadastrado com sucesso!\n");
                sleep(1);
                system("cls");
            
            *list += 1;
            ordeneId( list, key2);
            ordeneNome( list, key1);
            
        }
        printf("Deseja cadastrar mais produto(s)? (1 - Sim, 0 - Nao): ");
        scanf("%d", &flag->inserir);
    }
}

void listagem(produto *prod, condicao *flag, int *list, produto *key1, produto *key2){

    flag->listar=1;
    while(flag->listar!=0){
        printf("Como deseja listar os produtos?\n1 - Padrão:\n2 - Nome:\n3 - lista Id:\n\nDigite a opcao desejada:  ");
        scanf("%d",&flag->listar);
        system("cls");
        switch (flag->listar){
            case 1:
                for(int i=0;i<*list;i++){

                    printf("[%d] [id: %4.d] [ produto: %s | data de validade: %d/%d/%d | preco: %.2f ]", i+1, prod[i].id, prod[i].nome, prod[i].dia, prod[i].mes, prod[i].ano, prod[i].preco);
                    if(prod[i].venc==1){
                        printf(" (Produto vencido)");
                    }
                    printf("\n");
                }
                break;

            case 2:
                for(int i=0;i<*list;i++){

                    printf("[%d] [id: %4.d] [ produto: %s | data de validade: %d/%d/%d | preco: %.2f ]", i+1, key1[i].id, key1[i].nome, key1[i].dia, key1[i].mes, key1[i].ano, key1[i].preco);
                    if(key1[i].venc==1){
                    printf(" (Produto vencido)");
                    }
                    printf("\n");
                }
                break;

            case 3:
            for(int i=0;i<*list;i++){

                printf("[%d] [id: %4.d] [ produto: %s | data de validade: %d/%d/%d | preco: %.2f ]", i+1, key2[i].id, key2[i].nome, key2[i].dia, key2[i].mes, key2[i].ano, key2[i].preco);
                if(key2[i].venc==1){
                    printf(" (Produto vencido)");
                }
                printf("\n");
            }
            break;

        }
        
        printf("\ndeseja listar de outra forma? ( 1 - sim ) ( 0 - nao ): ");
        scanf("%d",&flag->listar);
    }
}

int main(){
    system("cls");
    srand(time(NULL));
    int count=0;
    produto prod[100], key1[100], key2[100];
    int* list = malloc(sizeof(int));
    *list = 0;
    condicao flag;
    flag.prog = 1;
    while(flag.prog != 0){

        printf("\n\n  1 - cadastrar um produto\n\n  2 - listar os produtos\n\n  3 - remover um produto\n\n  0 - sair\n\n  Digite a opcao desejada:  ");
        scanf("%d", &flag.prog);
            system("cls");
        switch (flag.prog){
            case 1:
                printf("Cadastro de produto\n\n");
                    sleep(1);
                    system("cls");              
                cadastrar_produto(prod, &flag, list, key1, key2);                  //vai receber um ponteiro para uma variavel limite para saber quantos produtos foram cadastrados na hora de listar-los.
                break;
            case 2:
                listagem(prod, &flag, list, key1, key2);     //vai receber um ponteiro para uma variavel limite para saber quantos produtos foram cadastrados para listar-los.
                break;
            case 3:
                flag.prog=1; 
                while(flag.prog!=0){
                    printf("como deseja buscar a entidade? ( 1 - nome | 2 - id ): ");
                    scanf("%d",&flag.prog);
                    switch (flag.prog){

                        case 1:
                            
                            buscador(key1,list); //a keey1 e a key2 e pra ser somente um vetor o qual tem o indice da struct.
                            break;
                        case 2:
                            buscador(key2, list);
                            break;
                        default:
                            printf("Digite um numero valido! se 0 saira do loop.");
                            system("cls");                            
                    }
                }
                break;
            case 4:
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