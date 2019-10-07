#include<stdio.h>
#include<stdlib.h>

#define MAX 10
#define WHITE 1
#define BLACK 2
#define PAN 0
void makepan();
bool checkstone();
void yesno();
int point_x;
int point_y;
int baducpan[MAX][MAX];
int countblack=0;
int countwhite=0;
int main()
{
	for (int i = 0; i < 100; i++)
	{
		printf_s("�浹�� ��ǥ�� �Է��ϼ��� \n");
	scanf_s("%d %d", &point_x, &point_y);
	yesno();
	baducpan[point_x-1][point_y-1] = BLACK;
	makepan();
	countblack++;
	printf_s("�浹 : %d �鵹 : %d\n", countblack, countwhite);
	printf_s("�鵹�� ��ǥ�� �Է��ϼ���");
	scanf_s("%d %d", &point_x, &point_y);
	yesno();
	baducpan[point_x-1][point_y-1] = WHITE;
	makepan();
	countwhite++;
	printf_s("�浹 : %d �鵹 : %d\n", countblack, countwhite);
	}
}

void yesno()
{


	while (checkstone())
	{

		printf_s("�̹��ְų� �߸��� ��ǥ�Դϴ� \n");
		printf_s("�浹�� ��ǥ�� �Է��ϼ��� \n");
		rewind(stdin);
		scanf_s("%d %d", &point_x, &point_y);

	}
}
bool checkstone()
{
	if (baducpan[point_x - 1][point_y - 1] == WHITE || baducpan[point_x - 1][point_y - 1] == BLACK)
		return true;
	else if (point_x < 0 || point_y < 0)
		return true;
	else if (point_x > 10 || point_y > 10)
		return true;
	else if (point_x == 0 && point_y==0)
		return true;
	else
		return false;
}
void makepan()
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j <MAX; j++)
		{
			if (baducpan[i][j] == WHITE)
			{
				printf_s(" �� ");
			}
			else if (baducpan[i][j] == BLACK)
			{
				printf_s(" �� ");
			}
			else printf_s(" + ");
		}
		printf_s("\n");
	}
}