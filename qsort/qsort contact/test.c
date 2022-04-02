#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

struct stu
{
	char name[20];
	int age;
};

void swap(char* dest, char* sour, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		int tmp = *dest;
		*dest = *sour;
		*sour = tmp;
		dest++;
		sour++;
	}
}



void* my_sort(void* base, int lens, int width, int(*cmp)(void* a, void* b))
{
	int i = 0;
	for (i = 0; i < lens-1; i++)
	{
		int j = 0;
		for (j = 0; j < lens - i-1; j++)
		{
			if (cmp((char*)base + j * width, (char*)base + width * (j + 1))>0)
				swap((char*)base + j * width, (char*)base + width * (j + 1),width);

		}
	}

}

int struct_cmp(void* a,void* b)
{
	return strcmp((*(struct stu*)a).name, (*(struct stu*)b).name);
}

int cmp_ch(void* a,void* b)
{
	return *(char*)a - *(char*)b;
}

int cmp_double(void* a, void* b)
{
	if (*(double*)a - *(double*)b > 0)
		return 1;
	else if (*(double*)a - *(double*)b < 0)
		return -1;
	else
		return 0;
}

int main()
{
	struct stu s[3] = { {"zhangsan",30},{"lisi",20},{"wangwu",10} };
	char ch[5] = { 'f','d','e','a','b' };
	double arr[5] = { 1.2,1.1,3.0,5.0,4.0 };
	/*int ret = sizeof(s) / sizeof(s[0]);*/
	/*printf("%d", ret);*/
	/*my_sort(s, 3, sizeof(s[0]),struct_cmp);
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		printf("%s ", s[i].name);
	}*/
	/*my_sort(ch, 5, sizeof(ch[0]), cmp_ch);
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		printf("%c", ch[i]);
	}*/

	my_sort(arr, 5, sizeof(arr[0]), cmp_double);
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		printf("%lf", arr[i]);
	}
}