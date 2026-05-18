#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>




typedef struct{
        char nome[50];
        int id;
        float preco;

}produto;



typedef struct{
    int inserir,listar,remover,prog,opcao;
}condicao;


void ordeneId( int *tam, produto *prod, int *indid){
    
    int i,j;
    for(i=1;i<*tam;i++){
        
        int aux = indid[i];

        for(j=i-1;j>=0&&prod[indid[j]].id>prod[aux].id;j--){

            indid[j+1]=indid[j];

        }
        indid[j+1] = aux;  //gravei o indice pelo ID
    }
}


void ordeneNome(int *tam,produto *prod, int *indnome){     
    
    
    int i,j,aux;
    for(i=1;i<*tam;i++){
        
        aux = indnome[i];
        for(j=i-1;j>=0&&strcmp(prod[indnome[j]].nome,prod[aux].nome)>0;j--){

            indnome[j+1]=indnome[j];

        }
        
        indnome[j+1] = aux;  //indice pelo nome gravado.
        /*nome[j+1].nome = aux;*/
    }
}

int buscadornm(produto *prod, int *indnome,char Buscanome[], int fim, int ini){

}


int buscadorid(produto *prod,int *indid, int BuscaId, int fim, int ini){
    
    if(ini>fim){
        return -1;
    }

    int meio = (ini+fim)/2;
    if( prod[indid[meio]].id == BuscaId ){
        return indid[meio];
    }

    if( prod[indid[meio]].id> BuscaId ){// o meio esta acima do id ent vamos descartar todo valor do meio ao fim.
        return buscadorid(prod, indid, BuscaId, meio-1,ini);
    }
    else{
        return buscadorid(prod, indid, BuscaId, fim, meio+1);
    }
    return -1;
}

void cadastrar_produto( produto *prod, condicao *flag, int *list, int *indnome, int *indid){      
    flag->inserir = 1;
    while(flag->inserir != 0){

        int qtd;

        printf("Quantos produtos deseja cadastrar?\n");
        scanf("%d", &qtd);
            system("cls");

        for(int i=0;i<qtd;i++){

            printf("Digite o nome do produto: ");
            scanf("%s", prod[*list].nome);
                
            printf("Digite o preço do produto: ");
            scanf("%f", &prod[*list].preco);


            prod[*list].id=rand()%1000;
            indnome[*list] = *list;
            indid[*list] = *list;

            printf("Produto cadastrado com sucesso!\n");
                sleep(1);
                system("cls");
            
            *list += 1;
                ordeneId( list, prod, indid);
                ordeneNome( list, prod, indnome);
                
            
        }
        printf("Deseja cadastrar mais produto(s)? (1 - Sim, 0 - Nao): ");
        scanf("%d", &flag->inserir);
    }
}

void listagem(produto *prod, condicao *flag, int *list, int *indnome, int *indid){

    flag->listar=1;
    while(flag->listar!=0){
        printf("Como deseja listar os produtos?\n1 - Padrão:\n2 - Nome:\n3 - lista Id:\n\nDigite a opcao desejada:  ");
        scanf("%d",&flag->listar);
        system("cls");
        switch (flag->listar){
            case 1:
                for(int i=0;i<*list;i++){

                    printf("[%d] [id: %4.d] [ produto: %s |  preco: %.2f ]", i+1, prod[i].id, prod[i].nome, prod[i].preco);
                    
                    printf("\n");
                }
                break;

            case 2:
                for(int i=0;i<*list;i++){

                    printf("[%d] [id: %4.d] [ produto: %s | preco: %.2f ]", i+1, prod[indnome[i]].id, prod[indnome[i]].nome, prod[indnome[i]].preco);
                    printf(" - %d",indnome[i]);
                    printf("\n");
                }
                break;

            case 3:
                for(int i=0;i<*list;i++){

                    printf("[%d] [id: %4.d] [ produto: %s | preco: %.2f ]", i+1, prod[indid[i]].id, prod[indid[i]].nome, prod[indid[i]].preco);
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

    produto prod[100];
    int indnome[100];
    int indid[100];
    condicao flag;
    char BuscaNome[50];
    int BuscaId;
    int* list = malloc(sizeof(int));
    *list = 0;

    

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
                cadastrar_produto(prod, &flag, list, indnome, indid);                  //vai receber um ponteiro para uma variavel limite para saber quantos produtos foram cadastrados na hora de listar-los.
                break;

            case 2:
                listagem(prod, &flag, list, indnome, indid);     //vai receber um ponteiro para uma variavel limite para saber quantos produtos foram cadastrados para listar-los.
                break;

            case 3:
                if(*list==0){
                    printf("voce ainda nao cadastrou um produto. volte assim que tiver ao menos um produto cadastrado.");
                    sleep(2);
                    system("cls");
                    break;
                }
                flag.prog=1; 
                while(flag.prog!=0){
                    printf("como deseja buscar a entidade? (1 - nome)  (2 - id)  (0 - sair): ");

                    int ini=0,fim=*list-1;
                    scanf("%d",&flag.prog);
                    switch (flag.prog){
                        case 0:
                            break;

                        case 1:
                        printf("Digite o nome desejado: ");
                            scanf("%s",BuscaNome);
                            
                            buscadornm(prod, indnome, BuscaNome, fim, ini); //a keey1 e a key2 e pra ser somente um vetor o qual tem o indice da struct.
                            break;

                        case 2:
                        printf("Digite o ID desejado: ");
                            scanf("%d",&BuscaId);
                            int ind = buscadorid(prod, indid,BuscaId, fim, ini);
                            if(ind == -1){
                                printf("ID Nao encontrado! tente novamente!");
                                sleep(2);
                                system("cls");
                                break;
                            }
                            printf("[id: %d] | Produto: %s | Preco: %.2f R$\n", prod[ind].id, prod[ind].nome, prod[ind].preco);
                            break;

                        default:
                            printf("Digite um numero valido! se 0 saira do loop.");
                            sleep(1);
                            system("cls");
                            break;                           
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
