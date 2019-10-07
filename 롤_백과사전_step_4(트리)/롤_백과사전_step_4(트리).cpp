
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include <windows.h>
#define index 10000

typedef struct champ {
	char posit[20];
	char name[20];
	int hp;
	int mp;
	int speed;
}champ;

typedef struct tree {
	champ data;
	tree *left;
	tree *right;
}tree;

int count = 0;
void MakeLeftSubtree(tree * main, tree * sub)
{


	if (main->left != NULL)
	{
		free(main->left);
	}
	else
	{
		main->left = sub;
	}



}
void MakerightSubtree(tree * main, tree * sub)
{

	if (main->right != NULL)
	{
		free(main->right);
	}
	else
	{
		main->right = sub;
	}

}
void insert_t(tree ** proot, champ data)
{
	tree * nnode = NULL;
	tree * cnode = *proot;
	tree * pnode = NULL;

	nnode = (tree*)malloc(sizeof(tree));
	nnode->left = NULL;
	nnode->right = NULL;

	strcpy(nnode->data.name, data.name);
	strcpy(nnode->data.posit, data.posit);
	nnode->data.hp = data.hp;
	nnode->data.mp = data.mp;
	nnode->data.speed = data.speed;

	while (cnode != NULL)
	{
		if (strcmp(cnode->data.name, data.name) == 0)
		{
			printf("이미 있는 이름입니다 \n");
			return;

		}
		pnode = cnode;
		if (strcmp(cnode->data.name, data.name) == 1)
		{

			cnode = cnode->left;

		}
		else
		{
			cnode = cnode->right;
		}
	}


	if (pnode != NULL)
	{
		if (strcmp(pnode->data.name, data.name) == 1)
		{
			MakeLeftSubtree(pnode, nnode);
		}
		else
		{
			MakerightSubtree(pnode, nnode);
		}
	}

	else
	{
		*proot = nnode;
	}


}


int check;
void inorder(tree *node)
{
	check += 1;

	if (node != NULL)
	{

		inorder(node->left);
		if (check%10000==0)
		{
			printf("[이름 %s] [포지션 %s] [hp %d] [mp %d] [speed %d] \n", node->data.name, node->data.posit, node->data.hp, node->data.mp, node->data.speed);

		}
		inorder(node->right);
	}
	else
	{
		return;
	}

	check += 1;
}

void search(tree *node, char *name)
{
	if (node != NULL)
	{
		search(node->left, name);
		if (strcmp(node->data.name, name) == 0)
		{
			printf("[이름 %s] [포지션 %s] [hp %d] [mp %d] [speed %d] \n", node->data.name, node->data.posit, node->data.hp, node->data.mp, node->data.speed);
			return;
		}
		search(node->right, name);

	}
	else
	{
		
		return;
	}



}
champ b[index];
int main()
{
	tree * root = NULL;
	time_t start, end;
	champ temp;
	int count = 0;
	FILE *fr;
	srand(time(0));
	int num;
	char S_name[20];
	fr = fopen("LOLDic.txt", "rt");
	for (int i = 0; i < index; i++)
	{
		fscanf(fr, "%s %s %d %d %d \n",  b[i].posit, b[i].name, &b[i].hp, &b[i].mp, &b[i].speed);
	}

	while (count != 1000000)
	{
		champ c;
		fscanf(fr, "%s %s %d %d %d \n", c.posit, c.name, &c.hp, &c.mp, &c.speed);
		insert_t(&root, c);
		count += 1;
	}
	fclose(fr);
	while (1)
	{
		printf(" 1 (배열)출력 2.(배열)이름정렬");
		scanf("%d", &num);
		if (num == 1)
		{

			count = 0;
			printf(" 배열 이름순으로 정렬 출력 하기  \n");
			start = clock();

			for (int i = 0; i < index; i++)
			{
				count += 1;
				if (count == 100)
				{

					printf("[이름 %s] [포지션 %s] [hp %d] [mp %d] [speed %d]\n", b[i].name, b[i].posit, b[i].hp, b[i].mp, b[i].speed);
					count = 0;
				}
			}
			end = clock();

			printf("걸린 시간 : %f \n", (double)(end - start) / CLOCKS_PER_SEC);

		}
		else if (num == 2)
		{
			start = clock();
			printf(" 배열 이름순으로 정렬하기  \n");

			for (int i = 0; i < index; i++)
			{
				for (int j = 0; j < i; j++)
				{
					if (strcmp(b[i].name, b[j].name) < 0)
					{
						temp = b[i];
						b[i] = b[j];
						b[j] = temp;
					}

				}
			}
			end = clock();
			printf("걸린 시간 : %f \n", (double)(end - start) / CLOCKS_PER_SEC);

		}
		else
		{
			break;
		}
	}




	while (1)
	{
		printf(" 1. seach 2.insert 3.delete 4.printall 5. sort");
		scanf("%d", &num);
		switch (num)
		{
		case 1:
			printf("찾는 이름 입력");
			scanf("%s", S_name);
			start = clock();
			search(root, S_name);
			end = clock();
			printf("걸린 시간 : %f \n", (double)(end - start) / CLOCKS_PER_SEC);
			break;

		case 2:
			printf("이름 hp mp speed 포지션 ");
			champ a;
			scanf(" %s %d %d %d %s", a.name, &a.hp, &a.mp, &a.speed, a.posit);
			start = clock();
			insert_t(&root, a);
			end = clock();
			printf("걸린 시간 : %f \n", (double)(end - start) / CLOCKS_PER_SEC);
			break;

		case 3:
			break;

		case 4:
			start = clock();
			inorder(root);
			end = clock();
			printf("걸린 시간 : %f \n", (double)(end - start) / CLOCKS_PER_SEC);
			break;

		case 5:
			start = clock();
			inorder(root);
			end = clock();
			printf("걸린 시간 : %f \n", (double)(end - start) / CLOCKS_PER_SEC);
			break;
		}
	}
}