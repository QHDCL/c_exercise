#include"SeqList.h"
#include<Windows.h>
#include<stdio.h>


//void TestSeqList(){
//	SeqList s;
//	SeqListInit(&s);
//	SeqListPushBack(&s, 1);
//	SeqListPushBack(&s, 2);
//	SeqListPushBack(&s, 3);
//	PrintSeqList(&s);
//
//SeqListPopBack(&s);
//PrintSeqList(&s);
//SeqListPopBack(&s);
//PrintSeqList(&s);
//SeqListPopBack(&s);
//PrintSeqList(&s);

//SeqListPushFront(&s, 4);
//PrintSeqList(&s);

//SeqListPopFront(&s);
//PrintSeqList(&s);
//}

void TestFind(){
	SeqList s;
	int pos = 0;
	SeqListInit(&s);
	
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	PrintSeqList(&s);

	pos = FindSeqList(&s,4);
	if (pos == -1){
		printf("找不到元素\n");
	}
	else {
		printf("找到了，下标是：%d\n", pos);
		
	}
}

void TestInsert(){
	SeqList s;
	int pos = 0;
	SeqListInit(&s);

	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	PrintSeqList(&s);
	pos = FindSeqList(&s, 3);
	if (pos != -1){
		//再指定位置的前面插入
		Insert(&s,pos, 5);
		PrintSeqList(&s);
	}
}

void TestErase(){
	SeqList s;
	int pos = 0;
	SeqListInit(&s);

	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	PrintSeqList(&s);
	pos = FindSeqList(&s, 3);
	if (pos != -1){
		Erase(&s, pos);
		PrintSeqList(&s);
	}
}

void TestRemove(){
	SeqList s;
	int pos = 0;
	SeqListInit(&s);

	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 7);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	PrintSeqList(&s);
	Remove(&s, 2);
	PrintSeqList(&s);//1 2 4 7 2 3 4
}

void TestAllRemove(){
	SeqList s;
	int pos = 0;
	SeqListInit(&s);

	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 7);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	PrintSeqList(&s);
	if (!Empty(&s))
	printf("大小：%d\n", Size(&s));
	AllRemove(&s,3);
	PrintSeqList(&s);
	printf("大小：%d\n", Size(&s));
}


void TestBubbleSort(){
	SeqList s;
	SeqListInit(&s);
	int i = 0;
	for (i = 0; i < 10; i++){
		SeqListPushFront(&s, i);
	}
	PrintSeqList(&s);
	BubbleSort(&s);
	PrintSeqList(&s);
}

void TestSelectSort(){
	SeqList s;
	SeqListInit(&s);
	int i = 0;
	for (i = 0; i < 10; i++){
		SeqListPushFront(&s, i);
	}
	PrintSeqList(&s);
	SelectSort(&s);
	PrintSeqList(&s);
}


void TestSelectSort_OP(){
	SeqList s;
	SeqListInit(&s);
	int i = 0;
	for (i = 0; i < 10; i++){
		SeqListPushFront(&s, i);
	}
	PrintSeqList(&s);
	SelectSort_OP(&s);
	PrintSeqList(&s);
}


void TestBinarySearch(){
	SeqList s;
	SeqListInit(&s);
	int pos = 0;
	int i = 0;
	for (i = 0; i < 10; i++){
		SeqListPushFront(&s, i);
	}
	PrintSeqList(&s);
 	SelectSort(&s);
	PrintSeqList(&s);
	pos = BinarySearch(&s, 20);
	if (pos != -1){
		printf("找到了,下标是：%d\n", pos);
	}
	else{
		printf("找不到元素\n");
	}
}


void TestBinarySearch_R(){
	SeqList s;
	SeqListInit(&s);
	int pos = 0;
	int i = 0;
	for (i = 0; i < 10; i++){
		SeqListPushFront(&s, i);
	}
	PrintSeqList(&s);
	SelectSort(&s);
	PrintSeqList(&s);
	pos = BinarySearch_R(&s,0,s.size-1,7);
	if (pos != -1){
		printf("下标是：%d\n", pos);
	}
	else{
		printf("找不到元素\n");
	}
}


int main(){
	//TestSeqList();
	//TestFind();
	//TestInsert();
	//TestErase();
	//TestRemove();
	//TestAllRemove();
	//TestBubbleSort();
	//TestSelectSort();
	TestSelectSort_OP();
	//TestBinarySearch();
	//TestBinarySearch_R();
	system("pause");
	return 0;
}


