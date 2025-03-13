#include <stdio.h>
#include <stdlib.h>

// 입력: 첫 줄에 인원 수, 두번째 줄부터 인원수 만큼 이름과 2개의 정수 - 신장(cm단위)과 체중(kg단위)
// 출력: 모든 사람의 비만도 관리 데이터

struct bmi_struct{
	char name[20];  // 이름 (공백 없이 영어 알파벳으로 구성)
	int height, weight; // 키(cm), 몸무게(kg)
	float bmi; // 비만도
	int bmi_level; // 비만등급 0~4
};

int loadData(struct bmi_struct* list[]);
void bmiResolve(struct bmi_struct* sp);
void printBmiData(struct bmi_struct* list[], int size);

char bmi_string[5][20] = {"Underweight","Normal weight","Overweight","Mild obesity","Severe obesity"};

int main(void) {
	struct bmi_struct* data[20];    // 최대 20명까지 관리
	int count;

	count = loadData(data);     // 여러 명의 이름, 신장, 체중 데이터 입력받기
	printf("Loaded %d\n", count);
	for(int i=0; i<count; i++)
		bmiResolve(data[i]);        // 비만도 관리 데이터 완성하기
	printBmiData(data, count);      // 비만도 관리 데이터 출력하기
	return 0;
}

void bmiResolve(struct bmi_struct* sp){
// 파라미터) sp: 신장과 체중이 입력되어 있는 구조체 변수의 포인터
// 수행내용) sp 포인터 내의 신장과 체중을 사용하여 비만도와 비만등급을 계산하여 넣는다.
// 리턴값) 없음
    sp -> bmi = sp -> weight / ((sp->height * 0.01) * (sp->height * 0.01));
    if(sp ->bmi < 18.5) sp -> bmi_level = 0;
    else if(sp->bmi < 23) sp -> bmi_level = 1;
    else if(sp->bmi < 25) sp -> bmi_level = 2;
    else if(sp->bmi < 30) sp -> bmi_level = 3;
    else sp -> bmi_level = 4;
}

int loadData(struct bmi_struct* list[]){
// 파라미터 : 채워야 하는 비만도 관리 데이터용 구조체 포인터 배열(list) 
// 리턴값 : 채워진 구조체 데이터 레코드의 갯수
// 수행내용 : 여러 명의 키와 몸무게의 데이터를 읽어 list 포인터 배열에 각각 메모리를 할당하여 키, 몸무게, 비만도, 비만도등급이 저장된 구조체 데이터가 연결되도록 한 후, 완성한 데이터 갯수를 리턴
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        list[i] = (struct bmi_struct*)malloc(sizeof(struct bmi_struct));
        scanf("%s %d %d", list[i]->name, &list[i]->height, &list[i]->weight);
    }
    return n;
}

void printBmiData(struct bmi_struct* list[], int size){
// 파라미터 : 채워야 하는 비만도 관리 데이터용 구조체 포인터 배열(list), 데이터 개수(size) 
// 리턴값 : 없음
// 수행내용 : list 포인터 배열에 들어있는 각 구조체의 데이터를 출력 형식에 맞추어 화면에 출력함
    for(int i = 0; i < size; i++){
        printf("%s %dcm %dkg %.1f %s\n", list[i]->name, list[i]->height, list[i]->weight, list[i]->bmi, bmi_string[list[i]->bmi_level]);
    }
}