#define _CRT_SECURE_NO_WARNINGS 1
#include"mine.h"
void InitBoard(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] =set;//����show/mine��ʼ��һ��ֵ������һ��set������
		}
	}
}
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	//��ӡ�к�
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);//�к�
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = Easy_Count;
	while (count)
	{
		int x = rand()%row+1;//���귶Χ��1-9
		int y = rand()%col+1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}
int get_mine(char mine[ROWS][COLS], int x, int y)
{
	 //'1'-'0'= 1  '3'-'0'=3  ����Χ���ּ�ȥ�������
	return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';
}
void SaoLei(char mine[ROWS][COLS],char show[ROWS][COLS], int row, int col) 
{
	int x = 0;
	int y = 0;
	int win = 0;//71��������

	while (win<row*col-Easy_Count)
	{
		printf("�������Ų��׵�����:>");
		scanf("%d%d", &x, &y);
		//�ж������Ƿ�Ϸ�
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//����Ϸ�:1,���� 2,ͳ���׵�����
			if (mine[x][y] == '1')
			{
				printf("�㱻ը����!\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else
			{
				//ͳ���׵�����
				int count = get_mine(mine, x, y);
				show[x][y] = count + '0';
				DisplayBoard(show, row, col);
			}
		}
		else
		{
			printf("��������Ƿ�������������!\n");
		}
	}
	if (win == row * col - Easy_Count)
	{
		printf("���׳ɹ���\n");
		DisplayBoard(mine, row, col);
	}
}