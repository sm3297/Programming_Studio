#include <stdio.h>

/*
신장(cm단위)과 체중(kg단위)를 입력받은 후, 비만도(BMI)를 계산하여 출력하라.
비만도 수치 = 체중(kg) / (신장(m)의 제곱) 으로 계산한다.
입력: 첫 줄에 인원 수, 두번째 줄부터 인원수 만큼 2개의 정수 - 신장(cm단위)과
체중(kg단위) 출력: 비만인 사람의 인원 수
*/

int main() {
  int height, weight; // 신장(cm), 체중(kg)
  float bmi;          // 비만도 수치
  int people;         // 인원수
  int count = 0;      // 비만인 사람의 수
  scanf("%d", &people);

  for (int i = 0; i < people; i++) {
    scanf("%d %d", &height, &weight);
    bmi = weight / ((height * 0.01) * (height * 0.01));
    if (bmi >= 25)
      count++;
  }

  printf("%d", count);

  return 0;
}