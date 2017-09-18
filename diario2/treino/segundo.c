#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct registro{
    char nome[30];
    int matricula;
    struct registro* prox;
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
    novo->prox = l;
    l->primeiro = l->ultimo = novo;
    l->quant++;
}

void insereFinal(Cab* l, char tempNome[30], int tempMatricula){

    if(l->primeiro == NULL){
        insereInicio(l,tempNome,tempMatricula);
        printf("%s,%d; ", l->nome, l->matricula);
    }else{

        Registro* novo = (Registro*)malloc(sizeof(Registro));

        strcpy(novo->nome, tempNome);
        novo->matricula = tempMatricula;
        novo->prox = NULL;

        l->ultimo->proximo = novo;
        l->ultimo = novo;
        l->quant ++;
    }
}

void imprimeRegistro(Cab* l){
    int i;
    Registro* aux = l->primeiro;
    for(i=0;i<l->quant;i++){
      printf("%s,%d; ", aux->nome, aux->matricula);
      aux = aux->proximo;
    }
}
void excluirAluno(Cab* l, char tempNome[30], int tempMatricula){
    
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
