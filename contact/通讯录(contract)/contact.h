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
//	PeoInfo data[MAX];//��ŵ���Ϣ
//	int sz;//�����Ϣ�ĸ���
//}Contact;

typedef struct Contact
{
	PeoInfo* data;
	int sz;//��Ч��Ϣ�ĸ���
	int capacity;//����
}Contact;

void InitContact(Contact* pc);//��ʼ��
void AddContact(Contact* pc);//�����Ϣ
int CheakCapacity(Contact* pc);//�������
void ShowContact(Contact* pc);//��ӡ
void DelContact(Contact* pc);//ɾ��
void ModifyContact(Contact* pc);//�޸�
void EmptyContact(Contact* pc);//���
void DestoryContact(Contact* pc);//�˳�ʱ����
void SortContact(Contact* pc);//����
void SaveContact(Contact* pc);//��������
void LoadContact(Contact* pc);//����
void SearchContact(Contact* pc);//����
int FindByName(Contact* pc);

#endif// __CONTACT_H__
