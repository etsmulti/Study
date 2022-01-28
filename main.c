#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int x = 0, y = 0;
int xx = 0, yy = 0;
int di = 1;
int dd = 0, df = 0;
int ii = 0, jj = 0, kk=0;
char seperator = ' ';
// ii 배열의 열수 수
// jj 배열의 컬럼의 수 캐릭터 숫자 + \n +\0 이렇게 해서 컬럼의 수 + 2 개가 됨

int main(void)
{
	FILE* fp;

	char st[100];
	printf("게임의 수준을 선택해 주세요 1: 매우쉬움 2: 쉬움 3:어려움 4:매우어려움 5: 종료\n");

	int level = '0';

	scanf("%d", &level);

	switch (level)
	{
		case 1:
			fp = fopen("miro1.txt", "r");
			break;
		case 2:
			fp = fopen("miro2.txt", "r");
			break;
		case 3:
			fp = fopen("miro3.txt", "r");
			break;
		case 4:
			fp = fopen("miro4.txt", "r");
			break;
		default :
			printf("게임 선택을 하지 않아서 종료 됩니다.");
			return 0;
	}

	if (fp == NULL)
	{
		printf("파일을 읽을수 없습니다. \n");
		return 0;
	}

	fseek(fp, 0, SEEK_SET);
	while(1)
	{
		fgets(st, sizeof(st), fp);
		if (feof(fp)) break;		
		if (ii == 0) {
			for (int i = 0; i < 100; i++)
			{
				if (st[i] == '\n') { jj++; break; }
				if (st[i] == seperator) {
					// 분별자는 스페이스 공백 ' '
				}
				else {
					jj++;
				}
				kk++;
			}
		}
		ii++;
//		printf("%s", st);
	}//while 끝 

	printf("문장의 줄수 %d, 문장의 수 %d 문장의 char 수 %d", ii, jj, kk);
	printf("재대로 인식 되었는지 확인 \n");
  
	xx = jj-2; // 문자의 수 컬럼의 수 - 개행문자 (\n) - 널문자(\0) 그래서 jj -2 가됨
	yy = ii-1; // 열의 수 배열이 0 부터 시작됨으로 

	char** m = (char*)malloc(sizeof(char*) * ii);
	for (int i = 0; i < ii; i++)
	{
		m[i] = malloc(sizeof(char) * (jj+2));
	}
	int i = 0, k = 0;
	
	fseek(fp, 0, SEEK_SET);

	char tst[50];  //임시로 받을 배열 설정  문자열을 받은다음 구분자를 제거하고 다시 저장하는 임시 배열

	while (1)
	{
		fgets(st, sizeof(st), fp);
		if (feof(fp))
		{
			break;
		} 
		for (int j = 0; j <= kk; j++)
		{
			if (st[j] == '\n') {
				tst[k] = '\n';
			//	tst[k + 1] = st[j + 1];
				break;
			}
			if (st[j] == seperator) {
				// 분별자는 스페이스 공백 ' '
			}
			else {
				tst[k] = st[j];
				k++;
			}
		}
		tst[k + 1] = NULL ;
		i++;
		strcpy(m[ii - i], tst); // 문자열 카피
//		printf("%s", m[ii - i]);

		k = 0;
	} //while 끝

	printf("****************************************\n");
	for (int i = ii - 1 ; i >= 0; i--) {
		for (int j = 0; j < jj; j++) {
			printf(" %c", m[i][j]);
		}
	}
	printf("****************************************\n");

	int dr;
	printf("미로찾기 프로그램을 시작합니다. \n");
	printf("이동위치를 입력하세요 상대 또는 절대적으로 내 위치에서 이동합니다. \n");
	printf("절대위치 방향으로 진행시 0 \n");
	printf("상대위치 방향으로 진행시 1 (예 : 0) \n");
	scanf("%d", &dd);

	int flag = 1;

	printf("****************************************\n");
	for (int i = ii - 1; i >= 0; i--) {
		for (int j = 0; j < jj; j++) {
			if (x == j && y == i) {
				if (df == 0) printf(" ▲");
				if (df == 1) printf(" ▶");
				if (df == 2) printf(" ▼");
				if (df == 3) printf(" ◀");
			}
			else {
				printf(" %c", m[i][j]);
			}
		}
	}
	printf("****************************************\n");

	while (flag)
	{
		printf("이동위치를 입력하세요 ( 직진: 0 오른쪽: 1 후진: 2  왼쪽:3  종료: 5 ) ==>  \n");
		scanf("%d", &dr);
		system("cls");

		printf("키입력전 현재의 위치는 x = %d, y = %d 이고 현위치의 값은 %c \n", x, y, m[y][x]);
		if (dr == 5) break;

		if (dd) dr = (df + dr) % 4;
		//상대 위치 결정

		switch (dr)
		{
			char mm;
		case 0:

			if (y == yy) {
				printf("최상단입니다 올라갈곳이 없습니다\n"); break;
			}
			printf("고정 위쪽 \n");
			mm = m[y + 1][x];
			switch (mm)
			{
			case 'o':
				y++;
				break;
			case 'x':
				printf("************ 막혀서 움직일수 없습니다. ************\n");
				break;
			case 'S':
				y++;
				printf("출발점에 위치 하였습니다 \n");
				break;
			case 'F':
				printf("결승점에 꼴인 하였습니다 \n");
				flag = 0;
			default:
				break;
			}
			break;

		case 1:
			printf("고정 오른쪽 \n");
			if (x == xx) {
				printf("현재 위치가 가장 오른쪽에 있습니다. \n");  
				break; 
			}

			mm = m[y][x+1];
			switch (mm)
			{
			case 'o':
				x++;
				break;
			case 'x':
				printf("************ 막혀서 움직일수 없습니다. ************\n");
				break;
			case 'S':
				x++;
				printf("출발점에 위치 하였습니다 \n");
				break;
			case 'F':
				printf("결승점에 꼴인 하였습니다 \n");
				flag = 0;
			default:
				break;
			}
			break;


		case 2:
			printf("고정 후진 \n");
			if (y == 0) { printf("현재 위치가 가장 바닥에 있습니다. \n");  break; }

			mm = m[y - 1][x];
			switch (mm)
			{
			case 'o':
				y--;
				break;
			case 'x':
				printf("************ 막혀서 움직일수 없습니다. ************\n");
				break;
			case 'S':
				y--;
				printf("출발점에 위치 하였습니다 \n");
				break;
			case 'F':
				printf("결승점에 꼴인 하였습니다 \n");
				flag = 0;
			default:
				break;
			}

		case 3:
			printf("고정 왼쪽 \n");
			if (x == 0) { printf("현재 위치가 가장 왼쪽에 있습니다. \n");  break; }
			mm = m[y][x - 1];


			switch (mm)
			{
			case 'o':
				x--;
				break;
			case 'x':
				printf("************ 막혀서 움직일수 없습니다. ************\n");
				break;
			case 'S':
				x--;
				printf("출발점에 위치 하였습니다 \n");
				break;
			case 'F':
				printf("결승점에 꼴인 하였습니다 \n");
				flag = 0;
			default:
				break;
			}
			break;

		default:
			break;
		}
		df = dr;
		printf("****************************************\n");
		for (int i = ii - 1; i >= 0; i--) {
			for (int j = 0; j < jj; j++) {
				if (x == j && y == i) {
					if (df == 0) printf(" ▲");
					if (df == 1) printf(" ▶");
					if (df == 2) printf(" ▼");
					if (df == 3) printf(" ◀");
				}
				else {
					printf(" %c", m[i][j]);
				}
			}
		}
		printf("****************************************\n");
		printf("키입력후 현재의 위치는 x = %d, y = %d 이고 현위치의 값은 %c \n", x, y, m[y][x]);
	}


	printf("\n***************************  end  *******************************\n");
	fclose(fp);

	for (int i = 0; i < ii; i++)
	{
		free(m[i]);
	}
	free(m);

	return 0;
} // main 의 끝