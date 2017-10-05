#include<stdio.h>

int fibonacci(int val){
  if(val == 1 || val ==2){
    return 1;
  }else{
    return fibonacci(val-1)+fibonacci(val-2);
  }
}


int main(){
  int val, i, result;
  scanf("%d", &val);
  for(i=0;i < val; i++){
    printf("%d ", result = fibonacci(i+1));
  }
  printf("\n");
  return 0;
}
