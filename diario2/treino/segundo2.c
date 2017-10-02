#include<stdio.h>

typedef struct registro{
  char nome[30];
  int matricula;
  struct registro* prox;
  struct registro* ant;
}Registro;

typedef struct cab{
  Registro* primeiro;
  Registro* ultimo;
  int quant;
}Cab;

Cab* iniciaCab(Cab* l){
  l = (Cab*)malloc(sizeof(Cab));
  l->primeiro = NULL;
  l->ultimo = NULL;
  l->quant = 0;
  return l;
}

void inserePrimeiro(Cab* l, char tempNome[30], int tempMatricula){
  Registro* novo = (Registro*)malloc(sizeof(Registro));
  novo->prox = NULL;
  novo->ant = NULL;
  strcpy(novo->nome,tempNome);
  novo->matricula = tempMatricula;

  l->quant++;
  l->primeiro = novo;
  l->ultimo = novo;
}


// Inserção ordenada de aluno
void insereAluno(Cab* l, char tempNome[30], int tempMatricula){
  int i;
  Registro* p;
  for(i = 0; i < l->quant; i++){
    
  }
}



int main(){
  char tempNome[30];
  int tempMatricula;
  Cab* l;
  l = iniciaCab(l);

  if(l->primeiro == NULL){
    inserePrimeiro(l,tempNome,tempMatricula);
  }else{
    insereAluno(l, tempNome, tempMatricula);
  }

  return 0;
}


void inserir(Cab* l){
  char nome[50];
  Registro* novo= (Registro*)malloc(sizeof(Registro));

  scanf("%s", nome);

  novo->nome = (char*)malloc(sizeof(char) * strlen(nome));
  strcpy(novo->nome, nome);
  novo->prox = NULL;

  if(l->primeiro == NULL){
    l->primeiro = novo;
    l->quant++;
  }else{
    
  }
}