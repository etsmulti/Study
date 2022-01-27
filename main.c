#include <stdio.h>
#include <stdlib.h>

int x = 0, y = 0;
int xx = 8, yy = 8;
int di = 1;
int dd = 0, df = 0;
// 1 진행방향이 북쪽
// 2 진행방향이 서쪽
// 3 진행방향이 동쪽
// 4 진행방향이 남쪽

// ToDo 파일의 가로 세로 임의일 경우? 처리

int main(void)
{
	FILE* fp;
	char str[9][20];
	char m[9][10];

	// miro.txt  입력

	fp = fopen("miro.txt", "r");

	if (fp == NULL)
	{
		printf("파일을 읽을수 없습니다. \n");
		return 0;
	}

	fseek(fp, 0, SEEK_SET);
	int i = 0, k = 0;

	while (1)
	{
		fgets(str[i], sizeof(str), fp);
		if (feof(fp))
		{
			printf("i의 값은 %d  k의 값은 %d \n", i, k);
			break;
		}

		for (int j = 0; j < 20; j++)
		{
			if (str[i][j] == '\n') {
				m[8 - i][k] = '\n';
				k = 0;
				break;
			}

			if (str[i][j] == ' ') {
				// 분별자는 스페이스 공백 ' '
			}
			else {
				m[8 - i][k] = str[i][j];
				k++;
			}
		}
		if (i == 8) {
			m[i][9] = NULL;
		}
		i++;
	}

	fclose(fp);

	for (int i = 8; i >= 0; i--) {
		printf("%c %c %c %c %c %c %c %c %c \n", m[i][0], m[i][1], m[i][2], m[i][3], m[i][4], m[i][5], m[i][6], m[i][7], m[i][8]);
	}

	int dr;
	printf("미로찾기 프로그램을 시작합니다. \n");
	printf("이동위치를 입력하세요 상대 또는 절대적으로 내 위치에서 이동합니다. \n");
	printf("절대위치 방향으로 진행시 0 \n");
	printf("상대위치 방향으로 진행시 1 (예 : 0) \n");
	scanf("%d", &dd);

	while (1)
	{
		printf("이동위치를 입력하세요 ( 직진: 0 오른쪽: 1 후진: 2  왼쪽:3  종료: 5 ) ==>  \n");
		scanf("%d", &dr);
		system("cls");
		printf("키입력전 현재의 위치는 x = %d, y = %d 이고 현위치의 값은 %c \n", x, y, m[x][y]);
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
				return 0;
			default:
				break;
			}
			break;

		case 1:
			printf("고정 오른쪽 \n");
			if (x == xx) { printf("현재 위치가 가장 오른쪽에 있습니다. \n");  break; }

			mm = m[y][x + 1];
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
				return 0;
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
				return 0;
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
				return 0;
			default:
				break;
			}
			break;

		default:
			break;
		}
		df = dr;
		printf("키입력후 현재의 위치는 x = %d, y = %d 이고 현위치의 값은 %c \n", x, y, m[x][y]);
	}

	return 0;
}