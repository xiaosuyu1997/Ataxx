#include"test.h"
using namespace std;

int Min(int qipan_1[7][7], int start, int depth);
int Max(int qipan_1[7][7], int start, int depth);
int estimate(int start, int qipan_1[7][7]);

struct mov{
	int from_x;
	int from_y;
	int to_x;
	int to_y;
};
//minimax+alpha-beta剪枝


//对棋盘的格式化（将一个棋盘赋给另外一个棋盘。）
void set(int to[7][7], int from[7][7])
{
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
		{
			to[i][j] = from[i][j];
		}
}


//对特定的一步棋完成棋盘颜色转换。
void change_color(int start_x, int start_y, int des_x, int des_y, int qipan_1[7][7], int start)
{
	if (max(abs(start_x - des_x), abs(start_y - des_y)) == 2) qipan_1[start_x][start_y] = 0;
	qipan_1[des_x][des_y] = start;
	for (int i = -1; i <= 1 && des_x + i >= 0 && des_x + i <= 6; i++)
	{
		for (int j = -1; j <= 1 && des_y + j >= 0 && des_y + j <= 6; j++)
		{
			if (qipan_1[des_x + i][des_y + j] == -start)
				qipan_1[des_x + i][des_y + j] = start;
		}
	}
}


mov minimax(int depth, int start) 
{
	
	int qipan_1[7][7] = { 0 };
	set(qipan_1, qipan);

	int best_val = -5000;
	mov best_move;
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
		{
			//找到所有可以移动的点
			if (qipan_1[i][j] == start)
			{
				//对每个点进行移动。
				for (int m = -2; m <=2 ; m++)
				{
					for (int n = -2; n <= 2; n++)
					{
						if (qipan_1[i + m][j + n] != 0 || (m == 0 && n == 0) ||
							i + m < 0 || i + m>6 || n + j < 0 || n + j>6) continue;
						
						//记录当前棋盘状态，在这里就是默认棋盘；
						
						
						//对每个点进行移动。
						change_color(i, j, i + m, j + n, qipan_1, start);

						//调用下一层；
						int t = Min(qipan_1, -start, depth - 1);
						if (t > best_val)
						{
							best_val = t;
							best_move = { i,j,i + m,j + n };
						}

						//恢复棋盘状态；
						set(qipan_1, qipan);
					}
				}
			}
		}
	return best_move;
}


int Max(int qipan_1[7][7], int start, int depth)
{
	if (depth == 0) return estimate(start, qipan_1);
	
	int qipan_2[7][7] = { 0 };
	set(qipan_2, qipan_1);

	int best_val = -5000;
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
		{
			//找到所有可以移动的点
			if (qipan_1[i][j] == start)
			{
				//对每个点进行移动。
				for (int m = -2; m <= 2; m++)
				{
					for (int n = -2; n <= 2; n++)
					{
						if (qipan_1[i + m][j + n] != 0 || (m == 0 && n == 0) || 
							i + m < 0 || i + m>6 || n + j < 0 || n + j>6) continue;

						//记录当前棋盘状态，在这里就是默认棋盘；


						//对每个点进行移动。
						change_color(i, j, i + m, j + n, qipan_2, start);

						//调用下一层；
						int t = Min(qipan_2, -start, depth - 1);
						if (t > best_val)
						{
							best_val = t;
						}

						//恢复棋盘状态；
						set(qipan_2, qipan_1);
					}
				}
			}
		}
	return best_val;
}

int Min(int qipan_1[7][7], int start, int depth)
{
	if (depth == 0) return estimate(start, qipan_1);

	int qipan_2[7][7] = { 0 };
	set(qipan_2, qipan_1);

	int best_val = 5000;
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
		{
			//找到所有可以移动的点
			if (qipan_1[i][j] == start)
			{
				//对每个点进行移动。
				for (int m = -2; m <= 2; m++)
				{
					for (int n = -2; n <= 2; n++)
					{
						if (qipan_1[i + m][j + n] != 0 || (m == 0 && n == 0) ||
							i + m < 0 || i + m>6 || n + j < 0 || n + j>6) continue;

						//记录当前棋盘状态，在这里就是默认棋盘；


						//对每个点进行移动。
						change_color(i, j, i + m, j + n, qipan_2, start);

						//调用下一层；
						int t = Max(qipan_2, -start, depth - 1);
						if (t < best_val)
						{
							best_val = t;
						}

						//恢复棋盘状态；
						set(qipan_2, qipan_1);
					}
				}
			}
		}
	return best_val;
}


void ai(int first, int next)
{
	mov t = minimax(2, first);
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


//评估函数,这个还可以改善。
int estimate(int start, int qipan_1[7][7])
{
	int sum = 0;
	for(int i=0;i<7;i++)
		for (int j = 0; j < 7; j++)
		{
			if (qipan_1[i][j] == start) sum++;
			else sum--;
		}
	return sum;
}

