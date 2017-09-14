#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct registro{
    char nome[30];
    int matricula;
    struct registro* prox;
}Registro;

Registro* inicializaRegistro(){
    return NULL;
}

void insereInicio(Registro* l, char tempNome[30], int tempMatricula){
    Registro* p;
    Registro* novo = (Registro*)malloc(sizeof(Registro));
    
    strcpy(novo->nome, tempNome);
    novo->matricula = tempMatricula;
    novo->prox = NULL;

    if(l == NULL){
        l = novo;
        printf("%s,%d; ", l->nome, l->matricula);
    }else{
        for(p = l; p != NULL; p = p->prox);
        printf("entreeeei %d", p->matricula);
        p->prox = novo;
    }
}

void imprimeRegistro(Registro* l){
    Registro* p;
    if(l==NULL){
        printf("BASE VAZIA\n");
    }else{
        for(p = l; p != NULL; p = p->prox){
            printf("%s,%d; ", p->nome, p->matricula);
        }
        printf("\n");
    }
}



int main(){
    Registro* l;
    char opcao[3];
    char tempNome[30];
    int tempMatricula;

    l = inicializaRegistro();

    while(strcmp(opcao,"sai")){
        printf("Insira OPCAO NOME MATRICULA\n");
        scanf("%s %s %d", opcao, tempNome, &tempMatricula);
        if(strcmp(opcao,"IU") == 0){
            

            insereInicio(l,tempNome,tempMatricula);
            imprimeRegistro(l);


        }
        if(strcmp(opcao,"EX")){
           // l = excluirAluno(l,tempNome,tempMatricula);
        }
        
        
    }

    return 0;
}