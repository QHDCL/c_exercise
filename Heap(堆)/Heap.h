//��:
//�����ڵ����Ķѽ������ѻ����ѣ����ڵ���С�Ķѽ�����С�ѻ�С���ѡ�
//����ĳ���ڵ��ֵ���ǲ����ڻ�С���丸�ڵ��ֵ��
//������һ����ȫ��������


//С��
#pragma once
typedef int HDataType;
typedef struct Heap{
	HDataType *_array;
	int _capacity;
	int _size;
}Heap;

//��ʼ��
void HeapInit(Heap* hp, HDataType *array, int size);

//��ӡ
void HeapPrint(Heap* hp);

//����
void HeapDestory(Heap* hp);

//����
void HeapInsert(Heap* hp, HDataType data);

//ɾ��
void HeapPop(Heap* hp);

//��ȡ���ڵ�
HDataType HeapTop(Heap* hp);

//��ȡ��С
int Heapsize(Heap* hp);

//�п�
int HeapEmpty(Heap* hp);

//���� 
void TestHeap();