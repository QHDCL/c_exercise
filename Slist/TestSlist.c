#include "Slist.h"
#include<Windows.h>
#include<stdio.h>

void TestSListBack(){
	SListNode* p;
	SListInit(&p);
	SListPushBack(&p, 1);
	SListPushBack(&p, 2);
	SListPushBack(&p, 3);
	SListPushBack(&p, 4);
	SListPushBack(&p, 5);
	SListPrint(p);


	SListPopBack(&p);
	SListPrint(p);
	
	
	printf("�����С:%d\n", SListSize(p));
	printf("�׽��:%d\n", Front(p));
	printf("ĩ�ڵ�:%d\n", Back(p));
	printf("�п�<1.����,0��>:%d\n", SListEmpty(p));
	printf("���ҽ��:%d\n", SListFind(&p, 10));

}
void TestSListFront(){
	SListNode* p;
	SListInit(&p);
	SListPushFront(&p, 1);
	SListPushFront(&p, 2);
	SListPushFront(&p, 3);
	SListPushFront(&p, 4);

	/*SListPopFront(&p);
	SListPrint(p);*/

}


void TestSList(){
	SListNode* p;
	SListInit(&p);
	SListPushBack(&p, 1);
	SListPushBack(&p, 2);
	SListPushBack(&p, 3);
	SListPushBack(&p, 4);
	SListPushBack(&p, 5);
	SListPrint(p);

	SListInsert(&p, SListFind(&p,3),7);
	SListPrint(p);

	SListErase(&p, SListFind(&p, 4));
	SListPrint(p);
}



int main(){

	TestSListBack();
	
	//TestSListFront();

	//TestSList();

	system("pause");
	return 0;
}