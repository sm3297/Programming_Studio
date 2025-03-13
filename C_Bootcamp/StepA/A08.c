#include <stdio.h>

/*
수정전
입력: 없음 (A08.txt 내용을 읽음, 10명에 대해 매 줄 마다 2개의 정수 포함 - 신장(cm단위)과 체중(kg단위)
출력: 첫 줄에는 비만인 사람의 순서, 두번째 줄에는 총 비만인 사람 수

수정후
입력: 첫 줄에 인원 수, 두번째 줄부터 인원수 만큼 2개의 정수 - 신장(cm단위)과 체중(kg단위)
출력: 비만인 사람의 수만큼 매줄마다 순서와 비만등급 문자열
*/

void makeDataFile();
int bmiLevel(int height, int weight);

int main(){
	int height[10], weight[10]; // 10명의 신장(cm), 체중(kg)
	int bmi_level[10]; // 10명의 비만등급(0~4)
	int count=0; // 비만인 사람의 숫자
	//makeDataFile();
	int all = 0;	// 총 인원
	char bmi_string[5][20] = {"Underweight","Normal weight","Overweight","Mild obesity","Severe obesity"};

	// Your code here.
    scanf("%d", &all);
    for(int i=0; i<all; i++){
        scanf("%d %d", &height[i], &weight[i]);
        bmi_level[i] = bmiLevel(height[i], weight[i]);
        if(bmi_level[i] >= 3)
            count++;
    }
    for(int i=0; i<all; i++){
        if(bmi_level[i] >= 3)
            printf("%d %s\n", i+1, bmi_string[bmi_level[i]]);
    }

	// 수정전
    // FILE *fp = fopen("A08.txt", "r");
    // for(int i=0; i<10; i++){
    //     fscanf(fp, "%d %d", &height[i], &weight[i]);
    //     bmi_level[i] = bmiLevel(height[i], weight[i]);
    //     if(bmi_level[i] >= 3)
    //         count++;
    // }
    // fclose(fp);
    // for(int i=0; i<10; i++){
    //     if(bmi_level[i] >= 3)
    //         printf("%d ", i+1);
    // }
    // printf("\n%d", count);

	return 0;
}
/*
void makeDataFile(){
	char str[] = "165 56\n\
176 90\n\
187 60\n\
155 47\n\
170 75\n\
173 80\n\
165 50\n\
182 73\n\
158 48\n\
170 66";
	FILE* fp = fopen("A08.txt", "w");
	fprintf(fp, "%s", str);
	fclose(fp);
}
*/

int bmiLevel(int height, int weight){
    float bmi = weight / ((height * 0.01) * (height * 0.01));
    if(bmi < 18.5) return 0;
    else if(bmi < 23) return 1;
    else if(bmi < 25) return 2;
    else if(bmi < 30) return 3;
    else return 4;
}