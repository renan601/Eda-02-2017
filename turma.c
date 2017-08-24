/*  1) Realizar inserção de informações
(matricula e nome) em vetor de,
no máximo, 40 posições*/

/* Para casa:
	1) Substitua a declaração
		registro aluno[tam_vet]
	por
		registro *aluno[tam_vet]
	e promova as alterações necessárias
	para o código continuar funcional

	2) Realizar a inserção (ordenada
	de matricula) de informações em
	um vetor de, no maximo, 40 posições.

	3) Alterar o programa para que o mesmo
	possa ter a opção de remoção de um registro
	do vetor */

#include<stdio.h>
#include<stdlib.h>

#define tam_vet 40

typedef struct {
	char nome[30];
	int matricula;
}registro;

int main(){

	menu();

	return 0;
}

void menu(){
  int menu, l_sup=0;
	registro aluno[tam_vet]; //caso colocar * antes de aluno, o que rola?
	while(menu){
		if(menu==1)
			incluirAluno(aluno, &l_sup);
		else
			imprimirAluno(aluno, &l_sup);
	}
}

void incluirAluno(registro *v, int *l_sup){

	printf("Digite matricula: ");
	scanf("%d\n", &v[*l_sup].matricula);
	printf("Digite o nome do aluno: ");
	scanf("%s\n", v[l_sup].nome);
	*lsupp++;

}

void imprimirAluno(registro *v, *l_sup){
	int i=0;

	while(i<*l_sup){
		printf("%d\t%s\n", v[i].matricula,v[i].nome);
		i++;
	}
}
