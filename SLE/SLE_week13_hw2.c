#include <stdio.h>

int main(void) {
  int num1, num2;
  int count = 0;
  int num[1000000] = {0};

  scanf("%d", &num1);
  num2 = 2 * num1;
  for(int i=num1+1;i<=num2;i++){
    for(int j=2;j<i;j++){
      if(i%j==0){
        num[i] = i;
        break;
      }
    }
  }
  for(int i=num1+1;i<=num2;i++){
    if(num[i]!=i&&num[i]!=1)
      count++;
  }
  if(num1==1)
    printf("%d\n", 1);
  
  else
    printf("%d\n", count);
  return 0;
}