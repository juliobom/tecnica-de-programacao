#include <stdio.h>


int main(){


    char s1[50],s2[50];
    scanf("%s",s1);
    scanf("%s",s2);
    int p1=0,p2=0;
    while(s1[p1]!='\0'){
        if(s1[p1]>='A'&&s1[p1]<='Z'){
            s1[p1]+= 32;
        }
        p1++;
    }
    while(s2[p2]!='\0'){
        if(s2[p2]>='A'&&s2[p2]<='Z'){
            s2[p2]+= 32;
        }
        p2++;
    }
    if(p1==p2){
        system("clear");
        printf("ambas tem o mesmo tamanha\n\n");
    }
    else if(p1>p2){
        system("clear");
        printf("P1 e maior\n\n");

    }
    else{
        system("clear");
        printf("P2 e maoir\n\n");
    }
    printf("%s\n",s1);

}