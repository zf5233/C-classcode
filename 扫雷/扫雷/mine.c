#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"mine.h"
void menu()
{
	printf("******************\n");
	printf("***** 1.play *****\n");
	printf("***** 0.exit *****\n");
	printf("******************\n");
}
void game()
{
	//雷的信息存储
	//布置好的雷的信息
	char mine[ROWS][COLS] = { 0 };
	//排查出的雷的信息
	char show[ROWS][COLS] = { 0 };//创建数组是11*11，所以在头文件中都是11*11
	//初始化
	InitBoard(mine, ROWS, COLS,'0');
	InitBoard(show, ROWS, COLS, '*');//设置成11*11，使mine成功对应起来
	//打印棋盘
	//DisplayBoard(mine,ROW,COL);
	DisplayBoard(show, ROW, COL);//传的是11*11，操作的是9*9
	//布置雷
	SetMine(mine,ROW,COL);
	//DisplayBoard(mine, ROW, COL);
	//扫雷过程的函数
	SaoLei(mine,show,ROW,COL);

}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do 
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，重新选择！\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}
//已基本写完，但需要展开一片的话，需要用到递归函数，自己完成