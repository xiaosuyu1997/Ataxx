#include"test.h"
using namespace std;

//����Ϸ��ѡ��˫��ģʽ
void f0()
{
	while (true)
	{
		system("cls");
		printf("��ѡ����Ϸģʽ��\n1. ����ģʽ\n2. ˫��ģʽ\n�������˵�������'r'\n");
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
			double_game(1);
			return;
		}
	}
}


//����Ϸ��ѡ��ڰ׿�ʼ��
void f1()
{
	while (true)
	{
		system("cls");
		printf("��ѡ��ִ��ִ��\n1.ִ��\n2.ִ��\n�������˵�������'r'\n");
		char a[10] = { '\0' };
		cin >> a;
		if (a[0] == '1')
		{
			black_game();
			return;
		}
		else if (a[0] == '2')
		{
			white_game();
			return;
		}
		else if (a[0] == 'r') return;
	}
}




//������Ϸ��ѡ��浵���棺
void f2()
{
	while (true)
	{
		system("cls");
		printf("��ѡ����Ҫ���صĴ浵\n1  2  3\n����������������\"r\"\n");
		char a[10] = { '\0' };
		cin >> a;
		int t = a[0] - '0';
		if (a[0] == 'r')  return;
		else if (t >= 1 && t <= 3)
		{
			int first = file_input(t);
			if (player == 1)
			{
				if (first == 1)
				{
					black_game();
					return;
				}
				else
				{ 
					if(game(-1)==1) return;
					white_game();
					return;
				}
			}
			else
			{
				double_game(first);
				return;
			}
		}

	}
}

//��ȡս��
void f3_1()
{
	system("cls");
	ifstream infile;
	infile.open("history.txt", ios::in);
	if (!infile)
	{
		printf("�ļ���ʧ��\n");
		return;
	}
	int total = 0;
	int win = 0;
	infile >> total >> win;
	infile.close();

	printf("�ܾ�����%d\n��ʤ������%d\n", total, win);
	printf("����������������\"r\"\n�����¼������\"c\"\n");
	char t = 0;
	while (cin.peek() != 'r' && cin.peek() != 'c') getchar();
	cin >> t;
	switch (t)
	{
	case 'r':return;
	case 'c':f3_2(0, 0);
	}
	return;
}

//��¼ս����ʷ��Ϣ��set Ϊ0��������
void f3_2(int thisgame, int set)
{
	if (set == 0)
	{
		ofstream outfile;
		outfile.open("history.txt", ios::out);
		if (!outfile) {
			printf("�ļ��򿪴���\n");
			return;
		}
		outfile << 0 << " " << 0;
		outfile.close();
		return;
	}

	ifstream infile;
	infile.open("history.txt", ios::in);
	if (!infile) {
		printf("�ļ��򿪴���\n");
		return;
	}
	int total = 0;
	int win = 0;
	infile >> total >> win;
	infile.close();

	ofstream outfile;
	outfile.open("history.txt", ios::out);
	if (!outfile) {
		printf("�ļ��򿪴���\n");
		return;
	}
	outfile << total + 1 << " " << win + thisgame;
	outfile.close();

	return;
}




void jiemian(int start)
{
	printf("���ǵ� %d �غ�\n�ڷ�������%d\n�׷�������%d\n���� ", cnt_step, cnt_black, cnt_white);
	if (start == 1) printf("�� ��\n");
	else printf("�� ��\n");
	printf("     1   2   3   4   5   6   7\n  ���������ש������ש������ש������ש������ש������ש�������\n");
	for (int i = 0; i < 7; i++)
	{
		printf("%d ��", i + 1);
		for (int j = 0; j < 7; j++)
		{
			if (qipan[i][j] == 1) printf(" ��");
			else if (qipan[i][j] == -1) printf(" ��");
			else printf("   ��");
		}
		printf("\n");
		if(i!=6) printf("  �ǩ������贈�����贈�����贈�����贈�����贈�����贈������\n");
	}
	printf("  ���������ߩ������ߩ������ߩ������ߩ������ߩ������ߩ�������\n");
}




