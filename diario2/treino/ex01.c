#include<stdio.h>
#include<string.h>

typedef struct registro{
  char nome[30];
  int matricula;
}registro;

void iniciaRegistro(registro aluno[20]){
  int i;
  for(i=0;i < 20; i++){
    aluno[i].nome[0] = '\0';
    aluno[i].matricula = 0;
  }
}

int tamanhoRegistro(registro aluno[20]){
  int i=0,cont=0;
  while(aluno[i].nome[0] != '\0'){
    if(aluno[i].nome[0] != '\0'){
      cont++;
    }
    i++;
  }
  return cont;
}

void printaRegistro(registro aluno[20]){
  int i, tam;
  tam = tamanhoRegistro(aluno);
  if(tam){
    for(i=0; i < tam; i++){
      printf("%s,%d; ", aluno[i].nome, aluno[i].matricula);
    }
  }else{
    printf("BASE VAZIA\n");
  }
}

int buscaAluno(registro temp, registro aluno[20]){
  int i, tam;
  tam = tamanhoRegistro(aluno);
  for(i=0; i < tam; i++){
    if(strcmp(temp.nome,aluno[i].nome)){
      return i;
    }else{
      return 0;
    }
  }
}

void incluiAluno(registro temp, registro aluno[20]){
  int tam;
  tam = tamanhoRegistro(aluno);
  strcpy(aluno[tam+1].nome,temp.nome);
  aluno[tam+1].matricula = temp.matricula;
  printaRegistro(aluno);
}

void excluiAluno(registro temp, registro aluno[20]){
  int acheiPosicao;
  acheiPosicao = buscaAluno(temp, aluno);
  if(acheiPosicao){
    aluno[acheiPosicao].nome== "\0";
    aluno[acheiPosicao].matricula = 0;
    printaRegistro(aluno);
  }else{
    printf("ENTRADA INVALIDA\n");
  }
}

void recebeDados(registro aluno[20]){
  registro temp;
  char opcao[3];
  int opcaoAux;
  scanf("%s %s %d", opcao, temp.nome, temp.matricula);
  if(opcao == "IU"){
    opcaoAux = 1;
  }
  if(opcao == "EX"){
    opcaoAux = 2;
  }
  switch(opcaoAux){
    case 1:
      incluiAluno(temp, aluno);
      break;
    case 2:
      excluiAluno(temp, aluno);
      break;
  }
}

int main(){
  registro aluno[20];
  iniciaRegistro(aluno);
  recebeDados(aluno);



  return 0;
}
