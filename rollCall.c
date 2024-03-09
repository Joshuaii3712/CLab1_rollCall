/*
Programming Studio C003
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
// 배정인원 리스트를 가져와 빈방을 찾아 배정하고, 배정된 방 번호를 리턴하는 함수이다.
// while 반복문을 이용해 자리가 있는 방을 찾을때까지 5개의 번호를 랜덤으로 뽑는다.
// 자리가 있는 방을 발견할 시 그 방의 인원을 추가하여 배정인원 리스트를 업데이트 한다.
  int rp; // 랜덤으로 배정할 방 번호

  while(1){
    srand(time(0));
    rp = rand()%5;
    if(persons[rp] == 0 || persons[rp] == 1){
      persons[rp]++;
      break;
    }
  }
  return rp+1; // 배정받은 호실 값을 리턴한다.
}

void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20], int wr[10], int wc){
// 메인함수에서 남녀 학생들 각각의 이름, 호실, 숫자를 파라미터로 받아 리턴값 없이 결과만를 출력하는 함수이다.
// 학생의 숫자만큼 그 숫자를 인덱스 삼아 남녀학생 명단을 각 학생별 호실과 함께 출력하도록 구현하였다.
// 또한, 각 호실을 값으로 가지고 있는 배열의 인덱스를 for반복문으로 찾아 배정된 학생의 이름을 보여주는 호실별 배정 명단을 출력하도록 하였다.
  int i, j; //반복문용 함수
  
  printf("남학생 명단 (%d명)\n", mc);
  for(i=0;i<mc;i++){
    printf("%d. %s [%d호]\n", i+1, mn[i], mr[i]);
  } // for 반복문을 이용하여 남학생의 숫자, 이름, 그리고 방 번호를 출력한다.

  printf("\n여학생 명단 (%d명)\n", wc);
  for(i=0;i<wc;i++){
    printf("%d. %s [%d호]\n", i+1, wn[i], wr[i]);
  } // for 반복문을 이용하여 여학생의 숫자, 이름, 그리고 방 번호를 출력한다.

  printf("\n호실별 배정 명단");
  for(i=0;i<5;i++){
    printf("\n%d호 : ", i+101);
    for(j=0;j<10;j++){
      if(mr[j] == i+101){
        printf("%s ", mn[j]);
      }
    }
  } // for 반복문을 이용하여 1층 5개의 호실별 학생 이름을 찾아 출력한다.

  for(i=0;i<5;i++){
    printf("\n%d호 : ", i+201);
    for(j=0;j<10;j++){
      if(wr[j] == i+201){
        printf("%s ", wn[j]);
      }
    }
  } // for 반복문을 이용하여 2층 5개의 호실별 학생 이름을 찾아 출력한다.

}
