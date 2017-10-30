


#include<stdio.h>
#include<stdlib.h>

typedef struct arvore{
    int info;
    struct arvore* esq;
    struct arvore* dir;
}Arv;

int checa_Vazio(Arv* a){
    return (a == NULL);
}

Arv* inicia_No(Arv* a, int val){
    a = (Arv*)malloc(sizeof(Arv));
    
    a->info = val;
    a->esq = NULL;
    a->dir = NULL;

    return a;
}

Arv* insere_No(Arv* a, int val){
    Arv* novo;

    if(checa_Vazio(a)){
        a = inicia_No(a, val);
    }else{
        if(val < a->info){
            if(checa_Vazio(a->esq)){
                novo = inicia_No(novo,val)
                a->esq = novo;
            }else{
                insere_No(a->esq, val);
            }
        }else if(val >= a->info){
            if(checa_Vazio(a->dir)){
                novo = inicia_No(novo,val);
                a->dir = novo;
            }else{
                novo = insere_No(a->dir,val);
            }
        }
    }

    return a;
}

Arv* destruir(Arv* a){
    if(!checa_Vazio(a)){
        destruir(a->esq);
        destruir(a->dir);
        free(a);
    }
    return NULL;
}



int main(){
    Arv* a

    return 0;
}