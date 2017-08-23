#include<stdio.h>
#include<stdlib.h>

#define tam_vet 7

void showMenu();
void selectMenu(int v[]);
void inserirValor(int v[]);
void ordenarValor(int v[]);
void buscarValor(int v[]);
void mostrarVetor(int v[]);

int main(){
	int v[tam_vet];
	selectMenu(v);	
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
				system("clear");
				inserirValor(v);
				break;
			case 2:
				system("clear");
				ordenarValor(v);
				break;
			case 3:
				system("clear");
				buscarValor(v);
				break;
			case 4:
				system("clear");
				mostrarVetor(v);
				break;
		}
	}
}

void inserirValor(int v[]){
	int i;

	for(i=0;i<tam_vet;i++){
		printf("Insira um valor para a posicao %d: ", (i+1));
		scanf("%d",v);
		v++;
	}
}

void ordenarValor(int v[]){
	int i, aux, l_sup;
	
	l_sup = tam_vet;
	while(l_sup>1){
		i=0;
		while(i<l_sup-1){
			if(v[i]>v[i+1]){
				aux = v[i];
				v[i] = v[i+1];
				v[i+1] = aux;
			}
			i++;
		}
		l_sup--;
	}
}	

void buscarValor(int v[]){
	int inicio = 0, meio, fim = tam_vet, posi=0, valor;
	int erro=0;
	
	while(!erro){
		printf("Insira um valor de busca valido: ");
		scanf("%d", &valor);
		while(posi){
			meio = (inicio + fim)/2; // adicionar o caso em que o valor inserido nao esteja
			if(v[meio] == valor){    // no vetor
				posi = meio;
				printf("O valor %d esta na posicao %d", valor,meio);
				erro = 1;
				getchar();
				getchar();
				break;
			}
			if(v[meio] < valor){
				inicio = meio ;
			}else{
				fim = meio;
			}
	
		}
		printf("Valor nao encontrado.\n");
	}
}

void mostrarVetor(int v[]){
	int i=0;
	
	while(i<tam_vet){
		printf("Posicao: %d; valor: %d\n", i,v[i]);
		i++;
	}
	getchar();
	getchar();
}
