#include"test.h"
using namespace std;

int Min(int qipan_1[7][7], int start, int depth,int, int);
int Max(int qipan_1[7][7], int start, int depth, int, int);
int estimate(int start, int qipan_1[7][7]);

struct mov{
	int from_x;
	int from_y;
	int to_x;
	int to_y;
};
//minimax+alpha-beta��֦

int decide_win2(int qipan_1[7][7])
{
	int black = 0, white = 0;
	for(int i=0;i<7;i++)
		for (int j = 0; j < 7; j++)
		{
			if (qipan_1[i][j] == 1) ++black;
			else if (qipan_1[i][j] == -1) ++white;
		}
	
	//3��һ��ȫ���Ӷ����Ե�
	if (black == 0)
		return 1;

	if (white == 0)
		return -1;

	//2��������ȫ����
	if (black + white == 49)
	{
		if (black > white)
			return 1;
		else return -1;
	}

	//1��һ���޷�����
	//�ڷ��޷�����
	bool can_black = 0;
	for(int i=0;i<7;i++)
		for (int j = 0; j < 7; j++)
		{
			if (qipan_1[i][j] == 1)
			{
				for (int m = -2; m <= 2; m++)
				{
					if (i + m < 0 || i + m > 6) continue;
					for (int n = -2; n <= 2; n++)
					{
						if (j + n < 0 || j + n>6) continue;
						if (qipan_1[i + m][j + n] == 0)
						{
							can_black = true;
							break;
						}
					}
					if (can_black) break;
				}
				if (can_black) break;
			}
			if (can_black) break;
		}
	if (can_black == false)
	{
		if (black > 24) return 1;
		else return -1;
	}


	bool can_white = 0;
	for (int i = 0; i<7; i++)
		for (int j = 0; j < 7; j++)
		{
			if (qipan_1[i][j] == -1)
			{
				for (int m = -2; m <= 2; m++)
				{
					if (i + m < 0 || i + m > 6) continue;
					for (int n = -2; n <= 2; n++)
					{
						if (j + n < 0 || j + n>6) continue;
						if (qipan_1[i + m][j + n] == 0)
						{
							can_white = true;
							break;
						}
					}
					if (can_white) break;
				}
				if (can_white) break;
			}
			if (can_white) break;
		}
	if (can_white == false)
	{
		if (white > 24) return -1;
		else return 1;
	}

	//Ĭ�Ϸ���0��
	return 0;
}

//�����̵ĸ�ʽ������һ�����̸�������һ�����̡���
void set(int to[7][7], int from[7][7])
{
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
		{
			to[i][j] = from[i][j];
		}
}


//���ض���һ�������������ɫת����
void change_color(int start_x, int start_y, int des_x, int des_y, int qipan_1[7][7], int start)
{
	if (max(abs(start_x - des_x), abs(start_y - des_y)) == 2) qipan_1[start_x][start_y] = 0;
	qipan_1[des_x][des_y] = start;
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (i == 0 && j == 0) continue;
			if (des_x + i < 0 || des_x + i >6 || des_y + j < 0 || des_y + j>6) continue;
			
			if (qipan_1[des_x + i][des_y + j] == -start)
				qipan_1[des_x + i][des_y + j] = start;
		}
	}
}


mov minimax(int depth, int start) 
{
	
	int qipan_1[7][7] = { 0 };
	set(qipan_1, qipan);

	int this_a = -50000;
	int this_b = -50000;
	mov best_move;
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
		{
			//�ҵ����п����ƶ��ĵ�
			if (qipan_1[i][j] == start)
			{
				//��ÿ��������ƶ���
				for (int m = -2; m <=2 ; m++)
				{
					for (int n = -2; n <= 2; n++)
					{
						if (qipan_1[i + m][j + n] != 0 || (m == 0 && n == 0) ||
							i + m < 0 || i + m>6 || n + j < 0 || n + j>6) continue;
						
						//��¼��ǰ����״̬�����������Ĭ�����̣�
						
						
						//��ÿ��������ƶ���
						change_color(i, j, i + m, j + n, qipan_1, start);

						//������һ�㣻
						int t = Min(qipan_1, -start, depth - 1,this_a,this_b);
						if (t > this_a)
						{
							this_a = t;
							best_move = { i,j,i + m,j + n };
						}

						//�ָ�����״̬��
						set(qipan_1, qipan);
					}
				}
			}
		}
	return best_move;
}


int Max(int qipan_1[7][7], int start, int depth,int a,int b)
{
	if (depth == 0) return estimate(start, qipan_1);
	
	int qipan_2[7][7] = { 0 };
	set(qipan_2, qipan_1);

	int this_a = -50000;
	int this_b = b;
	bool flag = false;
	if (decide_win2(qipan_1) != 0) return estimate(start, qipan_1);
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
		{
			//�ҵ����п����ƶ��ĵ�
			if (qipan_1[i][j] == start)
			{
				//��ÿ��������ƶ���
				for (int m = -2; m <= 2; m++)
				{
					for (int n = -2; n <= 2; n++)
					{
						if (qipan_1[i + m][j + n] != 0 || (m == 0 && n == 0) || 
							i + m < 0 || i + m>6 || n + j < 0 || n + j>6) continue;

						//��¼��ǰ����״̬�����������Ĭ�����̣�


						//��ÿ��������ƶ���
						change_color(i, j, i + m, j + n, qipan_2, start);

						//������һ�㣻
						int t = Min(qipan_2, -start, depth - 1,this_a,this_b);
						if (t > this_a) this_a = t;
						if (this_a >= this_b)
						{
							flag = true;
							break;
						}

						//�ָ�����״̬��
						set(qipan_2, qipan_1);
					}
					if (flag) break;
				}
				if (flag) break;
			}
			if (flag) break;
		}
	return this_a;
}

int Min(int qipan_1[7][7], int start, int depth, int a, int b)
{
	if (depth == 0) return estimate(start, qipan_1);

	int qipan_2[7][7] = { 0 };
	set(qipan_2, qipan_1);

	int this_a = b;
	int this_b = 50000;
	bool flag = false;
	if (decide_win2(qipan_1) != 0) return estimate(start, qipan_1);
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
		{
			//�ҵ����п����ƶ��ĵ�
			if (qipan_1[i][j] == start)
			{
				//��ÿ��������ƶ���
				for (int m = -2; m <= 2; m++)
				{
					for (int n = -2; n <= 2; n++)
					{
						if (qipan_1[i + m][j + n] != 0 || (m == 0 && n == 0) ||
							i + m < 0 || i + m>6 || n + j < 0 || n + j>6) continue;

						//��¼��ǰ����״̬�����������Ĭ�����̣�


						//��ÿ��������ƶ���
						change_color(i, j, i + m, j + n, qipan_2, start);

						//������һ�㣻
						int t = Max(qipan_2, -start, depth - 1,this_a,this_b);
						if (t < this_b)
						{
							this_b = t;
						}
						if (this_a >= this_b)
						{
							flag = true;
							break;
						}

						//�ָ�����״̬��
						set(qipan_2, qipan_1);
					}
					if (flag) break;
				}
				if (flag) break;
			}
			if (flag) break;
		}
	return this_b;
}


void ai(int first)
{
	mov t = minimax(4, first);
	change_color(t.from_x, t.from_y, t.to_x, t.to_y, qipan, first);
	cnt_black = 0; cnt_white = 0;
	for(int i=0;i<7;i++)
		for (int j = 0; j < 7; j++)
		{
			if (qipan[i][j] == 1) cnt_black++;
			else if (qipan[i][j] == -1) cnt_white++;
		}
	return;
}


//��������,��������Ը��ơ�
int estimate(int start, int qipan_1[7][7])
{

	int sum0 = 0;//sum0�Ƕ����������ĺ���
	int sum1 = 0; //sum1�Ƕ����ӱ��������һ������
	int sum2 = 0;//sum2�Ƕ������ж����ĺ���
	int sum3 = 0;//sum3�ǶԴ˴����ӱ���һ�ֳԵ��ķ��֡�
	int remain = 49;
	for(int i=0;i<7;i++)
		for (int j = 0; j < 7; j++)
		{
			if (qipan_1[i][j] == start)
			{
				remain--;
				sum0 += 1;
				for (int x = -1; x <= 1; x++)
					for (int y = -1; y <= 1; y++)
					{
						if (i + x < 0 || i + x>6 || j + y < 0 || j + y>6 || (x == 0 && y == 0)) continue;
						if (qipan_1[i + x][j + y] == start) sum1++;
					}
			}
			else if (qipan_1[i][j] == -start) { sum0 -= 1; remain--; }
		}
	if (remain <= 4) return 1000*sum0;
	for (int i = 0; i<7; i++)
		for (int j = 0; j < 7; j++)
		{
			if (qipan_1[i][j] == 0)
			{
				bool flag = false;
				for (int x = -2; x <= 2; x++)
				{
					for (int y = -2; y <= 2; y++)
					{
						if (i + x < 0 || i + x>6 || j + y < 0 || j + y>6 || (x == 0 && y == 0)) continue;
						if (qipan_1[i + x][j + y] == start)
						{
							flag = true;
							sum2++;
							break;
						}
					}
					if (flag) break;
				}
			}
		}

	for (int i = 0; i<7; i++)
		for (int j = 0; j < 7; j++)
		{
			if (qipan_1[i][j] == 0)
			{
				bool flag = false;
				for (int x = -2; x <= 2; x++)
				{
					for (int y = -2; y <= 2; y++)
					{
						if (i + x < 0 || i + x>6 || j + y < 0 || j + y>6 || (x == 0 && y == 0)) continue;
						if (qipan_1[i + x][j + y] == -start)
						{
							flag = true;
							int temp = 0;
							for (int m = -1; m <= 1; m++)
							{
								for (int n = -1; n <= 1; n++)
								{
									if (i + m < 0 || i + m>6 || j + n < 0 || j + n>6 || (m == 0 && n == 0)) continue;
									if(qipan_1[i+m][j+n]==start) temp++;
								}
							}
							sum3 += max(0, temp - 3);
							break;
						}
					}
					if (flag) break;
				}
			}
		}
	if(remain>=40) return 100 * sum0 + 6 * sum1 + 2*sum2- 2 * sum3;
	return 100*sum0 + 6*sum1 - 2*sum3;
}