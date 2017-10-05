#include <stdio.h>
#include <stdlib.h>

#define M 6

typedef struct cab{
    int ini;
    int fim;
}Cab;

int filaVazia(Cab* l, int* v){
    if(l->ini == l->fim)
        return 1;
    return 0;
}

int filaCheia(Cab* l, int* v){
    if(l->fim+1 == l->ini || (l->fim+1 == M && l->ini == 0))
        return 1;
    return 0;
}

void imprimirFila(Cab* l, int* v){
    int i;
    if(filaVazia(l,v)){
        printf("\nFila Vazia");
        return ;
    }
    printf("\n");
    for(i = l->ini; i != l->fim; i = (i+1)%M){
        printf(" %d ->", v[i]);
    }
}

void inserir(Cab* l, int* v){
    int x;
    if(filaCheia(l,v)){
        printf("\nFila Cheia\n");
        getchar();
        getchar();
    }else{
        scanf("%d", &x);
        v[l->fim] = x;
        l->fim = (l->fim + 1) % M;
    }
}

void remover(Cab* l, int* v){
    int y;
    if(filaVazia(l,v)){
        printf("\nFila Vazia\n");
        getchar();
        getchar();
    }else{
        if(l->ini + 1 == M)
            y = v[l->ini = 0];
        else
            y = v[l->ini++];
    }

}

/*
int main(){
    int v[M];
    int menu=1;
    Cab* l = (Cab*)malloc(sizeof(Cab));

    l->ini = 0;
    l->fim = 0;

    while(menu){
        system("clear");
        imprimirFila(l,v);
        printf("\n\n1.Inserir");
        printf("\n2.Remover");
        printf("\n0.Sair");
        printf("\nOpcao: ");
        scanf("%d", &menu);
        switch(menu){
            case 1:
                inserir(l,v);
                break;
            case 2:
                remover(l,v);
                break;
            default:
                break;
        }
    }
    return 0;
}
*/
