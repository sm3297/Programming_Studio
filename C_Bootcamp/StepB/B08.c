#include <stdio.h>

/*
입력: 이름과 정수 3개 (각각 국어, 영어, 수학 점수)
출력: 이름, 총점, 평균(소숫점 1자리)과 등급
*/

struct st_jumsu{
  char name[20]; // 이름 (공백 없이 영어 알파벳으로 구성)
  int jumsu[3]; // 3과목 점수 (국, 영, 수)
  int sum;	// 총점
  float avg;	// 평균
  char grade;	// 평균에 대한 등급
};

char getGrade(float score);

int main(){

    struct st_jumsu jumsu;
    int i;
    scanf("%s", jumsu.name);
    jumsu.sum = 0;
    for(i=0; i<3; i++){
        scanf("%d", &jumsu.jumsu[i]);
        jumsu.sum += jumsu.jumsu[i];
    }
        jumsu.avg = (float)jumsu.sum / 3.0;
        jumsu.grade = getGrade(jumsu.avg);
        printf("%s %d %.1f %c\n", jumsu.name, jumsu.sum, jumsu.avg, jumsu.grade);

    return 0;
}

char getGrade(float score){
    // 파라미터 : 평균 점수(score) 
    // 리턴값 : 해당 평균 점수의 등급 ('A','B','C','D','F')
    if(score >= 90) return 'A';
    else if(score >= 80) return 'B';
    else if(score >= 70) return 'C';
    else if(score >= 60) return 'D';
    else return 'F';
}
