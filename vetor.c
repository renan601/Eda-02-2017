#include<stdio.h>
#include<stdlib.h>

#define tam_vet 7

int main(){
	int v[tam_vet];
	
	return 0;
}

void showMenu(){
	printf("############ MENU ############\n");
	printf("1. Inserir valores\n");
	printf("2. Ordenar valores\n");
	printf("3. Buscar valor\n");
	printf("4. Mostrar vetor\n");
	printf("0. Sair\n");
}

void selectMenu(int v[]){
	int menu;
	
	while(menu!=0){
		system("clear");
		showMenu();
		scanf("%d",&menu);
		switch(menu){
			case 1:
				inserirValor(v);
			case 2:
				ordenarValor(v);
			case 3:
				buscarValor(v);
			case 4:
				mostrarVetor(v);
		}
	}
}

void inserirValor(int v[]){
	int i;

	for(i=0;i<tam_vet;i++){
		scanf("%d",v[i]);
	}
}

void ordenarValor(int v[]){
	
