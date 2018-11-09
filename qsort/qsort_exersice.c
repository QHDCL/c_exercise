//qsort 的函数原型是
//
//void qsort(void*base, size_t num, size_t width, int(__cdecl*compare)(const void*, const void*));
//
//各参数：1 待排序数组首地址 
//2 数组中待排序元素数量 3 各元素的占用空间大小 
//4 指向函数的指针 其中base是排序的一个集合数组，num是这个数组元素的个数，
//width是一个元素的大小，comp是一个比较函数。比如：对一个长为1000的数组进行排序时，
//int a[1000]; 那么base应为a，num应为 1000，width应为 sizeof(int)，
//comp函数随自己的命名。
//qsort(a, 1000, sizeof(int), comp);
//
// 功能： 对buf 指向的数据(包含num 项, 每项的大小为size)进行快速排序。
//如果函数compare 的第一个参数小于第二个参数，返回负值；如果等于返回零值；
//如果大于返回正值。函数对buf 指向的数据按升序排序。
#if 0
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>  
#include<stdlib.h>  
#include<math.h>  
#include<string.h>  
#include<assert.h>

int cmp1(const void * a, const void * b){
	assert(a);
	assert(b);
	return (*(int*)a - *(int*)b);//              //cmp1返回值   <0  a在b前。 >0  a在b后  =0   a=b
}

int cmp2(const void * a, const void *b){
	assert(a);
	assert(b);
	return(*(char*)a - *(char*)b);
}

int cmp3(const void *a, const void *b)
{
	assert(a);
	assert(b);
	return strcmp((char *)*(int *)a, (char *)*(int *)b);
}
int main()
{
	int i;
	int a[10] = { 9, 1, 3, 2, 7, 5, 6, 4, 8, 0 };
	char b[10] = { 'i', 'g', 'c', 'e', 'd', 'f', 'b', 'h', 'a', 'j' };
	char *c[5] = { "ddd", "fff","aaa", "bbb", "mmm" };
	qsort(a, 10, sizeof(int), &cmp1);//对于函数指针（指向函数的指针），直接传入函数名和函数名进行&  
	//运算都是可以的，因为在调用函数时也是取的函数的地址  所以上下两种调用函数的方式都是可以的
	qsort(b, 10, sizeof(char), cmp2);
	qsort(c, 5, sizeof(char *), cmp3);
	for (i = 0; i < 10; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
	for (i = 0; i < 10; i++){
		printf("%c ", b[i]);
	}
	printf("\n");
	for (i = 0; i < 5; i++)
	{
		printf("%s ", c[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}
#endif

#define _CRT_SECURE_NO_WARNINGS 1  
#include<stdio.h>  
#include <stdio.h>
int cmp(const void*n1, const void*n2)      //判断n1,n2元素大小，n1比n2大返回正数；小返回负数，相同返回0  
{
	return *(char*)n1 - *(char*)n2;        //升序  
}

void Swap(char *buf1, char* buf2, int width)  //交换每个字节  
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}

void bubble_sort(void *base, int sz, int width, int(*cmp)(const void* n1, const void*n2))   //模拟实现qsort  
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			int ret = cmp(((char*)base + (j*width)), ((char*)base + (j + 1)*width));
			if (ret>0)
			{
				Swap(((char*)base + (j*width)), ((char*)base + (j + 1)*width), width);
			}
		}
	}
}

int main()
{
	int arr[] = { 5, 4, 3, 2, 1 };
	bubble_sort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), cmp);
	int i = 0;
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	char arr1[] = { 'z', 'l', 's', 'x', 'm' };
	bubble_sort(arr1, sizeof(arr1) / sizeof(arr1[0]), sizeof(arr1[0]), cmp);
	for (i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++)
	{
		printf("%c ", arr1[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}
