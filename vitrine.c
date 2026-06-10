#include <stdio.h>


int main(){


    char s1[50],s2[50];
    scanf("%s",s1);
    scanf("%s",s2);
    int p1=0,p2=0;
    while(s1[p1]!='\0'){
        p1++;
    }
    while(s2[p2]!='\0'){
        p2++;
    }
    if(p1==p2){
        printf("ambas tem o mesmo tamanha\n");
    }
    else if(p1>p2){

        printf("P1 e maior\n");

    }
    else{
        printf("P2 e maoir\n");
    }

}