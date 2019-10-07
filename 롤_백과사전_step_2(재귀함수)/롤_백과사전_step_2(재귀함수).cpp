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
	printf("����: %d ", count + 1);
	printf("�̸�: %s ", p[count].name);
	printf("HP : %d ", p[count].hp);
	printf("MP : %d ", p[count].mp);
	printf("�̵��ӵ� : %d ", p[count].speed);
	printf("���ݹ��� : %d ", p[count].range);
	printf("������: ");
	switch (p[count].position)
	{
	case 1:
		printf("ž \n");
		break;
	case 2:
		printf("���� \n");
		break;
	case 3:
		printf("�̵� \n");
		break;
	case 4:
		printf("���� \n");
		break;
	case 5:
		printf("������ \n");
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
			printf("����");
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
		printf("è�Ǿ� �Է�");
		scanf_s("%s", p[count - 1].name,80);
		for (int k = 0; k < count - 1; k++)
		{
			if (my_strcmp(p[count - 1].name, p[k].name) == 0)
			{
				printf("�̹��ִ�");
				goto a;
			}
		}
		printf("HP �Է�");
		scanf_s("%d", &p[count - 1].hp);
		printf("MP �Է�");
		scanf_s("%d", &p[count - 1].mp);
		printf("�̼� �Է�");
		scanf_s("%d", &p[count - 1].speed);
		printf("���ݹ��� �Է�");
		scanf_s("%d", &p[count - 1].range);
		printf("������ �Է� 1:ž 2:���� 3:�̵� 4:���� 5: ����");
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
			printf("���� è���Է�");
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
	p[0] = { "����",489,377,335,550,5 };
	p[1] = { "������",561,325,350,125,1 };
	p[2] = { "�ٵ�",535,350,330,500,5 };
	p[3] = { "����",582,273,345,125,2 };
	p[4] = { "Ƽ��",528,267,330,500,4 };
	p[5] = { "������",562,400,335,125,3 };
	p[6] = { "��Į��",550,200,345,125,1 };
	p[7] = { "����",582,295,340,125,2 };
	p[8] = { "����",540,450,340,550,4 };
	p[9] = { "�ϴ޸�",545,295,335,525,1 };
	p[10] = { "����",510,100,325,175,1 };
	p[11] = { "�ܳ�",500,350,315,550,5 };
	p[12] = { "������",572,100,345,125,1 };
	p[13] = { "������",570,400,340,550,3 };
	p[14] = { "��ĭ",480,315,335,300,5 };
	p[15] = { "����",490,480,330,550,3 };
	p[16] = { "���",525,350,330,550,5 };
	p[17] = { "�ҳ�",482,340,325,550,5 };
	p[18] = { "�丯",580,300,340,175,1 };
	p[19] = { "�ھ�",561,340,325,525,4 };


	showmenu();
	scanf_s("%d", &menu);
	while (1)
	{
		switch (menu)
		{
		case 1:
			printf("è���Է�");
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
			printf("è���Է�");
			scanf_s("%s", searchchampion);
			remove(p, count, searchchampion, i);
			count -= 1;
			p = (champion *)realloc(p, sizeof(champion)*count);
			printall(p, count, i);
			break;
		case 4:
			printf("������ ��ȣ �Է� 1:ž 2:���� 3:�̵� 4: ���� 5:����");
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
	printf_s("1. Search[è�Ǿ��̸�] : �־��� è�Ǿ��� ������ ����Ѵ�.\n");
	printf_s("2. Insert : ���ο� è�Ǿ��� ������ �Է� �޾� �����Ѵ� \n");
	printf_s("3. Delete[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ������ �����Ѵ� \n");
	printf_s("4. DeleteAll[position] : �־��� ��ġ�� ��� è�Ǿ� ������ �����Ѵ�. \n");
	printf_s("5. PrintAll : ��� è�Ǿ��� ������ �迭�� ����� ������� ����Ѵ�.\n");
	printf_s("6. FindMaxHp : ���� ü���� ū è�Ǿ��� ������ ����Ѵ�.\n");
	printf_s("7. SortByHp : ü���� ū è�Ǿ���� ������� �����Ѵ�.\n");
	printf_s("�޴��� �����ϼ���");
}

