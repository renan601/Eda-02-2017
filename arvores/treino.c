


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

void imprimir_Pre_Ordem(Arv* a){
    if(!checa_Vazio(a)){
        printf("%d ", a->info);
        imprimir_Pre_Ordem(a->esq);
        imprimir_Pre_Ordem(a->dir);
    }
}

void imprimir_Em_Ordem(Arv* a){
    if(!checa_Vazio(a)){
        imprimir_Em_Ordem(a->esq);
        printf("%d ", a->info);
        imprimir_Em_Ordem(a->dir);
    }
}

//Impressão polonesa
void imprimir_Pos_Ordem(Arv* a){
    if(!checa_Vazio(a)){
        imprimir_Pos_Ordem(a->esq);
        imprimir_Pos_Ordem(a->dir):
        printf("%d ", a->info);
    }
}

void imprimir_Em_Nivel(Arv* a){
    if(!checa_Vazio(a)){

    }
}

int main(){
    Arv* a
    int opcao = 1;
    int val = 0;

    while(opcao){
        printf("\t\t>> MENU <<\n\n");
        printf("1 - Inserir\n");
        printf("2 - Destrói árvore\n");
        printf("3 - Busca\n");
        printf("4 - Impressão pré-ordem\n");
        printf("5 - Impressão em ordem\n");
        printf("6 - Impressão pós-ordem (polonesa)\n");
        printf("7 - Impressão em largura\n");
        printf("0 - SAIR\n");
        printf("\t\t\t\tOPÇÃO: ");
        setbuf(stdin, NULL);
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                printf("Insira um valor: ");
                scanf("%d", &val);
                a = insere_No(a, val);
                break;
            case 2:
                a = destruir(a);
                break;
            case 3:
                break;
            case 4:
                imprimir_Pre_Ordem(a);
                break;
            case 5:
                imprimir_Em_Ordem(a);
                break;
            case 6:
                imprimir_Pos_Ordem(a);
                break;
            case 7:
                
                break;
        }
    }


    return 0;
}