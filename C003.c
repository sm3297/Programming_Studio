/*
Programming Studio C003
기본 코드 : https://replit.com/@kkim0691/C003#main.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// 2층 짜리 생활관에서 학생을 등록하면서 호실을 등록하는 프로그램이다
// 각 층마다 개의 호실이 준비되어 있으며 인 실로 배정된다 층은 남학생용 층은 여학생용이다

int findRoom(int persons[5]); // 5개의 호실 중 빈 베드가 있는 방을 찾아낸다. (리턴값 1~5)
void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20], int wr[10], int wc); // 배정 결과를 출력한다.

int main(){
	char mnames[10][20]; // 남학생명단(최대 10명)
	int mroom[10];		// 남학생명단별 호실 배정 목록
	char wnames[10][20]; // 여학생명단(최대 10명)
	int wroom[10];		// 여학생명단별 호실 배정 목록
	int person[2][5]={0};   // 2개 층별 5개 호실의 배정 인원 수 
	int mcount=0, wcount=0; // 인원 합계 (남, 여)
	int menu;

	srand(time(0));
	printf("===========================================\n");
	printf("생활관 호실 배정 프로그램\n");
	printf("===========================================\n");
	while(1){
		printf("메뉴 : 1.남학생 등록 2.여학생 등록 0.종료 > ");
		scanf("%d", &menu);
		if(menu==0) break;
		else if(menu==1) {
			if(mcount>=10) {
				printf("정원 초과입니다. 등록불가!\n");
				continue;
			}
			printf("학생 이름은? > ");
			scanf("%s", mnames[mcount]);
			int roomno = findRoom(person[0]);
			mroom[mcount] = 100+roomno;
			printf("%s 학생 %d호실 배정되었습니다.\n", mnames[mcount], mroom[mcount]);
			mcount++;
		}
		else if(menu==2) {
			if(wcount>=10) {
				printf("정원 초과입니다. 등록불가!\n");
				continue;
			}
			printf("학생 이름은? > ");
			scanf("%s", wnames[wcount]);
			int roomno = findRoom(person[1]);
			wroom[wcount] = 200+roomno;
			printf("%s 학생 %d호실 배정되었습니다.\n", wnames[wcount], wroom[wcount]);
			wcount++;
		}
	}

	printf("===========================================\n");
	printf("생활관 호실 배정 결과는 다음과 같습니다.\n");
	printf("===========================================\n");
	printReport(mnames, mroom, mcount, wnames, wroom, wcount);

	return 0;
}

int findRoom(int persons[5]){
// 이 곳에 생각 정리와 코드 구현
    /*
    1. for문으로 랜덤함수 사용하여 1~5까지의 호실번호(room_num)를 생성한다.
        1-1. 만약, room_num에 해당하는 호실의 베드가 2개보다 작으면,
            1-1-1. 해당 호실의 베드수를 1증가시킨다.
            1-1-2. 해당 (room_num)를 리턴한다.
        1-2. 만약, room_num에 해당하는 호실의 베드가 2개 이상이면,
            1-2-3. 1번으로 돌아간다.(continue 이용)
    */
    int room_num = 0;
    for(int i=0; i<5; i++){
        room_num = rand()%5+1;
        if(persons[room_num-1]<2){
            persons[room_num-1]++;
            return room_num;
        }
        else{
            continue;
        }
    }
    return room_num;
}

void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20], int wr[10], int wc){
// 이 곳에 생각 정리와 코드 구현

    /*
    1. 남학생 명단 mc(남학생 총 입력 수) 출력 
        1-1. for 문으로 0번부터 mc(남학생 총 입력 수)까지 반복한다.
        1-2. mn(남학생명단 배열)과 mr(남학생 호실배정 배열)을 출력한다.
        예시) 1) James [104호]

    2. 한줄 ENTER

    3. 여학생 명단 wc(여학생 총 입력 수) 출력
        2-1. for 문으로 0번부터 wc(여학생 총 입력 수)까지 반복한다.
        2-2. wn(여학생명단 배열)과 wr(여학생 호실배정 배열)을 출력한다.
        예시) 1) Mary [204호]
    
    4. 한줄 ENTER

    5. 호실별 배정 명단 출력
        5-1. for 문으로 i=0 부터 2미만까지 (1층-2층) 반복한다.
        5-2. for 문으로 j=0 부터 5까지 (5개)의 호실 반복한다.
            5-2-1.
                우선, 호실만 먼저 출력한다.(101호 :) (남학생 호실 5개,여학생 호실 5개) 즉, 총 10개의 호실 출력하게 된다.
                먼저 count 변수를 선언하고, i가 0이면 count에 mc를, i가 1이면 count에 wc를 저장한다.
                for 문으로 k=0 부터 count미만까지 (남학생 mc, 여학생 wc) 반복한다.
                    만약에, 남자층이고 && 100+j+1호(0부터 시작하기때문에 +1)랑 해당 남자 호실(mr[k])이랑 같을 경우, 
                        해당하는 호의 남자 이름 출력
                    그렇지 않고, 여자층이고 && 200+j+1호(0부터 시작하기때문에 +1)랑 해당 여자 호실(wr[k])이랑 같을 경우,
                        해당하는 호의 여자 이름 출력
                    그외에 (남자층 X, 여자층 X, 호실이 서로 다를경우) -->  해당하는 호의 배정된 인원 0명이면, 다음 으로 넘어감
                        continue
                    한줄 ENTER  
                    예시) 101호 : Tom David
    */

    printf("남학생 명단 (%d명)\n", mc);
    for(int i=0; i<mc; i++){
        printf("%d. %s [%d호]\n", i+1, mn[i], mr[i]);
    }
    
    printf("\n");

    printf("여학생 명단 (%d명)\n", wc);
    for(int i=0; i<wc; i++){
        printf("%d. %s [%d호]\n", i+1, wn[i], wr[i]);
    }
    
    printf("\n");

    printf("호실별 배정 명단\n");

    int count; // mc 또는 wc의 값을 저장할 변수
    for(int i=0; i<2; i++){
        for(int j=0; j<5; j++){
            printf("%d0%d호 : ",i+1, j+1);
            if(i==0) count = mc;
            else count = wc;  
            for(int k=0; k<count; k++){
                if(i==0 && 100+j+1 == mr[k]) 
                    printf("%s ", mn[k]);
                else if(i==1 && 200+j+1 == wr[k]) 
                    printf("%s ", wn[k]);
                else 
                    continue;
            }
            printf("\n");
        }
    }
}