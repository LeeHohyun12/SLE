#include <stdio.h>
#include <string.h>
/*
idea: 공백의 개수 + 1이 곧 문장 내 단어의 총 개수
1.문장을 입력받는다 
2.우선 문장 내의 공백개수를 센다
3-1.공백이 없는 경우(하나의 단어)...
  --> 바로 1을 출력하고 끝
3-2.공백이 있는 경우...
  --> 공백개수에 +1을 하고 count출력
*/
int main(){
  char arr[1000000];
  int count = 0;

  scanf("%[^\n]", arr);
  unsigned length = strlen(arr);

  if(length==1){
    if(arr[0]==' '){
      printf("0\n");
      return 0;
    }
  }
  for(int i=1;i<length;i++){
    if(arr[i]==' ')
      count++;
  }

  printf("%d\n", count+1);
  return 0;
}