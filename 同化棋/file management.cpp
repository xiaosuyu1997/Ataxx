#include"test.h"

using namespace std;


void file_output(int first) //����Ϸ�������ĵ�
{
	while (true)
	{
		system("cls");
		printf("��������Ҫѡ�񱣴��λ��\n1  2  3\n");
		int t = 0;
		scanf("%d", &t);
		if (t != 1 && t != 2 && t != 3) continue;
		ifstream infile;
		switch (t)
		{
		case 1:infile.open("1.txt", ios::in); break;
		case 2:infile.open("2.txt", ios::in); break;
		case 3:infile.open("3.txt", ios::in); break;
		}
		int a = 0;
		infile >> a;
		if (a == 1)
		{
			printf("�Ƿ񸲸�ԭ�ĵ���\ny:����\nn:������\n");
			char b = 0;
			cin >> b;
			if (b == 'n') continue;
		}

		infile.close();

		ofstream outfile;
		switch (t)
		{
		case 1:outfile.open("1.txt", ios::out); break;
		case 2:outfile.open("2.txt", ios::out); break;
		case 3:outfile.open("3.txt", ios::out); break;
		}

		outfile << 1 <<endl;//��ʾ�Ѿ��ж��룻
		outfile << player << endl;//���������
		outfile << first << endl; //ִ�ӷ���
		outfile << cnt_black << " " << cnt_white << " " << cnt_step << endl;
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				outfile << qipan[i][j] << " ";
			}
			outfile << endl;
		}
		return;
			
	}
	
}

int file_input(int filename) //���ĵ�������Ϸ����,���ص�ǰִ�ӷ�
{
	ifstream infile;
	switch (filename)
	{
	case 1:infile.open("1.txt", ios::in); break;
	case 2:infile.open("2.txt", ios::in); break;
	case 3:infile.open("3.txt", ios::in); break;
	}

	int a = 0;
	int first = 0;
	infile >> a;
	infile >> player;
	infile >> first;
	infile >> cnt_black >> cnt_white >> cnt_step;
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
		{
			infile >> qipan[i][j];
		}

	return first;
	
}