#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct aluno{
  char* matricula;
  char* nome;
  int p1,p2,p3;
  float media;
  char result[3];
  struct aluno* prox;
}Registro;

typedef struct cab{
  Registro* primeiro;
  Registro* ultimo;
  int quant;
}Cab;

void ler_nome(char *s){
    char c;
    c = getchar();
    while(c!='\n'){
        *s = c;
        c=getchar();
        s++;
    }
    *s = '\0';
}

void insereAluno(Cab* l){
  char nome[50];
  char matricula[50];
  int p1=0,p2=0,p3=0;
  float media;
  Registro* novo = (Registro*)malloc(sizeof(Registro));
  Registro* aux;
  Registro* aux_ant;
  int i;


  //nome = (char*)malloc(sizeof(char)* 50);
  //matricula = (char*)malloc(sizeof(char)* 50);
  printf("Insira o nome do aluno: ");
  setbuf(stdin, NULL);
  ler_nome(nome);
  //scanf("%s", nome);
  printf("Insira a matricula do aluno: ");
  setbuf(stdin, NULL);
  ler_nome(matricula);
  //scanf("%s", matricula);

  printf("Insira a nota da P1: ");
  scanf("%d", &p1);
  printf("Insira a nota da P2: ");
  scanf("%d", &p2);
  printf("Insira a nota da P3: ");
  scanf("%d", &p3);

  novo->nome = (char*)malloc(sizeof(char) * strlen(nome));
  novo->matricula = (char*)malloc(sizeof(char) * strlen(matricula));
  strcpy(novo->nome, nome);
  strcpy(novo->matricula, matricula);
  novo->p1 = p1;
  novo->p2 = p2;
  novo->p3 = p3;
  novo->media = ((p1+p2+p3)/3);
  if(novo->media >= 50){
    strcpy(novo->result,"APR");
  }else{
    strcpy(novo->result,"REP");
  }

  if(l->primeiro == NULL){
    novo->prox = NULL;
    l->primeiro = novo;
    l->ultimo = novo;
  }else {
    if( novo->media < l->primeiro->media){
      novo->prox = l->primeiro;
      l->primeiro = novo;
    }else if( novo->media < l->ultimo->media){
      novo->prox = NULL;
      l->ultimo->prox = novo;
      l->ultimo = novo;
    }else{
      aux = l->primeiro->prox;
      aux_ant = l->primeiro;
      for(i=0; i < l->quant; i++){
        if(novo->media < aux->media){
          aux_ant->prox = novo;
          novo->prox = aux;
          break;
        }else{
          aux = aux->prox;
          aux_ant = aux_ant->prox;
        }
      }
    }
  
  }
  l->quant++;
}

void imprimirAlunos(Cab* l){
  Registro* aux;
  int i;

  printf("\nUnB - Universidade de Brasília / FGA-Gama");
  printf("\nEDA - Estruturas de Dados e Algoritmos");
  printf("\n1o. semestre de 2015");
  printf("\n\t >> DESEMPENHO DOS ALUNOS NO SEMESTRE (ORDENADO PELA MÉDIA) << \t");
  printf("\n MATRICULA \t ALUNOS \t\t P1\tP2\tP3\tMÉDIA\tRESULTADO");


  if(l->primeiro == NULL){
    printf("\n\nRegistro vazio");
  }else{
    aux = l->primeiro;
    for(i = 0; i<l->quant; i++){
      printf("\n %s \t %s \t\t %d\t%d\t%d\t%.1f\t%2s\n", aux->matricula, aux->nome, aux->p1, aux->p2, aux->p3, aux->media, aux->result);
      aux = aux->prox;
    }
    

  }
}

int menu(){
  int opcao;
  printf("\n\n1.Inserir aluno");
  printf("\n2.Imprimir alunos");
  printf("\n0.Sair");
  printf("\nOpcao: ");
  scanf("%d",&opcao);
  return opcao;
}

int main(){
  Cab* l;
  int opcao = 1;

  l = (Cab*)malloc(sizeof(Cab));
  l->primeiro = NULL;
  l->ultimo = NULL;
  l->quant = 0;
  while(opcao){
    opcao = menu();
    switch(opcao){
      case 1:
        insereAluno(l);
        break;
      case 2:
        imprimirAlunos(l);
        break;
      case 0:
        return 0;
        break;
      default:
        break;
    }
  }
  return 0;
}
