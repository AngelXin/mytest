#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	int max = 0;
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	max = arr[0];
//	for (i = 1; i < 10; i++)
//	{
//		if (arr[i]>max)
//		{
//			max = arr[i];
//		}
//	}
//	printf("%d", max);
//	return 0;
//}//��ʮ�����е����ֵ2.3


//#include <stdio.h>
//int main()
//{
//	int a = 0; 
//	int b = 0;
//	int c = 0;
//	scanf("%d %d", &a, &b);
//	while (c=a%b)
//	{
//		a = b;
//		b = c;
//	}
//	printf("%d", b);
//	return 0;
//}//�����Լ��--շת����� 2.5


//#include <stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int min = 0;
//	int i = 0;
//	scanf("%d %d", &a, &b);
//	if (a > b)
//	{
//		min = b;
//	}
//	else
//	{
//		min = a;
//	}
//	for (i = min; i > 0; i--)
//	{
//		if (a%i == 0 && b%i == 0)
//		{
//			printf("%d",i);
//			break;
//		}
//	}
//	return 0;
//}//�����Լ��2.5



//#include <stdio.h>
//int main()
//{
//	int arr1[5] = { 1, 3, 5, 7, 9 };
//	int arr2[5] = { 0, 2, 4, 6, 8 };
//	int i = 0;
//
//
//	for (i = 0; i < 5; i++)
//	{
//		printf(" %d", arr1[i]);
//	}
//	printf("\n");
//	for (i = 0; i < 5; i++)
//	{
//		printf(" %d", arr2[i]);
//	}
//	printf("\n");//��ӡԭ����������
//
//
//	for (i = 0; i < 5; i++)
//	{
//		arr1[i] = arr1[i] ^ arr2[i];
//		arr2[i] = arr1[i] ^ arr2[i];
//		arr1[i] = arr1[i] ^ arr2[i];
//	}//����������
//
//
//	for (i = 0; i < 5; i++)
//	{
//		printf(" %d", arr1[i]);
//	}
//	printf("\n");
//	for (i = 0; i < 5; i++)
//	{
//		printf(" %d", arr2[i]);
//	}
//	printf("\n");//��ӡ�������������
//
//	return 0;
//}//��������һ��������� 3.1��1��


//#include <stdio.h>
//
//void print_arr(int arr[5], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d", arr[i]);
//	}
//	printf("\n");
//}//��ӡ����
//void change_arr(int arr1[5], int arr2[5])
//{
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		arr1[i] = arr1[i] + arr2[i];
//		arr2[i] = arr1[i] - arr2[i];
//		arr1[i] = arr1[i] - arr2[i];
//	}
//}//��������
//
//int main()
//{
//	int arr1[5] = { 1, 3, 5, 7, 9 };
//	int arr2[5] = { 0, 2, 4, 6, 8 };
//	change_arr(arr1, arr2);
//	print_arr(arr1, 5);
//	print_arr(arr2, 5);
//	return 0;
//}//��������һ����������е�����3.1


//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	int flag = 1;
//	double sum = 0;
//	float num = 0.0;
//	for (i = 1; i <= 100; i++)
//	{
//		num = (1.0*flag) / (1.0*i);
//		sum = num+sum;
//		flag = -flag;
//	}
//	printf("%lf\n", sum);
//	return 0;
//}//��1-1/2+1/3-.......+1/99-1/100 ��ֵ��3.2��


//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 10 == 9)
//			count++;
//		if (i / 10 == 9)
//			count++;
//	}
//	printf("%d", count);
//	return 0;
//}//1��100��ӡ�˶��ٴ�9 ��3.3��


//#include <stdio.h>
//int main()
//{
//	int star = 0;
//	int end = 0;
//	int n = 0;
//	int count = 0;
//	scanf("%d %d", &star, &end);
//	for (n = star; n <= end; n++)
//	{
//		int temp = n;
//		while (temp)
//		{
//			if (temp % 10 == 9)
//				count++;
//			else
//				temp = temp / 10;
//		}
//	}
//	printf("%d", count);
//	return 0;
//}//�����������9�Ĵ���



//#include <stdio.h>
//int main()
//{
//	int maxline = 0;//�����
//	int i = 0;//����
//	int j = 0;//����
//	scanf("%d", &maxline);
//	for (i = 1; i <= maxline; i++)
//	{
//		for (j = 1; j <= maxline - 1; j++)
//		{
//			printf(" ");
//		}
//		for (j = 1; j <= 2 * i - 1; j++)
//		{
//			printf("*");
//		}
//		
//		printf("\n");
//	}//�ϰ벿��
//	for (i = 1; i <= maxline - 1; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf(" ");
//		}
//		for (j = 1; j <= 2 * (maxline - i) - 1;j++);
//		{
//			printf("*");
//		}
//		
//		printf("\n");
//	}
//	return 0;
//}//4.1


#include <stdio.h>
#include <math.h>
int main()
{
	int i = 0;
	for (i = 0; i < 1000; i++)
	{
		int sum = 100;
		int temp = i;
		while (temp)
		{
			temp = temp % 10;
			sum += pow(temp , 3);
		}
		if (sum == i)
		{
			printf("%d", i);
		}
	}
	return 0;
}//ˮ�ɻ���4.2



//#include <stdio.h>
//int main()
//{
//	int n = 0;
//	int sum = 0;
//	scanf("%d", &n);
//	sum = n + (n * 10 + n) + (n * 100 + n * 10 + n) + (n * 1000 + n * 100 + n * 10 + n) +
//		(n * 10000 + n * 1000 + n * 100 + n * 10 + n);
//	printf("%d", sum);
//	return 0;
//}4.3


//#include <stdio.h>
//int Sn(int n)
//{
//	int sum = 0;
//	scanf("%d", &n);
//	sum = n + (n * 10 + n) + (n * 100 + n * 10 + n) + (n * 1000 + n * 100 + n * 10 + n) +
//		(n * 10000 + n * 1000 + n * 100 + n * 10 + n);
//	return sum;
//}
//int main()
//{
//	int n = 0;
//	int sum = 0;
//	sum = Sn(n);
//	printf("%d\n", sum);
//	return 0;
//}4.3


