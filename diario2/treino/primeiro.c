#include<stdio.h>
#include<string.h>

typedef struct registro{
    char nome[30];
    int matricula;
}registro;


void imprimirAluno(registro aluno[20],int *l_sup){
    int i;
    if(*l_sup){
        for(i=0;i < *l_sup; i++){
            printf("%s,%d;", aluno[i].nome, aluno[i].matricula);
        }
        printf("\n");
    }else{
        printf("BASE VAZIA\n");
    }
}

void incluirAluno(registro temp, registro aluno[20],int *l_sup){
    strcpy(aluno[*l_sup].nome, temp.nome);
    aluno[*l_sup].matricula = temp.matricula;
    *l_sup = *l_sup+1;
}

void excluirAluno(registro temp, registro aluno[20], int *l_sup){
    int i, j, flag;
    for(i=0; i< *l_sup; i++){
        if((aluno[i].nome == temp.nome) || (aluno[i].matricula == temp.matricula)){
            flag = 1;
            break;
        }else{
            flag=0;
        }
    }
    if(flag){
        for(j=i; j < *l_sup; j++){
            strcpy(aluno[j].nome, aluno[j+1].nome);
            aluno[j].matricula = aluno[j+1].matricula;
        }
        *l_sup = *l_sup -1;
        imprimirAluno(aluno,l_sup);
    }else{
        printf("ENTRADA INVALIDA\n");
    }
}

void menu(){
    int l_sup=0;
    registro temp;
    registro aluno[20];
    char opcao[3] = "kkk";
    while(strcmp(opcao,"sai")){
        printf("Insira OPCAO NOME MATRICULA\n");
        scanf("%s %s %d", opcao, temp.nome, &temp.matricula);
        if(strcmp(opcao,"IU") == 0){
            incluirAluno(temp, aluno, &l_sup);
            imprimirAluno(aluno,&l_sup);
        }
        if(strcmp(opcao, "EX") == 0){
            excluirAluno(temp, aluno, &l_sup);
        }
    }
}


int main(){

    menu();

    return 0;
}