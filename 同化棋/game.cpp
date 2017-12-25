#include"test.h"


using namespace std;


int game(int first, int next)  //返回0代表继续游戏，返回1代表回到主界面
{
	
	

	//先要判断是否已经决定输赢
	if (decide_win()) return 1;
	
	system("cls");
	jiemian(first);


	char start_x = 0;
	char start_y = 0;
	//先方下棋，1为执黑，-1为执白
	char t = 0;
	printf("存档请输入\"s\"\n返回主界面请输入\"r\"\n请选择你要移动的棋子\n");
	char temp[100] = { '\0' };
	while (true)
	{
		while (true)
		{
			t = cin.peek();
			if (t =='\n' || t==' ') getchar();
			else break;
		}
		cin.getline(temp,1000);
		if (temp[0] == 'r') return 1;
		if (temp[0] == 's')
		{
			file_output(first);
			return 1;
		}

		start_x = temp[0];
		for (int i = 1; i < 100; i++) if (temp[i] <='7' && temp[i]>='1') { start_y = temp[i]; break; }
		start_x -= '0' + 1;
		start_y -= '0' + 1;
		if (start_x <= 6 && start_x >= 0 && start_y >= 0 && start_y <= 6 && qipan[start_x][start_y] == first)
		{
			break;
		}
		else printf("Please retry.\n");
	}

	printf("请选择你要移动到的地方\n");
	int des_x = 0, des_y = 0;
	while (true)
	{
		scanf("%d%d", &des_x, &des_y);
		des_x -= 1; des_y -= 1;
		//判断1、在棋盘内；2、在十六格内；3、可以落子（目标地点为空）
		if (decide_des_nextstep(first,start_x,start_y,des_x,des_y))
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
				for (int j = -1; j <= 1; j++)
				{
					if (i == 0 && j == 0) continue;
					if (des_x + i >= 0 && des_x + i < 7 && des_y + j >= 0 && des_y + j < 7 &&
						qipan[des_x + i][des_y + j] == next)
					{
						qipan[des_x + i][des_y + j] = first;
						if (first == 1) { cnt_black++; cnt_white--; }
						else { cnt_white++; cnt_black--; }
					}
						
				}
			break;
		}
		else printf("Please retry.\n");
	}

}

int double_game(int start,int next)
{
	while (true)
	{
		system("cls");
		if (game(start, next) == 1) return 1;
		if (game(next, start) == 1) return 1;
		cnt_step++;
	}
}


int black_game()  //返回0代表继续，返回1代表返回主界面(只返回1)
{
	while (true)
	{
		system("cls");
		if(game(1, -1)==1) return 1;
		system("cls");
		jiemian(-1);
		Sleep(2000);
		ai(-1, 1);
		cnt_step++;
	}
}


int white_game()  //返回0代表继续，返回1代表返回主界面
{
	while (true)
	{
		system("cls");
		ai(1, -1);
		if (game(-1, 1) == 1) return 1;
		system("cls");
		jiemian(1);
		Sleep(2000);
		cnt_step++;
	}
}


//判断输赢情况,1表示游戏终止，一方胜利；0表示游戏继续
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
		return 1;
	}

	//2、棋盘完全下满
	if (cnt_black + cnt_white == 49)
	{
		if (cnt_black > cnt_white)
		{
			printf("黑方胜利\n");
			system("pause");
			return 1;
		}
		if (cnt_white > cnt_black)
		{
			printf("白方胜利\n");
			system("pause");
			return 1;
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
		if (cnt_black > 24) { printf("黑方胜利\n"); system("pause"); return 1; }
		else { printf("白方胜利\n"); system("pause"); return 1; }
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
		if (cnt_white > 24) { printf("白方胜利\n"); system("pause"); return 1; }
		else { printf("黑方胜利\n"); system("pause"); return 1; }
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

//判断对于黑棋或者白棋特定的子，下一步是否可以移动到目标位置。0代表可以移到，1代表不能移到
int decide_des_nextstep(int first, int x_from, int y_from, int x_to, int y_to)
{
	if (x_to < 0 || y_to < 0 || x_to>6 || x_to>6 || (x_to == x_from && y_to == y_from)
		|| abs(x_to - x_from) > 2 || abs(y_to - y_from) > 2 || qipan[x_to][y_to] != 0) return 0;
	else return 1;
}