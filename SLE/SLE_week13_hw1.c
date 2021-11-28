#include <stdio.h>
/*
문제1: M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.
입력: 첫째 줄에 자연수 M과 N이 빈 칸을 사이에 두고 주어진다. (1 ≤ M ≤ N ≤ 1,000,000) M이상 N이하의 소수가 하나 이상 있는 입력만 주어진다.
출력: 한 줄에 하나씩, 증가하는 순서대로 소수를 출력한다.
*/

int main(void) {
  int num1, num2;
  int num[1000000] = {0};

  scanf("%d %d", &num1, &num2);

  

  for(int i=num1;i<=num2;i++){
    for(int j=2;j<i;j++){
      if(i%j==0){
        num[i-1] = i;
        //printf("%d\n", num[i]);
        break;
      }
    }
  }

  for(int i=num1;i<=num2;i++){
    if(num[i-1]!=i&&i!=1)
      printf("%d\n", i);
  }

  return 0;
}