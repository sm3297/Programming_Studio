#include <stdio.h>

/*
입력: 5줄에 걸쳐 정수 3개 (각각 국어, 영어, 수학 점수)
출력: 5줄에 걸쳐 번호, 총점, 평균(소숫점 1자리)
*/

int main(){

    int jumsu[5][3];  // 5명의 3과목 점수를 저장하는 2차원 배열
    int sum[5];  // 학생별 총점
    float average[5];  // 학생별 평균


    for(int i=0; i<5; i++){
        scanf("%d %d %d", &jumsu[i][0], &jumsu[i][1], &jumsu[i][2]);
        sum[i] = jumsu[i][0] + jumsu[i][1] + jumsu[i][2];
        average[i] = sum[i] / 3.0;
    }

    for(int i=0; i<5; i++){
        printf("%d) %d %.1f\n", i+1, sum[i], average[i]);
    }

    return 0;
}