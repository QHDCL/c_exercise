#include"mine.h"

void meau(){
	printf("*****************************\n");
	printf("****   欢迎进入扫雷界面  ****\n");
	printf("*****************************\n");
	printf("****  1 play     0 exit  ****\n");
	printf("*****************************\n");
}

void game(){
	char mine[ROWS][COLS];
	char show[ROWS][COLS];

	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	SetMine(mine, ROW, COL);

	PrintBoard(mine, ROW, COL);
	PrintBoard(show, ROW, COL);
	MoveLei(mine, ROW, COL);
	FindMine(mine, show, ROW, COL);
	

	
}

void test(){
	int select = 0;
	srand((unit)time(NULL));
	do{
		meau();
		printf("Please Enter Your Select:");
		scanf("%d", &select);
		switch (select){
		case 1:
			game();
			break;
		case 0:
			exit(0);
		default:
			break;
		}
	} while (select);
	
}


int main(){
	test();
	system("pause");
	return 0;
}