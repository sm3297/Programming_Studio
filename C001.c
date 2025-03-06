#include <stdio.h>

int main(){

    int size; // 크기
    int stars, blank1, blank2; // , 1 , 2 별의 갯수 빈칸 의 갯수 빈칸 의 갯수
    int i, j; // 반복문을 위한 변수 

    scanf("%d", &size);
    stars = 1;
    blank1 = size*2 - 2;
    int blanks = 0;
    for(int i=0; i<size; i++){
        for(int j=0; j<blanks; j++) printf(" ");
        for(int j=0; j<stars; j++) printf("*");
        for(int j=0; j<blank1; j++) printf(" ");
        for(int j=0; j<stars; j++) printf("*");
        printf("\n");
        blanks ++;
        blank1 -= 2;
    }

    for(int i=0; i<size; i++){
        stars = size*2;
        for(int j=0; j<stars; j++) printf("*");
        printf("\n");
    }
    
    stars = size*2;
    blank2 = 0;
    for(int i=0; i<size; i++){
        for(int j=0; j<blank2; j++) printf(" ");
        for(int j=0; j<stars; j++) printf("*");
        stars -= 2;
        blank2 ++;
        printf("\n");
    }

    stars = size*2;
    for(int j=0; j<stars; j++) printf("*");
    printf("\n");

    return 0;
}
