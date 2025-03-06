#include <stdio.h>

int main(){

    int person[4][3]; // 4 3 개 층별 개 호실의 점호 인원 수
    int sum[3]; // ( , , ) 점호 인원 수 합계 남 여 전체
    float ratio[3]; // ( , , ) 점호 인원 수 비율 남 여 전체
    int i, j; // 반복문을 위한 변수 

    for(i=0; i<sizeof(person[4][3]); i++){
        sum[i] = 0;
        if(i == 0)printf("Check room (Men)\n");
        if(i == 2)printf("Check room (Women)\n");
        for(j=0; j<3; j++){
            printf("Room #%d0%d > ",i+1,j+1);
            scanf("%d", &person[i][j]);

            if(i <= 1) sum[0] += person[i][j];
            else sum[1] += person[i][j];
        }
    }
    sum[2] = sum[0] + sum[1];

    printf("Check Result\n");

    char result_type[3][6] = {"Men", "Women","Total"};
    int total[3] = {24, 24, 48};
     
    for(i=0; i<3; i++){
        ratio[i] = (float)sum[i] / total[i] * 100;
        printf("%s: %d/%d (%.1f%%)\n",result_type[i], sum[i], total[i], ratio[i]);
    }
    return 0;
}