#include <stdio.h>
#include <stdlib.h>
/*
입력: 첫 줄에 인원 수, 둘째 줄부터 이름과 점수 3개 - 각각 국어, 영어, 수학 점수)
출력: 인원 수만큼 번호, 이름, 총점, 평균(소숫점 1자리), 등급, 그 다음 3줄에 걸쳐 과목명, 
과목의 가장 높은 점수를 받은 학생이름과 점수, 그 다음 줄부터 등급(A,B,C,D,F)별 인원 수
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
struct st_jumsu* firstRanking(struct st_jumsu* data[], int size, int index);
int countGrade(struct st_jumsu* data[], int size, char grade);

int main(){
	struct st_jumsu* jdata[20]; // 최대 20명의 점수 데이터
	//int sum_class[3]; // 과목별 총점
	//float average_class[3]; // 과목별 평균
	char class_name[3][20] = {"Korean", "English", "Math"};
	struct st_jumsu* first[3];
	char grades[5] = "ABCDF";
	int count_grade[5];
	//int count;


  // Your code here.
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        jdata[i] = (struct st_jumsu*)malloc(sizeof(struct st_jumsu));
        scanf("%s", jdata[i]->name);
        for(int j=0; j<3; j++)
            scanf("%d", &jdata[i]->jumsu[j]);
        
        makeJumsu(jdata[i]);
    }

    for(int i=0; i<n; i++){
        printf("%d) ",i+1);
        printJumsu(jdata[i]);
    }

    for(int i=0; i<3; i++){
        first[i] = firstRanking(jdata, n, i);
        printf("[%s] %s %d\n",class_name[i], first[i]->name, first[i]->jumsu[i]);
    }
    for(int i=0; i<5; i++){
        count_grade[i] = countGrade(jdata, n, grades[i]);
        printf("[%c] %d\n",grades[i], count_grade[i]);
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
    printf("%s - %d %.1f %c\n",p->name, p->sum, p->avg, p->grade);
}

struct st_jumsu* firstRanking(struct st_jumsu* data[], int size, int index){
    // 파라미터: 점수 데이터의 포인터 배열(data), 점수 데이터 개수, 과목번호(0~2) 
    // 리턴값: 과목번호에 해당하는 모든 점수 중 가장 높은 점수를 가진 점수 데이터 포인터
    // 수행내용: 모든 점수 데이터의 특정 과목번호의 점수 중에 가장 높은 점수를 가진 데이터를 찾아 그 데이터의 구조체 포인터를 리턴한다.
    struct st_jumsu* max = data[0];
    for(int i=1; i<size; i++){
        if(data[i]->jumsu[index] > max->jumsu[index])
            max = data[i];
    }
    return max;

}
int countGrade(struct st_jumsu* data[], int size, char grade){
    // 파라미터: 점수 데이터의 포인터 배열(data), 점수 데이터 개수, 등급문자(A,B,C,D,F) 
    // 리턴값: 모든 점수 데이터 중 특정 등급을 가진 점수 데이터의 개수
    // 수행내용: 모든 점수 데이터 중 특정 등급을 가진 점수 데이터의 개수를 계산하여 리턴한다.
    int count = 0;
    for(int i=0; i<size; i++){
        if(data[i]->grade == grade)
            count++;
    }
    return count;

}