#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
//����������
void menu()
{
	printf("****************\n");
	printf("* 1.play 0.exit*\n");
	printf("****************\n");
}
//��Ϸ�����㷨��ʵ��
void game()
{
	char ret = 0;
	//����-����߳���������Ϣ
	char board[ROW][COL] = { 0 };//ͷ�ļ��ı䣬����������Ĵ�СҲ��ı�

	//��ʼ�����̣�ʹ��ӡ��������֮��ȫ��Ϊ�ո�
	InitBoard(board, ROW, COL);

	//��ӡ���̵ľ��庯������ô��ӡ
	DisplayBoard(board, ROW, COL);
	//����
	while (1)
	{
		//�������
		PlayMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		//�ж������Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//��������
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�жϵ�����Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else
	{
		printf("ƽ��\n");
	}
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));//ֻ�ܵ���һ�Σ�testֻ����һ�Σ����Է�������
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", & input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}	