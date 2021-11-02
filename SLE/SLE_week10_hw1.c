#include <stdio.h>
/*
1.테스트 케이스의 개수 입력받아
2.테스트 케이스 숫자에 따라 테스트를 실행
3.각 테스트 안에서...
  3-1.학생들의 수를 먼저 입력받는다(student_num)
  3-2.학생들의 수에 따라 시험점수를 입력받는다
  3-3.점수 입력받으면서 학생들의 점수도 계속 더한다
  3-4.점수 입력받는 작업이 끝나면, 각 테스트의 평균을 계산한다
  3-5.if(각 학생 점수>평균)   count++;
  result = (count / student_num) * 100;
4.결과출력: 각 테스트의 result를 출력
*/
int main(void) {
  int case_num;
  int student_num[1000];
  int score[1000] = {0};
  int sum[1000] = {0};
  int count = 0;
  float avg[1000] = {0};
  float result[1000] = {0};

  scanf("%d", &case_num);
  // 테스트 케이스의 개수(case_num)
  for(int i=0;i<case_num;i++){
    count = 0;
    scanf("%d", &student_num[i]);
    // 학생들의 수(student_num)

    for(int j=0;j<student_num[i];j++){
      scanf("%d", &score[j]);
      // 각 학생의 점수(score)
      sum[i] += score[j];
    }
    avg[i] = sum[i] * 1.0 / student_num[i];
    
    for(int j=0;j<student_num[i];j++){
      if(score[j]>avg[i])
        count++;
    }
    result[i] = (count * 1.0 / student_num[i])*100;
  }

  for(int i=0;i<case_num;i++)
    printf("%.3f%%\n", result[i]);
  
  return 0;
}
