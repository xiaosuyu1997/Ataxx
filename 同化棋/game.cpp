#include"test.h"
using namespace std;


int game(int first)  //返回0代表继续游戏，返回1代表回到主界面
{
	while (true)
	{
		system("cls");
		jiemian(first);

		int start_x = 0, start_y = 0;
		int des_x = 0, des_y = 0;


		printf("存档请输入\"s\"\n返回主界面请输入\"r\"\n请选择你要移动的棋子:输入格式\"x y\"\n悔棋请输入\"c\"\n");

		while (true)
		{
			while (cin.peek() == '\n') getchar();

			char temp[100] = { '\0' };
			cin.getline(temp, 1000);
			if (temp[0] != 'r' && temp[0] != 's' && temp[0] != 'c' && !(temp[0] <= '7' && temp[0] >= '1')) { printf("please retry\n"); continue;  }
			if (temp[0] == 'r') return 1;
			if (temp[0] == 's')
			{
				file_output(first);
				system("cls");
				jiemian(first);
				printf("存档请输入\"s\"\n返回主界面请输入\"r\"\n请选择你要移动的棋子:输入格式\"x y\"\n悔棋请输入\"c\"\n");
				continue;
			}
			if (temp[0] == 'c')
				if (player == 1)
				{
					if (cnt_step == 1)
					{
						printf("已经不能悔棋了\n");
						printf("存档请输入\"s\"\n返回主界面请输入\"r\"\n请选择你要移动的棋子:输入格式\"x y\"\n悔棋请输入\"c\"\n");
						continue;
					}

					cnt_step -= 1;
					cnt_black = 0; cnt_white = 0;
					for (int i = 0; i < 7; i++)
						for (int j = 0; j < 7; j++)
						{
							qipan[i][j] = cunpan[cnt_step - 1][i][j];
							if (qipan[i][j] == 1) cnt_black++;
							else if (qipan[i][j] == -1) cnt_white++;
						}
					system("cls");
					jiemian(first);
					printf("存档请输入\"s\"\n返回主界面请输入\"r\"\n请选择你要移动的棋子:输入格式\"x y\"\n");
					continue;
				}
				else if(first==1)
				{
					if (cnt_step == 1)
					{
						printf("已经不能悔棋了\n");
						printf("存档请输入\"s\"\n返回主界面请输入\"r\"\n请选择你要移动的棋子:输入格式\"x y\"\n悔棋请输入\"c\"\n");
						continue;
					}

					cnt_step -= 1;
					cnt_black = 0; cnt_white = 0;
					for (int i = 0; i < 7; i++)
						for (int j = 0; j < 7; j++)
						{
							qipan[i][j] = black_cunpan[cnt_step - 1][i][j];
							if (qipan[i][j] == 1) cnt_black++;
							else if (qipan[i][j] == -1) cnt_white++;
						}
					system("cls");
					jiemian(first);
					printf("存档请输入\"s\"\n返回主界面请输入\"r\"\n请选择你要移动的棋子:输入格式\"x y\"\n");
					continue;
				}
				else if (first == -1)
				{
					if (cnt_step == 1)
					{
						printf("已经不能悔棋了\n");
						printf("存档请输入\"s\"\n返回主界面请输入\"r\"\n请选择你要移动的棋子:输入格式\"x y\"\n悔棋请输入\"c\"\n");
						continue;
					}

					cnt_step -= 1;
					cnt_black = 0; cnt_white = 0;
					for (int i = 0; i < 7; i++)
						for (int j = 0; j < 7; j++)
						{
							qipan[i][j] = white_cunpan[cnt_step - 1][i][j];
							if (qipan[i][j] == 1) cnt_black++;
							else if (qipan[i][j] == -1) cnt_white++;
						}
					system("cls");
					jiemian(first);
					printf("存档请输入\"s\"\n返回主界面请输入\"r\"\n请选择你要移动的棋子:输入格式\"x y\"\n");
					continue;
				}
			

			if (temp[1] != ' ' || !(temp[2] <= '7'&& temp[2] >= '1')) { printf("please retry\n"); continue; }
			start_x = temp[0] - '0' - 1;
			start_y = temp[2] - '0' - 1;

			if (qipan[start_x][start_y] == first && decide_num_nextstep(first, start_x, start_y) > 0)
			{
				break;
			}
			else printf("Please retry.\n");
		}

		printf("请选择你要移动到的地方   重新选子请输入\"c\"\n");

		while (true)
		{
			while (cin.peek() == '\n') getchar();

			char temp[1000] = { '\0' };
			cin.getline(temp, 1000);
			if (temp[0] != 'c' && !(temp[0] >= '1' && temp[0] <= '7')) { printf("please retry\n"); continue; }
			if (temp[0] == 'c') break;

			if (temp[1] != ' ' || !(temp[2] >= '1' && temp[2] <= '7')) { printf("please retry\n"); continue; }

			des_x = temp[0] - '0' - 1;
			des_y = temp[2] - '0' - 1;
			//判断1、在棋盘内；2、在十六格内；3、可以落子（目标地点为空）
			if (decide_des_nextstep(first, start_x, start_y, des_x, des_y))
			{
				//16位的情况：
				if (abs(des_x - start_x) == 2 || abs(des_y - start_y) == 2)
				{
					qipan[start_x][start_y] = 0;
					qipan[des_x][des_y] = first;
				}
				//8位的情况：
				else
				{
					qipan[des_x][des_y] = first;
					if (first == 1) cnt_black++;
					else cnt_white++;
				}
				for (int i = -1; i <= 1; i++)
				{
					if (des_x + i < 0 || des_x + i > 6) continue;
					for (int j = -1; j <= 1; j++)
					{
						if ((i == 0 && j == 0) || des_y + j < 0 || des_y + j > 6) continue;
						if (qipan[des_x + i][des_y + j] == -first)
						{
							qipan[des_x + i][des_y + j] = first;
							if (first == 1) { cnt_black++; cnt_white--; }
							else { cnt_white++; cnt_black--; }
						}
					}
				}
				if (first == 1)
				{
					for(int i=0;i<7;i++)
						for (int j = 0; j < 7; j++)
						{
							white_cunpan[cnt_step - 1][i][j] = qipan[i][j];
						}
				}
				else
				{
					for (int i = 0; i<7; i++)
						for (int j = 0; j < 7; j++)
						{
							black_cunpan[cnt_step][i][j] = qipan[i][j];
						}
				}
				return 0;
			}
			else printf("Please retry.\n");
		}
	}

}


//双人游戏区
void double_game(int first)
{
	while (true)
	{
		cnt_step++;
		system("cls");
		if (game(first) == 1) return;
		if (decide_win() != 0 ) return;
		

		if (game(-first) == 1) return;
		if (decide_win() != 0) return;
	}
}




//单人游戏区
void black_game()  //返回0代表继续，返回1代表返回主界面(只返回1)
{
	while (true)
	{
		cnt_step++;
		system("cls");
		if(game(1)==1) return;
		int t = decide_win();
		if (t == 1)
		{
			f3_2(1, 1);
			return;
		}
		else if (t == -1)
		{
			f3_2(0, 1);
			return;
		}

		

		system("cls");
		jiemian(-1);
		Sleep(1000);

		ai(-1);
		t = decide_win();
		if (t == 1)
		{
			f3_2(1, 1);
			return;
		}
		else if (t == -1)
		{
			f3_2(0, 1);
			return;
		}

		for (int i = 0; i<7; i++)
			for (int j = 0; j < 7; j++)
			{
				cunpan[cnt_step][i][j] = qipan[i][j];
			}
	}
}

void white_game()  //返回0代表继续，返回1代表返回主界面
{
	while (true)
	{
		cnt_step++;
		system("cls");
		jiemian(-1);
		Sleep(1000);
		ai(1);
		int t = decide_win();

		if (t == 1)
		{
			f3_2(0, 1);
			return;
		}
		else if (t == -1)
		{
			f3_2(1, 1);
			return;
		}

		for (int i = 0; i<7; i++)
			for (int j = 0; j < 7; j++)
			{
				cunpan[cnt_step - 1][i][j] = qipan[i][j];
			}
		
		if (game(-1) == 1) return;

		t = decide_win();
		if (t == 1)
		{
			f3_2(0, 1);
			return;
		}
		else if (t == -1)
		{
			f3_2(1, 1);
			return;
		}
	}
}


//判断输赢情况,1表示黑方胜利，-1代表白方胜利；0表示游戏继续
/*
输赢的可能;
1、一方无法落子
2、棋盘完全下满
3、一方全部子都被吃掉
*/
int decide_win()
{
	//3、一方全部子都被吃掉
	if (cnt_black == 0)
	{
		printf("黑方胜利\n");
		return 1;
	}
	if (cnt_white == 0)
	{
		printf("白方胜利\n");
		system("pause");
		return -1;
	}

	//2、棋盘完全下满
	if (cnt_black + cnt_white == 49)
	{
		if (cnt_black > cnt_white)
		{
			system("cls"); jiemian(1);
			printf("黑方胜利\n");
			system("pause");
			return 1;
		}
		if (cnt_white > cnt_black)
		{
			system("cls"); jiemian(-1);
			printf("白方胜利\n");
			system("pause");
			return -1;
		}
	}

	//1、一方无法落子
	//黑方无法落子
	int sum_black = 0;
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
		{
			if (qipan[i][j] == 1) sum_black += decide_num_nextstep(1, i, j);
		}
	if (sum_black == 0)
	{
		if (cnt_black > 24) { system("cls"); jiemian(1); printf("黑方胜利\n"); system("pause"); return 1; }
		else { system("cls"); jiemian(-1); printf("白方胜利\n"); system("pause"); return -1; }
	}
	//白方无法落子
	int sum_white = 0;
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
		{
			if (qipan[i][j] == -1) sum_white += decide_num_nextstep(-1, i, j);
		}
	if (sum_white == 0)
	{
		if (cnt_white > 24) { system("cls"); jiemian(-1); printf("白方胜利\n"); system("pause"); return -1; }
		else { system("cls"); jiemian(1); printf("黑方胜利\n"); system("pause"); return 1; }
	}


	//默认返回0；
	return 0;
}

//判断对于黑棋或者白棋特定的子，下一步可以移动的位置的数目。
int decide_num_nextstep(int first, int x, int y)
{
	int sum = 0;
	for (int i = -2; i <= 2; i++)
	{
		if (i + x < 0 || i + x >6) continue;
		for (int j = -2; j <= 2; j++)
		{
			if (j + y < 0 || j + y >6 || (i == 0 && j == 0)) continue;
			if (qipan[i + x][j + y] == 0) sum++;
		}
	}
	return sum;
}

//判断对于黑棋或者白棋特定的子，下一步是否可以移动到目标位置。0代表不能移到，1代表可以移到
int decide_des_nextstep(int first, int x_from, int y_from, int x_to, int y_to)
{
	if (x_to < 0 || y_to < 0 || x_to>6 || x_to>6 || (x_to == x_from && y_to == y_from)
		|| abs(x_to - x_from) > 2 || abs(y_to - y_from) > 2 || qipan[x_to][y_to] != 0) return 0;
	else return 1;
}