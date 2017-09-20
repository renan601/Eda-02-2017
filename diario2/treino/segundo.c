#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct registro{
    char nome[30];
    int matricula;
    struct registro* prox;
    struct registro* ant;
}Registro;

typedef struct cabeca{
    Registro* primeiro;
    Registro* ultimo;
    int quant;
}Cab;

void insereInicio(Cab* l, char tempNome[30], int tempMatricula){
    Registro* novo = (Registro*)malloc(sizeof(Registro));
    strcpy(novo->nome, tempNome);
    novo->matricula = tempMatricula;
    novo->prox = l->primeiro;
    l->primeiro = l->ultimo = novo;
    l->quant++;
}

void insereFinal(Cab* l, char tempNome[30], int tempMatricula){

    if(l->primeiro == NULL){
        insereInicio(l,tempNome,tempMatricula);
    }else{

        Registro* novo = (Registro*)malloc(sizeof(Registro));

        strcpy(novo->nome, tempNome);
        novo->matricula = tempMatricula;
        novo->prox = NULL;

        l->ultimo->prox = novo;
        l->ultimo = novo;
        l->quant ++;
    }
}

void imprimeRegistro(Cab* l){
    int i;
    Registro* aux = l->primeiro;
    for(i=0;i<l->quant;i++){
      printf("%s,%d; ", aux->nome, aux->matricula);
      aux = aux->prox;
    }
}
void excluirAluno(Cab* l, char tempNome[30], int tempMatricula){
    if(l->primeiro == NULL){
      printf("Lista vazia\n");
    }else{
      Registro* p,q;
      int i, achei=0;
      p = l->primeiro->prox;
      q = l->primeiro;
      for(i=0; i < l->quant; i++){
        if(strcmp(p->nome,tempNome)){
          achei = 1;
          break;
        }
        p = p->prox;
      }
      if(achei){
        l->quant--;
        q->prox = p->prox;
        free(p);
      }else{
        printf("Entrada inválida\n");
      }
    }
}



int main(){
    Cab* l;
    char opcao[3];
    char tempNome[30];
    int tempMatricula;

    l = (Cab*)malloc(sizeof(Cab));
    l->primeiro = NULL;
    l->ultimo = NULL;
    l->quant = 0;

    while(strcmp(opcao,"sai")){
        printf("Insira OPCAO NOME MATRICULA\n");
        scanf("%s %s %d", opcao, tempNome, &tempMatricula);
        if(strcmp(opcao,"IU") == 0){

            insereFinal(l,tempNome,tempMatricula);
            imprimeRegistro(l);


        }
        if(strcmp(opcao,"EX")){
           // l = excluirAluno(l,tempNome,tempMatricula);
        }


    }

    return 0;
}
