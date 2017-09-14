#include<stdio.h>

int fatorial(int val){
  if(val == 0){
    return 1;
  }else{
    return fatorial(val -1)*val;
  }
}

int main(){
  int result;
  int val;
  scanf("%d", &val);
  result = fatorial(val);
  printf("%d\n\n", result);
  return 0;
}
