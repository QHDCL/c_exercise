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


//��������-----�ȶ�,��������,�ӽ�����(���)   ʱ�临�Ӷ�:O(N^2)  �ռ临�Ӷ� O(1)
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

//ϣ������(��С��������)-----gap����:ÿ�μ���,����λ��,����,size/3+1(����)
void ShellSort(int *array, int size){
	int gap = size;
	while (gap > 1){
		gap = gap / 3 + 1;//(��СֵΪһ)
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



//ֱ��ѡ������-------���ȶ�(��ռ�)
void SelectSort(int *array, int size){
	//ѡ�������
	for (int i = 0; i < size - 1; i++){
		int maxPos = 0;
		//ѡ��ķ�ʽ
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
		//�������СԪ��
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
	//child������Һ����н�С�ĺ���,Ĭ������С
	int child = parent * 2 + 1;
	while (child < size){
		//�ҵ����ĺ���
		if (child + 1<size&&array[child + 1] > array[child]){
			child += 1;
		}
		//��˫�������ĺ��ӱȽ�
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

//������
void HaepSort(int *array, int size){
	//1.����--����
	int root = ((size - 2) >> 1);
	for (root; root >= 0; root--){
		HaepAdjust(root, array, size);
	}

	//2.����(ɾ���Ѷ�Ԫ��)
	int end = size - 1;
	while (end){
		int tmp = array[0];
		array[0] = array[end];
		array[end] = tmp;
		HaepAdjust(0, array, end--);
	}
}



//ð������ 
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

//����ȡ�з�ѡ��key��ֵ(������ȡ����ֵ�Ŀ���)
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



//ѡ���׼ֵ
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

//ѡ���׼ֵ
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

//ѡ���׼ֵ
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

//��������(�ݹ�)----------��������Ҷ�
void QuickSort(int *array, int left, int right){
	if (right - left <= 8){//�������ٵ�ʱ��ʹ�ò�������
		InsetSort(array + left, right - left);
	}else{
		int div = Pation3(array, left, right);
		QuickSort(array, left, div);
		QuickSort(array, div + 1, right);
	}
	
}

//��������(�ǵݹ�)
void QuickSortNor(int *array, int size){
	Stack s;
	StackInin(&s);
	StackPush(&s, size);//��
	StackPush(&s, 0);
	while(StackEmpty(&s)){
		int left=StackTop(&s);//��ȡ
		StackPop(&s);//��
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


//�鲢����
void MergeSort(int *array,  int size){
	int *temp = (int *)malloc(sizeof(array[0])*size);
	assert(temp);
	_MergeSort(array, 0, size,temp);
	free(temp);
}

//�鲢����(�ǵݹ�)
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


//��������
void CountSort(int *array, int size){
	//1.ȷ��Ԫ�ط�Χ
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
    //2.���ٿռ�
	int *count = (int *)malloc(sizeof(array[0])*range);
	memset(count, 0, sizeof(count[0])*range);

	//3.ͳ��ÿ��Ԫ�س��ֵĸ���---------��array�����е�ֵ��Ϊcount�±�
	for (int i = 0; i < size; i++){
		count[array[i] - minValue]++;
	}
	//4.����
	int index = 0;
	for (int i = 0; i < range; i++){     //count������±����array�������е���
										//count[i]�ʹ���array������i�����˼���
		int j = 0;
		while (j < count[i]){
			array[index++] = i + minValue;
			j++;
		}
	}
	free(count);
}