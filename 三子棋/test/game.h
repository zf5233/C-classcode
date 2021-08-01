//函数的声明
#define ROW 3
#define COL 3
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void PlayMove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);
//4种游戏结果：继续玩下去'C'，玩家赢'*'，电脑赢'#'，平局'Q'
char IsWin(char board[ROW][COL], int row, int col);