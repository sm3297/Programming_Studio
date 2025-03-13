#include <stdio.h>

/*
신장(cm단위)과 체중(kg단위)를 입력받은 후, 비만도(BMI)를 계산하여 출력하라.
비만도 수치 = 체중(kg) / (신장(m)의 제곱) 으로 계산한다.

입력: 10줄에 걸쳐 2개의 정수 - 신장(cm단위)과 체중(kg단위)
출력: 첫 줄에는 비만인 사람의 순서, 두번째 줄에는 총 비만인 사람 수
*/
int bmiLevel(int height, int weight);

int main(){
    int height[10], weight[10]; // 10명의 신장(cm), 체중(kg)
    int bmi_level[10]; // 10명의 비만등급(0~4)
    int count = 0; // 비만인 사람의 숫자


    for(int i = 0; i < 10; i++){
        scanf("%d %d", &height[i], &weight[i]);
        bmi_level[i] = bmiLevel(height[i], weight[i]);
    }
    for(int i = 0; i < 10; i++){
        if(bmi_level[i] >= 2){
            printf("%-2d ", i + 1);
            count++;
        }
    }

    printf("\n%d",count);
    
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