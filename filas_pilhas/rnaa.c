#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 300

void ler_nome(char *s);
void removeSolo(char* s);
void verifica(char* pilha1,int* topo1, char* pilha2,int* topo2, int* quant);
void dobra(char* pilha1, int* topo, int* quant);

int main(){
    char base[MAX];
    int topo;
    int quant=0;

    printf("Insira a base\n");
    ler_nome(base); // insere empilhado
    removeSolo(base);
    topo = strlen(base)+1;
    dobra(base,&topo,&quant);
    printf("Quantidade de ligações: %d\n", quant);

    return 0;
}
void ler_nome(char *s){
    // Função ler o nome
    char c;
    //int i;
    c = getchar();
    while(c!='\n'){
        *s = c;
        c=getchar();
        s++;
        //   i++;
    }
}

void removeSolo(char* s){
    if(strlen(s) % 2 != 0)
        s[strlen(s)-1];
}

void verifica(char* pilha1,int* topo1, char* pilha2,int* topo2, int* quant){
    char c;

    while(*topo1!=1){
        switch(pilha1[*topo1]){
            case 'B':
                if(pilha2[*topo2]== 'S'){
                    quant++;
                    topo1--;
                    topo2--;
                    break;
                }
            case 'S':
                if(pilha2[*topo2]== 'B'){
                    quant++;
                    topo1--;
                    topo2--;
                    break;
                }
            case 'F':
                if(pilha2[*topo2]== 'C'){
                    quant++;
                    topo1--;
                    topo2--;
                    break;
                }
            case 'C':
                if(pilha2[*topo2]== 'F'){
                    quant++;
                    topo1--;
                    topo2--;
                    break;
                }
            default:
                dobra(pilha1, topo1, quant);
                dobra(pilha2, topo2, quant);
        }
    }
}
void dobra(char* pilha1, int* topo, int* quant){
    char* pilha2 = (char*)malloc((strlen(pilha1)/2) * sizeof(char));
    int topo2=0;
    int i;

    for(i=*topo; i > strlen(pilha1)/2; i--){
        pilha2[topo2++] = pilha1[--*topo];
    }
    verifica(pilha1,topo,pilha2,&topo2,quant);
}
