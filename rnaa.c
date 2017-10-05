#include<stdio.h>
#include<stdlib.h>

void ler_nome(char *s){
    // Função ler o nome
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

void dobra(char* s){


}

int main(){
    char* base;

    ler_nome(base); // insere

    return 0;
}