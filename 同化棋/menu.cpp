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
			double_game(1, -1);
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
		if (a[0] == '1') if (black_game() == 1) return; else;
		else if (a[0] == '2') if (white_game() == 1) return; else;
		else if (a[0] == 'r') return;
	}
}




//������Ϸ��ѡ��浵���棺
void f3()
{
	while (true)
	{
		system("cls");
		printf("��ѡ����Ҫ���صĴ浵\n1  2  3\n����������������\"r\"\n");
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




