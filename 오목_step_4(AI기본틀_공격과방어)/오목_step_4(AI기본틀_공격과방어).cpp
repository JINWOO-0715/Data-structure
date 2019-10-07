#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 19
#define WHITE 1
#define BLACK 2
#define PAN 0

struct Point {
	int x;
	int y;
	int stone;
	int gravity;

};
void makepan();
int point_x;
int point_y;
int baducpan[MAX][MAX];
int top = -1;
Point Gravity[MAX][MAX];
Point stack[361];

int save = -1;
int turn = 2;
void findstone();
void MakeStone();
void BackStone();
void FMstone();
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
	findstone();
}
void findstone()
{
	return;
}
void MakeStone()
{

	while (save != 361)
	{

		if (turn % 2 == 0)
		{
			printf_s("흑돌의 좌표를 입력하세요 100 100 을 입력하면 나가짐\n");
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
						printf("잘못입력했어 \n");
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
					printf("잘못입력했어 \n");
					scanf_s("%d %d", &point_x, &point_y);
				}
			}
			top++;
			baducpan[point_x][point_y] = BLACK;
			Gravity[point_x][point_y].stone = BLACK;
			stack[top].x = point_x;
			stack[top].y = point_y;
			stack[top].stone = BLACK;



			turn++;
			save = top;
			makepan();
			FMstone();


		}
		else {
			printf_s("백돌의 좌표를 입력하세요");
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
						printf("잘못입력했어 \n");
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
					printf("잘못입력했어 \n");
					scanf_s("%d %d", &point_x, &point_y);
				}
			}


			baducpan[point_x][point_y] = WHITE;
			Gravity[point_x][point_y].stone = WHITE;
			top++;
			stack[top].x = point_x;
			stack[top].y = point_y;
			stack[top].stone = WHITE;

			save = top;
			makepan();
			FMstone();
			turn++;

		}
	}
}
void BackStone()
{
	FILE* fw;
	FILE* fr;
	int a = 0;
	while (1)
	{
		printf("1: 무르기 2: 무르기 취소 3:저장 4: 불러오기");
		scanf_s("%d", &a);
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
				printf("무르기 취소할게 없어요 \n");
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
			fopen_s(&fw, "t.text", "wt");
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
			fopen_s(&fr, "t.text", "rt");
			for (int i = 0; i < MAX; i++)
			{
				for (int j = 0; j < MAX; j++)
				{
					fscanf_s(fr, " %d", &baducpan[i][j]);
				}
				fscanf_s(fr, "\n");
			}

			fscanf_s(fr, " %d", &turn);
			fscanf_s(fr, "\n");

			fscanf_s(fr, " %d", &top);
			fscanf_s(fr, "\n");

			fscanf_s(fr, " %d", &save);
			fscanf_s(fr, "\n");
			for (int i = 0; i <= save; i++)
			{
				fscanf_s(fr, " %d", &stack[i].x);
				fscanf_s(fr, " %d", &stack[i].y);
				fscanf_s(fr, " %d", &stack[i].stone);
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
void FMstone()
{
	int max = 0;
	int min = 0;
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0 ;j<MAX ;j++)
		{
			Gravity[i][j].gravity = 0;
		}
	}
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (Gravity[i][j].stone == BLACK)

			{
				if (i - 1 >-1 && j - 1>-1)
				{
					Gravity[i - 1][j - 1].gravity += 5;//1
					if (Gravity[i - 1][j - 1].stone == BLACK)
					{
						Gravity[i + 1][j + 1].gravity += 55;//9
						if (Gravity[i + 1][j + 1].stone == BLACK)// 3연속 일떄
						{

						
							Gravity[i + 2][j + 2].gravity += 555; 
							printf("(%d,%d),(%d,%d),(%d,%d)연속입니다.\n ", i - 1, j - 1, i, j, i + 1, j + 1);
							if (Gravity[i + 3][j + 3].stone == BLACK) // 4연속일때
							{
								Gravity[i + 2][j + 2].gravity += 55555;
								printf("(%d,%d),(%d,%d),(%d,%d),(%d,%d)연속입니다.\n ", i - 1, j - 1, i, j, i + 1, j + 1,i+3,j+3);
							}

							if (Gravity[i + 2][j + 2].stone == BLACK) // 3:1 4연속일때
							{
								Gravity[i + 3][j + 3].gravity += 55555;
								printf("(%d,%d),(%d,%d),(%d,%d),(%d,%d)연속입니다.\n ", i - 1, j - 1, i, j, i + 1, j + 1, i + 2, j + 2);
							}


						}
						if (Gravity[i + 2][j + 2].stone == BLACK) // 2개 +1개 일때
						{
							Gravity[i + 1][j + 1].gravity += 5555;

							printf("(%d,%d),(%d,%d),(%d,%d)연속입니다.\n ", i - 1, j - 1, i, j, i + 2, j + 2);


						}
					}
				}
				if (i - 1>-1 && j>-1)
				{
					Gravity[i - 1][j].gravity += 5;//2
					if (Gravity[i - 1][j].stone == BLACK)
					{
						Gravity[i + 1][j].gravity += 55;//8
						if (Gravity[i + 1][j].stone == BLACK)
						{
							Gravity[i + 2][j].gravity += 555;
							printf("(%d,%d),(%d,%d),(%d,%d)연속입니다.\n ", i - 1, j , i, j, i + 1, j);
							if (Gravity[i + 2][j].stone == BLACK) // 4연속일때
							{
								Gravity[i + 3][j].gravity += 55555;
								printf("(%d,%d),(%d,%d),(%d,%d),(%d,%d)연속입니다.\n ", i - 1, j , i, j, i + 1, j,i+2,j );
							}
							if (Gravity[i + 3][j].stone == BLACK) // 4연속일때
							{
								Gravity[i + 2][j].gravity += 55555;
								printf("(%d,%d),(%d,%d),(%d,%d),(%d,%d)연속입니다.\n ", i - 1, j, i, j, i + 1, j, i + 3, j);
							}
						}
						if (Gravity[i + 2][j].stone == BLACK)//연속
						{
							Gravity[i + 1][j].gravity += 5555;
							printf("(%d,%d),(%d,%d),(%d,%d)연속입니다.\n ", i - 1, j, i, j, i + 1, j);
						}
					}
				}
				if (i - 1>-1 && j + 1<19)
				{
					Gravity[i - 1][j + 1].gravity += 5;//3
					if (Gravity[i - 1][j + 1].stone == BLACK)
					{
						Gravity[i + 1][j - 1].gravity += 55;//7.
						if (Gravity[i + 1][j - 1].stone == BLACK)
						{
							Gravity[i + 2][j - 2].gravity += 555;
							if (Gravity[i + 2][j - 2].stone == BLACK) // 4연속일때
							{
								Gravity[i + 3][j - 3].gravity += 55555;
								printf("(%d,%d),(%d,%d),(%d,%d),(%d,%d)연속입니다.\n ", i - 1, j+1, i, j, i + 1, j-1, i + 2, j-2);
							}
							if (Gravity[i + 3][j - 3].stone == BLACK) // 4연속일때
							{
								printf("(%d,%d),(%d,%d),(%d,%d),(%d,%d)연속입니다.\n ", i - 1, j + 1, i, j, i + 1, j - 1, i + 3, j - 3);
								Gravity[i + 2][j - 2].gravity += 55555;
							}
						}
						if (Gravity[i + 2][j - 2].stone == BLACK)
						{
							Gravity[i + 1][j - 1].gravity += 5555;
							printf("(%d,%d),(%d,%d),(%d,%d)연속입니다.\n ", i - 1, j + 1, i, j, i + 2, j - 2);
						}

					}
				}
				if (i>-1 && j - 1>-1)
				{
					Gravity[i][j - 1].gravity += 5;//4

					if (Gravity[i][j - 1].stone == BLACK)
					{
						Gravity[i][j + 1].gravity += 55;//6

						if (Gravity[i][j + 1].stone == BLACK)
						{
							Gravity[i][j + 2].gravity;
							if (Gravity[i][j + 2].stone == BLACK) // 4연속일때
							{
								Gravity[i][j + 3].gravity += 55555;
								printf("(%d,%d),(%d,%d),(%d,%d),(%d,%d)연속입니다.\n ", i , j - 1, i, j, i, j+1 , i , j+2 );
							}
							if (Gravity[i][j + 3].stone == BLACK) // 4연속일때
							{
								Gravity[i][j + 2].gravity += 55555;
								printf("(%d,%d),(%d,%d),(%d,%d),(%d,%d)연속입니다.\n ", i, j - 1, i, j, i , j+1, i, j+3);
							}
						}
						if (Gravity[i][j + 2].stone == BLACK)
						{
							Gravity[i][j + 1].gravity += 5555;
							printf("(%d,%d),(%d,%d),(%d,%d)연속입니다.\n ", i, j - 1, i, j,  i, j + 2);
						}
					}
				}
				if (i>-1 && j + 1<19)
				{

					Gravity[i][j + 1].gravity += 5;//6

					if (Gravity[i][j + 1].stone == BLACK)
					{
						Gravity[i][j - 1].gravity += 55;//8
						if (Gravity[i][j - 1].stone == BLACK)
						{
							Gravity[i][j - 2].gravity += 555;
							if (Gravity[i][j - 2].stone == BLACK) // 4연속일때
							{
								Gravity[i][j - 3].gravity += 55555;
								printf("(%d,%d),(%d,%d),(%d,%d),(%d,%d)연속입니다.\n ", i, j + 1, i, j-1, i,j, i, j -2);
							}
							if (Gravity[i][j - 3].stone == BLACK) // 4연속일때
							{
								Gravity[i][j - 2].gravity += 55555;
								printf("(%d,%d),(%d,%d),(%d,%d),(%d,%d)연속입니다.\n ", i, j + 1, i, j - 1, i, j, i, j - 3);
							}
						}
						if (Gravity[i][j - 2].stone == BLACK)
						{
							Gravity[i][j - 1].gravity += 5555;
							printf("(%d,%d),(%d,%d),(%d,%d)연속입니다.\n ", i, j + 1,  i, j, i, j - 2);
						}

					}
				}
				if (i + 1<19 && j - 1>-1)
				{
					Gravity[i + 1][j - 1].gravity += 5;//7.

					if (Gravity[i - 1][j - 1].stone == BLACK)
					{
						Gravity[i - 1][j + 1].gravity += 55;//3

						if (Gravity[i - 1][j + 1].stone == BLACK)
						{
							Gravity[i - 2][j + 2].gravity += 555;
							if (Gravity[i - 2][j + 2].stone == BLACK) // 4연속일때
							{
								Gravity[i - 3][j + 3].gravity += 55555;
								printf("(%d,%d),(%d,%d),(%d,%d),(%d,%d)연속입니다.\n ", i-1, j - 1, i, j , i-1, j+1, i-2, j - 2);
							}
							if (Gravity[i - 3][j + 3].stone == BLACK) // 4연속일때
							{
								Gravity[i - 2][j + 2].gravity += 55555;
								printf("(%d,%d),(%d,%d),(%d,%d),(%d,%d)연속입니다.\n ", i - 1, j - 1, i, j, i - 1, j + 1, i - 2, j - 2);

							}

						}
						if (Gravity[i - 2][j + 2].stone == BLACK)
						{
							Gravity[i - 1][j + 1].gravity += 5555;
							printf("(%d,%d),(%d,%d),(%d,%d)연속입니다.\n ", i - 1, j - 1, i, j,  i - 2, j - 2);
						}
					}
				}
				if (i + 1<19 && j>-1)
				{
					Gravity[i + 1][j].gravity += 5;//8
					if (Gravity[i + 1][j].stone == BLACK)
					{
						Gravity[i - 1][j].gravity += 55;//2
						if (Gravity[i - 1][j].stone == BLACK)
						{
							Gravity[i - 2][j].gravity += 555;
							if (Gravity[i - 2][j].stone == BLACK) // 4연속일때
							{
								Gravity[i - 3][j].gravity += 55555;
								printf("(%d,%d),(%d,%d),(%d,%d),(%d,%d)연속입니다.\n ", i +1, j , i, j, i - 1, j, i - 2, j );

							}
							if (Gravity[i - 3][j].stone == BLACK) // 4연속일때
							{
								Gravity[i - 2][j].gravity += 55555;
								printf("(%d,%d),(%d,%d),(%d,%d),(%d,%d)연속입니다.\n ", i + 1, j, i, j, i - 1, j, i - 3, j);
							}
						}
						if (Gravity[i - 2][j].stone == BLACK)
						{
							Gravity[i - 1][j].gravity += 5555;
							printf("(%d,%d),(%d,%d),(%d,%d),(%d,%d)연속입니다.\n ", i + 1, j, i, j, i - 2, j);
						}
					}

				}
				if (i + 1<19 && j + 1<19)
				{

					Gravity[i + 1][j + 1].gravity += 5;//9
					if (Gravity[i + 1][j + 1].stone == BLACK)
					{
						Gravity[i - 1][j - 1].gravity += 55;//8
						if (Gravity[i - 1][j - 1].stone == BLACK)
						{
							Gravity[i - 2][j - 2].gravity += 555;
							if (Gravity[i - 2][j - 2].stone == BLACK) // 4연속일때
							{
								Gravity[i - 3][j - 3].gravity += 55555;
								printf("(%d,%d),(%d,%d),(%d,%d),(%d,%d)연속입니다.\n ", i + 1, j+1, i, j, i - 1, j-1, i - 2, j-2);

							}
							if (Gravity[i - 3][j - 3].stone == BLACK) // 4연속일때
							{
								Gravity[i - 2][j - 2].gravity += 55555;
								printf("(%d,%d),(%d,%d),(%d,%d),(%d,%d)연속입니다.\n ", i + 1, j + 1, i, j, i - 1, j - 1, i - 3, j - 3);

							}
						}
						if (Gravity[i - 2][j - 2].stone == BLACK)
						{
							Gravity[i - 1][j - 1].gravity += 5555;
							printf("(%d,%d),(%d,%d),(%d,%d)연속입니다.\n ", i + 1, j + 1, i, j,  i - 2, j - 2);
						}
					}
				}

			}
			if (Gravity[i][j].stone == WHITE)

			{
				if (i - 1 >-1 && j - 1>-1)
				{
					Gravity[i - 1][j - 1].gravity -= 5;//1
					if (Gravity[i - 1][j - 1].stone == WHITE)
					{
						Gravity[i + 1][j + 1].gravity -= 55;//9
						if (Gravity[i + 1][j + 1].stone == WHITE)// 3연속 일떄
						{


							Gravity[i + 2][j + 2].gravity -= 555;
							printf("(%d,%d),(%d,%d),(%d,%d)연속입니다.\n ", i - 1, j - 1, i, j, i + 1, j + 1);
							if (Gravity[i + 3][j + 3].stone == WHITE) // 4연속일때
							{
								Gravity[i + 2][j + 2].gravity -= 55555;
								printf("(%d,%d),(%d,%d),(%d,%d),(%d,%d)연속입니다.\n ", i - 1, j - 1, i, j, i + 1, j + 1, i + 3, j + 3);
							}

							if (Gravity[i + 2][j + 2].stone == WHITE) // 3:1 4연속일때
							{
								Gravity[i + 3][j + 3].gravity -= 55555;
								printf("(%d,%d),(%d,%d),(%d,%d),(%d,%d)연속입니다.\n ", i - 1, j - 1, i, j, i + 1, j + 1, i + 2, j + 2);
							}


						}
						if (Gravity[i + 2][j + 2].stone == WHITE) // 2개 +1개 일때
						{
							Gravity[i + 1][j + 1].gravity -= 5555;

							printf("(%d,%d),(%d,%d),(%d,%d)연속입니다.\n ", i - 1, j - 1, i, j, i + 2, j + 2);


						}
					}
				}
				if (i - 1>-1 && j>-1)
				{
					Gravity[i - 1][j].gravity -= 5;//2
					if (Gravity[i - 1][j].stone == WHITE)
					{
						Gravity[i + 1][j].gravity -= 55;//8
						if (Gravity[i + 1][j].stone == WHITE)
						{
							Gravity[i + 2][j].gravity -= 555;
							printf("(%d,%d),(%d,%d),(%d,%d)연속입니다.\n ", i - 1, j, i, j, i + 1, j);
							if (Gravity[i + 2][j].stone == WHITE) // 4연속일때
							{
								Gravity[i + 3][j].gravity -= 55555;
								printf("(%d,%d),(%d,%d),(%d,%d),(%d,%d)연속입니다.\n ", i - 1, j, i, j, i + 1, j, i + 2, j);
							}
							if (Gravity[i + 3][j].stone == WHITE) // 4연속일때
							{
								Gravity[i + 2][j].gravity -= 55555;
								printf("(%d,%d),(%d,%d),(%d,%d),(%d,%d)연속입니다.\n ", i - 1, j, i, j, i + 1, j, i + 3, j);
							}
						}
						if (Gravity[i + 2][j].stone == WHITE)//연속
						{
							Gravity[i + 1][j].gravity -= 5555;
							printf("(%d,%d),(%d,%d),(%d,%d)연속입니다.\n ", i - 1, j, i, j, i + 1, j);
						}
					}
				}
				if (i - 1>-1 && j + 1<19)
				{
					Gravity[i - 1][j + 1].gravity -= 5;//3
					if (Gravity[i - 1][j + 1].stone == WHITE)
					{
						Gravity[i + 1][j - 1].gravity -= 55;//7.
						if (Gravity[i + 1][j - 1].stone == WHITE)
						{
							Gravity[i + 2][j - 2].gravity -= 555;
							if (Gravity[i + 2][j - 2].stone == WHITE) // 4연속일때
							{
								Gravity[i + 3][j - 3].gravity -= 55555;
								printf("(%d,%d),(%d,%d),(%d,%d),(%d,%d)연속입니다.\n ", i - 1, j + 1, i, j, i + 1, j - 1, i + 2, j - 2);
							}
							if (Gravity[i + 3][j - 3].stone == WHITE) // 4연속일때
							{
								printf("(%d,%d),(%d,%d),(%d,%d),(%d,%d)연속입니다.\n ", i - 1, j + 1, i, j, i + 1, j - 1, i + 3, j - 3);
								Gravity[i + 2][j - 2].gravity -= 55555;
							}
						}
						if (Gravity[i + 2][j - 2].stone == WHITE)
						{
							Gravity[i + 1][j - 1].gravity -= 5555;
							printf("(%d,%d),(%d,%d),(%d,%d)연속입니다.\n ", i - 1, j + 1, i, j, i + 2, j - 2);
						}

					}
				}
				if (i>-1 && j - 1>-1)
				{
					Gravity[i][j - 1].gravity -= 5;//4

					if (Gravity[i][j - 1].stone == WHITE)
					{
						Gravity[i][j + 1].gravity -= 55;//6

						if (Gravity[i][j + 1].stone == WHITE)
						{
							Gravity[i][j + 2].gravity;
							if (Gravity[i][j + 2].stone == WHITE) // 4연속일때
							{
								Gravity[i][j + 3].gravity -= 55555;
								printf("(%d,%d),(%d,%d),(%d,%d),(%d,%d)연속입니다.\n ", i, j - 1, i, j, i, j + 1, i, j + 2);
							}
							if (Gravity[i][j + 3].stone == WHITE) // 4연속일때
							{
								Gravity[i][j + 2].gravity -= 55555;
								printf("(%d,%d),(%d,%d),(%d,%d),(%d,%d)연속입니다.\n ", i, j - 1, i, j, i, j + 1, i, j + 3);
							}
						}
						if (Gravity[i][j + 2].stone == WHITE)
						{
							Gravity[i][j + 1].gravity -= 5555;
							printf("(%d,%d),(%d,%d),(%d,%d)연속입니다.\n ", i, j - 1, i, j, i, j + 2);
						}
					}
				}
				if (i>-1 && j + 1<19)
				{

					Gravity[i][j + 1].gravity -= 5;//6

					if (Gravity[i][j + 1].stone == WHITE)
					{
						Gravity[i][j - 1].gravity -= 55;//8
						if (Gravity[i][j - 1].stone == WHITE)
						{
							Gravity[i][j - 2].gravity -= 555;
							if (Gravity[i][j - 2].stone == WHITE) // 4연속일때
							{
								Gravity[i][j - 3].gravity -= 55555;
								printf("(%d,%d),(%d,%d),(%d,%d),(%d,%d)연속입니다.\n ", i, j + 1, i, j - 1, i, j, i, j - 2);
							}
							if (Gravity[i][j - 3].stone == WHITE) // 4연속일때
							{
								Gravity[i][j - 2].gravity -= 55555;
								printf("(%d,%d),(%d,%d),(%d,%d),(%d,%d)연속입니다.\n ", i, j + 1, i, j - 1, i, j, i, j - 3);
							}
						}
						if (Gravity[i][j - 2].stone == WHITE)
						{
							Gravity[i][j - 1].gravity -= 5555;
							printf("(%d,%d),(%d,%d),(%d,%d)연속입니다.\n ", i, j + 1, i, j, i, j - 2);
						}

					}
				}
				if (i + 1<19 && j - 1>-1)
				{
					Gravity[i + 1][j - 1].gravity -= 5;//7.

					if (Gravity[i - 1][j - 1].stone == WHITE)
					{
						Gravity[i - 1][j + 1].gravity -= 55;//3

						if (Gravity[i - 1][j + 1].stone == WHITE)
						{
							Gravity[i - 2][j + 2].gravity -= 555;
							if (Gravity[i - 2][j + 2].stone == WHITE) // 4연속일때
							{
								Gravity[i - 3][j + 3].gravity -= 55555;
								printf("(%d,%d),(%d,%d),(%d,%d),(%d,%d)연속입니다.\n ", i - 1, j - 1, i, j, i - 1, j + 1, i - 2, j - 2);
							}
							if (Gravity[i - 3][j + 3].stone == WHITE) // 4연속일때
							{
								Gravity[i - 2][j + 2].gravity -= 55555;
								printf("(%d,%d),(%d,%d),(%d,%d),(%d,%d)연속입니다.\n ", i - 1, j - 1, i, j, i - 1, j + 1, i - 2, j - 2);

							}

						}
						if (Gravity[i - 2][j + 2].stone == WHITE)
						{
							Gravity[i - 1][j + 1].gravity -= 5555;
							printf("(%d,%d),(%d,%d),(%d,%d)연속입니다.\n ", i - 1, j - 1, i, j, i - 2, j - 2);
						}
					}
				}
				if (i + 1<19 && j>-1)
				{
					Gravity[i + 1][j].gravity -= 5;//8
					if (Gravity[i + 1][j].stone == WHITE)
					{
						Gravity[i - 1][j].gravity -= 55;//2
						if (Gravity[i - 1][j].stone == WHITE)
						{
							Gravity[i - 2][j].gravity -= 555;
							if (Gravity[i - 2][j].stone == WHITE) // 4연속일때
							{
								Gravity[i - 3][j].gravity -= 55555;
								printf("(%d,%d),(%d,%d),(%d,%d),(%d,%d)연속입니다.\n ", i + 1, j, i, j, i - 1, j, i - 2, j);

							}
							if (Gravity[i - 3][j].stone == WHITE) // 4연속일때
							{
								Gravity[i - 2][j].gravity -= 55555;
								printf("(%d,%d),(%d,%d),(%d,%d),(%d,%d)연속입니다.\n ", i + 1, j, i, j, i - 1, j, i - 3, j);
							}
						}
						if (Gravity[i - 2][j].stone == WHITE)
						{
							Gravity[i - 1][j].gravity -= 5555;
							printf("(%d,%d),(%d,%d),(%d,%d),(%d,%d)연속입니다.\n ", i + 1, j, i, j, i - 2, j);
						}
					}

				}
				if (i + 1<19 && j + 1<19)
				{

					Gravity[i + 1][j + 1].gravity -= 5;//9
					if (Gravity[i + 1][j + 1].stone == WHITE)
					{
						Gravity[i - 1][j - 1].gravity -= 55;//8
						if (Gravity[i - 1][j - 1].stone == WHITE)
						{
							Gravity[i - 2][j - 2].gravity -= 555;
							if (Gravity[i - 2][j - 2].stone == WHITE) // 4연속일때
							{
								Gravity[i - 3][j - 3].gravity -= 55555;
								printf("(%d,%d),(%d,%d),(%d,%d),(%d,%d)연속입니다.\n ", i + 1, j + 1, i, j, i - 1, j - 1, i - 2, j - 2);

							}
							if (Gravity[i - 3][j - 3].stone == WHITE) // 4연속일때
							{
								Gravity[i - 2][j - 2].gravity -= 55555;
								printf("(%d,%d),(%d,%d),(%d,%d),(%d,%d)연속입니다.\n ", i + 1, j + 1, i, j, i - 1, j - 1, i - 3, j - 3);

							}
						}
						if (Gravity[i - 2][j - 2].stone == WHITE)
						{
							Gravity[i - 1][j - 1].gravity -= 5555;
							printf("(%d,%d),(%d,%d),(%d,%d)연속입니다.\n ", i + 1, j + 1, i, j, i - 2, j - 2);
						}
					}
				}

			}


		}
	}
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j<MAX; j++)
		{
			if (Gravity[i][j].stone == BLACK || Gravity[i][j].stone == WHITE)
			{
				Gravity[i][j].gravity = 0;
			}
			if (max < Gravity[i][j].gravity)
			{
				max = Gravity[i][j].gravity;
			}
			if (min > Gravity[i][j].gravity)
			{
				min = Gravity[i][j].gravity;
			}
		}
	
	}

	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j<MAX; j++)
		{
			printf("%3d", Gravity[i][j].gravity);
			

				
			
		}
		printf("\n");
	}

	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j<MAX; j++)
		{
			

			if (Gravity[i][j].gravity > 200 && Gravity[i][j].gravity < 999)
			{
				printf("흑의 3공격입니다 (%d,%d)를 막으세요\n",i,j);
			}
			if (Gravity[i][j].gravity > 999 && Gravity[i][j].gravity < 9999)
			{
				printf("흑의 2:1 연결 공격입니다 (%d,%d)를 막으세요\n",i, j);
			}
			if (Gravity[i][j].gravity > 8888 && Gravity[i][j].gravity < 88888)
			{
				printf("흑의 4연결 공격입니다 (%d,%d)를 막으세요\n",i, j);
			}

			if (Gravity[i][j].gravity < -200 && Gravity[i][j].gravity > -999)
			{
				printf("백의 3공격입니다 (%d,%d)를 막으세요\n", i, j);
			}
			if (Gravity[i][j].gravity < -999 && Gravity[i][j].gravity > -9999)
			{
				printf("백의 2:1 연결 공격입니다 (%d,%d)를 막으세요\n", i, j);
			}
			if (Gravity[i][j].gravity < -8888 && Gravity[i][j].gravity > -88888)
			{
				printf("백의 4연결 공격입니다 (%d,%d)를 막으세요\n", i, j);
			}


		}

	}



}