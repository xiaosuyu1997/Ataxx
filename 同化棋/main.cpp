#include"test.h"

using namespace std;

int main()
{
	while (true)
	{
		system("cls");
		printf("��ӭ����ͬ����\n1.�¿���\n2.�Ӵ浵��ʼ\n3.�˳�\n");
		char a[100] = { '\0' };
		cin.getline(a, 100);
		if (a[0] == '1')
		{
			for (int i = 0; i < 7; i++)
				for (int j = 0; j < 7; j++)
					qipan[i][j] = 0;

			cnt_step = 1;
			cnt_black = 2; //black�������ϽǺ����½�ִ��
			cnt_white = 2; //white�������ϽǺ����½�ִ��
			qipan[0][0] = 1;
			qipan[6][6] = 1;
			qipan[6][0] = -1;
			qipan[0][6] = -1;
			f0();
		}
		else if (a[0] == '2')
			f3();
		else if (a[0] == '3')
		{
			printf("goodbye\n");
			break;
		}
	}
	system("pause");
	return 0;
}