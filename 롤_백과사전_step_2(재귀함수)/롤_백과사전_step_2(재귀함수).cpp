#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define MAX 20

int my_strcmp(char * str, char *str2);
int searchcount = 0;
typedef struct _champion
{
	char name[MAX];
	int hp;
	int mp;
	int speed;
	int range;
	int position;
}champion;

char searchchampion[MAX];
void showmenu();
void printall2(champion *p, int count)
{
	printf("순서: %d ", count + 1);
	printf("이름: %s ", p[count].name);
	printf("HP : %d ", p[count].hp);
	printf("MP : %d ", p[count].mp);
	printf("이동속도 : %d ", p[count].speed);
	printf("공격범위 : %d ", p[count].range);
	printf("포지션: ");
	switch (p[count].position)
	{
	case 1:
		printf("탑 \n");
		break;
	case 2:
		printf("정글 \n");
		break;
	case 3:
		printf("미드 \n");
		break;
	case 4:
		printf("원딜 \n");
		break;
	case 5:
		printf("서포터 \n");
		break;

	}


}
void printall(champion *p, int count, int i)
{
	if (count == i)
	{
		return;
	}


	printall2(p, i);
	printall(p, count, i + 1);

}
void findmaxhp(champion *p, int count, int i)
{
	if (count == i)
	{
		return;
	}
	
	
	if (p[0].hp == p[i].hp)
	{
		printall2(p, i);
	}

	findmaxhp(p, count, i + 1);
}
void sorthp(champion *p, int count, int i)
{
	champion temp;
	if (count == i)
	{
		return;
	}
	for (int j = 0; j < count - 1; j++)
	{
		if (p[j].hp < p[j + 1].hp)
		{
			temp = p[j];
			p[j] = p[j + 1];
			p[j + 1] = temp;
		}
	}
	sorthp(p, count, i + 1);

}
void search(champion *p, int count, char *searchchampion, int i)
{
	if (count == i)
	{
		if (searchcount != 1)
		{
			printf("없음");
		}
		return;
	}

	if (my_strcmp(searchchampion, p[i].name) == 0)
	{
		printall2(p, i);
		searchcount = 1;
		return;

	}


	search(p, count, searchchampion, i + 1);
}
void insert(champion *p, int count, int i)
{
	if (i == count)
	{
		return;
	}

	if (p[i].hp == 0)
	{

	a:;
		printf("챔피언 입력");
		scanf_s("%s", p[count - 1].name,80);
		for (int k = 0; k < count - 1; k++)
		{
			if (my_strcmp(p[count - 1].name, p[k].name) == 0)
			{
				printf("이미있다");
				goto a;
			}
		}
		printf("HP 입력");
		scanf_s("%d", &p[count - 1].hp);
		printf("MP 입력");
		scanf_s("%d", &p[count - 1].mp);
		printf("이속 입력");
		scanf_s("%d", &p[count - 1].speed);
		printf("공격범위 입력");
		scanf_s("%d", &p[count - 1].range);
		printf("포지션 입력 1:탑 2:정글 3:미드 4:원딜 5: 서폿");
		scanf_s("%d", &p[count - 1].position);
		return;

	}


	insert(p, count, i + 1);
}
void remove(champion *p, int count, char *searchchampion, int i)
{
	if (i == count)
	{
		if (searchcount == 1)
		{
			searchcount = 0;
			return;
		}
		else if (searchcount == 0)
		{
			printf("없음 챔프입력");
			scanf_s("%s", searchchampion);
			i = 0;
		}
	}

	if (my_strcmp(searchchampion, p[i].name) == 0)
	{
		for (int k = i; k < count; k++)
		{
			p[k] = p[k + 1];
		}
		searchcount = 1;
	}

	remove(p, count, searchchampion, i + 1);
}
void removeall(champion *p, int count, int num, int i)
{
	if (i == count)
	{
		return;
	}

	if (num == p[i].position)
	{
		for (int k = i; k < count; k++)
		{

			p[k] = p[k + 1];

		}

		searchcount += 1;
	}
	if (num == p[i].position)
	{
		for (int k = i; k < count; k++)
		{

			p[k] = p[k + 1];

		}

		searchcount += 1;
	}
	removeall(p, count, num, i + 1);

}
int my_strcmp(char * str, char *str2)
{
	int count;
	if (str != '\0')
	{
		count = str - str2;
	}
	return count;
}

int main()
{
	int menu = 0;
	int count = 20;
	int i = 0;
	int num;
	champion *p = (champion*)malloc(sizeof(champion) * count);
	p[0] = { "나미",489,377,335,550,5 };
	p[1] = { "나서스",561,325,350,125,1 };
	p[2] = { "바드",535,350,330,500,5 };
	p[3] = { "녹턴",582,273,345,125,2 };
	p[4] = { "티모",528,267,330,500,4 };
	p[5] = { "갈리오",562,400,335,125,3 };
	p[6] = { "아칼리",550,200,345,125,1 };
	p[7] = { "바이",582,295,340,125,2 };
	p[8] = { "니코",540,450,340,550,4 };
	p[9] = { "니달리",545,295,335,525,1 };
	p[10] = { "나르",510,100,325,175,1 };
	p[11] = { "잔나",500,350,315,550,5 };
	p[12] = { "레넥톤",572,100,345,125,1 };
	p[13] = { "라이즈",570,400,340,550,3 };
	p[14] = { "라칸",480,315,335,300,5 };
	p[15] = { "럭스",490,480,330,550,3 };
	p[16] = { "룰루",525,350,330,550,5 };
	p[17] = { "소나",482,340,325,550,5 };
	p[18] = { "요릭",580,300,340,175,1 };
	p[19] = { "자야",561,340,325,525,4 };


	showmenu();
	scanf_s("%d", &menu);
	while (1)
	{
		switch (menu)
		{
		case 1:
			printf("챔프입력");
			scanf_s("%s", searchchampion);
			search(p, count, searchchampion, i);
			break;
		case 2:
			count += 1;
			p = (champion *)realloc(p, sizeof(champion)*count);
			p[count - 1] = {};
			insert(p, count, i);
			printall(p, count, i);
			break;
		case 3:
			printf("챔프입력");
			scanf_s("%s", searchchampion);
			remove(p, count, searchchampion, i);
			count -= 1;
			p = (champion *)realloc(p, sizeof(champion)*count);
			printall(p, count, i);
			break;
		case 4:
			printf("포지션 번호 입력 1:탑 2:정글 3:미드 4: 원딜 5:서폿");
			scanf_s("%d", &num);
			removeall(p, count, num, i);
			count = count - searchcount;
			p = (champion *)realloc(p, sizeof(champion)*count);
			searchcount = 0;
			printall(p, count, i);
			break;
		case 5:
			printall(p, count, i);
			break;
		case 6:
			sorthp(p, count, i);
			findmaxhp(p, count, i);
			
			break;
		case 7:
			sorthp(p, count, i);
			printall(p, count, i);
			break;
		default:
			break;
		}
		showmenu();
		scanf_s("%d", &menu);
	}

	free(p);
	scanf_s("%s", searchchampion);
	if (my_strcmp(searchchampion, p[0].name) == 0)
	{
		printf(":");
	}
	return 0;
}
void showmenu()
{
	printf_s("1. Search[챔피언이름] : 주어진 챔피언의 정보를 출력한다.\n");
	printf_s("2. Insert : 새로운 챔피언의 정보를 입력 받아 삽입한다 \n");
	printf_s("3. Delete[챔피언이름] : 주어진 챔피언에 대한 정보를 삭제한다 \n");
	printf_s("4. DeleteAll[position] : 주어진 위치의 모든 챔피언 정보를 삭제한다. \n");
	printf_s("5. PrintAll : 모든 챔피언의 정보를 배열에 저장된 순서대로 출력한다.\n");
	printf_s("6. FindMaxHp : 가장 체력이 큰 챔피언의 정보를 출력한다.\n");
	printf_s("7. SortByHp : 체력이 큰 챔피언부터 순서대로 저장한다.\n");
	printf_s("메뉴를 선택하세요");
}

