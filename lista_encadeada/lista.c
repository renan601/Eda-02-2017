#include<stdio.h>
#include<stdlib.h>

typedef struct lista{
  int info;
  struct lista* prox;
}Lista;

Lista* insereValor(Lista* l, int val){
  Lista* novo = (Lista*)malloc(sizeof(Lista));
  novo->info = val;
  novo->prox = l;
  return novo;
}


void imprimeLista(Lista* l){
  if(l!=NULL){
    imprimeLista(l->prox);
    printf("%d",l->info);
  }
}

int main(){
  Lista* l;
  l = NULL;
  int val;

  l = insereValor(l, 5);
  l = insereValor(l, 4);
  l = insereValor(l, 3);
  l = insereValor(l, 2);
  l = insereValor(l, 1);

  imprimeLista(l);
  return 0;
}
