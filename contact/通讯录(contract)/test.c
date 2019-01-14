#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"
#include <stdio.h>
#include <stdlib.h>

void menu()
{
	printf("***************************************\n");
	printf("****    1��add            2��del    ***\n");
	printf("****    3��search         4��modify ***\n");
	printf("****    5��show           6��empty  ***\n");
	printf("****    7��sort           0��exit   ***\n");
	printf("***************************************\n");
}
enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,//�޸�
	SHOW,//��ʾ
	EMPTY,//���
	SORT//����������
};

void test()
{
	int inputs = 0;
	Contact con;
	InitContact(&con);
	do
	{
		menu();
		printf("��ѡ��>");
		scanf("%d", &inputs);
		switch (inputs)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case EMPTY:
		    EmptyContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case EXIT:
			LoadContact(&con);
			SaveContact(&con);
			DestoryContact(&con);
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (inputs);

}
int main()
{
	test();
	return 0;
}