#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void menu()  //打印菜单 
{
	printf("*****************************\n");
	printf("***  欢迎进入三子棋界面  ****\n");
	printf("*****************************\n");
	printf("****  1 play     0 exit  ****\n");
	printf("*****************************\n");
}
void game()
{
	char win = 0;
	int c;
	char board[ROW][COL] = { 0 };
	InitBoard(board, ROW, COL);
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		printf("玩家走->\n");
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		win = IsWin(board, ROW, COL);
		if (win != ' ')
		{
			break;
		}
		printf("电脑走->\n");
		Computermove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		win = IsWin(board, ROW, COL);
		if (win != ' ')
		{
			break;
		}
	}
	if (win == 'x')
	{
		printf("玩家赢了\n");
	}
	else if (win == '0')
	{
		printf("电脑赢了\n");
	}
	else
	{
		printf("平局\n");
	}
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do{
		menu();
		printf("请选择：");
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
			printf("您的输入有误，请重新输入！\n");
		}
	} while (input);
}
int main()
{
	test();
	system("pause");
	return 0;
}
