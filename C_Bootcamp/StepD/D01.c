#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
입력: 첫째 줄에 입력할 영화 개수, 다음 줄부터 3줄 단위로 영화 제목 / 영화 소개글 / 개봉년도 쟝르 상영시간(분) 관객수
출력: 영화목록 (아래 출력 참고)
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

int main(){
	MOVIE* list[10];
	int count;
	char title[100], desc[255], genre[50];
	int year, playtime, viewers;
	
	scanf("%d", &count);
	for(int i=0; i<count; i++){
		getchar();
		fgets(title, 100, stdin);
		fgets(desc, 255, stdin);
		scanf("%d %s %d %d", &year, genre, &playtime, &viewers);
		list[i] = (MOVIE*) malloc(sizeof(MOVIE));

	// Your code here!
	// - 영화 정보를 입력받아 구조체에 저장한다.
	// - 영화 정보를 출력한다.
	// - 쟝르 이름을 인덱스로 변환한다.
	// - 메모리를 해제한다.
		strcpy(list[i]->title, title);
		strcpy(list[i]->description, desc);
		list[i]->year = year;
		list[i]->genre = indexGenre(genre);
		list[i]->playtime = playtime;
		list[i]->viewers = viewers;
	}

	for(int i=0; i<count; i++){
		printf("%d) ", i+1);
		printMovie(list[i]);
		printf("\n");
	}
	
	return 0;
}

void printMovie(MOVIE* p){
    // 특정 영화 정보를 출력한다.
    // - 파라미터 : 영화정보 구조체 포인터
    // - 리턴값 : 없음
	printf("%s [%d, %s, %d min, %d viewers]", p->title, p->year, genre_name[p->genre], p->playtime, p->viewers);


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