#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>


#define MAX 20
typedef int titem;
#define N 7
#define LIVRE 0
#define PAREDE 32767


typedef struct registro{
  int x,y;
}Registro;

void cria(int L[N][N]){
    int i,j;
    for(i=0;i<N;i++){
        L[i][0]=PAREDE;
        L[i][N-1] = PAREDE;
    }
    for(j=0;j<N;j++){
        L[0][j]=PAREDE;
        L[N-1][j] = PAREDE;
    }
    L[1][2] = PAREDE;
    L[2][2] = PAREDE;
    L[3][2] = PAREDE;
    L[5][2] = PAREDE;
    L[2][4] = PAREDE;
    L[3][4] = PAREDE;
    L[4][4] = PAREDE;
    L[4][5] = LIVRE;
    for(i=0; i<N-1; i++){
      for(j=0; j<N-1; j++){
        if(L[i][j] != PAREDE)
          L[i][j] = LIVRE;
      }
    }
}

void exibe(int L[N][N]){
    int i,j;
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            switch(L[i][j]){
                case LIVRE:
                    putchar(' ');
                    break;
                case PAREDE:
                    putchar('#');
                    break;
                default:
                    putchar(126);
            }
        }
    printf("\n");
    }
}

void anota(int L[N][N]){
    int i;
    int c;
    int ini=0, fim=0;
    Registro fila[MAX];

    L[1][1] = 1;

    fila[fim].x = 1;
    fila[fim++].y = 1;
    while(fim!=ini){
        c = L[ fila[ini].x ][ fila[ini].y ]+1;
        


/*
      for(i=fila[ini].x -1; i < fila[ini].x +2; i++){
        if(L[i][fila[ini].y] == LIVRE){
          L[i][fila[ini].y] = c;
          fila[fim++].x = i;
          fila[fim].y = fila[ini].y;
        }
      }
      for(i=fila[ini].y -1; i < fila[ini].y +2; i++){
        if(L[i][fila[ini].x] == LIVRE){
          L[fila[ini].x][i] = c;
          fila[fim++].x = fila[ini].x;
          fila[fim].y = i;
        }
      }
      ini++;
*/
    }
}


int main(){
    int L[N][N];
    char r;
    srand(time(NULL));
    do{
        system("clear");
        
        cria(L);
        anota(L);
        exibe(L);

        printf("Continua? (s/n) ");
        scanf("%c%*c",&r);
    }while(toupper(r) !='N');
    return 0;
}
