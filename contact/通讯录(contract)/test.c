#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"
#include <stdio.h>
#include <stdlib.h>

void menu()
{
	printf("***************************************\n");
	printf("****    1、add            2、del    ***\n");
	printf("****    3、search         4、modify ***\n");
	printf("****    5、show           6、empty  ***\n");
	printf("****    7、sort           0、exit   ***\n");
	printf("***************************************\n");
}
enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,//修改
	SHOW,//显示
	EMPTY,//清空
	SORT//以名字排序
};

void test()
{
	int inputs = 0;
	Contact con;
	InitContact(&con);
	do
	{
		menu();
		printf("请选择：>");
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
			printf("退出通讯录\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (inputs);

}
int main()
{
	test();
	return 0;
}