#include<stdio.h>

int main(){
    int a,b, produto = 0;
    scanf("%d", &a);
    scanf("%d", &b);
    while(b>0){
        produto += a;
        b--;
    }
    printf("%d\n", produto);
    return 0;
}