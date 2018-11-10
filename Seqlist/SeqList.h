#pragma once//避免头文件的重复引入，作用于预编译指令的作用几乎相同
#define MAX 100
typedef int DataType;

// 静态态顺序表的结构 
typedef struct SeqList
{
	DataType data[MAX];
	int size;            // 有效元素的个数 
}SeqList, *PSeqList;

//初始化顺序表 
void SeqListInit(PSeqList ps);

//打印顺序表
void PrintSeqList(PSeqList ps);

//在顺序表尾部插入元素data 
void SeqListPushBack(PSeqList ps, DataType data);

//在顺序表尾部删除元素
void SeqListPopBack(PSeqList ps);

//在顺序表头部插入元素
void SeqListPushFront(PSeqList ps, DataType data);

//在顺序表头部删除元素
void SeqListPopFront(PSeqList ps);

//在顺序表中查找指定元素
int FindSeqList(PSeqList ps, DataType data);

//再指定位置前面插入元素
void Insert(PSeqList ps, int pos, DataType data);

//删除指定位置的元素
void Erase(PSeqList ps, int pos);

//删除指定元素（只删除一个）
void Remove(PSeqList ps, DataType data);

//删除指定元素（删除所有的）
void AllRemove(PSeqList ps, DataType data);

//顺序表的大小
int Size(PSeqList ps);

//为空返回1,非空为0
int Empty(PSeqList ps);

//冒泡排序
void BubbleSort(PSeqList ps);

//选择排序
void SelectSort(PSeqList ps);

//优化选择排序
void SelectSort_OP(PSeqList ps);

//二分查找
int BinarySearch(PSeqList ps, DataType data);

//二分查找递归
int BinarySearch_R(PSeqList ps,int left,int right, DataType data);