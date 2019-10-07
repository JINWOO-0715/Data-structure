#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX_2014180021 19
#define WHITE_2014180021 1
#define BLACK_2014180021 2
#define PAN_2014180021 0

struct Point {
	int x;
	int y;
	int stone;
	int gravity;

};
void makepan();
int point_x;
int point_y;
int baducpan[MAX_2014180021][MAX_2014180021] = { PAN_2014180021 ,};
int top = -1;
Point Gravity[MAX_2014180021][MAX_2014180021] = { PAN_2014180021 , };
Point stack[361];

void FMstone();
void makepan()
{
	for (int i = 0; i < MAX_2014180021; i++)
	{
		for (int j = 0; j < MAX_2014180021; j++)
		{
			if (baducpan[i][j] == WHITE_2014180021)
			{
				printf_s(" ≤");
			}
			else if (baducpan[i][j] == BLACK_2014180021)
			{
				printf_s(" ≯");
			}
			else printf_s(" + ");
		}
		printf("%d", i);
		printf_s("\n");

	}

}

void FMstone()
{
	


}
void WhiteAttack_2014180021(int *x, int *y)
{
	int max = 0;
	int min = 0;
	for (int i = 0; i < MAX_2014180021; i++)
	{
		for (int j = 0; j < MAX_2014180021; j++)
		{
			Gravity[i][j].gravity = 0;
		}
	}
	for (int i = 0; i < MAX_2014180021; i++)
	{
		for (int j = 0; j < MAX_2014180021; j++)
		{
			if (Gravity[i][j].stone == BLACK_2014180021)

			{
				if (i - 1 > -1 && j - 1 > -1)
				{
					Gravity[i - 1][j - 1].gravity += 5;//1
					if (Gravity[i - 1][j - 1].stone == BLACK_2014180021)
					{
						Gravity[i + 1][j + 1].gravity += 55;//9
						if (Gravity[i + 1][j + 1].stone == BLACK_2014180021)// 3楷加 老嫐
						{


							Gravity[i + 2][j + 2].gravity += 555;
							if (Gravity[i + 3][j + 3].stone == BLACK_2014180021) // 4楷加老锭
							{
								Gravity[i + 2][j + 2].gravity += 55555;
							}

							if (Gravity[i + 2][j + 2].stone == BLACK_2014180021) // 3:1 4楷加老锭
							{
								Gravity[i + 3][j + 3].gravity += 55555;
							}


						}
						if (Gravity[i + 2][j + 2].stone == BLACK_2014180021) // 2俺 +1俺 老锭
						{
							Gravity[i + 1][j + 1].gravity += 5555;



						}
					}
				}
				if (i - 1 > -1 && j > -1)
				{
					Gravity[i - 1][j].gravity += 5;//2
					if (Gravity[i - 1][j].stone == BLACK_2014180021)
					{
						Gravity[i + 1][j].gravity += 55;//8
						if (Gravity[i + 1][j].stone == BLACK_2014180021)
						{
							Gravity[i + 2][j].gravity += 555;
							if (Gravity[i + 2][j].stone == BLACK_2014180021) // 4楷加老锭
							{
								Gravity[i + 3][j].gravity += 55555;
							}
							if (Gravity[i + 3][j].stone == BLACK_2014180021) // 4楷加老锭
							{
								Gravity[i + 2][j].gravity += 55555;
							}
						}
						if (Gravity[i + 2][j].stone == BLACK_2014180021)//楷加
						{
							Gravity[i + 1][j].gravity += 5555;
						}
					}
				}
				if (i - 1 > -1 && j + 1 < 19)
				{
					Gravity[i - 1][j + 1].gravity += 5;//3
					if (Gravity[i - 1][j + 1].stone == BLACK_2014180021)
					{
						Gravity[i + 1][j - 1].gravity += 55;//7.
						if (Gravity[i + 1][j - 1].stone == BLACK_2014180021)
						{
							Gravity[i + 2][j - 2].gravity += 555;
							if (Gravity[i + 2][j - 2].stone == BLACK_2014180021) // 4楷加老锭
							{
								Gravity[i + 3][j - 3].gravity += 55555;
							}
							if (Gravity[i + 3][j - 3].stone == BLACK_2014180021) // 4楷加老锭
							{
								Gravity[i + 2][j - 2].gravity += 55555;
							}
						}
						if (Gravity[i + 2][j - 2].stone == BLACK_2014180021)
						{
							Gravity[i + 1][j - 1].gravity += 5555;
						}

					}
				}
				if (i > -1 && j - 1 > -1)
				{
					Gravity[i][j - 1].gravity += 5;//4

					if (Gravity[i][j - 1].stone == BLACK_2014180021)
					{
						Gravity[i][j + 1].gravity += 55;//6

						if (Gravity[i][j + 1].stone == BLACK_2014180021)
						{
							Gravity[i][j + 2].gravity;
							if (Gravity[i][j + 2].stone == BLACK_2014180021) // 4楷加老锭
							{
								Gravity[i][j + 3].gravity += 55555;
							}
							if (Gravity[i][j + 3].stone == BLACK_2014180021) // 4楷加老锭
							{
								Gravity[i][j + 2].gravity += 55555;
							}
						}
						if (Gravity[i][j + 2].stone == BLACK_2014180021)
						{
							Gravity[i][j + 1].gravity += 5555;
						}
					}
				}
				if (i > -1 && j + 1 < 19)
				{

					Gravity[i][j + 1].gravity += 5;//6

					if (Gravity[i][j + 1].stone == BLACK_2014180021)
					{
						Gravity[i][j - 1].gravity += 55;//8
						if (Gravity[i][j - 1].stone == BLACK_2014180021)
						{
							Gravity[i][j - 2].gravity += 555;
							if (Gravity[i][j - 2].stone == BLACK_2014180021) // 4楷加老锭
							{
								Gravity[i][j - 3].gravity += 55555;
							}
							if (Gravity[i][j - 3].stone == BLACK_2014180021) // 4楷加老锭
							{
								Gravity[i][j - 2].gravity += 55555;
							}
						}
						if (Gravity[i][j - 2].stone == BLACK_2014180021)
						{
							Gravity[i][j - 1].gravity += 5555;
						}

					}
				}
				if (i + 1 < 19 && j - 1 > -1)
				{
					Gravity[i + 1][j - 1].gravity += 5;//7.

					if (Gravity[i - 1][j - 1].stone == BLACK_2014180021)
					{
						Gravity[i - 1][j + 1].gravity += 55;//3

						if (Gravity[i - 1][j + 1].stone == BLACK_2014180021)
						{
							Gravity[i - 2][j + 2].gravity += 555;
							if (Gravity[i - 2][j + 2].stone == BLACK_2014180021) // 4楷加老锭
							{
								Gravity[i - 3][j + 3].gravity += 55555;
							}
							if (Gravity[i - 3][j + 3].stone == BLACK_2014180021) // 4楷加老锭
							{
								Gravity[i - 2][j + 2].gravity += 55555;

							}

						}
						if (Gravity[i - 2][j + 2].stone == BLACK_2014180021)
						{
							Gravity[i - 1][j + 1].gravity += 5555;
						}
					}
				}
				if (i + 1 < 19 && j > -1)
				{
					Gravity[i + 1][j].gravity += 5;//8
					if (Gravity[i + 1][j].stone == BLACK_2014180021)
					{
						Gravity[i - 1][j].gravity += 55;//2
						if (Gravity[i - 1][j].stone == BLACK_2014180021)
						{
							Gravity[i - 2][j].gravity += 555;
							if (Gravity[i - 2][j].stone == BLACK_2014180021) // 4楷加老锭
							{
								Gravity[i - 3][j].gravity += 55555;

							}
							if (Gravity[i - 3][j].stone == BLACK_2014180021) // 4楷加老锭
							{
								Gravity[i - 2][j].gravity += 55555;
							}
						}
						if (Gravity[i - 2][j].stone == BLACK_2014180021)
						{
							Gravity[i - 1][j].gravity += 5555;
						}
					}

				}
				if (i + 1 < 19 && j + 1 < 19)
				{

					Gravity[i + 1][j + 1].gravity += 5;//9
					if (Gravity[i + 1][j + 1].stone == BLACK_2014180021)
					{
						Gravity[i - 1][j - 1].gravity += 55;//8
						if (Gravity[i - 1][j - 1].stone == BLACK_2014180021)
						{
							Gravity[i - 2][j - 2].gravity += 555;
							if (Gravity[i - 2][j - 2].stone == BLACK_2014180021) // 4楷加老锭
							{
								Gravity[i - 3][j - 3].gravity += 55555;

							}
							if (Gravity[i - 3][j - 3].stone == BLACK_2014180021) // 4楷加老锭
							{
								Gravity[i - 2][j - 2].gravity += 55555;

							}
						}
						if (Gravity[i - 2][j - 2].stone == BLACK_2014180021)
						{
							Gravity[i - 1][j - 1].gravity += 5555;
						}
					}
				}

			}
			if (Gravity[i][j].stone == WHITE_2014180021)

			{
				if (i - 1 > -1 && j - 1 > -1)
				{
					Gravity[i - 1][j - 1].gravity -= 5;//1
					if (Gravity[i - 1][j - 1].stone == WHITE_2014180021)
					{
						Gravity[i + 1][j + 1].gravity -= 55;//9
						if (Gravity[i + 1][j + 1].stone == WHITE_2014180021)// 3楷加 老嫐
						{


							Gravity[i + 2][j + 2].gravity -= 555;
							if (Gravity[i + 3][j + 3].stone == WHITE_2014180021) // 4楷加老锭
							{
								Gravity[i + 2][j + 2].gravity -= 55555;
							}

							if (Gravity[i + 2][j + 2].stone == WHITE_2014180021) // 3:1 4楷加老锭
							{
								Gravity[i + 3][j + 3].gravity -= 55555;
							}


						}
						if (Gravity[i + 2][j + 2].stone == WHITE_2014180021) // 2俺 +1俺 老锭
						{
							Gravity[i + 1][j + 1].gravity -= 5555;



						}
					}
				}
				if (i - 1 > -1 && j > -1)
				{
					Gravity[i - 1][j].gravity -= 5;//2
					if (Gravity[i - 1][j].stone == WHITE_2014180021)
					{
						Gravity[i + 1][j].gravity -= 55;//8
						if (Gravity[i + 1][j].stone == WHITE_2014180021)
						{
							Gravity[i + 2][j].gravity -= 555;
							if (Gravity[i + 2][j].stone == WHITE_2014180021) // 4楷加老锭
							{
								Gravity[i + 3][j].gravity -= 55555;
							}
							if (Gravity[i + 3][j].stone == WHITE_2014180021) // 4楷加老锭
							{
								Gravity[i + 2][j].gravity -= 55555;
							}
						}
						if (Gravity[i + 2][j].stone == WHITE_2014180021)//楷加
						{
							Gravity[i + 1][j].gravity -= 5555;
						}
					}
				}
				if (i - 1 > -1 && j + 1 < 19)
				{
					Gravity[i - 1][j + 1].gravity -= 5;//3
					if (Gravity[i - 1][j + 1].stone == WHITE_2014180021)
					{
						Gravity[i + 1][j - 1].gravity -= 55;//7.
						if (Gravity[i + 1][j - 1].stone == WHITE_2014180021)
						{
							Gravity[i + 2][j - 2].gravity -= 555;
							if (Gravity[i + 2][j - 2].stone == WHITE_2014180021) // 4楷加老锭
							{
								Gravity[i + 3][j - 3].gravity -= 55555;
							}
							if (Gravity[i + 3][j - 3].stone == WHITE_2014180021) // 4楷加老锭
							{
								Gravity[i + 2][j - 2].gravity -= 55555;
							}
						}
						if (Gravity[i + 2][j - 2].stone == WHITE_2014180021)
						{
							Gravity[i + 1][j - 1].gravity -= 5555;
						}

					}
				}
				if (i > -1 && j - 1 > -1)
				{
					Gravity[i][j - 1].gravity -= 5;//4

					if (Gravity[i][j - 1].stone == WHITE_2014180021)
					{
						Gravity[i][j + 1].gravity -= 55;//6

						if (Gravity[i][j + 1].stone == WHITE_2014180021)
						{
							Gravity[i][j + 2].gravity;
							if (Gravity[i][j + 2].stone == WHITE_2014180021) // 4楷加老锭
							{
								Gravity[i][j + 3].gravity -= 55555;
							}
							if (Gravity[i][j + 3].stone == WHITE_2014180021) // 4楷加老锭
							{
								Gravity[i][j + 2].gravity -= 55555;
							}
						}
						if (Gravity[i][j + 2].stone == WHITE_2014180021)
						{
							Gravity[i][j + 1].gravity -= 5555;
						}
					}
				}
				if (i > -1 && j + 1 < 19)
				{

					Gravity[i][j + 1].gravity -= 5;//6

					if (Gravity[i][j + 1].stone == WHITE_2014180021)
					{
						Gravity[i][j - 1].gravity -= 55;//8
						if (Gravity[i][j - 1].stone == WHITE_2014180021)
						{
							Gravity[i][j - 2].gravity -= 555;
							if (Gravity[i][j - 2].stone == WHITE_2014180021) // 4楷加老锭
							{
								Gravity[i][j - 3].gravity -= 55555;
							}
							if (Gravity[i][j - 3].stone == WHITE_2014180021) // 4楷加老锭
							{
								Gravity[i][j - 2].gravity -= 55555;
							}
						}
						if (Gravity[i][j - 2].stone == WHITE_2014180021)
						{
							Gravity[i][j - 1].gravity -= 5555;
						}

					}
				}
				if (i + 1 < 19 && j - 1 > -1)
				{
					Gravity[i + 1][j - 1].gravity -= 5;//7.

					if (Gravity[i - 1][j - 1].stone == WHITE_2014180021)
					{
						Gravity[i - 1][j + 1].gravity -= 55;//3

						if (Gravity[i - 1][j + 1].stone == WHITE_2014180021)
						{
							Gravity[i - 2][j + 2].gravity -= 555;
							if (Gravity[i - 2][j + 2].stone == WHITE_2014180021) // 4楷加老锭
							{
								Gravity[i - 3][j + 3].gravity -= 55555;
							}
							if (Gravity[i - 3][j + 3].stone == WHITE_2014180021) // 4楷加老锭
							{
								Gravity[i - 2][j + 2].gravity -= 55555;

							}

						}
						if (Gravity[i - 2][j + 2].stone == WHITE_2014180021)
						{
							Gravity[i - 1][j + 1].gravity -= 5555;
						}
					}
				}
				if (i + 1 < 19 && j > -1)
				{
					Gravity[i + 1][j].gravity -= 5;//8
					if (Gravity[i + 1][j].stone == WHITE_2014180021)
					{
						Gravity[i - 1][j].gravity -= 55;//2
						if (Gravity[i - 1][j].stone == WHITE_2014180021)
						{
							Gravity[i - 2][j].gravity -= 555;
							if (Gravity[i - 2][j].stone == WHITE_2014180021) // 4楷加老锭
							{
								Gravity[i - 3][j].gravity -= 55555;

							}
							if (Gravity[i - 3][j].stone == WHITE_2014180021) // 4楷加老锭
							{
								Gravity[i - 2][j].gravity -= 55555;
							}
						}
						if (Gravity[i - 2][j].stone == WHITE_2014180021)
						{
							Gravity[i - 1][j].gravity -= 5555;
						}
					}

				}
				if (i + 1 < 19 && j + 1 < 19)
				{

					Gravity[i + 1][j + 1].gravity -= 5;//9
					if (Gravity[i + 1][j + 1].stone == WHITE_2014180021)
					{
						Gravity[i - 1][j - 1].gravity -= 55;//8
						if (Gravity[i - 1][j - 1].stone == WHITE_2014180021)
						{
							Gravity[i - 2][j - 2].gravity -= 555;
							if (Gravity[i - 2][j - 2].stone == WHITE_2014180021) // 4楷加老锭
							{
								Gravity[i - 3][j - 3].gravity -= 55555;

							}
							if (Gravity[i - 3][j - 3].stone == WHITE_2014180021) // 4楷加老锭
							{
								Gravity[i - 2][j - 2].gravity -= 55555;

							}
						}
						if (Gravity[i - 2][j - 2].stone == WHITE_2014180021)
						{
							Gravity[i - 1][j - 1].gravity -= 5555;
						}
					}
				}

			}


		}
	}
	for (int i = 0; i < MAX_2014180021; i++)
	{
		for (int j = 0; j < MAX_2014180021; j++)
		{
			if (Gravity[i][j].stone == BLACK_2014180021 || Gravity[i][j].stone == WHITE_2014180021)
			{
				Gravity[i][j].gravity = 0;
			}

		}

	}


	for (int i = 0; i < MAX_2014180021; i++)
	{
		for (int j = 0; j < MAX_2014180021; j++)
		{
			if (abs(max) < abs(Gravity[i][j].gravity))
			{
				max = Gravity[i][j].gravity;
			}
			if (min > abs(Gravity[i][j].gravity))
			{
				min = Gravity[i][j].gravity;
			}

		}

	}
	for (int i = 0; i < MAX_2014180021; i++)
	{
		for (int j = 0; j < MAX_2014180021; j++)
		{
			if (max == Gravity[i][j].gravity)
			{
				
				Gravity[i][j].stone = WHITE_2014180021;
				*x = i;
				*y = j;
				
				return;
			}
		}
	}
}
void WhiteDefence_2014180021(int x, int y)
{
	Gravity[x][y].stone = BLACK_2014180021;
}