#include <stdio.h>
#include <stdlib.h>

/*
입력: 첫 줄에 점수를 입력할 인원 수, 둘째 줄부터 이름과 점수 3개 (각각 국어, 영어, 수학 점수)
출력: 인원 수만큼 번호, 이름, 총점, 평균(소숫점 1자리), 등급, 그 다음 3줄에 걸쳐 과목명, 과목 총점, 과목 평균
*/

struct st_jumsu{
  char name[20]; // 이름 (공백 없이 영어 알파벳으로 구성)
  int jumsu[3]; // 3과목 점수 (국, 영, 수)
  int sum;	// 총점
  float avg;	// 평균
  char grade;	// 평균에 대한 등급
};

char getGrade(float score);
void makeJumsu(struct st_jumsu* p);
void printJumsu(struct st_jumsu* p);
int getClassSum(struct st_jumsu* data[], int size, int index);

int main(){

    struct st_jumsu* jdata[20]; // 최대 20명의 점수 데이터
    int sum_class[3]; // 과목별 총점
    float average_class[3]; // 과목별 평균
    char class_name[3][20] = {"Korean", "English", "Math"};

    int n; // 입력할 인원 수
    int i;

    scanf("%d", &n);
    for(i=0; i<n; i++){
        jdata[i] = (struct st_jumsu*)malloc(sizeof(struct st_jumsu));
        scanf("%s", jdata[i]->name);
        for(int j=0; j<3; j++)
            scanf("%d", &jdata[i]->jumsu[j]);

        makeJumsu(jdata[i]);
       
    }
    for(i=0; i<n; i++)
        printJumsu(jdata[i]);

    for(int j=0; j<3; j++){
        sum_class[j] = getClassSum(jdata, n, j);
        average_class[j] = (float)sum_class[j] / n;
        printf("%s %d %.1f\n", class_name[j], sum_class[j], average_class[j]);
    }


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

void makeJumsu(struct st_jumsu* p){
    // 파라미터: 점수 데이터의 포인터(p) 
    // 리턴값: 없음
    // 수행내용: 해당 학생의 점수 데이터 구조체 내의 과목 점수로 총점, 평균, 등급을 넣는다.
    for(int i=0; i<3; i++)
        p->sum += p->jumsu[i];
    p->avg = p->sum / 3.0;
    p->grade = getGrade(p->avg);
}


void printJumsu(struct st_jumsu* p){
    // 파라미터: 점수 데이터의 포인터(p) 
    // 리턴값: 없음
    // 수행내용: 해당 학생의 점수 데이터 구조체 내의 값을 출력한다.
    printf("%s %d %.1f %c\n",p->name, p->sum, p->avg, p->grade);
}


int getClassSum(struct st_jumsu* data[], int size, int index){
    // 파라미터: 점수 데이터의 포인터 배열(data), 점수 데이터 개수, 과목번호(0~2) 
    // 리턴값: 과목번호에 해당하는 점수의 총 합계
    // 수행내용: 모든 점수 데이터의 특정 과목번호의 점수 합계를 구한다.

    int sum = 0;
    for(int i=0; i<size; i++){
        sum += data[i]->jumsu[index];
    }
    return sum;
}