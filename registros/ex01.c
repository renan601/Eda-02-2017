/*
Inclui um aluno no final do vetor
e o imprime
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tam_vet 40

typedef struct {
    char nome[30];
    int matricula;
} registro;

void menu();
void showMenu();
void inserirAluno(registro aluno[], int *l_sup);
void imprimirTurma(registro aluno[], int *l_sup);

int main(){

    menu();

    return 0;
}

void menu(){
    registro aluno[tam_vet];
    int menu=1, l_sup=0;

    while(menu){
        system("clear");
        showMenu();
        printf("\nOpcao: ");
        scanf("%d", &menu);
        switch(menu){
            case 1:
                system("clear");
                inserirAluno(aluno,&l_sup);
                break;
            case 2:
                system("clear");
                imprimirTurma(aluno,&l_sup);
        }
    }
}

void showMenu(){
    printf("############ MENU ############\n");
	printf("1. Inserir alunos\n");
	printf("2. Mostrar Turma\n");
	printf("0. Sair\n");
}

void inserirAluno(registro aluno[], int *l_sup) {

    char nome_aux[30];
    int matricula_aux;

    while(*l_sup <= tam_vet) {
        printf("**Para sair informe o valor 0**\n");
        printf("Insira o nome do aluno: ");
        scanf("%s", nome_aux);
        printf("Insira a matricula de %s:", aluno[*l_sup].nome);
        scanf("%d", &matricula_aux);
        if (!strcmp(nome_aux, "0\0" || matricula_aux == 0 ) {
            break;
        }
        strcpy(aluno[*l_sup].nome, nome_aux);

        *l_sup++;
        printf("De novo: %d", *l_sup);
    }

}

void imprimirTurma(registro aluno[], int *l_sup){
    int i;

    printf("MATRICULA \t NOME\n");
    for(i=0; i <= *l_sup; i++){
        printf("%d \t %s", aluno[i].matricula, aluno[i].nome);
    }

    getchar();
    getchar();
}
