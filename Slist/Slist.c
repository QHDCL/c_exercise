#include"Slist.h"
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>



//��ʼ��
void SListInit(SListNode** pHead){
	assert(pHead);
	*pHead = NULL;
}

//�����½��
SListNode* SListNewNode(SLDataType data){
	SListNode* _pNew = (SListNode*)malloc(sizeof(data));
	if (_pNew == NULL){
		exit(0);
	}
	else{
		_pNew->_data = data;
		_pNew->_pNext = NULL;
		return _pNew;
	}
}

//���ٽ��
void SListIDestroyNode(SListNode** pHead)
{
	//�ͷŸý�㣬����ͷָ��ָ��NULL����ֹ����Ұָ��
	free(pHead);
	*pHead = NULL;
}

//��ӡ����
void SListPrint(SListNode* pHead){
	SListNode* pCur = pHead;
	for (pCur; pCur != NULL; pCur = pCur->_pNext)
	{
		printf("%d--->", pCur->_data);
	}
	printf("NULL\n");
}


//β��
void SListPushBack(SListNode** pHead, SLDataType data){
	assert(pHead);
	SListNode* NewNode = SListNewNode(data);
	//�������Ϊ�գ���ֱ����ͷָ��ָ��������Ľڵ㼴��
	if (*pHead == NULL)
	{
		*pHead = NewNode;
		return;
	}
	//�����ͷ��ʼ����������ֱ����ǰ�ڵ��ָ����ָ��NULL��Ȼ���õ�ǰ��
	//���ָ����ָ��������Ľڵ㼴��
	SListNode* pTail = *pHead;
	while (pTail->_pNext)
	{
		pTail = pTail->_pNext;
	}
	pTail->_pNext = NewNode;
}

//βɾ
void SListPopBack(SListNode** pHead){
	assert(pHead);
	//��������ֱ�Դ�
	if (NULL == *pHead)
	{
		return;
	}
	else if (NULL == (*pHead)->_pNext){
		free(*pHead);
		*pHead = NULL;
	}
	else{
		//�����������������ڵ�
		SListNode* pCur = *pHead;
		while (pCur->_pNext->_pNext){
			pCur = pCur->_pNext;

		}
		free(pCur->_pNext->_pNext);
		pCur->_pNext = NULL;
	}
}


//ͷ��Ԫ��
void SListPushFront(SListNode** pHead, SLDataType data)
{
	assert(pHead);
	SListNode* NewNode = SListNewNode(data);
	NewNode->_pNext = (*pHead);
	*pHead = NewNode;
}

//ͷɾԪ��
void SListPopFront(SListNode** pHead)
{
	assert(pHead);
	SListNode* pDel = *pHead;
	//��������Ϊ�����
	if ((*pHead) == NULL)
	{
		printf("����Ϊ�գ��޷�ɾ����\n");
		return;
	}
	else{
		*pHead = pDel->_pNext;
		//free(pDel);
	}
}

//����Ԫ��
SListNode* SListFind(SListNode** pHead, SLDataType data){
	assert(pHead);
	//��������Ϊ�յ����
	if (*pHead == NULL)
	{
		return NULL;
	}
	SListNode* pFind = *pHead;
	while(pFind){
		if (pFind->_data == data){
			return  pFind;
		}
			pFind = pFind->_pNext;
	}
	return NULL;
}


//����λ�õĲ���
void SListInsert(SListNode** pHead, SListNode* pos, SLDataType data)
{
	SListNode* _pNew = (SListNode*)SListNewNode(data);

	if (NULL == pos){
		return;
	}
	_pNew->_pNext = pos->_pNext;
	pos->_pNext = _pNew;
}

//����λ�õ�ɾ��
void SListErase(SListNode** pHead, SListNode* pos)
{
	assert(pHead);
	assert(pos);
	if (pos == NULL || *pHead == NULL){
		return;
	}
	if (*pHead == pos){
		*pHead = pos->_pNext;
	}
	else{
		//��posǰһ�����
		SListNode * posPre = *pHead;
		while (posPre->_pNext != pos){
			posPre = posPre->_pNext;
		}
		posPre->_pNext = pos->_pNext;   //1		2		3		4		5
		//free(pos);					//	  pospre   pos
	}
}


//���ٵ�����
void SListDestroy(SListNode** pHead){
	SListNode *pDel = *pHead;
	while (*pHead){
		pDel = *pHead;
		*pHead = pDel->_pNext;
		//free(pDel);
	}
}

//������С
int SListSize(SListNode* pHead){
	SListNode * pCur = pHead;
		int length = 0;
		while (pCur) {
			++length;
			pCur = pCur->_pNext;
		}
		return length;
	}


//�п�
int SListEmpty(SListNode* pHead){
	SListNode *pCur = pHead;
	if (pCur->_pNext != NULL){
		return 1;
	}
	return 0;
}

//�׽ڵ�
SLDataType Front(SListNode* pHead){
	SListNode *pCur = pHead;
	return pCur->_data;
}

//ĩ�ڵ�
SLDataType Back(SListNode* pHead){
	SListNode *pCur = pHead;
	while (pCur->_pNext){
		pCur = pCur->_pNext;	
	}
	return pCur->_data;
}

//ɾ����һ��ֵΪdata�Ľ��
void SListRemove(SListNode** pHead, SLDataType data){
	assert(pHead);
	SListErase(pHead, SListFind(pHead, data));
}

//ɾ��ָ�������нڵ�
void SListRemoveAll(SListNode** pHead, SLDataType data){
	assert(pHead);
	SListNode *pCur = *pHead;
	while (pCur){
		SListRemove(pHead, data);
		pCur = pCur->_pNext;
	}	
}



//ð������
void SlistBubbleSort(SListNode** pHead){
	assert(pHead);
	SListNode *pCur = NULL;
	SListNode *pTail = NULL;
	int flag = 0;
	if (*pHead == NULL || (*pHead)->_pNext==NULL){
		return;
	}
	else{
		for (pCur = *pHead; pCur != NULL; pCur = pCur->_pNext){
			flag = 0;
			for (pTail = pCur; pTail != NULL; pTail = pTail->_pNext){
				if ((pCur->_data) > (pTail->_data)){
					int a = pCur->_data;
					pCur->_data = pTail->_data;
					pTail->_data = a;
					flag = 1;
				}
			}
			if (flag == 0){
				return;
			}
		}
	}
}