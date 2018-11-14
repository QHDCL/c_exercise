#ifndef __MINE_H__
#define __MINE_H__

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include<time.h>

typedef unsigned int unit;

enum MINE_COUNT{
	EASY_COUNT = 79
};

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

void InitBoard(char board[ROWS][COLS], int rows, int cols,char set);
void PrintBoard(char board[ROWS][COLS], int row, int col);
void SetMine(char board[ROWS][COLS], int row, int col);
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
int GetMineGount(char mine[ROWS][COLS], int x, int y);
void MoveLei(char mine[ROWS][COLS], int x, int y);

#endif //__MINE_H__