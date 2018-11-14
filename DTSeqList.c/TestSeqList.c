#include  "SeqList.h"
#include<Windows.h>
#include<stdio.h>


void TestSeqListBack(){
	SeqList s;
	SeqListInit(&s,10);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	printf("β������:\n");
	PrintSeqList(&s);
	
	SeqListPopBack(&s);
	printf("β��ɾ��:\n");
	PrintSeqList(&s);
}

void TestSeqListFront(){
	SeqList s;
	SeqListInit(&s, 10);
	SeqListPushFront(&s, 1);
	SeqListPushFront(&s, 2);
	SeqListPushFront(&s, 3);
	SeqListPushFront(&s, 4);
	printf("ͷ������:\n");
	PrintSeqList(&s);
	SeqListPopFront(&s);
	printf("ͷɾ����:\n");
	PrintSeqList(&s);
}

void TestSeqListInsert(){
	SeqList s;
	SeqListInit(&s, 10);
	SeqListPushFront(&s, 1);
	SeqListPushFront(&s, 2);
	SeqListPushFront(&s, 3);
	SeqListPushFront(&s, 4);
	PrintSeqList(&s);

	printf("����:\n");
	SeqListInsert(&s, 2, 9);
	PrintSeqList(&s);

	printf("ɾ��:\n");
	SeqListErase(&s, 3);
	PrintSeqList(&s);
}

void TestSeqListFind(){
	SeqList s;
	SeqListInit(&s, 10);
	SeqListPushFront(&s, 3);
	SeqListPushFront(&s, 1);
	SeqListPushFront(&s, 2);
	SeqListPushFront(&s, 3);
	SeqListPushFront(&s, 3);
	SeqListPushFront(&s, 3);
	SeqListPushFront(&s, 4);
	PrintSeqList(&s);

	SeqListRemoveAll(&s, 3);        //ɾ�����е�data
	//SeqListRemove(&s, 3);         //ɾ��һ��data
	PrintSeqList(&s);
}


void TestBubbleSort(){
	SeqList s;
	SeqListInit(&s, 3);
	SeqListPushFront(&s, 1);
	SeqListPushFront(&s, 7);
	SeqListPushFront(&s, 8);
	SeqListPushFront(&s, 21);
	SeqListPushFront(&s, 9);
	SeqListPushFront(&s, 3);
	SeqListPushFront(&s, 4);
	PrintSeqList(&s);

	BubbleSort(&s);
	PrintSeqList(&s);
}


int Front(){
	SeqList s;
	SeqListInit(&s, 10);
	SeqListPushFront(&s, 1);
	SeqListPushFront(&s, 7);
	SeqListPushFront(&s, 8);
	SeqListPushFront(&s, 21);
//  return SeqListSize(&s);           //��ЧԪ�ظ���
//  return SeqListCapacity(&s);       //����
//  return SeqListFront(&s);          //��һ��Ԫ��
	return SeqListBack(&s);           //���һ��Ԫ��
}



int main(){
/*
	int i = Front();
	printf("%d\n", i);*/

	TestBubbleSort();
	//TestSeqListFind();
	//TestSeqListInsert();
	//TestSeqListBack();
	//TestSeqListFront();
	system("pause");
	return 0;
}