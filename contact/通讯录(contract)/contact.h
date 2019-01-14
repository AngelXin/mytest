#ifndef __CONTACT_H__
#define __CONTACT_H__


#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#define NAME_MAX 20
#define SEX_MAX 5
#define ADDR_MAX 25
#define TELE_MAX 12
#define MAX 1000

typedef struct PeoInfo
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char addr[ADDR_MAX];
	char tele[TELE_MAX];
}PeoInfo;

//typedef struct Contact
//{
//	PeoInfo data[MAX];//存放的信息
//	int sz;//存放信息的个数
//}Contact;

typedef struct Contact
{
	PeoInfo* data;
	int sz;//有效信息的个数
	int capacity;//容量
}Contact;

void InitContact(Contact* pc);//初始化
void AddContact(Contact* pc);//添加信息
int CheakCapacity(Contact* pc);//检查容量
void ShowContact(Contact* pc);//打印
void DelContact(Contact* pc);//删除
void ModifyContact(Contact* pc);//修改
void EmptyContact(Contact* pc);//清空
void DestoryContact(Contact* pc);//退出时销毁
void SortContact(Contact* pc);//排序
void SaveContact(Contact* pc);//保存数据
void LoadContact(Contact* pc);//加载
void SearchContact(Contact* pc);//查找
int FindByName(Contact* pc);

#endif// __CONTACT_H__
