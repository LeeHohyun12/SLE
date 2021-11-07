#include <stdio.h>
/*
생각 정리)
정의역 범위를 자연수 n으로... 공역의 범위를 1~10000으로...
함수 N = d(n)을 치역으로... 
따라서 이 문제는 구한 치역이 공역 범위 안에 있는지 확인하여 치역이 아닌 공역숫자들을 출력하는 것으로 이해할 수 있을 것이다.

1.자연수 n이 정의역이므로 한계가 없는 while문을 사용하자
2.자연수 n을 변환함수 d(n)에 넣어 얻은 함숫값 N을 만든다.
--> %와 / 기호를 사용하여 각 자릿수를 얻는다.
--> 얻은 자릿수들과 해당 자연수를 합하여 함숫값 N을 얻는다.
3.함숫값 N이 1~10000 사이에 있는지 확인한다
--> for(int i=0;i<10000;i++) 사용
4.결과출력: 1~10000사이에 존재하지 않는 N을 출력한다.
--> if(N!=i) >> printf("%d\n", i);
*/

int main(void){
  int n = 1;
  int d[5] = {0};
  int d_r[5] = {0};
  int d_number = 1; 
  int count = 1;
  int N[10000] = {0};
  int i = 0;
  int temp[10000] = {0};
  int check;

  for(int n=1;n<=10000;n++){
    count = 1;
    d_number = n / 10;
    while(d_number!=0){
      count++;
      d_number = d_number / 10;
    }
    if(count==1||count==2){
      d[0] = n % 10;
      d_r[0] = n / 10;
      N[i] += (d[0] + d_r[0] + n);
    }
    else if(count==3){
      d[0] = n % 100;
      d_r[0] = n / 100;
      d[1] = d[0] % 10;
      d_r[1] = d[0] / 10;
      N[i] += (d[1] + d_r[0] + d_r[1] + n);
    }
    else if(count==4){
      d[0] = n % 1000;
      d_r[0] = n / 1000;
      d[1] = d[0] % 100;
      d_r[1] = d[0] / 100;
      d[2] = d[1] / 10;
      d_r[2] = d[1] % 10;
      N[i] += (d[2] + d_r[0] + d_r[1] + d_r[2] + n);
    }
    check = N[i];
    if(check<=10000)
      temp[check] = 1;
    // N을 모조리 구해놓고 후에 비교 
    i++;
  }
  for(int k=1;k<=10000;k++){
    if(temp[k]!=1)
      printf("%d\n", k);
  }
  return 0;
}