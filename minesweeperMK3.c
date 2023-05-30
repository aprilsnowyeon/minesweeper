
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define rows 14
#define cols 14
#define startmines 40

void victory()
{
	getch();
	system("cls");
	printf("���������������������������������\n");
	printf("���������������������������������\n");
	printf("���������������������������������\n");
	printf("���������������������������������\n");
	printf("���������������������������������\n");
	printf("���������������������������������\n");
	printf("���������������������������������\n");
	printf("���������������������������������\n");
	printf("���������������������������������\n");
	printf("���������������������������������\n");
	printf("���������������������������������\n");
	printf("���������������������������������\n");
	printf("���������������������������������\n");
	printf("���������������������������������\n");
	printf("���������������������������������\n");
	printf("���������������������������������\n");
	printf("���������������������������������\n");
	printf("���������������������������������\n");
	printf("���������������������������������\n");
	printf("���������������������������������\n");
	printf("���������������������������������\n");
}
void gameover() ////////////////////////////////////////////////////////////////////////�ڶ����� ȣ���� ������ �ڵ�
{
	getch();
	system("cls");
	printf("���������������������������������\n");
	printf("���������������������������������\n");
	printf("���������������������������������\n");
	printf("���������������������������������\n");
	printf("���������������������������������\n");
	printf("���������������������������������\n");
	printf("���������������������������������\n");
	printf("���������������������������������\n");
	printf("���������������������������������\n");
	printf("���������������������������������\n");
	printf("���������������������������������\n");
	printf("���������������������������������\n");
	printf("���������������������������������\n");
	printf("���������������������������������\n");
	printf("���������������������������������\n");
	printf("���������������������������������\n");
	printf("���������������������������������\n");
	printf("���������������������������������\n");
	printf("���������������������������������\n");
	printf("���������������������������������\n");
	printf("���������������������������������\n");
}


//Ŭ���� : ��, Ŭ���� : ��� F, 0 : ��, ���� : ����
void fieldgraphic(int field[rows][cols], int flag[rows][cols], int x, int y, int findmines)
{
	system("cls");
	
	printf("ã�� ���ڼ� : %d", findmines);
	printf(" / ���� ���ڼ� : %d\n", startmines - findmines);
	
	printf("   ");
	for (int ii = 0; ii < cols; ii++)
	{
		if (ii + 1 < 10)
			printf(" ");
		printf("%d", ii + 1);
	}

	printf("\n");

	for (int ii = 0; ii < rows; ii++)
	{
		if (ii + 1 < 10)
			printf(" ");
		printf("%d ", ii + 1);
		for (int jj = 0; jj < cols; jj++)
		{
			if (ii == x - 1 && jj == y - 1)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			}
			else
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			if (flag[ii][jj] == 1)
				printf(" F");
			else if (field[ii][jj] == 10)
				printf("  ");
			else if (field[ii][jj] != 'm' && field[ii][jj] > 10)
			{
				printf(" %d", field[ii][jj] - 10);
			}
			else if (field[ii][jj] == 'm' || field[ii][jj] < 10)
				printf("��");
		}
		if (ii + 1 == x)
			printf("��");
		printf("\n");
	}
	printf(" ");
	for (int ii = 0; ii < y; ii++)
		printf("  ");
	printf("��");
	printf("\n");
}

void fieldxray(int field[rows][cols]) //����׿� ������
{
	for (int ii = 0; ii < rows; ii++)
	{
		if (ii + 1 < 10)
			printf(" ");
		printf("%d ", ii + 1);
		for (int jj = 0; jj < cols; jj++)
		{
			if (field[ii][jj] == 'm')
				printf(" m");
			else
			{
				if (field[ii][jj] < 10)
					printf(" %d", field[ii][jj]);
				else
					printf("%d", field[ii][jj]);
			}
		}
		printf("\n");
	}
}

void flagxray(int flag[rows][cols]) //����׿� ������
{
	for (int ii = 0; ii < rows; ii++)
	{
		if (ii + 1 < 10)
			printf(" ");
		printf("%d ", ii + 1);
		for (int jj = 0; jj < cols; jj++)
		{
			if (flag[ii][jj] == 'F')
				printf(" F");
			else
			{
				if (flag[ii][jj] < 10)
					printf(" %d", flag[ii][jj]);
				else
					printf("%d", flag[ii][jj]);
			}
		}
		printf("\n");
	}
}

main()
{
	srand(time(NULL));
	int field[rows][cols] = { 0 };
	int flag[rows][cols] = { 0 };
	int mines = startmines;
	int findmines = 0;
	int safeplace = 0;
	int x = 1, y = 1;
	int key=0;

	fieldgraphic(field, flag, x, y, findmines);
	while (mines > 0) //�ʵ� ����
	{
		for (int ii = 0; ii < rows; ii++)
		{
			for (int jj = 0; jj < rows; jj++)
			{
				if (rand() % 1000 == 0 && field[ii][jj] != 'm')
				{
					field[ii][jj] = 'm';
					mines -= 1;
				}
			}
		}
	}

	for (int ii = 0; ii < rows; ii++)
	{
		for (int jj = 0; jj < cols; jj++)
		{
			if (field[ii][jj] != 'm')
			{
				if (field[ii - 1][jj - 1] == 'm' && ii != 0 && jj != 0)
					field[ii][jj] += 1;
				if (field[ii][jj - 1] == 'm' && jj != 0)
					field[ii][jj] += 1;
				if (field[ii + 1][jj - 1] == 'm' && ii != rows - 1 && jj != 0)
					field[ii][jj] += 1;
				if (field[ii - 1][jj] == 'm' && ii != 0)
					field[ii][jj] += 1;
				if (field[ii + 1][jj] == 'm' && ii != rows - 1)
					field[ii][jj] += 1;
				if (field[ii - 1][jj + 1] == 'm' && ii != 0 && jj != cols - 1)
					field[ii][jj] += 1;
				if (field[ii][jj + 1] == 'm' && jj != cols - 1)
					field[ii][jj] += 1;
				if (field[ii + 1][jj + 1] == 'm' && ii != rows - 1 && jj != cols - 1)
					field[ii][jj] += 1;
			}
		}
	}

	while (1)
	{
		while (1) // ������Ʈ
		{
			if (kbhit())
			{
				key = getch();
				if (key == 224)
				{
					key = getch();
					switch (key)
					{
					case 80: //��
						x++;
						if (x >= rows)
							x = rows;
						break;
					case 72: //��
						x--;
						if (x < 1)
							x = 1;
						break;
					case 77: //��
						y++;
						if (y >= rows)
							y = rows;
						break;
					case 75: //��
						y--;
						if (y < 1)
							y = 1;
						break;
					}
				}
				else if (key == 'd' || key == 'f')
					break;
				fieldgraphic(field, flag, x, y, findmines);
				fieldxray(field);//////////////////////////////////////////////����׿� ������
			}
		}
		if (key=='d') //���ı���Ʈ
		{
			//fieldxray(field);
			/*
			printf("�� �ı� ������ǥ, ������ǥ �Է� : ");
			scanf(" %d %d", &x, &y);
			getchar();
			*/
			if (field[x - 1][y - 1] <= 18 && field[x - 1][y - 1] >= 10 || flag[x - 1][y - 1] == 1)//10~18���� ������ ���� �ٽô����� ��
			{
			}
			else
			{
				if (field[x - 1][y - 1] == 'm') //////////////////////////////////////���ڹ���
				{
					system("cls");
					printf("   ");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					for (int ii = 0; ii < cols; ii++)
					{
						if (ii + 1 < 10)
							printf(" ");
						printf("%d", ii + 1);
					}
					printf("\n");

					for (int ii = 0; ii < rows; ii++)
					{
						if (ii + 1 < 10)
							printf(" ");
						printf("%d ", ii + 1);
						for (int jj = 0; jj < cols; jj++)
						{
							if (field[ii][jj] == 'm')
							{
								if (flag[ii][jj] == 1)
									printf(" F");
								else
									printf(" m");
							}
							else if (field[ii][jj] > 10)
								printf(" %d", field[ii][jj] - 10);
							else if (field[ii][jj] == 10 || field[ii][jj] == 0)
								printf("  ");
							else
								if (flag[ii][jj] == 1)
									printf(" X");
								else if (flag[ii][jj] == 0)
									printf(" %d", field[ii][jj]);
						}
						printf("\n");
					}
					gameover();
					return;
				}/////////////////////////////////////////////////////////////////////���ڹ���
				else//////////////////////////////////////////////////////////////////���ھȹ���
				{
					field[x - 1][y - 1] += 10;
					flag[x - 1][y - 1] = 3;

					if (field[x - 1][y - 1] == 10)///////////////////////////////////////////////////////////////////////////////////0 ����
					{
						for (int kk = 0; kk < 2; kk++) //�밢 ���� ����
						{
							for (int ii = 0; ii < rows; ii++)
							{
								for (int jj = 0; jj < cols; jj++)
								{
									if (field[ii][jj] != 'm' && field[ii][jj] < 10)
									{
										int temp = field[ii][jj];
										if (field[ii - 1][jj - 1] == 10 && ii != 0 && jj != 0)
										{
											flag[ii][jj] = 3;
											field[ii][jj] = temp + 10;
										}
										if (field[ii][jj - 1] == 10 && jj != 0)
										{
											flag[ii][jj] = 3;
											field[ii][jj] = temp + 10;
										}
										if (field[ii + 1][jj - 1] == 10 && ii != rows - 1 && jj != 0)
										{
											flag[ii][jj] = 3;
											field[ii][jj] = temp + 10;
										}
										if (field[ii - 1][jj] == 10 && ii != 0)
										{
											flag[ii][jj] = 3;
											field[ii][jj] = temp + 10;
										}
										if (field[ii + 1][jj] == 10 && ii != rows - 1)
										{
											flag[ii][jj] = 3;
											field[ii][jj] = temp + 10;
										}
										if (field[ii - 1][jj + 1] == 10 && ii != 0 && jj != cols - 1)
										{
											flag[ii][jj] = 3;
											field[ii][jj] = temp + 10;
										}
										if (field[ii][jj + 1] == 10 && jj != cols - 1)
										{
											flag[ii][jj] = 3;
											field[ii][jj] = temp + 10;
										}
										if (field[ii + 1][jj + 1] == 10 && ii != rows - 1 && jj != cols - 1)
										{
											flag[ii][jj] = 3;
											field[ii][jj] = temp + 10;
										}
									}
								}
							}
							for (int ii = rows - 1; ii >= 0; ii--)
							{
								for (int jj = cols - 1; jj >= 0; jj--)
								{
									if (field[ii][jj] != 'm' && field[ii][jj] < 10)
									{
										int temp = field[ii][jj];
										if (field[ii - 1][jj - 1] == 10 && ii != 0 && jj != 0)
										{
											flag[ii][jj] = 3;
											field[ii][jj] = temp + 10;
										}
										if (field[ii][jj - 1] == 10 && jj != 0)
										{
											flag[ii][jj] = 3;
											field[ii][jj] = temp + 10;
										}
										if (field[ii + 1][jj - 1] == 10 && ii != rows - 1 && jj != 0)
										{
											flag[ii][jj] = 3;
											field[ii][jj] = temp + 10;
										}
										if (field[ii - 1][jj] == 10 && ii != 0)
										{
											flag[ii][jj] = 3;
											field[ii][jj] = temp + 10;
										}
										if (field[ii + 1][jj] == 10 && ii != rows - 1)
										{
											flag[ii][jj] = 3;
											field[ii][jj] = temp + 10;
										}
										if (field[ii - 1][jj + 1] == 10 && ii != 0 && jj != cols - 1)
										{
											flag[ii][jj] = 3;
											field[ii][jj] = temp + 10;
										}
										if (field[ii][jj + 1] == 10 && jj != cols - 1)
										{
											flag[ii][jj] = 3;
											field[ii][jj] = temp + 10;
										}
										if (field[ii + 1][jj + 1] == 10 && ii != rows - 1 && jj != cols - 1)
										{
											flag[ii][jj] = 3;
											field[ii][jj] = temp + 10;
										}
									}
								}
							}
						}
					}//////////////////////////////////////////////////////////////////////////////////////////////////////////////////0����
				}
			}
		}
		if (key == 'f')
		{
			if (flag[x - 1][y - 1] == 0)
			{
				flag[x - 1][y - 1] = 1;
				findmines++;
			}
			else if (flag[x - 1][y - 1] == 1)
			{
				flag[x - 1][y - 1] = 0;
				findmines--;
			}
		}
		safeplace = 0;
		for (int ii = 0; ii < rows; ii++)
		{
			for (int jj = 0; jj < cols; jj++)
			{
				if (flag[ii][jj] == 3)
					safeplace++;
			}
		}
		if (safeplace == rows * cols - startmines)
		{
			system("cls");
			printf("   ");
			for (int ii = 0; ii < cols; ii++)
			{
				if (ii + 1 < 10)
					printf(" ");
				printf("%d", ii + 1);
			}
			printf("\n");

			for (int ii = 0; ii < rows; ii++)
			{
				if (ii + 1 < 10)
					printf(" ");
				printf("%d ", ii + 1);
				for (int jj = 0; jj < cols; jj++)
				{
					if (field[ii][jj] == 'm')
					{
						if (flag[ii][jj] == 1)
							printf(" F");
						else
							printf(" m");
					}
					else if (field[ii][jj] > 10)
						printf(" %d", field[ii][jj] - 10);
					else if (field[ii][jj] == 10 || field[ii][jj] == 0)
						printf("  ");
					else
						if (flag[ii][jj] == 1)
							printf(" X");
						else if (flag[ii][jj] == 0)
							printf(" %d", field[ii][jj]);
				}
				printf("\n");
			}
			victory();
			return;
		}
		//printf("%d", safeplace);
		fieldgraphic(field, flag, x, y, findmines);
		//flagxray(flag);
	}
}