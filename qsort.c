#include <stdio.h>
#include <stdlib.h>


int compara(const void* a,const void* b){

    int *A1 = (int*)a;
    int *B1 = (int*)b;

    if(*A1==*B1){
        return 0;
        
    }
    else if(*A1>*B1){
        return 1;
    }
    else{
        return -1;
    }

}

int main(){

    int vet[8];

    for(int i=0;i<8;i++){
        scanf("%d",&vet[i]);
    }
    qsort(vet,8,sizeof(int),compara);
    for(int i=0;i<8;i++){
        printf("%d\n",vet[i]);
    }


}