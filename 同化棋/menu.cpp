#include"test.h"
using namespace std;

//新游戏中选择单双人模式
void f0()
{
	while (true)
	{
		system("cls");
		printf("请选择游戏模式：\n1. 单人模式\n2. 双人模式\n返回主菜单请输入'r'\n");
		char a[10] = { '\0' };
		cin.getline(a, 10);
		if (a[0] == 'r') return;
		else if (a[0] == '1')
		{
			f1();
			return;
		}
		else if (a[0] == '2')
		{
			player = 2;
			double_game(1, -1);
			return;
		}
	}
}


//新游戏中选择黑白开始。
void f1()
{
	while (true)
	{
		system("cls");
		printf("请选择执黑执白\n1.执黑\n2.执白\n返回主菜单请输入'r'\n");
		char a[10] = { '\0' };
		cin >> a;
		if (a[0] == '1') if (black_game() == 1) return; else;
		else if (a[0] == '2') if (white_game() == 1) return; else;
		else if (a[0] == 'r') return;
	}
}




//重载游戏中选择存档界面：
void f3()
{
	while (true)
	{
		system("cls");
		printf("请选择需要加载的存档\n1  2  3\n返回主界面请输入\"r\"\n");
		char a[10] = { '\0' };
		cin >> a;
		if (a[0] == 'r')  return;
		else if (a[0] == '1')
		{
			int first = file_input(1);
			if (player == 1)
			{
				if (first == 1) if (black_game() == 1) return; else;
				else { if (white_game() == 1) return; }
			}
			else
			{
				double_game(first, -first);
				return;
			}
		}
		else if (a[0] == '2')
		{
			int first = file_input(2);
			if (player == 1)
			{
				if (first == 1) if (black_game() == 1) return; else;
				else { if (white_game() == 1) return; }
			}
			else
			{
				double_game(first, -first);
				return;
			}
		}
		else if (a[0] == '3')
		{
			int first = file_input(3);
			if (player == 1)
			{
				if (first == 1) if (black_game() == 1) return; else;
				else { if (white_game() == 1) return; }
			}
			else
			{
				double_game(first, -first);
				return;
			}
		}

	}
}



void jiemian(int start)
{
	printf("这是第 %d 回合\n黑方子数：%d\n白方子数：%d\n您是 ", cnt_step, cnt_black, cnt_white);
	if (start == 1) printf("黑 方\n");
	else printf("白 方\n");
	printf("     1   2   3   4   5   6   7\n  ┏━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┓\n");
	for (int i = 0; i < 7; i++)
	{
		printf("%d ┃", i + 1);
		for (int j = 0; j < 7; j++)
		{
			if (qipan[i][j] == 1) printf(" ○┃");
			else if (qipan[i][j] == -1) printf(" ●┃");
			else printf("   ┃");
		}
		printf("\n");
		if(i!=6) printf("  ┣━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━┫\n");
	}
	printf("  ┗━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┛\n");
}




