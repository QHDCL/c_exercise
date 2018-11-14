#include"mine.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set){
	int i = 0;
	int j = 0; 
	for (i = 0; i < rows; i++){
		for (j = 0; j < cols; j++){
			board[i][j] = set;
		}
	}
}

void PrintBoard(char board[ROWS][COLS], int row, int col){
	int i = 0;
	int j = 0;
	printf("   ");
	for (i = 1; i <= row; i++)
	{
		printf("%3d", i);
	}
	printf("\n");
	for (i = 0; i <= row; i++)
	{
		printf("---");
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%2d|", i);
		for (j = 1; j <= col; j++)
		{
			printf("%3c", board[i][j]);
		}
		printf("\n");
	}

}


void SetMine(char board[ROWS][COLS], int row, int col){
	int count = EASY_COUNT;
	while (count){
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0'){
			board[x][y] = '1';
			count--;
		}
	}
}

int GetMineGount(char mine[ROWS][COLS], int x, int y){
	return mine[x - 1][y] + mine[x - 1][y - 1] + mine[x][y - 1] +
		mine[x + 1][y - 1] + mine[x + 1][y] +
		mine[x + 1][y + 1] + mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';
}


void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col){
	int x = 0;
	int y = 0;
	int win = 0;
	int temp = 0;

	while (win<col*row - EASY_COUNT){
		printf("Please Enter: <x,y>\n");
		scanf("%d%d", &x, &y);
		temp++;
		if (x > 0 && x <= row && y > 0 && y <= col){
			while ((mine[x][y] == '1') && (temp == 1)){
				MoveLei(mine, x, y);
				GetMineGount(mine, x, y);
				
			}if (mine[x][y] == '1'){
				printf("You Die!\n");
				PrintBoard(mine, ROW, COL);
				break;
			}
			else{
				int count = 0;
				win++;
				count = GetMineGount(mine, x, y);
				show[x][y] = count + '0';
				PrintBoard(show, ROW, COL);
			}
		}
		else{
			printf("Enter Error!\n");
		}
	}
	if (win == col*row - EASY_COUNT){
		printf("Find Mine Succes!\n");
		PrintBoard(mine, ROW, COL);
	}
}

void MoveLei(char mine[ROWS][COLS], int x, int y)
{
	int ret = 1;
	do
	{
		mine[x][y] == '0';
		while (ret)
		{
			x = rand() % ROW + 1;
			y = rand() % COL + 1;
			if (mine[x][y] == '1')
			{
				mine[x][y] = '1';
			}
			ret--;
		}
	} while (ret);
	
}


