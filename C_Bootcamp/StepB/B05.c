#include <stdio.h>

/*
입력: 5줄에 걸쳐 정수 3개 (각각 국어, 영어, 수학 점수)
출력: 5줄에 걸쳐 번호, 총점, 평균(소숫점 1자리), 등급, 그 다음 3줄에 걸쳐 과목명, 과목 총점, 과목 평균
*/

int main(){

    int jumsu[5][3]; // 5명의 3과목 점수를 저장하고 있는 2차원 배열 
    int sum_student[5]; // 학생별 총점
    float average_student[5];  // 학생별 평균
    char grade[5]; // 학생별 등급 

    int sum_class[3]; // 과목별 총점
    float average_class[3]; // 과목별 평균
    char class_name[3][20] = {"Korean", "English", "Math"};


    for(int i=0; i<5; i++){
        scanf("%d %d %d", &jumsu[i][0], &jumsu[i][1], &jumsu[i][2]);
        sum_student[i] = jumsu[i][0] + jumsu[i][1] + jumsu[i][2];
        average_student[i] = sum_student[i] / 3.0;
    
        if(average_student[i] >= 90) grade[i] = 'A';
        else if(average_student[i] >= 80) grade[i] = 'B';
        else if(average_student[i] >= 70) grade[i] = 'C';
        else if(average_student[i] >= 60) grade[i] = 'D';
        else grade[i] = 'F';
    }

    for(int i=0; i<5; i++){
        printf("%d) %d %.1f %c\n", i+1, sum_student[i], average_student[i], grade[i]);
    }

    for(int i=0 ;i<3; i++){
        sum_class[i] = 0;
        for(int j=0; j<5; j++){
            sum_class[i] += jumsu[j][i];
        }
        average_class[i] = sum_class[i] / 5.0;
    }

    for(int i=0; i<3; i++){
        printf("%s %d %.1f\n", class_name[i], sum_class[i], average_class[i]);
    }

    return 0;
}