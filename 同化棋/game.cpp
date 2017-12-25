#include"test.h"


using namespace std;


int game(int first, int next)  //����0���������Ϸ������1����ص�������
{
	
	

	//��Ҫ�ж��Ƿ��Ѿ�������Ӯ
	if (decide_win()) return 1;
	
	system("cls");
	jiemian(first);


	char start_x = 0;
	char start_y = 0;
	//�ȷ����壬1Ϊִ�ڣ�-1Ϊִ��
	char t = 0;
	printf("�浵������\"s\"\n����������������\"r\"\n��ѡ����Ҫ�ƶ�������\n");
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

	printf("��ѡ����Ҫ�ƶ����ĵط�\n");
	int des_x = 0, des_y = 0;
	while (true)
	{
		scanf("%d%d", &des_x, &des_y);
		des_x -= 1; des_y -= 1;
		//�ж�1���������ڣ�2����ʮ�����ڣ�3���������ӣ�Ŀ��ص�Ϊ�գ�
		if (decide_des_nextstep(first,start_x,start_y,des_x,des_y))
		{
			//16λ�������
			if (abs(des_x - start_x) == 2 || abs(des_y - start_y) == 2)
			{
				qipan[start_x][start_y] = 0;
				qipan[des_x][des_y] = first;
			}
			//8λ�������
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


int black_game()  //����0�������������1������������(ֻ����1)
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


int white_game()  //����0�������������1������������
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


//�ж���Ӯ���,1��ʾ��Ϸ��ֹ��һ��ʤ����0��ʾ��Ϸ����
/*
��Ӯ�Ŀ���;
1��һ���޷�����
2��������ȫ����
3��һ��ȫ���Ӷ����Ե�
*/
int decide_win()
{
	//3��һ��ȫ���Ӷ����Ե�
	if (cnt_black == 0)
	{
		printf("�ڷ�ʤ��\n");
		return 1;
	}
	if (cnt_white == 0)
	{
		printf("�׷�ʤ��\n");
		system("pause");
		return 1;
	}

	//2��������ȫ����
	if (cnt_black + cnt_white == 49)
	{
		if (cnt_black > cnt_white)
		{
			printf("�ڷ�ʤ��\n");
			system("pause");
			return 1;
		}
		if (cnt_white > cnt_black)
		{
			printf("�׷�ʤ��\n");
			system("pause");
			return 1;
		}
	}

	//1��һ���޷�����
	//�ڷ��޷�����
	int sum_black = 0;
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
		{
			if (qipan[i][j] == 1) sum_black += decide_num_nextstep(1, i, j);
		}
	if (sum_black == 0)
	{
		if (cnt_black > 24) { printf("�ڷ�ʤ��\n"); system("pause"); return 1; }
		else { printf("�׷�ʤ��\n"); system("pause"); return 1; }
	}
	//�׷��޷�����
	int sum_white = 0;
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
		{
			if (qipan[i][j] == -1) sum_white += decide_num_nextstep(-1, i, j);
		}
	if (sum_white == 0)
	{
		if (cnt_white > 24) { printf("�׷�ʤ��\n"); system("pause"); return 1; }
		else { printf("�ڷ�ʤ��\n"); system("pause"); return 1; }
	}


	//Ĭ�Ϸ���0��
	return 0;
}

//�ж϶��ں�����߰����ض����ӣ���һ�������ƶ���λ�õ���Ŀ��
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

//�ж϶��ں�����߰����ض����ӣ���һ���Ƿ�����ƶ���Ŀ��λ�á�0��������Ƶ���1�������Ƶ�
int decide_des_nextstep(int first, int x_from, int y_from, int x_to, int y_to)
{
	if (x_to < 0 || y_to < 0 || x_to>6 || x_to>6 || (x_to == x_from && y_to == y_from)
		|| abs(x_to - x_from) > 2 || abs(y_to - y_from) > 2 || qipan[x_to][y_to] != 0) return 0;
	else return 1;
}