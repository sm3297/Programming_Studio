#include <stdio.h>

/*
신장(cm단위)과 체중(kg단위)를 입력받은 후, 비만도(BMI)를 계산하여 출력하라.
비만도 수치 = 체중(kg) / (신장(m)의 제곱) 으로 계산한다.

입력: 2개의 정수 - 신장(cm단위)과 체중(kg단위)
출력: 비만 등급 문자열과 등급 수치(0~4)
*/
int bmiLevel(int height, int weight);

int main(){
    char bmi_string[5][20] = {"Underweight","Normal weight","Overweight","Mild obesity","Severe obesity"};
    int height, weight; // 신장(cm), 체중(kg)
    
    scanf("%d %d", &height, &weight);
    int level = bmiLevel(height, weight);

    printf("%s (%d)", bmi_string[level], level);
    
    return 0;

}

int bmiLevel(int height, int weight){
    float bmi = weight / ((height * 0.01) * (height * 0.01));
    if(bmi < 18.5) return 0;
    else if(bmi < 23) return 1;
    else if(bmi < 25) return 2;
    else if(bmi < 30) return 3;
    else return 4;
}