#include"stack.h"
#include<Windows.h>
#include<stdio.h>



void test(){
	Stack sk;
	StackInin(&sk);
	//printf("ջ�Ĵ�С:%d\n", StackSize(&sk));

	StackPush(&sk,2);
	StackPush(&sk, 5);
	StackPush(&sk, 6);
	StackPush(&sk, 5);
	StackPush(&sk, 7);
	//printf("ջ�Ĵ�С:%d\n", StackSize(&sk));

	Stackprint(&sk);

    StackPop(&sk);
	Stackprint(&sk);

	printf("ջ��Ԫ��:%d\n", StackTop(&sk));
	printf("ջ�Ĵ�С:%d\n", StackSize(&sk));

	printf("�Ƿ��ջ<-1.��ջ;1�ǿ�>:%d\n", StackEmpty(&sk));
}

int main(){
	test();
	system("pause");
	return 0;
}