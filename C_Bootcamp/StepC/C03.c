#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct st_person{
    char name[20];
    int gender;
    int country;
    int birthyear;
};

int getCountry(char* str);
void printInfo(struct st_person* p);
int countGender(struct st_person* data[], int size, int gender);

char country_type[6][5] = {"KR", "US","JP","CN","FR","--"};
char gender_type[3][10] = {"Female", "Male"};

int main(){

    struct st_person* pdata[20]; // 최대 20명의 데이터
    char country[5]; // 국적입력을 위한 문자열
    char count_gender[6][2] = {0}; // 성별 인원수
    int count = 0;  // 인원수
    float average[6]; // 국적별 평균
    int sum_age[6] = {0}; // 국적

    scanf("%d", &count);
    for(int i=0; i<count; i++){
        pdata[i] = (struct st_person*)malloc(sizeof(struct st_person));
        scanf("%s %d %s %d",pdata[i]->name, &(pdata[i]->gender), country, &(pdata[i]->birthyear));
        pdata[i]->country = getCountry(country);
    }

    for(int i=0; i<count; i++){
        printf("%d) ",i+1);
        printInfo(pdata[i]);
        
    }

    for(int i=0; i<count ; i++){
        int a = pdata[i]->country;
        int b = pdata[i]->gender;
        count_gender[a][b]++;
    }

    for(int i=0; i<count; i++){
        sum_age[pdata[i]->country] += 2025 - pdata[i]->birthyear;
    }

    for(int i=0; i<6; i++){
        average[i] = (float)sum_age[i] / (count_gender[i][0] + count_gender[i][1]);  
    }

    for(int i=0; i<6; i++){
        printf("[%s] %s:%d %s:%d average age:%.1f\n",country_type[i],gender_type[0],count_gender[i][0],gender_type[1],count_gender[i][1], average[i]);   
    }

    return 0;
}

int getCountry(char* str){
    int i;
    for(i=0; i<5; i++){
        if(strcmp(str,country_type[i]) == 0) return i;
    }
    return i;
}

void printInfo(struct st_person* p){
    printf("%s (%s, age:%d, from %s)\n",p->name, gender_type[p->gender],2025-(p->birthyear),country_type[p->country]);
}

int countGender(struct st_person* data[], int size, int gender){
    // 파라미터: 학생정보 데이터 포인터 배열(data), 데이터 개수, 성별 인덱스(0~1) 
    // 리턴값: 해당 성별 인원수
    // 수행내용: 모든 학생 정보 데이터에서 특정 성별인 인원수를 구한다.
    int g_count = 0;
    for(int i=0; i<size; i++){
        if(data[i]->gender == gender) g_count++;
    }
    return g_count;
}
