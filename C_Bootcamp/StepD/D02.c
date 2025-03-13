#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
입력: 첫째 줄에 입력할 영화 개수, 다음 줄부터 3줄 단위로 영화 제목 / 영화 소개글 / 개봉년도 쟝르 상영시간(분) 관객수
출력: 영화목록, 쟝르별 영화 개수, 상영시간이 가장 긴 영화, 관객 수가 가장 많은 영화 (아래 출력 참고)
*/

typedef struct st_movie{
	char title[100];
	int year, genre, playtime, viewers;
	char description[255];
} MOVIE;

const char* genre_name[] = {
	"Sci-Fi",
	"Thriller",
	"Action",
	"Romance",
	"Musical",
	"Drama",
	"Animation",
	"War"
};


void printMovie(MOVIE* p);
int indexGenre(char* name);
int loadRecords(MOVIE* list[]);
void printReport(MOVIE* list[], int size);
void printGenreCount(MOVIE* list[], int size);
int maxViewers(MOVIE* list[], int size);
int maxPlaytime(MOVIE* list[], int size);


int main() {
	MOVIE* mlist[50];
	int count;

	count = loadRecords(mlist);	
    printf("%d records loaded.\n",count);
	for(int i=0; i<count; i++){
		printf("%d) ", i+1);
		printMovie(mlist[i]);
	}
	printReport(mlist, count);
	return 0;
}

void printMovie(MOVIE* p){
    // 특정 영화 정보를 출력한다.
    // - 파라미터 : 영화정보 구조체 포인터
    // - 리턴값 : 없음
	printf("%s [%d, %s, %d min, %d viewers]\n", p->title, p->year, genre_name[p->genre], p->playtime, p->viewers);

}

int indexGenre(char* name){
    // 쟝르 이름에 해당하는 인덱스 값을 찾는다.
    // - 파라미터 : 쟝르이름
    // - 리턴값 : 해당 쟝르의 인덱스 값
	if(strcmp(name, "Sci-Fi") == 0) return 0;
	else if(strcmp(name, "Thriller") == 0) return 1;
	else if(strcmp(name, "Action") == 0) return 2;
	else if(strcmp(name, "Romance") == 0) return 3;
	else if(strcmp(name, "Musical") == 0) return 4;
	else if(strcmp(name, "Drama") == 0) return 5;
	else if(strcmp(name, "Animation") == 0) return 6;
	else if(strcmp(name, "War") == 0) return 7;
	else return -1;

}

int loadRecords(MOVIE* list[]){
    // 영화 개수 및 그만큼의 영화 정보를 입력받아 목록에 추가한다.
    // - 파라미터 : 목록 포인터 배열
    // - 리턴값 : 읽어온 목록 수
    // - 주의사항 : 메모리 할당은 이 함수에서 진행한다.
    int count = 0;
    char title[100], desc[255], genre[50];
    int year, playtime, viewers;

    scanf("%d", &count);

    for(int i=0; i<count; i++){
        getchar();
        fgets(title, 100, stdin);
        fgets(desc, 255, stdin);
        scanf("%d %s %d %d", &year, genre, &playtime, &viewers);
        list[i] = (MOVIE*) malloc(sizeof(MOVIE));

        strcpy(list[i]->title, title);
        strcpy(list[i]->description, desc);
        list[i]->year = year;
        list[i]->genre = indexGenre(genre);
        list[i]->playtime = playtime;
        list[i]->viewers = viewers;
    }

    return count;

}

void printGenreCount(MOVIE* list[], int size){
    // 영화 전체목록에서 쟝르별로 영화의 개수를 세어 출력한다.
    // - 파라미터 : 목록 포인터 배열, 목록크기
    // - 리턴값 : 없음
    
    int count[8] = {0};
    for(int i=0; i<size; i++){
        count[list[i]->genre]++;
    }

    printf("\n1. Number of movies by genre\n");

    for(int i=0; i<8; i++){
        printf("[%d] %-11s %d movies\n", i+1, genre_name[i], count[i]);   
    }

}

void printReport(MOVIE* list[], int size){
    // 쟝르별 영화 개수, 상영시간이 가장 긴 영화, 관객 수가 가장 많은 영화 정보를 출력한다.
    // - 파라미터 : 목록 포인터 배열, 목록크기
    // - 리턴값 : 없음
    // - 주의사항 : 이 함수에서 printGenreCount(), maxViewers(), maxPlaytime() 함수를 사용한다.
    printGenreCount(list, size);


    printf("\n2. Longest\n");
    printMovie(list[maxPlaytime(list, size)]);
    printf("%s",list[maxPlaytime(list, size)]->description);


    printf("\n");

    printf("3. Most popular\n");
    printMovie(list[maxViewers(list, size)]);
    printf("%s",list[maxViewers(list, size)]->description);

    printf("\n");
}



int maxPlaytime(MOVIE* list[], int size){
    // 영화 전체목록에서 상영시간이 가장 긴 영화의 인덱스를 찾는다. (완성코드 제공)
    // - 파라미터 : 목록 포인터 배열, 목록크기
    // - 리턴값 : 인덱스(0~size-1)
    int max = 0;
    for(int i=1; i<size; i++){
        if(list[i]->playtime > list[max]->playtime){
            max = i;
        }
    }
    return max;

}

int maxViewers(MOVIE* list[], int size){
    // 영화 전체목록에서 관객수가 가장 많은 영화의 인덱스를 찾는다.
    // - 파라미터 : 목록 포인터 배열, 목록크기
    // - 리턴값 : 인덱스(0~size-1)
    int max = 0;
    for(int i=1; i<size; i++){
        if(list[i]->viewers > list[max]->viewers){
            max = i;
        }
    }
    return max;

}