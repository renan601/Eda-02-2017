#include<stdio.h>

int main(){
    int  i,fat;

    scanf("%d",&i);
    fat = 1;
    while(i>0){
        fat *=i;
        i--;
    }
    printf("O fatorial é: %d\n", fat);

    return 0;
}