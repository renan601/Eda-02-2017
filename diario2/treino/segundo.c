#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct registro{
    char nome[30];
    int matricula;
    struct registro* prox;
}Registro;

void insereInicio(Registro* l, char tempNome[30], int tempMatricula){
    Registro* novo = (Registro*)malloc(sizeof(Registro));
    strcpy(novo->nome, tempNome);
    novo->matricula = tempMatricula;
    novo->prox = l;
    l=novo;
}

void insereFinal(Registro* l, char tempNome[30], int tempMatricula){
   
    if(l == NULL){
        insereInicio(l,tempNome,tempMatricula);
        printf("%s,%d; ", l->nome, l->matricula);
    }else{
        
        Registro* p;
        Registro* novo = (Registro*)malloc(sizeof(Registro));
        
        strcpy(novo->nome, tempNome);
        novo->matricula = tempMatricula;
        novo->prox = NULL;
    
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
void excluirAluno(Registro* l, char tempNome[30], int tempMatricula){

}



int main(){
    Registro* l;
    char opcao[3];
    char tempNome[30];
    int tempMatricula;

    l = NULL;

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