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
			board[i][j] =set;//根据show/mine初始化一个值，设置一个set更方便
		}
	}
}
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	//打印列号
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);//行号
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
		int x = rand()%row+1;//坐标范围：1-9
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
	 //'1'-'0'= 1  '3'-'0'=3  把周围数字减去后加起来
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
	int win = 0;//71个不是雷

	while (win<row*col-Easy_Count)
	{
		printf("请输入排查雷的坐标:>");
		scanf("%d%d", &x, &y);
		//判断坐标是否合法
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//坐标合法:1,踩雷 2,统计雷的数量
			if (mine[x][y] == '1')
			{
				printf("你被炸死了!\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else
			{
				//统计雷的数量
				int count = get_mine(mine, x, y);
				show[x][y] = count + '0';
				DisplayBoard(show, row, col);
			}
		}
		else
		{
			printf("输入坐标非法，请重新输入!\n");
		}
	}
	if (win == row * col - Easy_Count)
	{
		printf("排雷成功！\n");
		DisplayBoard(mine, row, col);
	}
}