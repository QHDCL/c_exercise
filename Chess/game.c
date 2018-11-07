#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void InitBoard(char board[ROW][COL], int row, int col)  //��ʼ������
{
	int i = 0;
	int j = 0;
	for (i = 0; i<row; i++)
	{
		for (j = 0; j<col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void DisplayBoard(char board[ROW][COL], int row, int col)  //��ӡ��ʾ����
{
	int i=0;
	for (i = 0; i < row; i++)
	{
		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
		if (i < (row - 1)){
			printf("---|---|---\n");
		}
	}
	
}
	
void PlayerMove(char board[ROW][COL], int row, int col)   //����ߵĺ���
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("����ߣ�������������꡷\n");
		scanf("%d%d", &x, &y);
		if ((x >= 0 && x <= row) && (y >= 0 && y <= col))
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'x';
				break;
			}
			else
			{
				printf("�˴����߹�����������\n");
			}
		}
		else
		{
			printf("������������������\n");
		}
	}
}
void Computermove(char board[ROW][COL], int row, int col)   //�����ߵĺ���
{
	while (1)
	{
		int x = rand() % 3;
		int y = rand() % 3;
		if (board[x][y] == ' ')
		{
			board[x][y] = '0';
			break;
		}
	}
}
static int  is_full(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i<row; i++)
	{
		for (j = 0; j<col; j++)
		{
			if (board[i][j] == ' ')  //���̻��п�λ��
				return 0;
		}
	}
	return 1;     //�������� 
}

char IsWin(char board[ROW][COL], int row, int col)   //�ж��Ƿ�Ӯ��
{
	//���Ӯ   ����Ӯ
	int i = 0;
	for (i = 0; i<row; i++)  //��������Ӯ��
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
	for (i = 0; i<col; i++)   //��������Ӯ��
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}
	}
	//б������Ӯ��
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (is_full(board, row, col))
	{
		return 'Q';            //ƽ��
	}
	return ' ';  //������Ϸ
}
