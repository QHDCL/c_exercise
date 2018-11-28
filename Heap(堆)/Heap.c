#include"Heap.h"
#include<assert.h>
#include<stdlib.h>
#include<malloc.h>
#include<stdio.h>
#include<string.h>


void AdjustDown(int root, HDataType* array,int size){
	int parent = root;
	//child������Һ����н�С�ĺ���,Ĭ������С
	int child = parent * 2 + 1;
	while (child < size){
		//�ҵ���С�ĺ���
		if (child + 1<size&&array[child + 1] < array[child]){
			child += 1;
		}
		//��˫������С�ĺ��ӱȽ�
		if (array[parent]>array[child]){
			HDataType tmp = array[parent];
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

void AdjustUP(int child, HDataType *array, int size){
	int parent = ((child - 1) >> 1);
	while (child){
		if (array[parent]>array[child]){
			HDataType tmp = array[parent];
			array[parent] = array[child];
			array[child] = tmp;
			child = parent;
			parent = ((child - 1) >> 1);
		}
		else{
			return;
		}
	}
}


//�������
void _CheckCapacity(Heap* hp){
	assert(hp);
	if (hp->_size == hp->_capacity){
		
		HDataType *pNew = (HDataType *)realloc( hp->_array,sizeof(HDataType)*hp->_capacity*2);
		if (pNew == NULL){
			return;
		}
		hp->_array = pNew;
		hp->_capacity *= 2;
	}
}

//��ʼ��
//ʱ�临�Ӷ�:n*log(2^(n+1))
void HeapInit(Heap* hp, HDataType *array, int size){
	assert(hp);
	hp->_array = (HDataType*)malloc(sizeof(HDataType)*size);
	if (hp->_array == NULL){
		return;
	}
	for (int i = 0; i < size; i++){
		hp->_array[i] = array[i];
	}
	hp->_capacity = size;
	hp->_size = size;
	int root = ((size - 2) >> 1);
	for (root; root >= 0; root--){
		AdjustDown(root, hp->_array, size);
	}
}

//��ӡ
void HeapPrint(Heap* hp){
	assert(hp);
	for (int i = 0; i < hp->_size; i++){
		printf("%d ", hp->_array[i]);
	}
	printf("\n");
}

//����
void HeapInsert(Heap* hp, HDataType data){
	assert(hp);
	_CheckCapacity(hp);//�������
	hp->_array[hp->_size++] = data;
	//�ƻ��ѵ�����,���ϵ���
	AdjustUP(hp->_size - 1, hp->_array, hp->_size);
}

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//ɾ��
void HeapPop(Heap* hp){
	assert(hp);

	swap((&hp->_array[0]), &(hp->_array[hp->_size-1]));
	hp->_size--;

	//���µ���
	AdjustDown(0, hp->_array, hp->_size);
}



//�Ѷ�Ԫ��
HDataType HeapTop(Heap* hp){
	assert(hp);
	return hp->_array[0];
}

//�ѵĴ�С
int Heapsize(Heap* hp){
	assert(hp);
	return hp->_size;
}


///////////////////////////////////////////////
//����
void TestHeap(){
	Heap hp;
	int array[4] = { 10, 2, 5, 7 };
	int size = sizeof(array) / sizeof(array[0]);
	HeapInit(&hp,array,size);
	HeapPrint(&hp);

	HeapInsert(&hp, 1);
	HeapInsert(&hp, 3);
	HeapInsert(&hp, 4);
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);

	printf("�ѵĴ�С:%d\n", Heapsize(&hp));
	printf("�Ѷ�Ԫ��:%d\n", HeapTop(&hp));

}