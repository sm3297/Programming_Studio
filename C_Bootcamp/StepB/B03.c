#include <stdio.h>

/*
입력: 정수 3개 (각각 국어, 영어, 수학 점수)
출력: 평균(소숫점 1자리)과 등급
*/

int main(){

    int kor, eng, math; // 국어점수, 영어점수, 수학점수
    int total; // 총점
    float average;  // 평균점수
    char grade; // 등급

    scanf("%d %d %d", &kor, &eng, &math);
    total = kor + eng + math;
    average = total / 3.0;

    if(average >= 90) grade = 'A';
    else if(average >= 80) grade = 'B';
    else if(average >= 70) grade = 'C';
    else if(average >= 60) grade = 'D';
    else grade = 'F';

    printf("%.1f %c\n", average, grade);

    return 0;
}