/* Exemplo do professor
*/

#include<stdio.h>
#include<stdlib.h>

#define tam_vet 40

typedef struct {
	char nome[30];
	int matricula;
}registro;

int main(){

	opcaoMenu(aluno);

	return 0;
}

void showMenu(){
	printf("\tMENU\n");
	printf("1 - Incluir aluno na turma\n");
	printf("2 - Imprimir alunos da turma\n");
}

void opcaoMenu(registro aluno[]){
	int menu, l_sup=0;
	registro aluno[tam_vet];

	showMenu();
	while(menu){
		switch(menu){
			case 1:
				system("clear");
				incluirAluno(registro,&l_sup);
			case 2:
				system("clear");
				imprimirAluno(registro,&l_sup);
		}
	}
}

void incluirAluno(registro aluno[], int *l_sup){
	int i=0;

}

void imprimirAluno(registro aluno[], int *l_sup){
	int i;
}
