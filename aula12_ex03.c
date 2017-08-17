#include<stdio.h>

int main(){
    int n,i=0, atual=1, anterior=0, anterior2=1;

    scanf("%d", &n);
    while(i<n){
        printf("%d ", atual);
        atual = anterior + anterior2;
        anterior = anterior2;
        anterior2 = atual;
        i++;
    }
    printf("\n");

    return 0;
}