#include"Slist.h"
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>


//初始化
void SListInit(SListNode** pHead){
	assert(pHead);
	*pHead = NULL;
}

//创建新结点
SListNode* SListNewNode(SLDataType data){
	SListNode* _pNew = (SListNode*)malloc(sizeof(data));
	assert(_pNew);
	_pNew->_data = data;
	_pNew->_pNext = NULL;
	return _pNew;
}

//销毁结点
void SListIDestroyNode(SListNode** pHead)
{
	//释放该结点，并将头指针指向NULL，防止出现野指针
	free(pHead);
	*pHead = NULL;
}

//打印链表
void SListPrint(SListNode* pHead){
	SListNode* pCur = pHead;
	for (pCur; pCur != NULL; pCur = pCur->_pNext)
	{
		printf("%d--->", pCur->_data);
	}
	printf("NULL\n");
}


//尾插
void SListPushBack(SListNode** pHead, SLDataType data){
	assert(pHead);
	SListNode* NewNode = SListNewNode(data);
	//如果链表为空，则直接让头指针指向新申请的节点即可
	if (*pHead == NULL)
	{
		*pHead = NewNode;
		return;
	}
	//否则从头开始遍历链表，直到当前节点的指针域指向NULL，然后让当前节
	//点的指针域指向新申请的节点即可
	SListNode* pTail = *pHead;
	while (pTail->_pNext)
	{
		pTail = pTail->_pNext;
	}
	pTail->_pNext = NewNode;
}

//尾删
void SListPopBack(SListNode** pHead){
	assert(pHead);
	//三种情况分别对待
	if (NULL == *pHead)
	{
		return;
	}
	else if (NULL == (*pHead)->_pNext){
		free(*pHead);
		*pHead = NULL;
	}
	else{
		//链表中至少有两个节点
		SListNode* pCur = *pHead;


		while (pCur->_pNext->_pNext){
			pCur = pCur->_pNext;

		}
		free(pCur->_pNext->_pNext);
		pCur->_pNext = NULL;

	}
}


//头插元素
void SListPushFront(SListNode** pHead, SLDataType data)
{
	assert(pHead);
	SListNode* NewNode = SListNewNode(data);
	NewNode->_pNext = (*pHead);
	*pHead = NewNode;
}

//头删元素
void SListPopFront(SListNode** pHead)
{
	SListNode* pDel = NULL;
	assert(pHead);
	//考虑链表为空情况
	if ((*pHead) == NULL)
	{
		printf("链表为空！无法删除！\n");
		return;
	}
	else{
		pDel = *pHead;
		*pHead = pDel->_pNext;
		free(pDel);
	}
}

//查找元素
SListNode* SListFind(SListNode** pHead, SLDataType data){
	assert(pHead);
	//考虑链表为空的情况
	if (*pHead == NULL)
	{
		return NULL;
	}
	SListNode* pFind = *pHead;
	while(pFind){
		if (pFind->_data == data){
			return  pFind;
			pFind = pFind->_pNext;
		}
	}
	return NULL;
}


//任意位置的插入
void SListInsert(SListNode** pHead, SListNode* pos, SLDataType data)
{
	SListNode* _pNew = (SListNode*)SListNewNode(sizeof(data));

	if (NULL == pos){
		return;
	}
	_pNew->_pNext = pos->_pNext;
	pos->_pNext = _pNew;

}

//任意位置的删除
void SListErase(SListNode** pHead, SListNode* pos)
{
	assert(pHead);
	assert(pos);

	if (pos == NULL || *pHead == NULL){
		return;
	}
	if (*pHead == pos){
		*pHead = pos->_pNext;
		free(pos);
	}
	else{
		//找pos前一个结点
		SListNode * posPre = *pHead;
		while (posPre->_pNext != pos){
			posPre = posPre->_pNext;
		}
		posPre->_pNext = pos->_pNext;
		free(pos);
	}
}


//销毁单链表
void SListDestroy(SListNode** pHead){
	SListNode *pDel = *pHead;
	while (*pHead){
		pDel = *pHead;
		*pHead = pDel->_pNext;
		free(pDel);
	}
}

//链表大小
int SListSize(SListNode* pHead){
	SListNode * pCur = pHead;
		int length = 0;
		while (pCur) {
			++length;
			pCur = pCur->_pNext;
		}
		return length;
	}


//判空
int SListEmpty(SListNode* pHead){
	SListNode *pCur = pHead;
	if (pCur->_pNext != NULL){
		return 1;
	}
	return 0;
}

//首节点
SLDataType Front(SListNode* pHead){
	SListNode *pCur = pHead;
	return pCur->_data;
}

//末节点
SLDataType Back(SListNode* pHead){
	SListNode *pCur = pHead;
	while (pCur->_pNext){
		pCur = pCur->_pNext;	
	}
	return pCur->_data;
}

//删除指定节点
//void SListRemove(SListNode* pHead, SLDataType data){
//	SListNode *pCur = pHead;
//	SListNode *pTail = pHead;
//	if (pCur->_data == data){
//
//	}
//}

//删除指定的所有节点
void SListRemoveAll(SListNode* pHead, SLDataType data);

//冒泡排序
void SlistBubbleSort(SListNode* pHead);
