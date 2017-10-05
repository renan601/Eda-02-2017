#include<stdio.h>

void power(int *py, int *px){
    printf("&px = %p\t px = %p\t *px = %d\n",&px,px,*px);
    *py = *px + *px;
    printf("&py = %p\t py = %p\t *py = %d\n",&py,py,*py);
}




int main(){
    int x=2, y;

    printf("&x = %p \t\t\t x = %d\n", &x, x);
    printf("&y = %p \t\t\t y = %d\n", &y, y);
    power(&y,&x);
    printf("%d ao quadrado = %d\n", x,y);
    return 0;
}