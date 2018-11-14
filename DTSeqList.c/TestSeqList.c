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
	printf("尾部插入:\n");
	PrintSeqList(&s);
	
	SeqListPopBack(&s);
	printf("尾部删除:\n");
	PrintSeqList(&s);
}

void TestSeqListFront(){
	SeqList s;
	SeqListInit(&s, 10);
	SeqListPushFront(&s, 1);
	SeqListPushFront(&s, 2);
	SeqListPushFront(&s, 3);
	SeqListPushFront(&s, 4);
	printf("头部插入:\n");
	PrintSeqList(&s);
	SeqListPopFront(&s);
	printf("头删插入:\n");
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

	printf("插入:\n");
	SeqListInsert(&s, 2, 9);
	PrintSeqList(&s);

	printf("删除:\n");
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

	SeqListRemoveAll(&s, 3);        //删除所有的data
	//SeqListRemove(&s, 3);         //删除一个data
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
//  return SeqListSize(&s);           //有效元素个数
//  return SeqListCapacity(&s);       //容量
//  return SeqListFront(&s);          //第一个元素
	return SeqListBack(&s);           //最后一个元素
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