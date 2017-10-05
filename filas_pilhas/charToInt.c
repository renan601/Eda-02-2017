#include<stdio.h>
#include<stdlib.h>

int main(){
    char* s = {"123"};
    int i;
    char c;

    c = s[1];
    printf("%s\n\n", s);
    i = c - '0';
    printf("%d\n\n", i);
    return 0;
}