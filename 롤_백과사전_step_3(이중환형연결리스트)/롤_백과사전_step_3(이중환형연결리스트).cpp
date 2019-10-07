#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#define MAX 20


typedef struct _champion
{
	char name[MAX];
	int hp;
	int mp;
	int speed;
	int range;
	int position;
	struct  _champion* next;
	struct  _champion* prev;
} champion;

typedef struct _List {
	champion* head;
	champion* tail;
} List;

List *q;

void showmenu();

void printall(List* list);
List* Listnit(List* list, champion* p);
List* listinsert(List* list, champion* target);
champion* search(List* list);
List* listinsertAfterSort(List* list, champion* target);
void Deletechampion(List* list);
void DeletePositionAll(List* list);
void DeleteChampionByIndexPointer(List* list, champion* target);
champion* FindMaxHP(List* list, int mode);
List* Sort(List* list);
int count = 20;

int main()
{
	int menu = 0;
	champion* p = (champion*)malloc(sizeof(champion) * count);
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
	q = Listnit(q, p);

	showmenu();
	scanf_s("%d", &menu);
	while (1)
	{
		switch (menu)
		{
		case 1:
			search(q);
			break;
		case 2:
		{
			champion* insertChampion = (champion*)malloc(sizeof(champion));

			char name[MAX];
			int hp = 0;
			int mp = 0;
			int range = 0;
			int speed = 0;
			int position = 0;

			printf_s("è�Ǿ� �̸� �Է� : ");
			scanf_s("%s", name, 20);
			strcpy_s(insertChampion->name, name);

			printf_s("è�Ǿ� ü�� �Է� : ");
			scanf_s("%d", &hp);
			insertChampion->hp = hp;

			printf_s("è�Ǿ� ���� �Է� : ");
			scanf_s("%d", &mp);
			insertChampion->mp = mp;

			printf_s("è�Ǿ� ��Ÿ� �Է� : ");
			scanf_s("%d", &range);
			insertChampion->range = range;

			printf_s("è�Ǿ� �̵��ӵ� �Է� : ");
			scanf_s("%d", &speed);
			insertChampion->speed = speed;

			printf_s("è�Ǿ� ������ �Է�(1:ž, 2:����, 3:�̵�, 4:����, 5:������) : ");
			scanf_s("%d", &position);
			insertChampion->position = position;

			q = listinsertAfterSort(q, insertChampion);

		}
		break;
		case 3:
			Deletechampion(q);
			break;
		case 4:
			DeletePositionAll(q);
			break;
		case 5:
			printall(q);
			break;
		case 6:
			FindMaxHP(q, 0);
			break;
		case 7:
			q = Sort(q);
			break;
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
	printf_s("1. Search[è�Ǿ��̸�] : �־��� è�Ǿ��� ������ ����Ѵ�.\n");
	printf_s("2. Insert : ���ο� è�Ǿ��� ������ �Է� �޾� �����Ѵ� \n");
	printf_s("3. Delete[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ������ �����Ѵ� \n");
	printf_s("4. DeleteAll[position] : �־��� ��ġ�� ��� è�Ǿ� ������ �����Ѵ�. \n");
	printf_s("5. PrintAll : ��� è�Ǿ��� ������ �迭�� ����� ������� ����Ѵ�.\n");
	printf_s("6. FindMaxHp : ���� ü���� ū è�Ǿ��� ������ ����Ѵ�.\n");
	printf_s("7. SortByHp : ü���� ū è�Ǿ���� ������� �����Ѵ�.\n");
	printf_s("�޴��� �����ϼ���");
}

List* Listnit(List* list, champion* p) // ���� ���� ���Ḯ��Ʈ �ʱ�ȭ & �ֱ� �õ�
{
	list = (List*)malloc(sizeof(List));
	list->head = (champion*)malloc(sizeof(champion));
	list->tail = (champion*)malloc(sizeof(champion));

	list->head->next = list->tail;
	list->head->prev = list->tail;

	list->tail->next = list->head;
	list->tail->prev = list->head;

	for (int i = 0; i < 20; i++)
	{
		if (p != nullptr)
		{
			listinsert(list, &p[i]);
		}
	}
	return list;
}

List* listinsert(List* list, champion* target) // ���� ���� ���Ḯ��Ʈ �ֱ�.
{

	if (list->head->next == list->tail)
	{
		target->next = list->tail;
		target->prev = list->head;
		list->head->next = target;
		list->tail->prev = target;
		return list;
	}
	else
	{
		champion * index = list->head;
		while (index->next != list->tail)
		{
			index = index->next;
		}

		target->next = list->tail;
		target->prev = index;

		index->next = target;
		list->tail->prev = target;

		return list;
	}

	return list;
}

void printall(List* list)
{
	int i = 1;
	champion *index = list->head->next;
	while (index != list->tail)
	{
		
		printf("����:%d �̸�:%s HP:%d MP:%d RANGE:%d SPEES%d POSITION:", i, index->name, index->hp, index->mp, index->range, index->speed);

		switch (index->position)
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
		i++;
		index = index->next;
	}
}

champion* search(List* list)
{
	char name[20];
	printf("è�Ǿ� �̸��� �Է�:\n");
	scanf_s("%s", name, MAX);
	champion *index = list->head;
	while (index != list->tail)
	{
		if (strcmp(index->name, name) == 0)
		{
			printf("�̸�:%s HP:%d MP:%d RANGE:%d SPEES%d POSITION:", index->name, index->hp, index->mp, index->range, index->speed);

			switch (index->position)
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
			return index;
		}
		index = index->next;
	}
	return nullptr;
}

List* listinsertAfterSort(List* list, champion* target)
{
	champion * index = list->head->next;
	while (index != list->head)
	{
		if (index->hp < target->hp)
		{
			target->next = index;
			target->prev = index->prev;
			index->prev->next = target;
			index->prev = target;
			return list;
		}
		index = index->next;
	}

	return list;


}

void  Deletechampion(List* list)
{
	champion * index = search(list);
	if (index == nullptr)
	{
		printf("���� è�Ǿ� �Դϴ�");
	}
	else
	{
		DeleteChampionByIndexPointer(list, index);
	}
}


void DeleteChampionByIndexPointer(List* list, champion* target)
{
	target->prev->next = target->next;
	target->next->prev = target->prev;

}

void DeletePositionAll(List* list)
{
	int position = 0;
	printf("���� ������ �Է� \n");
	scanf_s("%d", &position);
	champion * index = list->head->next;

	while (index != list->tail)
	{
		if (index->position == position)
		{
			DeleteChampionByIndexPointer(list, index);
		}
		index = index->next;
	}
}

champion* FindMaxHP(List* list, int mode)
{
	champion * index = list->head->next;
	champion * Maxhp = list->head->next;
	while (index != list->tail)
	{
		if (index->hp > Maxhp->hp)
		{
			Maxhp = index;
		}
		index = index->next;
	}

	if (mode == 0)
	{
		int maxhp = Maxhp->hp;
		index = list->head->next;
		while (index != list->tail)
		{
			if (maxhp == index->hp)
			{
				printf("�̸�:%s HP:%d MP:%d RANGE:%d SPEES%d POSITION:", index->name, index->hp, index->mp, index->range, index->speed);

				switch (index->position)
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
			index = index->next;
		}
	}
	return Maxhp;

}
List* Sort(List* list)
{
	List *temp = nullptr;
	temp = Listnit(list, nullptr);
	champion * index = nullptr;
	while (1)
	{
		index = FindMaxHP(list, 2);
		if (index == list->head || index == list->tail)
		{
			break;
		}
		DeleteChampionByIndexPointer(list, index);
		listinsert(temp, index);
	
	}
	return temp;
}

