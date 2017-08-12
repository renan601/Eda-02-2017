#include<stdio.h>

int soma(int matriz[][4]){
    int soma=0, i,j;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(i>j){
                soma += matriz[i][j];
            }
        }
    }
    return soma;
}


void main(){
    int matriz[4][4], i ,j, result;

    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            scanf("%d", &matriz[i][j]);
        }
    }
    result = soma(matriz);
    printf("A soma e: %d\n", result);

}