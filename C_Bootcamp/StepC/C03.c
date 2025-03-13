#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
입력: 첫 줄에 입력할 인원 수, 둘째 줄부터 이름과 성별인덱스, 국적문자열, 태어난 년도
출력: 인원 수만큼 인적사항 정보 (아래 출력 참고), 그 다음 줄에 국적에 따라 성별 인원수와 평균 나이(소숫점 1자리)
*/

struct st_person{
	char name[20]; 	// Name (single word, no duplicates)
	int gender;  	// 0 - Female, 1 - Male
	int country;	// Country code (index of COUNTRY_NAME 0~5)
	int birthyear; 	// Birthyear
};

int getCountry(char* str);
void printInfo(struct st_person* p);

int main(){
    struct st_person* pdata[20]; // 최대 20명의 데이터
    char country[5]; // 국적입력을 위한 문자열
    int count;  // 인원수

    scanf("%d", &count);
    for(int i=0; i<count; i++){
        pdata[i] = (struct st_person*) malloc(sizeof(struct st_person)); 
        scanf("%s %d %s %d",pdata[i]->name, &(pdata[i]->gender), country, &(pdata[i]->birthyear));
        pdata[i]->country = getCountry(country);

    }

    for(int i=0; i<count; i++){
        printf("%d) ", i+1);
        printInfo(pdata[i]);
    }

    // 국적별 성별 인원수와 평균 나이 출력
    char countrys[6][5] = {"KR", "US", "JP", "CN", "FR", "UK"};
    char Gender[2][10] = {"Female", "Male"};

  
    return 0;
}

int getCountry(char* str){
    // 파라미터: 국적을 나타내는 문자열(str) 
    // 리턴값: 국적에 해당되는 인덱스 (0~5)
    // 수행내용: 국적 문자열에 해당하는 인덱스를 찾는다.
    if(strcmp(str, "KaR")) return 0;
    else if(strcmp(str, "US")) return 1;
    else if(strcmp(str, "JP")) return 2;
    else if(strcmp(str, "CN")) return 3;
    else if(strcmp(str, "FR")) return 4;
    else return 5;

}

void printInfo(struct st_person* p){
    // 파라미터: 학생정보 구조체 포인터(p) 
    // 리턴값: 없음
    // 수행내용: 해당 학생 정보의 내용을 출력한다.
    char Gender[2][10] = {"Female", "Male"};
    char country[6][5] = {"KR", "US", "JP", "CN", "FR", "UK"};
    int age = 2025 - p->birthyear; 
    printf("%s (%s, age:%d, from %s)\n",p->name,Gender[p->gender],age,country[p->country]);

}