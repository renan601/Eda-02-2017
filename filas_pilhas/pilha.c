#include <stdio.h>
#include <stdlib.h>

#define M 6

typedef struct cab{
    int ini;
    int topo;
}Cab;

int pilhaVazia(Cab* l, int* v){
    if(l->ini == l->topo)
        return 1;
    return 0;
}

int pilhaCheia(Cab* l, int* v){
    if(l->topo == M)
        return 1;
    return 0;
}

void imprimirPilha(Cab* l, int* v){
    int i;
    if(pilhaVazia(l,v)){
        printf("\nPilha Vazia");
        return ;
    }
    printf("\n");
    for(i = l->ini; i != l->topo; i++){
        printf(" %d ->", v[i]);
    }
}

void empilhar(Cab* l, int* v){
    int x;
    if(pilhaCheia(l,v)){
        printf("\nPilha Cheia\n");
        getchar();
        getchar();
    }else{
        scanf("%d", &x);
        v[l->topo++] = x;
    }
}

void desempilhar(Cab* l, int* v){
    int y;
    if(pilhaVazia(l,v)){
        printf("\nPilha Vazia\n");
        getchar();
        getchar();
    }else{
        y = v[--l->topo];
    }

}


int main(){
    int v[M];
    int menu=1;
    Cab* l = (Cab*)malloc(sizeof(Cab));

    l->ini = 0;
    l->topo = 0;

    while(menu){
        system("clear");
        imprimirPilha(l,v);
        printf("\n\n1.Empilha");
        printf("\n2.Desempilha");
        printf("\n0.Sair");
        printf("\nOpcao: ");
        scanf("%d", &menu);
        switch(menu){
            case 1:
                empilhar(l,v);
                break;
            case 2:
                desempilhar(l,v);
                break;
            default:
                break;
        }
    }
    return 0;
}