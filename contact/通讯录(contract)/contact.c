#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"
#include <stdio.h>
#include <stdlib.h>

void InitContact(Contact* pc)//��ʼ��
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
		PeoInfo* str = (PeoInfo*)realloc(pc->data, (pc->capacity + 3)*sizeof(PeoInfo));//����
		if (pc->data != NULL)
		{
			pc->data = str;
			pc->capacity += 2;
			printf("���ݳɹ�\n");
			return 1;
		}
		else
			return 0;
	}
	return 1;
}

void AddContact(Contact* pc)//���
{
	assert(pc);
	/*if (pc->sz == MAX)
	{
		printf("���ź���ͨѶ¼�������޷����");
		return;
	}*/
	if (CheakCapacity == 0)
	{
		printf("����ʧ�ܣ��޷����\n");
		return;
	}
		printf("���������֣�>");
		scanf("%s", pc->data[pc->sz].name);
		printf("���������䣺>");
		scanf("%d", &(pc->data[pc->sz].age));
		printf("�������Ա�>");
		scanf("%s", &(pc->data[pc->sz].sex));
		printf("�������ַ��>");
		scanf("%s", &(pc->data[pc->sz].addr));
		printf("������绰��>");
		scanf("%s", &(pc->data[pc->sz].tele));
		pc->sz++;

		printf("��ӳɹ�\n");
	}

void ShowContact(Contact* pc)//��ʾ
{
	assert(pc);
	int i = 0;
	printf("%10s\t%5s\t%5s\t%15s\t%12s\n", "����", "����", "�Ա�", "��ַ", "�绰");
	
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
	printf("����������:>");
	scanf("%s\n", &name);
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
			return i;
	}
	return -1;
}

void SearchContact(Contact* pc)//����
{
	int ret = FindByName(pc);
	
	if (ret != -1)
	{
		printf("%10s\t%5s\t%5s\t%15s\t%12s\n", "����", "����", "�Ա�", "��ַ", "�绰");
		printf("%10s\t%5d\t%5s\t%15s\t%12s\n",
			pc->data[ret].name,
			pc->data[ret].age,
			pc->data[ret].sex,
			pc->data[ret].addr,
			pc->data[ret].tele);
		return;
	}
		printf("���ҵ��˲�����\n");
}



void DelContact(Contact* pc)//ɾ��
{
	assert(pc);
	int ret = 0;
	int i = 0;
	if (pc->sz == 0)
	{
		printf("��Ǹ��û�п���ɾ������");
		return;
	}
	ret = FindByName(pc);
	if (-1 == ret)
	{
		printf("��Ǹ��Ҫɾ�����˲�����");
		return;
	}
	for (i = ret; i < pc->sz - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->sz--;
	printf("ɾ���ɹ�");
}

void ModifyContact(Contact* pc)//�޸�
{
	assert(pc);
	int ret = 0;
	int i = 0;
	if (pc->sz == 0)
	{
		printf("��Ǹ��û�п����޸ĵ���");
	}
	ret = FindByName(pc);
	if (ret == -1)
	{
		printf("��Ǹ��Ҫɾ���������");
	}
	printf("%10s\t%5d\t%5s\t%15s\t%12s\n",
		pc->data[ret].name,
		pc->data[ret].age,
		pc->data[ret].sex,
		pc->data[ret].addr,
		pc->data[ret].tele);
}

void EmptyContact(Contact* pc)//���
{
	assert(pc);
	pc->sz = 0;
	memset(pc->data, 0, sizeof(pc->data));
}

void DestoryContact(Contact* pc)//����
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

void SortContact(Contact* pc)//����
{
	assert(pc);
	qsort(pc->data, pc->sz, sizeof(PeoInfo), int_cmp);
}


void SaveContact(Contact* pc)//д�����ݣ��Ա㱣��
{
	FILE* pf = fopen("contact.dat", "wb");
	int i = 0;
	if (pf == NULL)
	{
		perror("SaveContact::fopen");
		return;
	}
	//д�ļ�
	for (i = 0; i < pc->sz; i++)
	{
		fwrite(&(pc->data[i]), sizeof(PeoInfo), 1, pf);
	}
	fclose(pf);
	pf = NULL;
}


void LoadContact(Contact* pc)//����
{
	FILE* pf = fopen("contact.dat", "rb");
	PeoInfo tmp = { 0 };
	if (pf == NULL)
	{
		perror("LoadContact::fopen");
		return;
	}
	//���ļ�
	while (fread(&tmp, sizeof(PeoInfo), 1, pf))
	{
		//����ȡ��Ԫ�طŵ�ͨѶ¼��
		CheakCapacity(pc);
		pc->data[pc->sz] = tmp;
		pc->sz++;
	}
	fclose(pf);
	pf = NULL;

}