#include<stdio.h>
#include<Windows.h>
#include<assert.h>

void Swap(int* a, int *b){
	assert(a&&b);
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void SelectSort(int *arr, int size){
	assert(arr);
	int i = 0;
	int j = 0;
	for (i = 0; i < size; i++){
		for (j = i + 1; j < size; j++){
			if (arr[i]>arr[j]){
				Swap(&arr[i], &arr[j]);
			}
		}
	}
}

int main(){
	int i = 0;
	int arr[] = { 23, 43, 1, 5, 67, 42, 6, 89, 55 };
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("原始的数组\n");
	for (i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");

	SelectSort(arr, size);
	printf("快速排序后的数组\n");
	for (i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}