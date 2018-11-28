//堆:
//将根节点最大的堆叫做最大堆或大根堆，根节点最小的堆叫做最小堆或小根堆。
//堆中某个节点的值总是不大于或不小于其父节点的值；
//堆总是一棵完全二叉树。


//小堆
#pragma once
typedef int HDataType;
typedef struct Heap{
	HDataType *_array;
	int _capacity;
	int _size;
}Heap;

//初始化
void HeapInit(Heap* hp, HDataType *array, int size);

//打印
void HeapPrint(Heap* hp);

//销毁
void HeapDestory(Heap* hp);

//插入
void HeapInsert(Heap* hp, HDataType data);

//删除
void HeapPop(Heap* hp);

//获取根节点
HDataType HeapTop(Heap* hp);

//获取大小
int Heapsize(Heap* hp);

//判空
int HeapEmpty(Heap* hp);

//测试 
void TestHeap();