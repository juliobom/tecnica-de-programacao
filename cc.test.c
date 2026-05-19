#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>


typedef struct{
        char nome[50];
        int id,del;
        float preco;


}produto;

typedef struct{
    int inserir,listar,remover,prog,opcao;
}condicao;

void limpeza(){

     #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

}

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
    if(ini>fim){
        return -1;
    }
    int meio = (ini+fim)/2;
    if(strcmp( prod[indnome[meio]].nome, Buscanome) == 0){
        return indnome[meio];
    }

    if(strcmp(prod[indnome[meio]].nome, Buscanome) > 0){
        return buscadornm( prod , indnome, Buscanome, meio - 1, ini);
    }
    else{
        return buscadornm( prod, indnome, Buscanome, fim, meio+1);
    }
    return -1;
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

            prod[*list].del = 1;
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

void proddell(produto *prod, int *indnome, int *indid, char BuscaNome[], int BuscaId, int fim, int ini){
    
    int flag = 3;

    while(flag!=0){

        int ind;
        limpeza();
        printf("deseja remover produto por: ( 0-Sair ) ( 1-Nome ) ( 2- ID): ");
        scanf("%d",&flag);


        switch (flag){
            case 1:{

                printf("digite o nome do produto: ");
                scanf("%s", BuscaNome);
                ind = buscadornm(prod, indnome, BuscaNome, fim, ini);
                if(ind == -1){
                    limpeza();
                    printf("Nome nao encontrado!");
                    break;
                }
                prod[ind].del = 0;
                limpeza();
                printf("Produto Removido!");
                sleep(1);
                break;
            }
            case 2:{

                printf("digite o ID do produto: ");
                scanf("%d",&BuscaId);
                int inde = buscadorid(prod, indid, BuscaId, fim, ini);
                if(inde== -1){
                    limpeza();
                    printf("ID nao encontrado!");
                    break;
                }
                prod[inde].del = 0;
                limpeza();
                printf("Produto Removido!");
                sleep(1);
                break;
            }
        }
    }
}

void listagem(produto *prod, condicao *flag, int *list, int *indnome, int *indid){

    flag->listar=1;
    while(flag->listar!=0){

        printf("Como deseja listar os produtos?\n1 - Padrão:\n2 - Nome:\n3 - lista Id:\n\nDigite a opcao desejada:  ");
        scanf("%d",&flag->listar);
        system("cls");

        switch (flag->listar){

            case 1:{
                for(int i=0;i<*list;i++){
                    if(prod[i].del!=0){
                        
                        printf("[%d] [id: %4.d] [ produto: %s |  preco: %.2f ]", i+1, prod[i].id, prod[i].nome, prod[i].preco);
                        printf("\n");
                    }
                    
                }
                break;
            }
            case 2:{
                for(int i=0;i<*list;i++){

                    if(prod[indnome[i]].del!=0){
                        
                        printf("[%d] [id: %4.d] [ produto: %s | preco: %.2f ]", i+1, prod[indnome[i]].id, prod[indnome[i]].nome, prod[indnome[i]].preco);
                        printf("\n");

                    }
                }
                break;
            }
            case 3:{
                for(int i=0;i<*list;i++){

                    if(prod[indid[i]].del!=0){
                        printf("[%d] [id: %4.d] [ produto: %s | preco: %.2f ]", i+1, prod[indid[i]].id, prod[indid[i]].nome, prod[indid[i]].preco);
                        printf("\n");
                    }
                }
                break;
            }
        }
        
        printf("\ndeseja listar de outra forma? ( 1 - sim ) ( 0 - nao ): ");
        scanf("%d",&flag->listar);
        limpeza();
    }
}

int main(){
    
    limpeza();
    srand(time(NULL));
    
    produto prod[100];
        int indnome[100],indid[100];   
    condicao flag;
        char BuscaNome[50];
        int BuscaId, list = 0; 
    
    flag.prog = 1;

    while(flag.prog != 0){

        printf("\n\n  1 - cadastrar um produto\n\n  2 - listar os produtos\n\n  3 - Buscar um produto\n\n  4 - Remover um produto \n\n  0 - sair\n\n  Digite a opcao desejada:  ");
        scanf("%d", &flag.prog);
            limpeza();

        int ini = 0 , fim = list-1;
        switch (flag.prog){

            case 1:{

                printf("Cadastro de produto\n\n");
                    sleep(1);
                    limpeza();              
                cadastrar_produto(prod, &flag, &list, indnome, indid);                  
                break;
            }
            case 2:{

                listagem(prod, &flag, &list, indnome, indid);     
                break;
            }
            case 3:{
                
                flag.listar=1; 
                while(flag.listar!=0){
                    printf("como deseja buscar a entidade? (1 - nome)  (2 - id)  (0 - sair): ");

                    
                    scanf("%d",&flag.listar);
                    switch (flag.listar){
                        
                        case 0:{
                            break;
                        }
                        case 1:{
                            printf("Digite o nome desejado: ");
                            scanf("%s",BuscaNome);
                            int inde = buscadornm(prod, indnome, BuscaNome, fim, ini);
                            if(inde == -1){
                                printf("Nome Nao encontrado! tente novamente!");
                                limpeza();
                                break;
                            }
                            printf("\n[id: %d] | Produto: %s | Preco: %.2f R$\n\n", prod[inde].id, prod[inde].nome, prod[inde].preco); 
                            break;
                        }
                        case 2:{
                            printf("Digite o ID desejado: ");
                            scanf("%d",&BuscaId);
                            int ind = buscadorid(prod, indid,BuscaId, fim, ini);
                            if(ind == -1){
                                printf("ID Nao encontrado! tente novamente!");
                                sleep(2);
                                limpeza();
                                break;
                            }
                            printf("\n[id: %d] | Produto: %s | Preco: %.2f R$\n\n", prod[ind].id, prod[ind].nome, prod[ind].preco);
                            break;
                        }                        
                        default:{
                            printf("Digite um numero valido! se 3 saira do loop.");
                            sleep(1);
                            limpeza();
                            break;  
                        }                         
                    }
                }
                break;
            }
            case 4:{

                proddell(prod, indnome, indid, BuscaNome, BuscaId, fim ,ini);
                break;
            }
            case 0:{
                int count =0;
                while (count<1)
                {
                    printf("Saindo do programa.");
                        sleep(1);
                        limpeza();
                    printf("Saindo do programa..");
                        sleep(1);
                        limpeza();
                    printf("Saindo do programa...");
                        sleep(1);
                        limpeza();
                    count++;
                }
                break;
            }
        }   

    }
    return 0;
}