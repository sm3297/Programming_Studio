#include <stdio.h>

/*
입력: 정수 3개 (각각 국어, 영어, 수학 점수)
출력: 총점과 평균(소숫점 1자리)
*/

int main(){

    int kor, eng, math; // 국어점수, 영어점수, 수학점수 
    int total; // 총점
    float average; // 평균점수 

    scanf("%d %d %d", &kor, &eng, &math);
    total = kor + eng + math;
    average = total / 3.0;

    printf("%d %.1f", total, average);

    return 0;
}