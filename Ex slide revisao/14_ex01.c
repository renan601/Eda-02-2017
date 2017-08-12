#include<stdio.h>

double conversor(double temp){
    
    temp = ((temp*9/5)+32);

    return temp;
}

int main(){
    double temp;

    printf("Insira a temperatura em graus Celsius: ");
    scanf("%lf", &temp);
    if(temp>=9999 || temp <=-9999){
        printf("O valor de temperatura inserido não é válido.\n");
    }else{
        temp = conversor(temp);
        printf("A temperatura equivalente em Fahrenheit é: %.2lf\n", temp);
    }


    return 0;
}