#include"Sort.h"
#include<Windows.h>
#include<stdio.h>

int main(){
	int array[] = { 4, 7, 3, 1, 6, 8, 2, 9, 0, 5 };
	int size = sizeof(array) / sizeof(array[0]);
	printf("before sort:\n");
	PrintArray(array, size);
	//InsetSort(array, size);

	//ShellSort(array, size);

	//SelectSort(array,size);

	//SelectSortOP(array, size);

	//HaepSort(array, size);

	//BubbleSort(array, size);

	//QuickSort(array, 0, size);

	QuickSortNor(array, size);
	
	//MergeSort(array,size);

	//MergeSortNor(array, size);

	//CountSort(array, size);

	printf("after sort:\n");
	PrintArray(array, size);

	system("pause");
	return 0;

}