#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void menu()  //��ӡ�˵� 
{
	printf("*****************************\n");
	printf("***  ��ӭ�������������  ****\n");
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
		printf("�����->\n");
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		win = IsWin(board, ROW, COL);
		if (win != ' ')
		{
			break;
		}
		printf("������->\n");
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
		printf("���Ӯ��\n");
	}
	else if (win == '0')
	{
		printf("����Ӯ��\n");
	}
	else
	{
		printf("ƽ��\n");
	}
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do{
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("���������������������룡\n");
		}
	} while (input);
}
int main()
{
	test();
	system("pause");
	return 0;
}
