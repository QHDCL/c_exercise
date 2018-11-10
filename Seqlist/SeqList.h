#pragma once//����ͷ�ļ����ظ����룬������Ԥ����ָ������ü�����ͬ
#define MAX 100
typedef int DataType;

// ��̬̬˳���Ľṹ 
typedef struct SeqList
{
	DataType data[MAX];
	int size;            // ��ЧԪ�صĸ��� 
}SeqList, *PSeqList;

//��ʼ��˳��� 
void SeqListInit(PSeqList ps);

//��ӡ˳���
void PrintSeqList(PSeqList ps);

//��˳���β������Ԫ��data 
void SeqListPushBack(PSeqList ps, DataType data);

//��˳���β��ɾ��Ԫ��
void SeqListPopBack(PSeqList ps);

//��˳���ͷ������Ԫ��
void SeqListPushFront(PSeqList ps, DataType data);

//��˳���ͷ��ɾ��Ԫ��
void SeqListPopFront(PSeqList ps);

//��˳����в���ָ��Ԫ��
int FindSeqList(PSeqList ps, DataType data);

//��ָ��λ��ǰ�����Ԫ��
void Insert(PSeqList ps, int pos, DataType data);

//ɾ��ָ��λ�õ�Ԫ��
void Erase(PSeqList ps, int pos);

//ɾ��ָ��Ԫ�أ�ֻɾ��һ����
void Remove(PSeqList ps, DataType data);

//ɾ��ָ��Ԫ�أ�ɾ�����еģ�
void AllRemove(PSeqList ps, DataType data);

//˳���Ĵ�С
int Size(PSeqList ps);

//Ϊ�շ���1,�ǿ�Ϊ0
int Empty(PSeqList ps);

//ð������
void BubbleSort(PSeqList ps);

//ѡ������
void SelectSort(PSeqList ps);

//�Ż�ѡ������
void SelectSort_OP(PSeqList ps);

//���ֲ���
int BinarySearch(PSeqList ps, DataType data);

//���ֲ��ҵݹ�
int BinarySearch_R(PSeqList ps,int left,int right, DataType data);