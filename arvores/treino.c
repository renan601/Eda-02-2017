


#include<stdio.h>
#include<stdlib.h>

typedef struct arvore{
    int val;
    struct arvore* esq;
    struct arvore* mid;
    struct arvore* dir;
}Arv;

int checa_Vazio(Arv* a){
    return (a == NULL);
}

Arv* cria_Vazio(Arv* a){
    a = (Arv*)malloc(sizeof(Arv));
    
    a->val = 0;
    a->esq = NULL;
    a->mid = NULL;
    a->dir = NULL;

    return a;
}

Arv* cria_No(Arv* a, int val){
    Arv* novo;

    if(!checa_Vazio(a)){
    }

    return a;
}

int main(){
    Arv* a

    return 0;
}