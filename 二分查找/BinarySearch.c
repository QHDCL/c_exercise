#include<stdio.h>
#include<Windows.h>

int BinarySearch(int *arr, int size,int data){
	int left = 0;
	int right = size - 1;
    
	

	while (left <= right){
		int mid = left + ((right - left) >> 1);
		if (arr[mid] > data){
			right = mid - 1;
		}
		else if (arr[mid] < data){
			left = mid + 1;
		}
		else{
			return mid;
			break;
		}
	}
	return -1;
}

int main(){
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int size = sizeof(arr) / sizeof(arr[0]);

	int pos = 0;
	pos = BinarySearch(arr, size, 7);

	if (pos!=-1){
		printf("找到了，下标为：%d\n", pos);
	}
	else{
		printf("找不到元素\n");
	}
	system("pause");
	return 0;
}