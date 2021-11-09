#include <stdio.h>
#include <string.h>
/*
1.알파벳들을 입력받는다
2.입력받은 알파벳들을 모두 대문자로 바꾼다.(개수 통일위해)
3.A부터 Z까지 각 항목별로 개수 대응하는 배열을 만든다
4.바뀐 알파벳들을 가지고 알파벳에 따라 count증가
  --> if(str[i]=='A')     count[0]++
  --> if(str[i]=='B')     count[1]++
  --> ...
  --> if(str[i]=='Z')     count[25]++
5.count배열 안에서 최댓값을 가려낸다.
6.최댓값을 가림과 동시에, 그에 대응하는 입력받은 문자의 index도 추출
  --> 만약 최댓값 개수가 1이라면... 다음 단계
  --> 만약 최댓값 개수가 2이상이라면... 그냥 ? 출력
7.index에 대응하는 문자를 출력한다.
*/
int main(void) {
  char word[1000000];
  char alphabet[26] = {'A',};
  int count[26] = {0};
  int k = 0;
  int max = 0;
  int max_index;
  int max_count = 0;
  
  for(int i=1; i<26; i++){
    alphabet[i] = 'A' + i;
  } // 대문자들을 하나의 배열에 정리

  scanf("%s", word);
  for(int i=0; i<1000000; i++){
    if(word[i]>='a'&&word[i]<='z')
      word[i] = word[i] - 'a' + 'A';
    // 소문자들을 모두 대문자로 바꿔줌
  }
  
  for(int i=0; i<strlen(word); i++){
    for(int j=0;j<26;j++){
      if(word[i]==alphabet[j]){
        count[j]++;
        break;
      }
    }
  } // 각 알파벳에 따라 count증가
  
  for(int i=0; i<26; i++){
    if(count[i]>=max){
      max = count[i];
      max_index = i;
    }
  }
  for(int i=0; i<26; i++){
    if(count[i]==max && (count[i]!=0))
      max_count++;
  }

  if(max_count>=2)          
    printf("%c\n", '?');
  // 최댓값 개수가 2개 이상일 경우 '?'출력...

  else if(max_count==1){
    printf("%c\n", alphabet[max_index]);
  } // 최댓값 개수가 한 개일 경우

  return 0;
}