#include <stdio.h>

/*
입력: 이름(문자열)과 2개의 정수 - 신장(cm단위)과 체중(kg단위)
출력: 비만도 수치 (소수점 1자리)
*/

struct bmi_struct{
    char name[20];  // 이름 (공백 없이 영어 알파벳으로 구성)
    int height, weight; // 키(cm), 몸무게(kg)
    float bmi; // 비만도
    int bmi_level; // 비만등급 0~4
};

void bmiResolve(struct bmi_struct* sp);

int main(){
    struct bmi_struct data;
    char bmi_string[5][20] = {"Underweight","Normal weight","Overweight","Mild obesity","Severe obesity"};

    scanf("%s %d %d", data.name, &data.height, &data.weight);
    bmiResolve(&data);
    printf("%s, You are %s.\n", data.name, bmi_string[data.bmi_level]);
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



