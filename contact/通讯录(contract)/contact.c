#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"
#include <stdio.h>
#include <stdlib.h>

void InitContact(Contact* pc)//初始化
{
	assert(pc);
	pc->sz = 0;
	//memset(pc->data, 0, sizeof(pc->data));
	pc->data = (PeoInfo*)malloc(3 * sizeof(PeoInfo));
	if (pc->data == NULL)
	{
		perror("InitContact::malloc()");
		exit(EXIT_FAILURE);
	}
	pc->capacity = 3;
	
}



int CheakCapacity(Contact* pc)
{
	if (pc->capacity == pc->sz)
	{
		PeoInfo* str = (PeoInfo*)realloc(pc->data, (pc->capacity + 3)*sizeof(PeoInfo));//增容
		if (pc->data != NULL)
		{
			pc->data = str;
			pc->capacity += 2;
			printf("增容成功\n");
			return 1;
		}
		else
			return 0;
	}
	return 1;
}

void AddContact(Contact* pc)//添加
{
	assert(pc);
	/*if (pc->sz == MAX)
	{
		printf("很遗憾，通讯录已满，无法添加");
		return;
	}*/
	if (CheakCapacity == 0)
	{
		printf("增容失败，无法添加\n");
		return;
	}
		printf("请输入名字：>");
		scanf("%s", pc->data[pc->sz].name);
		printf("请输入年龄：>");
		scanf("%d", &(pc->data[pc->sz].age));
		printf("请输入性别：>");
		scanf("%s", &(pc->data[pc->sz].sex));
		printf("请输入地址：>");
		scanf("%s", &(pc->data[pc->sz].addr));
		printf("请输入电话：>");
		scanf("%s", &(pc->data[pc->sz].tele));
		pc->sz++;

		printf("添加成功\n");
	}

void ShowContact(Contact* pc)//显示
{
	assert(pc);
	int i = 0;
	printf("%10s\t%5s\t%5s\t%15s\t%12s\n", "名字", "年龄", "性别", "地址", "电话");
	
	for (i = 0; i < pc->sz; i++)
	{
		printf("%10s\t%5d\t%5s\t%15s\t%12s\n", 
			pc->data[i].name, 
			pc->data[i].age,
			pc->data[i].sex,
			pc->data[i].addr,
			pc->data[i].tele);
	}
}




int FindByName(Contact* pc)
{
	assert(pc);
	int i = 0;
	char name[NAME_MAX] = { 0 };
	printf("请输入姓名:>");
	scanf("%s\n", &name);
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
			return i;
	}
	return -1;
}

void SearchContact(Contact* pc)//查找
{
	int ret = FindByName(pc);
	
	if (ret != -1)
	{
		printf("%10s\t%5s\t%5s\t%15s\t%12s\n", "名字", "年龄", "性别", "地址", "电话");
		printf("%10s\t%5d\t%5s\t%15s\t%12s\n",
			pc->data[ret].name,
			pc->data[ret].age,
			pc->data[ret].sex,
			pc->data[ret].addr,
			pc->data[ret].tele);
		return;
	}
		printf("查找的人不存在\n");
}



void DelContact(Contact* pc)//删除
{
	assert(pc);
	int ret = 0;
	int i = 0;
	if (pc->sz == 0)
	{
		printf("抱歉，没有可以删除的项");
		return;
	}
	ret = FindByName(pc);
	if (-1 == ret)
	{
		printf("抱歉，要删除的人不存在");
		return;
	}
	for (i = ret; i < pc->sz - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->sz--;
	printf("删除成功");
}

void ModifyContact(Contact* pc)//修改
{
	assert(pc);
	int ret = 0;
	int i = 0;
	if (pc->sz == 0)
	{
		printf("抱歉，没有可以修改的项");
	}
	ret = FindByName(pc);
	if (ret == -1)
	{
		printf("抱歉，要删除的项不存在");
	}
	printf("%10s\t%5d\t%5s\t%15s\t%12s\n",
		pc->data[ret].name,
		pc->data[ret].age,
		pc->data[ret].sex,
		pc->data[ret].addr,
		pc->data[ret].tele);
}

void EmptyContact(Contact* pc)//清空
{
	assert(pc);
	pc->sz = 0;
	memset(pc->data, 0, sizeof(pc->data));
}

void DestoryContact(Contact* pc)//销毁
{
	assert(pc);
	pc->sz = 0;
	pc->capacity = 0;
	free(pc->data);
	pc->data = NULL;
}

//qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), int_cmp);/

int int_cmp(const void* e1, const void* e2)
	{
		if (*(char*)e1 > *(char*)e2)
			return 1;
		else if (*(char*)e1 < *(char*)e2)
			return -1;
		else
			return 0;
	}

void SortContact(Contact* pc)//排序
{
	assert(pc);
	qsort(pc->data, pc->sz, sizeof(PeoInfo), int_cmp);
}


void SaveContact(Contact* pc)//写入数据，以便保存
{
	FILE* pf = fopen("contact.dat", "wb");
	int i = 0;
	if (pf == NULL)
	{
		perror("SaveContact::fopen");
		return;
	}
	//写文件
	for (i = 0; i < pc->sz; i++)
	{
		fwrite(&(pc->data[i]), sizeof(PeoInfo), 1, pf);
	}
	fclose(pf);
	pf = NULL;
}


void LoadContact(Contact* pc)//加载
{
	FILE* pf = fopen("contact.dat", "rb");
	PeoInfo tmp = { 0 };
	if (pf == NULL)
	{
		perror("LoadContact::fopen");
		return;
	}
	//读文件
	while (fread(&tmp, sizeof(PeoInfo), 1, pf))
	{
		//将读取的元素放到通讯录里
		CheakCapacity(pc);
		pc->data[pc->sz] = tmp;
		pc->sz++;
	}
	fclose(pf);
	pf = NULL;

}