#include"Sort.h"
#include"E:\Program Files (x86)\code\stack\stack\stack.h"
#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<string.h>

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}


void PrintArray(int *array, int size){
	for (int i = 0; i < size; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
}


//插入排序-----稳定,数据量少,接近有序(最好)   时间复杂度:O(N^2)  空间复杂度 O(1)
void InsetSort(int *array, int size){
	for (int i = 1; i < size; i++){
		int key = array[i];
		int end = i - 1;
		while (end >= 0 && key < array[end]){
			array[end + 1] = array[end];
			end--;
		}
		array[end + 1] = key;
	}
}

//希尔排序(缩小增量排序)-----gap给法:每次减半,奇数位置,素数,size/3+1(最优)
void ShellSort(int *array, int size){
	int gap = size;
	while (gap > 1){
		gap = gap / 3 + 1;//(最小值为一)
		for (int i = gap; i < size; i++){
			int key = array[i];
			int end = i - gap;
			while (end >= 0 && key  < array[end]){
				array[end + gap] = array[end];
				end -= gap;
			}
			array[end + gap] = key;
		}
	}
}



//直接选择排序-------不稳定(跨空间)
void SelectSort(int *array, int size){
	//选择的躺数
	for (int i = 0; i < size - 1; i++){
		int maxPos = 0;
		//选择的方式
		for (int j = 1; j < size - i; j++){
			if (array[maxPos]<array[j]){
				maxPos = j;
			}
		}
		if (maxPos != size - i - 1){
			swap(&array[maxPos], &array[size - 1 - i]);
		}
	}
}

void SelectSortOP(int *array,int size){
	int begin = 0;
	int end = size - 1;
	while (begin < end){
		int minPos = begin;
		int maxPos = begin;
		int index = begin + 1;
		//找最大最小元素
		while (index <= end){
			if (array[index] < array[minPos]){
				minPos = index;
			}
			if (array[index] > array[maxPos]){
				maxPos = index;
			}
			index++;
		}
		if (maxPos != end){
			swap(&array[maxPos], &array[end]);
		}
		if (minPos == end){
			minPos = maxPos;
		}
		if (minPos != end){
			swap(&array[minPos], &array[begin]);
		}
		begin++;
		end--;
	}
}

void HaepAdjust(int root,int *array, int size){
	int parent = root;
	//child标记左右孩子中较小的孩子,默认左孩子小
	int child = parent * 2 + 1;
	while (child < size){
		//找到最大的孩子
		if (child + 1<size&&array[child + 1] > array[child]){
			child += 1;
		}
		//将双亲与最大的孩子比较
		if (array[parent]<array[child]){
			int  tmp = array[parent];
			array[parent] = array[child];
			array[child] = tmp;
			parent = child;
			child = parent * 2 + 1;
		}
		else{
			return;
		}
	}
}

//堆排序
void HaepSort(int *array, int size){
	//1.建堆--升序
	int root = ((size - 2) >> 1);
	for (root; root >= 0; root--){
		HaepAdjust(root, array, size);
	}

	//2.排序(删除堆顶元素)
	int end = size - 1;
	while (end){
		int tmp = array[0];
		array[0] = array[end];
		array[end] = tmp;
		HaepAdjust(0, array, end--);
	}
}



//冒泡排序 
void BubbleSort(int *array, int size){
	int flag;
	for (int i = 0; i < size - 1; i++){
		flag = 0;
		for (int j = 0; j < size - i - 1; j++){
			if (array[j]>array[j + 1]){
				swap(&array[j], &array[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0){
			return;
		}
	}
}

//三数取中法选择key的值(降低了取到极值的可能)
int GetMidIndex(int*array, int left, int right){
	int mid = ((right - left) >> 1 )+ left;

	if (array[left] < array[right-1]){
		if (array[mid] < array[left]){
			return left;
		}
		else if (array[right-1]<array[mid]){
			return right-1;
		}
		else{
			return mid;
		}
	}
	else{
		if (array[mid] >array[left]){
			return left;
		}
		else if (array[right-1]>array[mid]){
			return right-1;
		}
		else{
			return mid;
		}
	}
}



//选择基准值
int Pation1(int* array, int left, int right)
{
	int prev = left - 1;
	int cur = left;
	int mid = GetMidIndex(array, left, right);
	if (mid != right - 1){
		swap(&array[mid], &array[right - 1]);
	}

	int key = array[right - 1];

	while (cur < right-1)
	{
		if (array[cur] < key && ++prev != cur)
			swap(&array[cur], &array[prev]);
		++cur;
	}
	if (++prev != right-1 )
		swap(&array[prev], &array[right-1]);
	return prev;
}

//选择基准值
int Pation2(int* array, int left, int right){
	int begin = left;
	int end = right-1;
	int mid = GetMidIndex(array, left, right);
	if (mid != right - 1){
		swap(&array[mid], &array[right - 1]);
	}
	int key = array[right - 1];
	while (begin < end){	
		while (begin < end && array[begin] < key){
			begin++;
		}
		array[end] = array[begin];
		while (begin < end && array[end] > key){
			end--;
		}
		array[begin] = array[end];
	}
	array[begin] = key;
	return begin;
}

//选择基准值
int Pation3(int* array, int left, int right){
	int begin = left;
	int end = right - 1;
	int mid = GetMidIndex(array, left, right);
	if (mid != right - 1){
		swap(&array[mid], &array[right - 1]);
	}
	int key = array[right - 1];

	while (begin<end){
		while (begin<end&&array[begin]<key){
			begin++;
		}
		swap(&array[begin], &array[end]);
		while (begin<end&&array[end]>key){
			end--;
		}
		swap(&array[end], &array[begin]);
	}
	return begin;
}

//快速排序(递归)----------数据随机且多
void QuickSort(int *array, int left, int right){
	if (right - left <= 8){//数据量少的时候使用插入排序
		InsetSort(array + left, right - left);
	}else{
		int div = Pation3(array, left, right);
		QuickSort(array, left, div);
		QuickSort(array, div + 1, right);
	}
	
}

//快速排序(非递归)
void QuickSortNor(int *array, int size){
	Stack s;
	StackInin(&s);
	StackPush(&s, size);//入
	StackPush(&s, 0);
	while(StackEmpty(&s)){
		int left=StackTop(&s);//获取
		StackPop(&s);//出
		int right=StackTop(&s);
		StackPop(&s);
		if(right-left>1){
			int div=Pation1(array,left,right);
			StackPush(&s,right);
			StackPush(&s,div+1);
			StackPush(&s,div);
			StackPush(&s,left);
		}
	}
	StackDestory(&s);
}





void MergeData(int *array, int *temp, int left, int mid, int right){
	int begin1 = left;
	int end1 = mid;
	int begin2 = mid;
	int end2 = right;
	int index = left;
	while (begin1<end1&&begin2<end2)
	{
		if (array[begin1] <= array[begin2])
			temp[index++] = array[begin1++];
		else
			temp[index++] = array[begin2++];
	}
	while (begin1<end1){
		temp[index++] = array[begin1++];
	}
	while (begin2<end2){
		temp[index++] = array[begin2++];
	}
}

void _MergeSort(int *array,int left,int right,int *temp){
	if (right-left>1)
	{
		int mid = left + ((right - left) >> 1);
		_MergeSort(array, left, mid,temp);
		_MergeSort(array, mid, right,temp);

		MergeData(array,temp,left, mid, right);
		memcpy(array + left, temp + left, (right - left)*sizeof(array[0]));
	}
}


//归并排序
void MergeSort(int *array,  int size){
	int *temp = (int *)malloc(sizeof(array[0])*size);
	assert(temp);
	_MergeSort(array, 0, size,temp);
	free(temp);
}

//归并排序(非递归)
void MergeSortNor(int *array, int size){
	int *temp = (int*)malloc(size*sizeof(array[0]));
	assert(temp);
	int gap = 1;
	while (gap < size){
		for (int i = 0; i < size; i += 2 * gap){
			int left = i;
			int mid = left + gap;
			int right = mid + gap;

			if (mid>size){
				mid = size;
			}
			if (right>size){
				right = size;
			}
			MergeData(array, temp, left, mid, right);
		}
		memcpy(array, temp, sizeof(array[0] )* size);
		gap *= 2;
	}
	free(temp);
}


//计数排序
void CountSort(int *array, int size){
	//1.确定元素范围
	int	minValue = array[0];
	int maxValue = array[0];
	for (int i = 0; i < size; i++){
		if (array[i] < minValue){
			minValue = array[i];
		}
		if (array[i]>maxValue){
			maxValue = array[i];
		}
	}
	int range = maxValue - minValue+1;
    //2.开辟空间
	int *count = (int *)malloc(sizeof(array[0])*range);
	memset(count, 0, sizeof(count[0])*range);

	//3.统计每个元素出现的个数---------以array数组中的值作为count下标
	for (int i = 0; i < size; i++){
		count[array[i] - minValue]++;
	}
	//4.回收
	int index = 0;
	for (int i = 0; i < range; i++){     //count数组的下标就是array数组中有的数
										//count[i]就代表array数组中i出现了几次
		int j = 0;
		while (j < count[i]){
			array[index++] = i + minValue;
			j++;
		}
	}
	free(count);
}