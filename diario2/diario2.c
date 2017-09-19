#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct registro{
    char nome[20];
    int nota;
    struct registro* prox;
    struct registro* ant;
}Registro;

typedef struct cabeca{
    Registro* primeiro;
    Registro* ultimo;
    int maior;
    int menor;
    int quant;
}Cab;

Cab* inicializarLista(Cab* l){
  l = (Cab*)malloc(sizeof(Cab));
  l->primeiro = NULL;
  l->ultimo = NULL;
  l->maior = 0;
  l->menor = 0;
  l->quant = 0;
}


void inserePrimeiro(Cab* l, char tempNome[30], int tempNota){
  if(l->primeiro == NULL){
    Registro* novo = (Registro*)malloc(sizeof(Registro));
    strcpy(novo->nome, tempNome);
    novo->nota = tempNota;
    novo->prox = NULL;
    novo->ant = NULL;
    l->maior = l->menor = tempNota;
    l->primeiro = l->ultimo = novo;
    l->quant++;
  }
}

void insereInicio(Cab* l, char tempNome[30], int tempNota){
  if(l->primeiro == NULL){
      inserePrimeiro(l,tempNome,tempNota);
      printf("%s,%d; ", l->nome, l->nota);
  }
  Registro* novo = (Registro*)malloc(sizeof(Registro));
  strcpy(novo->nome, tempNome);
  novo->nota = tempNota;
  novo->prox = l->primeiro;
  novo->ant = NULL;
  l->primeiro->ant = novo;
  l->primeiro = novo;
  l->quant++;
  if(tempNota > l->maior)
    l->maior = tempNota;
  if(tempNota < l->menor)
    l->menor = tempNota;

}

void insereFinal(Cab* l, char tempNome[30], int tempNota){

    if(l->primeiro == NULL){
        inserePrimeiro(l,tempNome,tempNota);
        printf("%s,%d; ", l->nome, l->nota);
    }else{
        Registro* novo = (Registro*)malloc(sizeof(Registro));
        strcpy(novo->nome, tempNome);
        novo->matricula = tampNota;
        novo->prox = NULL;
        novo->ant = l->ultimo;
        l->ultimo->proximo = novo;
        l->ultimo = novo;
        l->quant++;
        if(tempNota > l->maior)
          l->maior = tempNota;
        if(tempNota < l->menor)
          l->menor = tempNota;
    }
}

void imprimeRegistroDireto(Cab* l){
    int i;
    Registro* p = l->primeiro;
    for(i = 0; i < l->quant; i++){
      printf("%s,%d; ", p->nome, p->nota);
      p = p->proximo;
    }
}
void imprimeRegistroInverso(Cab* l){

}

void excluirAluno(Cab* l, char tempNome[30], int tampNota){
  if(l->primeiro == NULL){
    printf("A lista está vazia");
  }else{
    Registro* p;
    int i;
    p = l->primeiro;
    for(i=0; i < l->quant; i++){
      if(p->nota == tempNota){
        break;
      }
      p = p->prox;
    }
    if(p == l->primeiro){
      l->primeiro = p->prox;
      free(p);
      l->quant--;
    }else if(p == l->ultimo){
      l->utlimo = p->ant;
      free(p);
      l->quant--;
    }else{
      // se estiver no meio da lista
      p->ant->prox = p->prox;
      p->prox->ant = p->ant;
      free(p);
      l->quant--;
    }
  }
}


void ler_nome(char *s){
    char c;
    c = getchar();
    while(c!='\n'){
        *s = c;
        c=getchar();
        s++;
    }
}

char* printNome(char*s){
  while(nome[i] != '\0'){
      printf("%c",nome[i]);
      i++;
  }
}


int main(){
    Cab* l;
    char opcao[3];
    char tempNome[30];
    int tempMatricula;
    int opcao;

    menu();
    scanf("%d", &opcao);


    }

    return 0;
}
