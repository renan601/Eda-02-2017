#include<stdio.h>

int main(){
    int i[10];
    int topo=10,j;

    for(j=0;j<10;j++){
        i[j] = j;
    }
    j = i[--topo] + i[--topo];
    printf("%d\n\n",j);

    return 0;
}