/*
    Exercicio de sala de aula
    Recriar a seguinte arvore:
                A
            B          C
        Null   D     E   F
            Null    Null    Null
    montar um programa com as
        opções a seguir:
        sair
        criar arvore(pre definida)
        destroi arvore
        consulta elemento
        imprimir arvore
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct arvore{
    char info;
    struct arvore* esq;
    struct arvore* dir;
}Arv;

int arv_Vazia(Arv* a){
    return (a == NULL);
}

Arv* cria_No(Arv* novo, char c, Arv* esq, Arv* dir){
    novo = (Arv*)malloc(sizeof(Arv));

    novo->info = c;
    novo->esq = esq;
    novo->dir = dir;

    return novo;
}

Arv* destroi_Arv(Arv* a){
    if(!arv_Vazia(a)){
        destroi_Arv(a->esq);
        destroi_Arv(a->dir);
        free(a);
    }
    return NULL;
}


int main(){
    Arv *a, *b, *c, *d, *e, *f;
    int opcao=1;

    while(opcao){
        switch(opcao){
            system("clear");
            printf("1.Criar Árvore\n");
            printf("2.Destruir Árvore\n");
            printf("3.Imprimir Árvore\n");
            printf("0.Sair");
            printf("Opcao: ");
            scanf("%d", &opcao);
            case 1:
                f = cria_No(f,'f',NULL,NULL);
                e = cria_No(e,'e',NULL,NULL);
                d = cria_No(d,'d',NULL,NULL);
                c = cria_No(c,'c',e,f);
                b = cria_No(b,'b',NULL,d);
                a = cria_No(a,'a',b,c);
                break;
            case 2:
                a = destroi_Arv(a);
                break;
            case 3:
                //imprimir arvore
                break;
            case 0:
                break;
        }
    }
    
    return 0;
}