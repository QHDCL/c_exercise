#pragma once


typedef int SLDataType;
typedef struct SListNode
{
	struct SListNode* _pNext;   //next��
	SLDataType _data;           //������
}SListNode;


////////����ͷ�ڵ�ĵ����� /////////////////
//
//�����ʼ��
void SListInit(SListNode** pHead);

//�����½��
SListNode* SListNewNode(SLDataType data);

//���ٽ��
void SListIDestroyNode(SListNode** pHead);

//��ӡ����
void SListPrint(SListNode* pHead);

//β��
void SListPushBack(SListNode** pHead, SLDataType data);

//βɾ
void SListPopBack(SListNode** pHead);

//ͷ��
void SListPushFront(SListNode** pHead, SLDataType data);

//ͷɾ
void SListPopFront(SListNode** pHead);

//����
SListNode* SListFind(SListNode** pHead, SLDataType data);

//����λ�ò���
void SListInsert(SListNode** pHead, SListNode* pos, SLDataType data);

//����λ��ɾ��
void SListErase(SListNode** pHead, SListNode* pos);

//���ٵ�����
void SListDestroy(SListNode** pHead);

//�����С
int SListSize(SListNode* pHead);

//�п�
int SListEmpty(SListNode* pHead);

//�׽ڵ�
SLDataType Front(SListNode* pHead);

//ĩ�ڵ�
SLDataType Back(SListNode* pHead);

//ɾ����һ��ֵΪdata�Ľ��
void SListRemove(SListNode** pHead, SLDataType data);

//ɾ��ֵΪdata�����нڵ�
void SListRemoveAll(SListNode** pHead, SLDataType data);

//ð������
void SlistBubbleSort(SListNode** pHead);

