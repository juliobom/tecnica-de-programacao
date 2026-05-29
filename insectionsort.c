#include <stdio.h>

int main(){

    int vet[8];

    for(int i=0;i<8;i++){

        scanf("%d",&vet[i]);
        int j,aux = vet[i];
        for(j=i-1;j>=0&&vet[j]>aux;j--){

            vet[j+1]=vet[j];

        }
        vet[j+1]=aux;

        

    }
    for(int i=0;i<8;i++){
        printf("%d ",vet[i]);
    }

}