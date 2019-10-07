/*LOL의 챔피언들에 대하여 다음 6가지 정보를 관리하기 위하여 구조체형 배열형태로 선언하고 데이터를 입력하는 부분을 작성해오세요. 단, 챔피언의 개수는 최소 20개
–name, hp, mp, speed, range, position(top, mid 등) -> 구조체 배열 20개 선언해서 인자로 넣어주기

•작성해 온 배열을 이용하여 LOL_Dic을 작성하라.
1. Search[챔피언이름] : 주어진 챔피언의 정보를 출력한다. ->  if strcnp (마오카이 == 마이카이)
2. Insert : 새로운 챔피언의 정보를 입력 받아 삽입한다
3. Delete[챔피언이름] : 주어진 챔피언에 대한 정보를 삭제한다.
4. DeleteAll[position] : 주어진 위치의 모든 챔피언 정보를 삭제한다.
5. PrintAll : 모든 챔피언의 정보를 배열에 저장된 순서대로 출력한다.
6. FindMaxHp : 가장 체력이 큰 챔피언의 정보를 출력한다.
7. SortByHp : 체력이 큰 챔피언부터 순서대로 저장한다.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20
typedef struct _champion
{
	char name[MAX];
	int hp;
	int mp;
	int speed;
	int range;
	char position[MAX];
}champion;
champion *p;
int size = 20;
char searchchampion[MAX];
void showmenu();
void search(champion q[]);
void insert(champion q[]);
void printall(champion q[]);
void findmaxhp(champion q[]);
void sorthp(champion q[]);
void remove(champion q[]);
void removeall(champion q[]);

int main()
{
	p = (champion*)malloc(sizeof(champion) * size);
	p[0] = { "나미",489,377,335,550,"서포터" };
	p[1] = { "나서스",561,325,350,125,"탑" };
	p[2] = { "바드",535,350,330,500,"서포터" };
	p[3] = { "녹턴",582,273,345,125,"정글" };
	p[4] = { "티모",528,267,330,500,"원딜" };
	p[5] = { "갈리오",562,400,335,125,"미드" };
	p[6] = { "아칼리",550,200,345,125,"탑" };
	p[7] = { "바이",582,295,340,125,"정글" };
	p[8] = { "니코",540,450,340,550,"원딜" };
	p[9] = { "니달리",545,295,335,525,"탑" };
	p[10] = { "나르",510,100,325,175,"탑" };
	p[11] = { "잔나",500,350,315,550,"서포터" };
	p[12] = { "레넥톤",572,100,345,125,"탑" };
	p[13] = { "라이즈",570,400,340,550,"미드" };
	p[14] = { "라칸",480,315,335,300,"서포터" };
	p[15] = { "럭스",490,480,330,550,"미드" };
	p[16] = { "룰루",525,350,330,550,"서포터" };
	p[17] = { "소나",482,340,325,550,"서포터" };
	p[18] = { "요릭",580,300,340,175,"탑" };
	p[19] = { "자야",561,340,325,525,"원딜" };
	int menu = 0;
	showmenu();
	scanf_s("%d", &menu);
	while (1)
	{
		switch (menu)
		{
		case 1:
			search(p); break;
		case 2:
			insert(p); break;
		case 3:
			remove(p); break;
		case 4:
			removeall(p); break;
		case 5:
			printall(p); break;
		case 6:
			findmaxhp(p); break;
		case 7:
			sorthp(p); break;
		default:
			break;
		}
		showmenu();
		scanf_s("%d", &menu);
	}

	free(p);

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
void search(champion q[])
{
	scanf_s("%s",&searchchampion,sizeof(searchchampion));
	for (int i = 0; i < size; i++)
	{
		if (strcmp(searchchampion,p[i].name) == 0)
		{
			printf_s("%s,%3d,%3d,%3d,%3d,%s \n", p[i].name,p[i].hp, p[i].mp, p[i].speed, p[i].range, p[i].position);
			return;
		}
	}

	printf("없는 챔피언 \n");
	return;
}
void insert(champion q[])
{
	champion *op = (champion *)malloc(sizeof(champion)*(size + 1));
	for (int i = 0; i<size; i++)
	{
		strcpy_s(op[i].name,MAX, p[i].name);
		op[i].hp = p[i].hp;
		op[i].mp = p[i].mp;
		op[i].range = p[i].range;
		op[i].speed = p[i].speed;
		strcpy_s(op[i].position,MAX, p[i].position);
	}
	free(p);
	p = (champion*)malloc(sizeof(champion)*(size + 1));
	size +=1;
	printf_s("이름입력 \n");
	scanf_s("%s", &op[size - 1].name, MAX);
	printf_s("HP 입력 \n");
	scanf_s("%d", &op[size - 1].hp);
	printf_s("MP 입력 \n");
	scanf_s("%d", &op[size - 1].mp);
	printf_s("이속입력 \n");
	scanf_s("%d", &op[size - 1].speed);
	printf_s("공격범위 입력 \n");
	scanf_s("%d", &op[size - 1].range);
	printf_s("포지션 입력 \n");
	scanf_s("%s", &op[size - 1].position, MAX);
	
	for (int i = 0; i < size; i++)
	{
		strcpy_s( p[i].name,MAX, op[i].name);
	 p[i].hp = op[i].hp;
		p[i].mp = op[i].mp;
		 p[i].range = op[i].range ;
		 p[i].speed = op[i].speed ;
		strcpy_s( p[i].position, MAX, op[i].position);
	}

}
void remove(champion q[])
{
	int count = 0;
	scanf_s("%s",&searchchampion,MAX);

	for (int i = 0; i < size; i++)
	{
		if (strcmp(searchchampion, p[i].name) == 0)
		{
			count = i;
		}
	}
	if (count == 0)
	{
		printf_s("없는 챔피언입니다 \n");
		return;
	}
	printf_s("%s를 삭제합니다\n", searchchampion);
	champion *op = (champion *)malloc(sizeof(champion)*size-1);

	for (int i = 0; i<size-1 ; i++)
	{
	
		if(i<=count)
		{
		strcpy_s(op[i].name, MAX, p[i].name);
		op[i].hp = p[i].hp;
		op[i].mp = p[i].mp;
		op[i].range = p[i].range;
		op[i].speed = p[i].speed;
		strcpy_s(op[i].position, MAX, p[i].position);
		
		}
		else
		{
			strcpy_s(op[i].name, MAX, p[i+1].name);
			op[i].hp = p[i+1].hp;
			op[i].mp = p[i+1].mp;
			op[i].range = p[i+1].range;
			op[i].speed = p[i+1].speed;
			strcpy_s(op[i].position, MAX, p[i+1].position);
			
		}
	}
	
	free(p);
	p = (champion*)malloc(sizeof(champion)*(size-1));
	size -= 1;
	for (int i = 0; i < size; i++)
	{
		strcpy_s(p[i].name, MAX, op[i].name);
		p[i].hp = op[i].hp;
		p[i].mp = op[i].mp;
		p[i].range = op[i].range;
		p[i].speed = op[i].speed;
		strcpy_s(p[i].position, MAX, op[i].position);
	}

	
}
void printall(champion p[])
{  
	printf_s("순서 이름 HP MP 이속 공격범위 포지션 \n");
	for (int i = 0; i <size; i++)
	{
		printf_s("%d,%s,%3d,%3d,%3d,%3d,%s \n",i+1, p[i].name, p[i].hp, p[i].mp, p[i].speed, p[i].range, p[i].position);
	}
}
void findmaxhp(champion q[])
{
	int count = 0;
	int max = 0;
	for (int i = 0; i < size; i++)
	{
		if (max < p[i].hp)
		{
			max = p[i].hp;
			count = i;
		}
		
	}
	
	printf_s("%s,%3d,%3d,%3d,%3d,%s \n",p[count].name, p[count].hp, p[count].mp, p[count].speed, p[count].range, p[count].position);

}
void sorthp(champion q[])
{
	champion temp;

	for (int i = 0; i < size-1; i++)
	{
		for (int j = 0;  j < size - i - 1; j++)
		{
			if (p[j].hp < p[j + 1].hp)
			{
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}
}
void removeall(champion q[])
{
	int count = 0;
	char po[MAX];
	printf("삭제 포지션입력");
	scanf_s("%s", &po, sizeof(po));
	for (int i = 0; i < size; i++)
	{
		if (strcmp(po, p[i].position)==0)
		{
			count = i;

			champion *op = (champion *)malloc(sizeof(champion)*size - 1);

			for (int i = 0; i<size - 1; i++)
			{

				if (i<count)
				{
					strcpy_s(op[i].name, MAX, p[i].name);
					op[i].hp = p[i].hp;
					op[i].mp = p[i].mp;
					op[i].range = p[i].range;
					op[i].speed = p[i].speed;
					strcpy_s(op[i].position, MAX, p[i].position);

				}
				else
				{
					strcpy_s(op[i].name, MAX, p[i + 1].name);
					op[i].hp = p[i + 1].hp;
					op[i].mp = p[i + 1].mp;
					op[i].range = p[i + 1].range;
					op[i].speed = p[i + 1].speed;
					strcpy_s(op[i].position, MAX, p[i + 1].position);

				}
			}

			free(p);
			p = (champion*)malloc(sizeof(champion)*(size - 1));
			size -= 1;
			for (int i = 0; i < size; i++)
			{
				strcpy_s(p[i].name, MAX, op[i].name);
				p[i].hp = op[i].hp;
				p[i].mp = op[i].mp;
				p[i].range = op[i].range;
				p[i].speed = op[i].speed;
				strcpy_s(p[i].position, MAX, op[i].position);
			
			}
		
		}	
	
	}



}