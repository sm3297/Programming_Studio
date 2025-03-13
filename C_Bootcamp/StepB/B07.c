#include <stdio.h>

/*
입력: 첫 줄에 인원 수, 두번째 줄부터 정수 3개 (각각 국어, 영어, 수학 점수)
출력: 인원 수 만큼 매 줄마다 번호, 총점, 평균(소숫점 1자리), 등급, 그 다음 3줄에 걸쳐 과목명, 과목 총점, 과목 평균, 그 다음 줄에 가장 높은 점수를 받은 학생 번호
*/

/*
여러 명(최대 20명)의 국어, 영어, 수학 점수를 각각 입력받아 저장한 후에, 다음 항목들을 계산하여 출력하라.

1) 각 학생별 총점과 평균점수, 평균에 따른 등급
2) 각 과목별 총점과 평균 점수
3) 가장 높은 점수를 받은 학생 번호(1~20)

등급은 다음과 같은 기준으로 판정하라.

평균 90이상 : A
평균 80이상 ~ 90미만 : B
평균 70이상 ~ 80미만 : C
평균 60이상 ~ 70미만 : D
평균 60미만 : F
*/

int studentSum(int s[20][3], int size, int index);
char getGrade(float score);
int classSum(int s[20][3], int size, int index);
int firstRanking(int s[20], int size);

int main(){
	int jumsu[20][3]; // 최대 20명의 3과목 점수를 저장하고 있는 2차원 배열 
	int sum_student[20]; // 최대 20명의 학생별 총점
	float average_student[20];  // 최대 20명의 학생별 평균
	char grade[20]; // 최대 20명의 학생별 등급 
	int first;	// 1등 학생 번호
	int all;	// 인원수
	int sum_class[3]; // 과목별 총점
	float average_class[3]; // 과목별 평균
	char class_name[3][20] = {"Korean", "English", "Math"};

	// Your code here.
    scanf("%d", &all);
    for(int i=0; i<all; i++){
        for(int j=0; j<3; j++){
            scanf("%d", &jumsu[i][j]);
        }
    }

    for(int i=0; i<all; i++){
        sum_student[i] = studentSum(jumsu, all, i);
        average_student[i] = (float)sum_student[i] / 3;
        grade[i] = getGrade(average_student[i]);
    }

    for(int i=0; i<3; i++){
        sum_class[i] = classSum(jumsu, all, i);
        average_class[i] = (float)sum_class[i] / all;
    }

    first = firstRanking(sum_student, all)+1;

    for(int i=0; i<all; i++){
        printf("%d) %d %.1f %c\n", i+1, sum_student[i], average_student[i], grade[i]);
    }

    for(int i=0; i<3; i++){
        printf("%s %d %.1f\n", class_name[i], sum_class[i], average_class[i]);
    }

    printf("1st Ranking: %d",first);

	return 0;
}

int studentSum(int s[20][3], int size, int index){
    // 파라미터 : 점수배열(s)과 인원수(size), 학생순서(index 0,1,2,3,4) 
    // 리턴값 : 해당 학생의 총점
    int sum = 0;
    for(int i=0; i<3; i++){
        sum += s[index][i];
    }
    return sum;
}

char getGrade(float score){
    // 파라미터 : 평균 점수(score) 
    // 리턴값 : 해당 평균 점수의 등급 ('A','B','C','D','F')
    if(score >= 90)
        return 'A';
    else if(score >= 80)
        return 'B';
    else if(score >= 70)
        return 'C';
    else if(score >= 60)
        return 'D';
    else
        return 'F';


}

int classSum(int s[20][3], int size, int number){
    // 파라미터 : 점수배열(s)과 인원수(size), 과목번호(index 0,1,2) 
    // 리턴값 : 해당 과목의 총점
    int sum = 0;
    for(int i=0; i<size; i++){
        sum += s[i][number];
    }
    return sum;

}

int firstRanking(int s[20], int size){
    // 파라미터 : 점수배열(s)과 인원수(size) 
    // 리턴값 : 가장 높은 점수를 가진 배열 인덱스
    int max = 0;
    for(int i=0; i<size; i++){
        if(s[i] > s[max])
            max = i;
    }
    return max;

}


