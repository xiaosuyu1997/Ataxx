#include"test.h"

using namespace std;

int main()
{
	while (true)
	{
		system("cls");
		printf("欢迎来玩同化棋\n1. 新开局\n2. 从存档开始\n3. 观战\n4. 查看战绩\n5. 退出\n");
		char a[100] = { '\0' };
		cin.getline(a, 100);
		if (a[0] == '1')
		{
			for (int i = 0; i < 7; i++)
				for (int j = 0; j < 7; j++)
					qipan[i][j] = 0;

			qipan[0][0] = 1;
			qipan[6][6] = 1;
			qipan[6][0] = -1;
			qipan[0][6] = -1;
			cunpan[0][0][0] = cunpan[0][6][6] = 1;
			cunpan[0][6][0] = cunpan[0][0][6] = -1;
			white_cunpan[0][0][0] = white_cunpan[0][6][6] = 1;
			black_cunpan[0][0][0] = black_cunpan[0][6][6] = 1;
			white_cunpan[0][0][6] = white_cunpan[0][6][0] = -1;
			black_cunpan[0][0][6] = black_cunpan[0][6][0] = -1;
			cnt_step = 0;
			cnt_black = 2; cnt_white = 2;
			f0();
		}
		else if (a[0] == '2')
			f2();
		else if (a[0] == '3')
			;//观战
		else if (a[0] == '4')
			f3_1();//查看战绩
		else if (a[0] == '5')
		{
			printf("goodbye\n");
			break;
		}
	}
	system("pause");
	return 0;
}