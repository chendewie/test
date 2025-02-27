#include "game.h"

void menu()
{
	printf("**************************\n");
	printf("**********1.play**********\n");
	printf("**********0.exit**********\n");
	printf("**************************\n");
}

void game()
{
	char mine[ROWS][COLS] = { 0 };//原始雷信息 
	char show[ROWS][COLS] = { 0 };	//展示信息 
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');//初始化 
	SetMine(mine, ROW, COL);//buzhi

	PrintBoard(mine, ROW, COL);
	printf("\n");
	PrintBoard(show, ROW, COL);//打印 
	
	SafeMine(mine, show);//pailei

	PrintBoard(mine, ROW, COL);
	printf("\n");
	PrintBoard(show, ROW, COL);

	ClearMine(mine, show, ROW, COL);
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：");
		scanf_s("%d", &input);
		printf("——————————\n");
		switch (input)
		{
		case 1:game();
			break;
		case 0:printf("退出游戏！\n");
			break;
		default:printf("选择错误！\n");
			break;
		}
	} while (input);
}

int main(int argc, char* argv[])
{
	test();
	return 0;
}