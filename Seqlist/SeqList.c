#include"SeqList.h"
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>


//动态初始化
void SeqListInit(PSeqList ps){
	assert(ps);
	ps->size = 0;
	memset(ps->data, 0, sizeof(ps->data));
}

// 在顺序表尾部插入元素data 
void SeqListPushBack(PSeqList ps, DataType data){
	//断言
	assert(ps);
	//判断满
	if (ps->size == MAX){
		printf("顺序表已满，无法插入\n");
		return;
	}
	//存储元素
	ps->data[ps->size] = data;
	ps->size++;
}

//打印顺序表
void PrintSeqList(PSeqList ps){
	assert(ps);
	if (ps->size == 0){
		printf("顺序表为空\n");
	}
	for (int i = 0; i <ps->size; i++){
		printf("%d ", ps->data[i]);
	}
	printf("\n");
}

//尾删
void SeqListPopBack(PSeqList ps){
	assert(ps);
	//判空
	if (ps->size==0){
		printf("顺序表为空，无法删除\n");
	}
	//删除
	ps->size--;
}

//头插
void SeqListPushFront(PSeqList ps, DataType data){
	assert(ps);
	//判满
	if (ps->size == MAX){
		printf("顺序表已满，无法插入\n");
		return;
	}
	for (int i = ps->size - 1; i >= 0; i--){
		ps->data[i + 1] = ps->data[i];
	}
	ps->data[0] = data;
	ps->size++;
}

void SeqListPopFront(PSeqList ps){
	assert(ps);
	if (ps->size == 0){
		printf("顺序表为空，无法删除\n");
		return;
	}
	for (int i = 0; i <ps->size ; i++){
		ps->data[i] = ps->data[i + 1];
	}
	ps->size--;
}

int FindSeqList(PSeqList ps, DataType data){
	assert(ps);
	for (int i = 0; i < ps->size; i++){
		if (ps->data[i] == data){
			return i;
		}
	}
	return -1;
}

void Insert(PSeqList ps, int pos, DataType data){
	assert(ps);
	assert(pos>0 && pos <= ps->size);
	if (ps->size == MAX){
		printf("顺序表已满，无法插入\n");
		return;
	}
	for (int i = ps->size-1; i >= pos ; i--){
		ps->data[i+1] = ps->data[i];
	}
	ps->data[pos] = data;
	ps->size++;
}

void Erase(PSeqList ps, int pos){
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);

	if (ps->size == 0){
		printf("顺序表为空，无法删除\n");
		return;
	}
	for (int i = pos; i < ps->size - 1; i++){
		ps->data[i] = ps->data[i + 1];
	}
	ps->size--;
}


void Remove(PSeqList ps, DataType data){
	int i = 0;
	int pos = 0;
	assert(ps);
	if (ps->size == 0){
		printf("顺序表为空\n");
		return;
	}

	if((pos=FindSeqList(ps,data))!=-1){
		Erase(ps,pos);
	}
}
#if 0
	for (i = 0; i < ps->size; i++){
		if (ps->data[i] == data){
			break;
		}
	}
	if (i == ps->size){
		printf("删除元素不存在\n");
		return;
	}
	//删除
	for (; i < ps->size - 1; i++){
		ps->data[i] = ps->data[i + 1];
	}
	ps->size--;
#endif


void AllRemove(PSeqList ps, DataType data){
	assert(ps);
	DataType *tmp = NULL;
	int count = 0;
	int i = 0;
#if 0
	for (i = 0; i < ps->size; i++){
		if (ps->data[i] == data){
			int j = 0;
			for (j = i; j < ps->size-1; j++){
				ps->data[j] = ps->data[j + 1];
			}
			ps->size--;
			--i;
		}
	}
#endif


#if 0
	tmp = (DataType *)malloc(sizeof(DataType)*ps->size);
	for (i = 0; i < ps->size; i++){
		if (ps->data[i] != data){
			tmp[count++] = ps->data[i];
		}
	}
	memcpy(ps->data, tmp, count*sizeof(DataType));
	ps->size = count;
	free(tmp);
	tmp = NULL;
#endif

	for (i = 0; i < ps->size; i++){
		if (ps->data[i] != data){
			ps->data[count++] = ps->data[i];
		}
	}
	ps->size = count;
}


int Size(PSeqList ps){
	assert(ps);
	return ps->size;
}


int Empty(PSeqList ps){
	assert(ps);
	return ps->size==0;
}


void Swap(DataType* p1, DataType* p2){
	DataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void BubbleSort(PSeqList ps){
	assert(ps);
	int i = 0;
	int j = 0;
	int flag = 0;
	for (i = 0; i < ps->size - 1; i++){
		flag = 0;
		for (j = 0; j < ps->size - 1 - i; j++){
			if (ps->data[j]>ps->data[j + 1]){
				Swap(ps->data + j, ps->data + j + 1);
				flag = 1;
			}
		}
		if (flag == 0){
			return;
		}
	}
}



void SelectSort(PSeqList ps){
	int i = 0;
	int j = 0;
	assert(ps);
	for (i = 0; i < ps->size-1; i++){
		int max = 0;
		for (j = 1; j < ps->size-i; j++){
			if (ps->data[max] < ps->data[j]){
				max = j;
			}
		}
		//max最大元素的下标
		if (max != ps->size - 1 - i){
			Swap(ps->data + max, ps->data + ps->size-1-i);
		}
	}
}


void SelectSort_OP(PSeqList ps){
	assert(ps);
	int start = 0;
	int end = ps->size - 1;
	while (start < end){
		int max = start;
		int min = start;
		int i = 0;
		for (i = start; i <= end; i++){
			if (ps->data[i]>ps->data[max]){
				max = i;
			}
			if (ps->data[i] < ps->data[min]){
				min = i;
			}
		}
		if (min != start){
			Swap(ps->data + start, ps->data + min);
		}
		if (max == start){
			max = min;
		}
		if (max != end){
			Swap(ps->data + max, ps->data + end);
		}
			start++;
			end--;
	}
}




int BinarySearch(PSeqList ps, DataType data){
	int left = 0;
	int right = ps->size - 1;
	while (left<=right){
		int mid = left + ((right - left) >> 1);
		if (ps->data[mid] > data){
			right = mid - 1;
		}
		else if (ps->data[mid] < data){
			left = mid + 1;
		}
		else{
			return mid;
		}
	}
	return -1;
}



int BinarySearch_R(PSeqList ps, int left, int right, DataType data){
	int mid = 0;
	if (left > right){
		return -1;
	}
	mid = left + ((right - left) >> 1);

	if (ps->data[mid] > data){
		return BinarySearch_R(ps, left, mid - 1, data);
	}
	else if (ps->data[mid] < data){
		return BinarySearch_R(ps, mid+1, right, data);
	}
	else{
		return mid;
	}
}