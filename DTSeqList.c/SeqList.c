#include "SeqList.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>


//初始化顺序表
void SeqListInit(PSeqList ps, int capacity){
	assert(ps);
	ps->_pData = (DataType *)malloc(sizeof(DataType)*capacity);
	if (ps->_pData == NULL){
		exit(0);
	}
	ps->_capacity = capacity;
	ps->_size = 0;
}


//打印顺序表
void PrintSeqList(PSeqList ps){
	assert(ps);
	if (ps->_size == 0){
		printf("顺序表为空\n");
	}
	for (int i = 0; i <ps->_size; i++){
		printf("%d ", ps->_pData[i]);
	}
	printf("\n");
}


//尾部插入元素data
void SeqListPushBack(PSeqList ps, DataType data){
	assert(ps);
	CheckCapacity(ps);
	ps->_pData[ps->_size] = data;
	ps->_size++;
}


//尾部删除最后一个元素
void SeqListPopBack(PSeqList ps){
	assert(ps);
	if (ps->_size == 0){
		printf("顺序表为空\n");
	}
	else{
		ps->_size--;
	}
}


// 在顺序表的头部插入元素data
void SeqListPushFront(PSeqList ps, DataType data){
	assert(ps);
	CheckCapacity(ps);
	for (int i = ps->_size ; i >=0;i--){
		ps->_pData[i] = ps->_pData[i-1];
	}
	ps->_pData[0] = data;
	ps->_size++;
}


// 删除顺序表的头部元素
void SeqListPopFront(PSeqList ps){
	assert(ps);
	if (ps->_size == 0){
		printf("顺序表为空\n");
	}
	else{
		for (int i = 0; i < ps->_size; i++){
			ps->_pData[i] = ps->_pData[i + 1];
		}
		ps->_size--;
	}
}


// 在顺序表的pos位置插入元素data
void SeqListInsert(PSeqList ps, int pos, DataType data){
	assert(ps);
	if (pos<0 || pos>ps->_size){
		printf("位置信息有误\n");
	}

	CheckCapacity(ps);

	for (int i = ps->_size-1; i >=pos; i--){
		ps->_pData[i + 1] = ps->_pData[i];
	}
	ps->_pData[pos] = data;
	ps->_size++;
	
	
}


// 删除顺序表中pos位置上的元素
void SeqListErase(PSeqList ps, int pos){
	if (pos<0 || pos>ps->_size){
		printf("位置信息有误\n");
	}
	for (int i =pos+1; i<ps->_size; i++){
		ps->_pData[i - 1] = ps->_pData[i];
	}
	ps->_size--;
	
}


// 在顺序表中找data元素第一次出现的位置
int SeqListFind(PSeqList ps, DataType data){
	assert(ps);
	for (int i = 0; i < ps->_size; i++){
		if (ps->_pData[i] == data){
			return i;
		}
	}
	return -1;
}


// 删除顺序表中值为data的元素
void SeqListRemove(PSeqList ps, DataType data){
	assert(ps);
	int pos = SeqListFind(ps,data);
	SeqListErase(ps, pos);
}


// 获取顺序表中有效元素的个数
int SeqListSize(PSeqList ps){
	assert(ps);
	return ps->_size;
}


// 获取顺序表的容量
int SeqListCapacity(PSeqList ps){
	assert(ps);
	return ps->_capacity;
}



// 获取顺序表中第一个元素
DataType SeqListFront(PSeqList ps){
	assert(ps);
	return ps->_pData[0];
}

// 获取顺序表中最后一个元素
DataType SeqListBack(PSeqList ps){
	assert(ps);
	return ps->_pData[ps->_size-1];
}


// 清空顺序表中有效元素的个数
void SeqListClear(PSeqList ps){
	assert(ps);
	ps->_size = 0;
}

// 销毁顺序表
void SeqListDestroy(PSeqList ps){
	assert(ps);
	if (ps->_pData){
		free(ps->_pData);
		ps->_capacity = 0;
		ps->_size = 0;
	}
}


// 检测容量
void CheckCapacity(PSeqList ps){
	assert(ps);
	if (ps->_size == ps->_capacity){
		int newCapacity = ps->_capacity * 2;

		DataType *pNew = (DataType *)malloc(sizeof(DataType));
		if (NULL == pNew){
			printf("内存不足,申请失败!!!\n");
			exit(0);
		}
		memcpy(pNew, ps->_pData, sizeof(DataType));
	}

}



// 删除顺序表中所有值为data的元素
void SeqListRemoveAll(PSeqList ps, DataType data){
	assert(ps);
	DataType *tmp = NULL;
	int count = 0;
	int i = 0;
#if 0
	for (i = 0; i < ps->size; i++){
		if (ps->data[i] == data){
			int j = 0;
			for (j = i; j < ps->size - 1; j++){
				ps->data[j] = ps->data[j + 1];
			}
			ps->size--;
			--i;
		}
	}
#endif


#if 0    //借助临时空间
	tmp = (DataType *)malloc(sizeof(DataType)*ps->size);
	if (tmp == NULL){
		exit(0);
	}
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

	for (i = 0; i < ps->_size; i++){
		if (ps->_pData[i] != data){
			ps->_pData[i - count] = ps->_pData[i];
		}
		else{
			count++;
		}
	}
	ps->_size -= count;
}





void Swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

// 用冒泡排序的方式对顺序表中的元素进行排序
void BubbleSort(PSeqList ps){
	assert(ps);
	int flag = 0;
	if (ps->_size == 0){
		printf("顺序表为空!!!\n");
	}
	else{
		for (int i = 0; i < ps->_size; i++){
			flag = 0;
			for (int j = 0; j<ps->_size - 1; j++){
				if (ps->_pData[j]>ps->_pData[j + 1]){
					Swap(ps->_pData + j, ps->_pData + j + 1);
					flag = 1;
				}
			}
			if (flag == 0){
				return;
			}
		}
	}
}
