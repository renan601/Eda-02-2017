#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node {
    char *nome;
    struct _Node *prox;
} Node;

typedef struct _Cab {
    Node *prim;
    Node *ult;
    int qtd;
} Cab;

void inserir(Cab *cab) {
    char nome[50];
    Node *no = (Node*) malloc(sizeof(Node));
    Node *aux;
    Node *aux_ant;
    int i;

    scanf("%s", nome);

    no->nome = (char*) malloc(sizeof(char) * strlen(nome));
    strcpy(no->nome, nome);
    no->prox = NULL;

    if(cab->prim == NULL) {
        cab->prim = no;
        cab->ult = no;
    } else {
        if(strcmp(no->nome, cab->prim->nome) < 0) { // Inseri no início pq Novo < Primeiro elemento
            no->prox = cab->prim;
            cab->prim = no;
        } else if(strcmp(no->nome, cab->ult->nome) > 0) { // Insere no final pq Novo > Ultimo elemento
            cab->ult->prox = no;
            cab->ult = no;
        } else {
            aux_ant = cab->prim;
            aux = cab->prim->prox;
            for(i=0; i<cab->qtd; i++) {
                if(strcmp(no->nome, aux->nome) < 0) {
                    no->prox = aux;
                    aux_ant->prox = no;
                    break;
                }

                aux_ant = aux_ant->prox;
                aux = aux->prox;
            }
        }
    }

    cab->qtd ++;
}

void remover(Cab *cab) {
    int i;
    Node *aux, *aux_ant;
    char del[50];

    scanf("%s", del);

    if(cab->prim == NULL){
        printf("\nLista vazia\n");
    } else {
        if(strcmp(del, cab->prim->nome) == 0) { // Inicio
            aux = cab->prim;
            cab->prim = aux->prox;
        } else if(strcmp(del, cab->ult->nome) == 0) { // Fim
            aux = cab->ult;
            aux_ant = cab->prim;
            for(i=0; i<cab->qtd-1; i++)
                aux_ant = aux_ant->prox;

            aux_ant->prox = NULL;
            cab->ult = aux_ant;
        } else {
            aux_ant = cab->prim;
            aux = cab->prim->prox;
            for(i=0; i<cab->qtd-1; i++) {
                if(strcmp(del, aux->nome) == 0) {
                    aux_ant->prox = aux->prox;
                    break;
                }
                aux_ant = aux_ant->prox;
                aux = aux->prox;
                printf("%d ", i);
                if(i == cab->qtd-1){
                    printf("\nNome não está na lista\n");
                    return;
                }
            }
        }

        free(aux);
        cab->qtd --;
    }
}

void imprimir(Cab *cab) {
    int i;
    Node *aux = cab->prim;

    if(cab->prim == NULL)
        printf("\nLista vazia\n");
    else
    for(i=0; i<cab->qtd; i++) {
        printf("%s -> ", aux->nome);
        aux = aux->prox;
    }

    printf("\n");
}

void desaloca(Cab *cab) {
    
}

int main() {
    int menu = 10;
    Cab *cab = (Cab*) malloc(sizeof(Cab));
    
    cab->prim = NULL;
    cab->qtd = 0;

    do {
        printf("\n1- Inserir");
        printf("\n2- Remover");
        printf("\n3- Imprimir");
        printf("\n0- Finalizar\n");
        scanf("%d", &menu);

        switch(menu) {
            case 1:
                inserir(cab);
                break;

            case 2:
                remover(cab);
                break;

            case 3:
                imprimir(cab);
                break;

            case 0:
                desaloca(cab);
                break;

            default:
                break;
        }
    } while(menu != 0);

    return 0;
}