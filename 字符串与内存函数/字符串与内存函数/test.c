#define _CRT_SECURE_NO_WARNINGS 1

//strlen的三种实现方式
//方法一：非递归
//#include <stdio.h>
//int my_strlen(const char* str)
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//int main()
//{
//	int len = my_strlen("abcdef");
//	printf("%d\n", len);
//	return 0;
//}

//方法二：递归
//#include <stdio.h>
//int my_strlen(const char* str)
//{
//	if (*str != '\0')
//	{
//		return 1 + my_strlen(str + 1);
//	}
//	else
//		return 0;
//}
//int main()
//{
//	int len = my_strlen("abcdef");
//	printf("%d\n", len);
//	return 0;
//}

////方法三：用指针-指针
//#include <stdio.h>
//int my_strlen(char* str)
//{
//	char* p = str;
//	while (*p != '\0')
//		p++;
//	return p - str;
//}
//int main()
//{
//	int len = my_strlen("abcdef");
//	printf("%d\n", len);
//	return 0;
//}


//#include <stdio.h>
//#include <assert.h>
//char* my_strcpy(char* dest, const char* str)
//{
//	char* ret = dest;
//	assert(dest != NULL);
//	assert(str != NULL);
//	while (*dest++ = *str++)
//	{
//		 ;
//	}
//	return ret;
//}
//int main()
//{
//	char arr1[20] = {'a','\0'};
//	printf("%s\n", my_strcpy(arr1,"abcdef"));
//	return 0;
//}//my_strcpy的实现

//#include <stdio.h>
//#include <assert.h>
//#include <string.h>
//char* my_strncpy(char* dest, const char* str, size_t count)
//{
//	char* ret = dest;
//	int len = strlen(str);
//	assert(dest);
//	assert(str);
//	while (((int)count<=len) && (count--))
//	{
//		*dest++ = *str++;
//	}
//	return ret;
//}
//int main()
//{
//	char arr1[20] = "at";
//	printf("%s\n", my_strncpy(arr1, "bcdefg", 5));
//	return 0;
//}//my_strncpy的实现


//#include <stdio.h>
//#include <assert.h>
//char* my_strcat(char* dest, const char* str)
//{
//	char* ret = dest;
//	assert(dest != NULL);
//	assert(str != NULL);
//	while (*dest != '\0')
//	{
//		dest++;
//	}
//	while (*dest++ = *str++)
//	{
//		 ;
//	}
//	return ret;
//}
//int main()
//{
//	char arr1[20] = {'a','\0'};
//	 printf("%s\n", my_strcat(arr1,"abcdef"));
//	return 0;
//}//my_strcat的实现


//#include <stdio.h>
//#include <assert.h>
//#include <string.h>
//char* my_strncat(char* dest, const char* str, size_t count)
//{
//	char* ret = dest;
//	assert(dest);
//	assert(str);
//	int len = strlen(str);
//	while (*dest != '\0')
//	{
//		dest++;
//	}
//	while (((int)count <= len) && (count--))
//	{
//		*dest++ = *str++;
//	}
//	return ret;
//}
//int main()
//{
//	char arr1[20] = "er";
//	printf("%s\n", my_strncat(arr1, "abcdef", 3));
//	return 0;
//}//my_strncat的实现




//#include <stdio.h>
//#include <assert.h>
//int my_strcmp(const char* str1, const char* str2)
//{
//	if (*str1 == '\0')
//		return 0;
//	assert(str1 != NULL);
//	assert(str2 != NULL);
//	while (*str1 == *str2)
//	{
//		str1++;
//		str2++;
//	}
//	return *str1 - *str2;
//}
//int main()
//{
//	char arr1[10] = "abcd";
//	char arr2[9] = "abcdef";
//	int p = my_strcmp(arr1, arr2);
//	printf("%d\n", p);
//	return 0;
//}//my_strcmp的自己实现


#include <stdio.h>
#include <assert.h>
#include <string.h>
int my_strncmp(const char* str1, const char* str2, size_t count)
{
	assert(str1);
	assert(str2);

	int len1 = strlen(str1);
	int len2 = strlen(str2);
	if ((len1 < count) || (len2 < count))
		printf("无法比较\n");
	while ((count--) && (*str1==*str2))
	{
		str1++;
		str2++;
	}
	return *str1 - *str2;
}
int main()
{
	char arr1[10] = "abcde";
	char arr2[10] = "abcdh";
	int p = my_strncmp(arr1, arr2,5);
	printf("%d\n", p);
	if (p > 0)
		printf("第一个数组大\n");
	else if (p < 0)
		printf("第二个数组大\n");
	else
		printf("两个数组一样大\n");
	return 0;
}
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char arr[10] = "abcdef";
//	printf("%s\n", strncpy(arr, "hello bit", 3));
//	return 0;
//}//strncpy的引用(注意特殊情况：要拷贝的字符串位数不足的情况)


//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char arr[10] = "abcdef";
//	printf("%s\n", strncat(arr, "world", 2));
//	return 0;
//}//strncat的引用

//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	printf("%d\n", strncmp("abc", "aefg", 1));
//	return 0;
//}//strncmp的引用


//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char arr[] = "abcdefabcdef";
//	char *ret = strchr(arr, 'd');
//	if (ret != NULL)
//		printf("%s\n", ret);
//	else
//		printf("找不到\n");
//}//strchr的引用


//#include <stdio.h>
//#include <assert.h>
//char* my_strchr1(const char* str, int c)
//{
//	assert(str != NULL);
//	while (*str != c)
//	{
//		str++;
//	}
//	return (char*)str;
//}
//
//char* my_strchr2(const char* str, int c)
//{
//	while (*str&&*str != (char)c)
//	{
//		str++;
//	}
//	if (*str == (char)c)
//		return (char*)str;//解引用是为了前面的const,防止出现不符合
//	else
//		return NULL;
//}
//int main()
//{
//	char arr[] = "abcdefrt";
//	char* ret1 = my_strchr1(arr, 'r');
//	char* ret2 = my_strchr2(arr, 'r');
//	printf("%s\n", ret1);
//	printf("%s\n", ret2);
//	return 0;
//}//my_strchr的自己实现(两种方法)


//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char arr[11] = "abcdefgyui";
//	char* ret = strstr(arr, "cdef");           
//	printf("%s\n", ret);
//	return 0;
//}//strstr的引用


//#include <stdio.h>
//char* my_strstr(const char* str1, const char* str2)
//{
//	char* s1 = (char*)str1;
//	char* s2 = (char*)str2;
//	char* cur =(char*)str1;
//	while (*cur)
//	{
//		s1 = cur;
//		s2 = (char*)str2;
//		while (*s1 && *s2 && *s1 == *s2)
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')
//			return cur;
//		cur++;
//	}
//	return NULL;
//}
//int main()
//{
//	char arr[12] = "abcdefgyui";
//	printf("%s\n", my_strstr(arr, "cdef"));
//	return 0;
//}//my_strstr的自己实现


//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char arr1[30] = "txworld@bitedu.hu";
//	char arr2[30] = { 0 };
//	const char* p = "@.";
//	char* str = NULL;
//	strcpy(arr2, arr1);//先拷贝一份
//	for (str = strtok(arr2, p); str != NULL; str = strtok(NULL, p))
//	{
//		printf("%s\n", str);
//	}
//	return 0;
//}//运用strtok;


//#include <stdio.h>
//int main()
//{
//	printf("%d\n", isspace('\n'));
//	return 0;
//}


//#include <stdio.h>
//#include <assert.h>
//void* my_memcpy(void* dest, const void* str, size_t count)
//{
//	void* ret = dest;
//	assert(dest != NULL);
//	assert(str != NULL);
//	while (count)
//	{
//		*(char*)dest = *(char*)str;
//		((char*)dest)++;
//		((char*)str)++;
//		count--;
//	}
//	return ret;
//}
//int  main()
//{
//	char arr1[15] = "abcdefgtyu";
//	char arr2[15] = { 0 };
//	 printf("%s\n", my_memcpy(arr2, arr1, 20));
//	return 0;
//}//字符型
//
//int main()
//{
//	int arr1[15] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
//	int arr2[15] = { 0 };
//	my_memcpy(arr2, arr1, 20);
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		printf(" %d ",arr2[i]);
//	}
//	printf("\n");
//	return 0;
//}//整型//my_memcpy的运用


//#include <stdio.h>
//#include <assert.h>
//void* my_memmove(void* dest, const void* str, size_t count)
//{
//	void* ret = dest;
//	assert(dest != NULL);
//	assert(str != NULL);
//	if (dest < str)
//	{
//		while (count--)
//		{
//			*(char*)dest = *(char*)str;
//			((char*)dest)++;
//			((char*)str)++;
//		}
//	}
//	else
//	{
//		while (count--)
//		{
//			*((char*)dest + count) = *((char*)str + count);
//		}
//	}
//	return ret;
//
//}
//int main()
//{
//	int i = 0;
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	my_memmove(arr, arr + 2, 16);
//	for (i = 0; i < sz; i++)
//	{
//		printf(" %d ", arr[i]);
//	}
//	printf("\n");
//	return 0;
//}//my_memmove的实现