#include<stdio.h>

void ler_nome(char *s){
    char c;
    //int i;
    c = getchar();
    while(c!='\n'){
        *s = c;
        c=getchar();
        s++;
     //   i++;
    }
}

int main(){
    char c, nome[20];
    int i=0;

    ler_nome(nome);

    while(nome[i] != '\0'){
        printf("%c",nome[i]);
        i++;
    }


    return 0;
}