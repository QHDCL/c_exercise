#include<stdio.h>
#include<Windows.h>

void Swap (int* a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void BubbleSort(int *arr, int size){
	int i = 0;
	int j = 0;
	int flag = 0;
	for (i = 0; i < size; i++){
		flag = 0;
		for (j = 0; j < size - 1 - i; j++){
			if (arr[j]>arr[j + 1]){
				Swap(&arr[j], &arr[j + 1]);
				flag = 1;
			}
		}
	}
	if (flag == 0){
		return;
	}
}

int main(){
	int i = 0;
	int arr[] = { 23, 43, 1, 5, 67, 42, 6, 89, 55 };
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("原始的数组\n");
	for (i=0; i < size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");

	BubbleSort(arr,size);
	printf("冒泡排序后的数组\n");
	for (i=0; i < size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}