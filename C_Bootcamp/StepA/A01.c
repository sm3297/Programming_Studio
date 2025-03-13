#include <stdio.h>

/*
신장(cm단위)과 체중(kg단위)를 입력받은 후, 비만도(BMI)를 계산하여 출력하라.
비만도 수치 = 체중(kg) / (신장(m)의 제곱) 으로 계산한다.
*/

int main() {
  int height, weight; // 신장(cm), 체중(kg)
  float bmi;          // 비만도 수치

  scanf("%d %d", &height, &weight);
  bmi = weight / ((height * 0.01) * (height * 0.01));

  printf("%.1f", bmi);

  return 0;
}