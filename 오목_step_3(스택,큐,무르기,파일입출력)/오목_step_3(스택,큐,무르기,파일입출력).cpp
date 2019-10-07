#include<stdio.h>
#include<stdlib.h>

#define MAX 19
#define WHITE 1
#define BLACK 2
#define PAN 0

struct  Point
{
	int x;
	int y;
	int stone;
};

Point stack[361];
void makepan();
int point_x;
int point_y;
int baducpan[MAX][MAX];
int top = -1;


int save = -1;
int turn = 2;
//void findstone();
void MakeStone();
void BackStone();

int main()
{
	int a = 0;

	while (1)
	{
		makepan();
		printf("1:좌표 2:무르기메뉴 3:종료 \n");
		scanf_s("%d", &a);
		switch (a)
		{
		case 1:
			MakeStone();
			break;
		case 2:
			BackStone();
			break;
		case 3:
			exit(0);
			break;
		default:
			break;
		}
	}
	return 0;
}
void makepan()
{

	system("cls");
	printf("-------------------------------------------------------\n");
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (baducpan[i][j] == WHITE)
			{
				printf_s(" ●");
			}
			else if (baducpan[i][j] == BLACK)
			{
				printf_s(" ○");
			}
			else printf_s(" + ");
		}
		printf("%d", i);
		printf_s("\n");

	}
	printf(" 0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18\n");
	printf("-------------------------------------------------------\n");
//	findstone();
}/*
void findstone()
{
	int count_1 = 0, count_2 = 0, count_3 = 0, count_4 = 0, count_5 = 0, count_6 = 0;
	int countblock = 0, countwhite = 0;
	int max_white = 0, max_black = 0, a = 0, b = 0, c = 0;
	int white_max[MAX], black_max[MAX];

	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (baducpan[i][j] == BLACK)
			{
				count_1 += 1;
				countblock++;
			}
			else if (baducpan[i][j] == WHITE)
			{
				count_2 += 1;
				countwhite++;
			}
			if (baducpan[j][i] == BLACK)
			{
				count_3 += 1;

			}
			else if (baducpan[j][i] == WHITE)
			{
				count_4 += 1;

			}


		}

		printf("%d행 흑:%d  백:%d  %d열 흑:%d 백 %d\n", i, count_1, count_2, i, count_3, count_4);
		count_1 = 0, count_2 = 0, count_3 = 0, count_4 = 0;
		for (int j = 0; j < MAX; j++)
		{
			if (baducpan[i][j] == BLACK)
			{
				if (baducpan[i][j + 1] == BLACK || baducpan[i][j - 1] == BLACK)
					count_1 += 1;
			}
			else if (baducpan[i][j] == WHITE)
			{
				if (baducpan[i][j + 1] == WHITE || baducpan[i][j - 1] == WHITE)
					count_2 += 1;
			}
			if (baducpan[j][i] == BLACK)
			{
				if (baducpan[j + 1][i] == BLACK || baducpan[j - 1][i] == BLACK)
					count_3 += 1;
			}
			else if (baducpan[j][i] == WHITE)
			{
				if (baducpan[j + 1][i] == WHITE || baducpan[j - 1][i] == WHITE)
					count_4 += 1;
			}
		}
		if (count_1 > count_2)
		{
			printf(" 흑 :%d                ", count_1);
		}
		else if (count_1 < count_2)
		{
			printf(" 백 :%d                ", count_2);
		}
		else if (count_1 == count_2 && count_1 != 0)
		{
			printf("동 :%d                  ", count_2);
		}
		else
		{
			printf("           ");
		}

		if (count_3 > count_4)
		{
			printf(" 흑 :%d\n", count_3);
		}
		else if (count_3 < count_4)
		{
			printf(" 백 :%d\n", count_4);
		}
		else if (count_3 == count_4 && count_3 != 0)
		{
			printf("동 :%d\n", count_3);
		}
		else
		{
			printf("\n");
		}
		black_max[a] = count_1;
		white_max[a] = count_2;
		a++;
		count_1 = 0, count_2 = 0, count_3 = 0, count_4 = 0;
	}
	printf("현재 흑: %d, 백 : %d \n", countblock, countwhite);
	for (int i = 0; i < MAX; i++)
	{
		if (white_max[i] > max_white)
		{
			max_white = white_max[i];
			b = i;
		}
		if (black_max[i] > max_black)
		{
			max_black = black_max[i];
			c = i;
		}
	}

	if (max_white > max_black)
	{
		printf("최고 연속 좌표 백:");
		for (int i = 0; i < MAX; i++)
		{
			if (baducpan[b][i] == WHITE)
			{
				if (baducpan[b][i + 1] == WHITE || baducpan[b][i - 1] == WHITE)
				{
					printf("(%d,%d)", b, i);
				}
			}
		}
		printf("\n");
	}
	else if (max_white < max_black)
	{
		printf("최고 연속 좌표 흑: ");
		for (int i = 0; i < MAX; i++)
		{
			if (baducpan[c][i] == BLACK)
			{
				if (baducpan[c][i + 1] == BLACK || baducpan[c][i - 1] == BLACK)
				{
					printf("(%d,%d)", c, i);
				}
			}
		}
		printf("\n");
	}
	else if (max_white == max_black && max_white != 0)
	{
		printf("동 :%d \n", max_white);
		max_white = 0;
		max_black = 0;
	}
	a = 0;
	printf("정방향 대각선 /모양 \n");
	for (int k = 0; k < 37; k++)
	{
		for (int i = 0; i < MAX; i++)
		{
			for (int j = 0; j < MAX; j++)
			{
				if (i + j == k)
				{
					if (baducpan[i][j] == BLACK)
					{
						if (baducpan[i - 1][j + 1] == BLACK || baducpan[i + 1][j - 1] == BLACK)
							count_5 += 1;
					}

					if (baducpan[i][j] == WHITE)
					{
						if (baducpan[i - 1][j + 1] == WHITE || baducpan[i + 1][j - 1] == WHITE)
							count_6 += 1;
					}
				}
			}
		}
		if (count_5 > count_6)
		{
			printf("흑 %d", count_5);
		}
		else if (count_5 < count_6)
		{
			printf("백 %d", count_6);
		}
		else if (count_5 == count_6 && count_5 != 0)
		{
			printf("동 %d", count_5);
		}
		else
		{

			printf(" %d ", k);
		}

		if (k == 10)
		{
			printf("\n");
		}
		if (k == 20)
		{
			printf("\n");
		}
		if (k == 30)
		{
			printf("\n");
		}
		count_5 = 0;
		count_6 = 0;
	}
	printf("\n");
	printf("역방향 대각선  \n");
	for (int k = 18; k >= -18; k--)
	{
		for (int i = 0; i < MAX; i++)
		{
			for (int j = 0; j < MAX; j++)
			{
				if (i - j == k)
				{
					if (baducpan[i][j] == BLACK)
					{
						if (baducpan[i + 1][j + 1] == BLACK || baducpan[i - 1][j - 1] == BLACK)
							count_5 += 1;
					}

					if (baducpan[i][j] == WHITE)
					{
						if (baducpan[i + 1][j + 1] == WHITE || baducpan[i - 1][j - 1] == WHITE)
							count_6 += 1;
					}
				}
			}
		}
		if (count_5 > count_6)
		{
			printf("흑 %d", count_5);
		}
		else if (count_5 < count_6)
		{
			printf("백 %d", count_6);
		}
		else if (count_5 == count_6 && count_5 != 0)
		{
			printf("동 %d", count_5);
		}
		else
		{

			printf(" %d ", k);
		}

		if (k == -10)
		{
			printf("\n");
		}
		if (k == 0)
		{
			printf("\n");
		}
		if (k == 10)
		{
			printf("\n");
		}
		count_5 = 0;
		count_6 = 0;
	}
	printf("\n");
}*/
void MakeStone()
{

	while (save != 361)
	{

		if (turn % 2 == 0)
		{
			printf_s("흑돌의 좌표를 입력하세요 100 100은 나가기 입니다.\n");
			scanf_s("%d %d", &point_x, &point_y);
			while (1)
			{
				if (point_x == 100 && point_y == 100)
				{
					return;
				}
				if (point_x >= 0 && point_x < 19 && point_y >= 0 && point_y < 19)
				{
					if (baducpan[point_x][point_y] == WHITE || baducpan[point_x][point_y] == BLACK)
					{
						rewind(stdin);
						printf("잘못입력했습니다 \n");
						scanf_s("%d %d", &point_x, &point_y);
					}
					else
					{
						break;
					}
				}
				else
				{
					rewind(stdin);
					printf("잘못입력했습니다 \n");
					scanf_s("%d %d", &point_x, &point_y);
				}
			}

			baducpan[point_x][point_y] = BLACK;
			top++;
			stack[top].x = point_x;
			stack[top].y = point_y;
			stack[top].stone = BLACK;
			save = top;

			turn++;
			makepan();


		}
		else {
			printf_s("백돌의 좌표를 입력하세요 100 100은 나가기입니다.\n");
			scanf_s("%d %d", &point_x, &point_y);
			while (1)
			{
				if (point_x == 100 && point_y == 100)
				{
					return;
				}
				if (point_x > -1 && point_x < 19 && point_y > -1 && point_y < 19)
				{
					if (baducpan[point_x][point_y] == WHITE || baducpan[point_x][point_y] == BLACK)
					{
						rewind(stdin);
						printf("잘못입력했습니다. \n");
						scanf_s("%d %d", &point_x, &point_y);
					}
					else
					{
						break;
					}
				}
				else
				{
					rewind(stdin);
					printf("잘못입력했습니다 \n");
					scanf_s("%d %d", &point_x, &point_y);
				}
			}


			baducpan[point_x][point_y] = WHITE;

			top++;
			stack[top].x = point_x;
			stack[top].y = point_y;
			stack[top].stone = WHITE;
			save = top;
			turn++;


			makepan();

		}
	}
}
void BackStone()
{
	FILE *fw;
	FILE *fr;
	int a = 0;
	while (1)
	{
		printf("1:무르기 2:무르기취소 3:저장 4:불러오기 5:돌아가기\n");
		scanf("%d", &a);
		if (a == 1)
		{
			if (top == -1)
			{
				printf("무를게 없어요 \n");
			}
			else
			{
				baducpan[stack[top].x][stack[top].y] = PAN;
				top--;
				turn--;
				makepan();
			}

		}
		else if (a == 2)
		{
			if (save == top)
			{
				printf("무르기를 취소할게 없어요\n");
			}
			else
			{
				top++;
				baducpan[stack[top].x][stack[top].y] = stack[top].stone;
				turn++;
				makepan();
			}
		}
		else if (a == 3)
		{
			fopen_s(&fw, "one.text", "wt");
			for (int i = 0; i < MAX; i++)
			{
 				for (int j = 0; j < MAX; j++)
				{
					fprintf(fw, " %d", baducpan[i][j]);
				}
				fprintf(fw, "\n");

			}
			fprintf(fw, " %d", turn);
			fprintf(fw, "\n");

			fprintf(fw, " %d", top);
			fprintf(fw, "\n");

			fprintf(fw, " %d", save);
			fprintf(fw, "\n");

			for (int i = 0; i <= save; i++)
			{
				fprintf(fw, " %d", stack[i].x);
				fprintf(fw, " %d", stack[i].y);
				fprintf(fw, " %d", stack[i].stone);
			}
			fclose(fw);

		}
		else if (a == 4)
		{
			fopen_s(&fr, "one.text", "rt");
			for (int i = 0; i < MAX; i++)
			{
				for (int j = 0; j < MAX; j++)
				{
					fscanf(fr, " %d", &baducpan[i][j]);
				}
				fscanf(fr, "\n");

			}
			fscanf(fr, " %d", &turn);
			fscanf(fr, "\n");

			fscanf(fr, " %d", &top);
			fscanf(fr, "\n");

			fscanf(fr, " %d", &save);
			fscanf(fr, "\n");

			for (int i = 0; i <= save; i++)
			{
				fscanf(fr, " %d", &stack[i].x);
				fscanf(fr, " %d", &stack[i].y);
				fscanf(fr, " %d", &stack[i].stone);
			}
			fclose(fr);

			makepan();
		}
		else if (a == 5)
		{
			return;
		}
	}
		
}