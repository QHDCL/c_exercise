#include"Heap.h"
#include<assert.h>
#include<stdlib.h>
#include<malloc.h>
#include<stdio.h>
#include<string.h>


void AdjustDown(int root, HDataType* array,int size){
	int parent = root;
	//child标记左右孩子中较小的孩子,默认左孩子小
	int child = parent * 2 + 1;
	while (child < size){
		//找到最小的孩子
		if (child + 1<size&&array[child + 1] < array[child]){
			child += 1;
		}
		//将双亲与最小的孩子比较
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


//检测容量
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

//初始化
//时间复杂度:n*log(2^(n+1))
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

//打印
void HeapPrint(Heap* hp){
	assert(hp);
	for (int i = 0; i < hp->_size; i++){
		printf("%d ", hp->_array[i]);
	}
	printf("\n");
}

//插入
void HeapInsert(Heap* hp, HDataType data){
	assert(hp);
	_CheckCapacity(hp);//检测容量
	hp->_array[hp->_size++] = data;
	//破坏堆的性质,向上调整
	AdjustUP(hp->_size - 1, hp->_array, hp->_size);
}

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//删除
void HeapPop(Heap* hp){
	assert(hp);

	swap((&hp->_array[0]), &(hp->_array[hp->_size-1]));
	hp->_size--;

	//向下调整
	AdjustDown(0, hp->_array, hp->_size);
}



//堆顶元素
HDataType HeapTop(Heap* hp){
	assert(hp);
	return hp->_array[0];
}

//堆的大小
int Heapsize(Heap* hp){
	assert(hp);
	return hp->_size;
}


///////////////////////////////////////////////
//测试
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

	printf("堆的大小:%d\n", Heapsize(&hp));
	printf("堆顶元素:%d\n", HeapTop(&hp));

}