#include<stdio.h>

#define tam 20

typedef struct turma{
    char nome[30];
    int matricula;
} registro;

registro lerValores(){
    char opcao;
    registro aux;
    scanf("%s %s %d", opcao, aux.nome, aux.matricula);
}

int main(){
    registro aluno[tam];


    return 0;
}