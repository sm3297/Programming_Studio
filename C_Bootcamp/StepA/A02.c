#include <stdio.h>

/*
신장(cm단위)과 체중(kg단위)를 입력받은 후, 비만도(BMI)를 계산하여 출력하라.
비만도 수치 = 체중(kg) / (신장(m)의 제곱) 으로 계산한다.
단, 비만 여부판정 기준은 비만도 수치가 25 이상인 경우에 “Overweight”, 그 외의 경우에 “Normal” 이라고 판단한다.
*/

int main() {
  int height, weight; // 신장(cm), 체중(kg)
  float bmi;          // 비만도 수치

  scanf("%d %d", &height, &weight);
  bmi = weight / ((height * 0.01) * (height * 0.01));

  if (bmi >= 25)
    printf("%.1f Overweight", bmi);
  else
    printf("%.1f Normal", bmi);

  return 0;
}