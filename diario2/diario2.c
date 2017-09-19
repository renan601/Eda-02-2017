/*Participantes
Arthur Evangelista - 140016686
Rafael Makaha - 160142369
Renan Schadt - 160143403
*/

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
  return l;
}


void inserePrimeiro(Cab* l, char tempNome[30], int tempNota){

  if(l->primeiro == NULL){
    Registro* novo = (Registro*)malloc(sizeof(Registro));
    strcpy(novo->nome, tempNome);
    novo->nota = tempNota;
    novo->prox = NULL;
    novo->ant = NULL;
    l->maior = l->menor = tempNota;
    l->primeiro =  novo;
    l->ultimo = novo;
    l->quant++;
  }
}

void insereInicio(Cab* l, char tempNome[30], int tempNota){

  if(l->primeiro == NULL){
      inserePrimeiro(l,tempNome,tempNota);
  }else{
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
}

void insereFinal(Cab* l, char tempNome[30], int tempNota){

    if(l->primeiro == NULL){
        inserePrimeiro(l,tempNome,tempNota);
    }else{
        Registro* novo = (Registro*)malloc(sizeof(Registro));
        strcpy(novo->nome, tempNome);
        novo->nota = tempNota;
        novo->prox = NULL;
        novo->ant = l->ultimo;
        l->ultimo->prox = novo;
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
    printf("\tRELATÓRIO\n");
    printf("---------------------------------------------------\n");
    printf("NOME\t\t\t\tNOTA\n");
    printf("---------------------------------------------------\n");
    /*Estrutura de repetição para printar valores*/
    for(i = 0; i < l->quant; i++){
      printf("%s\t\t\t\t%d\n", p->nome, p->nota);
      p = p->prox;
    }
    printf("---------------------------------------------------\n");
    printf("MAIOR NOTA: %d\n", l->maior);
    printf("MENOR NOTA: %d\n", l->menor);
    printf("QTDE DE ALUNOS: %d\n", l->quant);


}
void imprimeRegistroInverso(Cab* l){
  int i;
  Registro* p = l->ultimo;
  printf("\tRELATÓRIO:\n");
  printf("---------------------------------------------------\n");
  printf("NOME\t\t\t\tNOTA\n");
  printf("---------------------------------------------------\n");
  /*Estrutura de repetição para printar valores*/
  for(i = l->quant; i >0; i--){
    printf("%s\t\t\t\t%d\n", p->nome, p->nota);
    p = p->ant;
  }
  printf("---------------------------------------------------\n");
  printf("MAIOR NOTA: %d\n", l->maior);
  printf("MENOR NOTA: %d\n", l->menor);
  printf("QTDE DE ALUNOS: %d\n", l->quant);


}

void excluirAluno(Cab* l, char tempNome[30], int tempNota){
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
      l->ultimo = p->ant;
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

void menu(){
  printf("\t\t>>MENU<<\n");
  printf("0 - SAIR\n");
  printf("1 - Inicializar lista\n");
  printf("2 - Inserir no início\n");
  printf("3 - Inserir no final\n");
  printf("4 - Remover um nó (Pesquisa pela nota)\n"); /*Supor que não há dois alunos com a mesma nota*/
  printf("5 - Imprimir em ordem normal, com maior nota, menor nota e quantidade de alunos\n");
  printf("6 - Imprimir em ordem inversa, com maior nota, menor nota e quantidade de alunos\n");
  printf("\n\t\tOPÇÃO: ");
}


int main(){
    Cab* l;
    char tempNome[30];
    int tempNota;
    int opcao = 1;

    while(opcao){
      menu();
      setbuf(stdin, NULL);
      scanf("%d", &opcao);
      switch(opcao){
        case 0:
          break;
        case 1:
          l =inicializarLista(l);
          break;
        case 2:
          setbuf(stdin, NULL);
          printf("Insira o nome: ");
          ler_nome(tempNome);
          printf("Insira a nota: ");
          scanf("%d", &tempNota);
          insereInicio(l, tempNome, tempNota);
          break;
        case 3:
          setbuf(stdin, NULL);
          printf("Insira o nome: ");
          ler_nome(tempNome);
          printf("Insira a nota: ");
          scanf("%d", &tempNota);
          insereFinal(l, tempNome, tempNota);
          break;
        case 4:
          setbuf(stdin, NULL);
          printf("Insira o nome: ");
          ler_nome(tempNome);
          printf("Insira a nota: ");
          scanf("%d", &tempNota);
          excluirAluno(l, tempNome, tempNota);
          break;
        case 5:
          imprimeRegistroDireto(l);
          getchar();
          break;
        case 6:
          imprimeRegistroInverso(l);
          getchar();
          break;
      }
    }




    return 0;
}
