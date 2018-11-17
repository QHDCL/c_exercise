#pragma once


typedef int SLDataType;
typedef struct SListNode
{
	struct SListNode* _pNext;   //next域
	SLDataType _data;           //数字域
}SListNode;


////////不带头节点的单链表 /////////////////
//
//链表初始化
void SListInit(SListNode** pHead);

//创建新结点
SListNode* SListNewNode(SLDataType data);

//销毁结点
void SListIDestroyNode(SListNode** pHead);

//打印链表
void SListPrint(SListNode* pHead);

//尾插
void SListPushBack(SListNode** pHead, SLDataType data);

//尾删
void SListPopBack(SListNode** pHead);

//头插
void SListPushFront(SListNode** pHead, SLDataType data);

//头删
void SListPopFront(SListNode** pHead);

//查找
SListNode* SListFind(SListNode** pHead, SLDataType data);

//任意位置插入
void SListInsert(SListNode** pHead, SListNode* pos, SLDataType data);

//任意位置删除
void SListErase(SListNode** pHead, SListNode* pos);

//销毁单链表
void SListDestroy(SListNode** pHead);

//链表大小
int SListSize(SListNode* pHead);

//判空
int SListEmpty(SListNode* pHead);

//首节点
SLDataType Front(SListNode* pHead);

//末节点
SLDataType Back(SListNode* pHead);

//删除第一个值为data的结点
void SListRemove(SListNode** pHead, SLDataType data);

//删除值为data的所有节点
void SListRemoveAll(SListNode** pHead, SLDataType data);

//冒泡排序
void SlistBubbleSort(SListNode** pHead);

