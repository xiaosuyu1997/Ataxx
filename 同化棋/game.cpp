#include"test.h"
using namespace std;


int game(int first)  //����0���������Ϸ������1����ص�������
{
	while (true)
	{
		system("cls");
		jiemian(first);

		int start_x = 0, start_y = 0;
		int des_x = 0, des_y = 0;


		printf("�浵������\"s\"\n����������������\"r\"\n��ѡ����Ҫ�ƶ�������:�����ʽ\"x y\"\n����������\"c\"\n");

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
				printf("�浵������\"s\"\n����������������\"r\"\n��ѡ����Ҫ�ƶ�������:�����ʽ\"x y\"\n����������\"c\"\n");
				continue;
			}
			if (temp[0] == 'c')
				if (player == 1)
				{
					if (cnt_step == 1)
					{
						printf("�Ѿ����ܻ�����\n");
						printf("�浵������\"s\"\n����������������\"r\"\n��ѡ����Ҫ�ƶ�������:�����ʽ\"x y\"\n����������\"c\"\n");
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
					printf("�浵������\"s\"\n����������������\"r\"\n��ѡ����Ҫ�ƶ�������:�����ʽ\"x y\"\n");
					continue;
				}
				else if(first==1)
				{
					if (cnt_step == 1)
					{
						printf("�Ѿ����ܻ�����\n");
						printf("�浵������\"s\"\n����������������\"r\"\n��ѡ����Ҫ�ƶ�������:�����ʽ\"x y\"\n����������\"c\"\n");
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
					printf("�浵������\"s\"\n����������������\"r\"\n��ѡ����Ҫ�ƶ�������:�����ʽ\"x y\"\n");
					continue;
				}
				else if (first == -1)
				{
					if (cnt_step == 1)
					{
						printf("�Ѿ����ܻ�����\n");
						printf("�浵������\"s\"\n����������������\"r\"\n��ѡ����Ҫ�ƶ�������:�����ʽ\"x y\"\n����������\"c\"\n");
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
					printf("�浵������\"s\"\n����������������\"r\"\n��ѡ����Ҫ�ƶ�������:�����ʽ\"x y\"\n");
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

		printf("��ѡ����Ҫ�ƶ����ĵط�   ����ѡ��������\"c\"\n");

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
			//�ж�1���������ڣ�2����ʮ�����ڣ�3���������ӣ�Ŀ��ص�Ϊ�գ�
			if (decide_des_nextstep(first, start_x, start_y, des_x, des_y))
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


//˫����Ϸ��
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




//������Ϸ��
void black_game()  //����0�������������1������������(ֻ����1)
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

void white_game()  //����0�������������1������������
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


//�ж���Ӯ���,1��ʾ�ڷ�ʤ����-1����׷�ʤ����0��ʾ��Ϸ����
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
		return -1;
	}

	//2��������ȫ����
	if (cnt_black + cnt_white == 49)
	{
		if (cnt_black > cnt_white)
		{
			system("cls"); jiemian(1);
			printf("�ڷ�ʤ��\n");
			system("pause");
			return 1;
		}
		if (cnt_white > cnt_black)
		{
			system("cls"); jiemian(-1);
			printf("�׷�ʤ��\n");
			system("pause");
			return -1;
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
		if (cnt_black > 24) { system("cls"); jiemian(1); printf("�ڷ�ʤ��\n"); system("pause"); return 1; }
		else { system("cls"); jiemian(-1); printf("�׷�ʤ��\n"); system("pause"); return -1; }
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
		if (cnt_white > 24) { system("cls"); jiemian(-1); printf("�׷�ʤ��\n"); system("pause"); return -1; }
		else { system("cls"); jiemian(1); printf("�ڷ�ʤ��\n"); system("pause"); return 1; }
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

//�ж϶��ں�����߰����ض����ӣ���һ���Ƿ�����ƶ���Ŀ��λ�á�0�������Ƶ���1��������Ƶ�
int decide_des_nextstep(int first, int x_from, int y_from, int x_to, int y_to)
{
	if (x_to < 0 || y_to < 0 || x_to>6 || x_to>6 || (x_to == x_from && y_to == y_from)
		|| abs(x_to - x_from) > 2 || abs(y_to - y_from) > 2 || qipan[x_to][y_to] != 0) return 0;
	else return 1;
}