#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int x = 0, y = 0;
int xx = 0, yy = 0;
int di = 1;
int dd = 0, df = 0;
int ii = 0, jj = 0, kk=0;
char seperator = ' ';
// ii �迭�� ���� ��
// jj �迭�� �÷��� �� ĳ���� ���� + \n +\0 �̷��� �ؼ� �÷��� �� + 2 ���� ��

int main(void)
{
	FILE* fp;

	char st[100];
	printf("������ ������ ������ �ּ��� 1: �ſ콬�� 2: ���� 3:����� 4:�ſ����� 5: ����\n");

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
			printf("���� ������ ���� �ʾƼ� ���� �˴ϴ�.");
			return 0;
	}

	if (fp == NULL)
	{
		printf("������ ������ �����ϴ�. \n");
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
					// �к��ڴ� �����̽� ���� ' '
				}
				else {
					jj++;
				}
				kk++;
			}
		}
		ii++;
//		printf("%s", st);
	}//while �� 

	printf("������ �ټ� %d, ������ �� %d ������ char �� %d", ii, jj, kk);
	printf("���� �ν� �Ǿ����� Ȯ�� \n");
  
	xx = jj-2; // ������ �� �÷��� �� - ���๮�� (\n) - �ι���(\0) �׷��� jj -2 ����
	yy = ii-1; // ���� �� �迭�� 0 ���� ���۵����� 

	char** m = (char*)malloc(sizeof(char*) * ii);
	for (int i = 0; i < ii; i++)
	{
		m[i] = malloc(sizeof(char) * (jj+2));
	}
	int i = 0, k = 0;
	
	fseek(fp, 0, SEEK_SET);

	char tst[50];  //�ӽ÷� ���� �迭 ����  ���ڿ��� �������� �����ڸ� �����ϰ� �ٽ� �����ϴ� �ӽ� �迭

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
				// �к��ڴ� �����̽� ���� ' '
			}
			else {
				tst[k] = st[j];
				k++;
			}
		}
		tst[k + 1] = NULL ;
		i++;
		strcpy(m[ii - i], tst); // ���ڿ� ī��
//		printf("%s", m[ii - i]);

		k = 0;
	} //while ��

	printf("****************************************\n");
	for (int i = ii - 1 ; i >= 0; i--) {
		for (int j = 0; j < jj; j++) {
			printf(" %c", m[i][j]);
		}
	}
	printf("****************************************\n");

	int dr;
	printf("�̷�ã�� ���α׷��� �����մϴ�. \n");
	printf("�̵���ġ�� �Է��ϼ��� ��� �Ǵ� ���������� �� ��ġ���� �̵��մϴ�. \n");
	printf("������ġ �������� ����� 0 \n");
	printf("�����ġ �������� ����� 1 (�� : 0) \n");
	scanf("%d", &dd);

	int flag = 1;

	printf("****************************************\n");
	for (int i = ii - 1; i >= 0; i--) {
		for (int j = 0; j < jj; j++) {
			if (x == j && y == i) {
				if (df == 0) printf(" ��");
				if (df == 1) printf(" ��");
				if (df == 2) printf(" ��");
				if (df == 3) printf(" ��");
			}
			else {
				printf(" %c", m[i][j]);
			}
		}
	}
	printf("****************************************\n");

	while (flag)
	{
		printf("�̵���ġ�� �Է��ϼ��� ( ����: 0 ������: 1 ����: 2  ����:3  ����: 5 ) ==>  \n");
		scanf("%d", &dr);
		system("cls");

		printf("Ű�Է��� ������ ��ġ�� x = %d, y = %d �̰� ����ġ�� ���� %c \n", x, y, m[y][x]);
		if (dr == 5) break;

		if (dd) dr = (df + dr) % 4;
		//��� ��ġ ����

		switch (dr)
		{
			char mm;
		case 0:

			if (y == yy) {
				printf("�ֻ���Դϴ� �ö󰥰��� �����ϴ�\n"); break;
			}
			printf("���� ���� \n");
			mm = m[y + 1][x];
			switch (mm)
			{
			case 'o':
				y++;
				break;
			case 'x':
				printf("************ ������ �����ϼ� �����ϴ�. ************\n");
				break;
			case 'S':
				y++;
				printf("������� ��ġ �Ͽ����ϴ� \n");
				break;
			case 'F':
				printf("������� ���� �Ͽ����ϴ� \n");
				flag = 0;
			default:
				break;
			}
			break;

		case 1:
			printf("���� ������ \n");
			if (x == xx) {
				printf("���� ��ġ�� ���� �����ʿ� �ֽ��ϴ�. \n");  
				break; 
			}

			mm = m[y][x+1];
			switch (mm)
			{
			case 'o':
				x++;
				break;
			case 'x':
				printf("************ ������ �����ϼ� �����ϴ�. ************\n");
				break;
			case 'S':
				x++;
				printf("������� ��ġ �Ͽ����ϴ� \n");
				break;
			case 'F':
				printf("������� ���� �Ͽ����ϴ� \n");
				flag = 0;
			default:
				break;
			}
			break;


		case 2:
			printf("���� ���� \n");
			if (y == 0) { printf("���� ��ġ�� ���� �ٴڿ� �ֽ��ϴ�. \n");  break; }

			mm = m[y - 1][x];
			switch (mm)
			{
			case 'o':
				y--;
				break;
			case 'x':
				printf("************ ������ �����ϼ� �����ϴ�. ************\n");
				break;
			case 'S':
				y--;
				printf("������� ��ġ �Ͽ����ϴ� \n");
				break;
			case 'F':
				printf("������� ���� �Ͽ����ϴ� \n");
				flag = 0;
			default:
				break;
			}

		case 3:
			printf("���� ���� \n");
			if (x == 0) { printf("���� ��ġ�� ���� ���ʿ� �ֽ��ϴ�. \n");  break; }
			mm = m[y][x - 1];


			switch (mm)
			{
			case 'o':
				x--;
				break;
			case 'x':
				printf("************ ������ �����ϼ� �����ϴ�. ************\n");
				break;
			case 'S':
				x--;
				printf("������� ��ġ �Ͽ����ϴ� \n");
				break;
			case 'F':
				printf("������� ���� �Ͽ����ϴ� \n");
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
					if (df == 0) printf(" ��");
					if (df == 1) printf(" ��");
					if (df == 2) printf(" ��");
					if (df == 3) printf(" ��");
				}
				else {
					printf(" %c", m[i][j]);
				}
			}
		}
		printf("****************************************\n");
		printf("Ű�Է��� ������ ��ġ�� x = %d, y = %d �̰� ����ġ�� ���� %c \n", x, y, m[y][x]);
	}


	printf("\n***************************  end  *******************************\n");
	fclose(fp);

	for (int i = 0; i < ii; i++)
	{
		free(m[i]);
	}
	free(m);

	return 0;
} // main �� ��