#include"stack.h"
#include<Windows.h>
#include<stdio.h>



void test(){
	Stack sk;
	StackInin(&sk);
	//printf("栈的大小:%d\n", StackSize(&sk));

	StackPush(&sk,2);
	StackPush(&sk, 5);
	StackPush(&sk, 6);
	StackPush(&sk, 5);
	StackPush(&sk, 7);
	//printf("栈的大小:%d\n", StackSize(&sk));

	Stackprint(&sk);

    StackPop(&sk);
	Stackprint(&sk);

	printf("栈顶元素:%d\n", StackTop(&sk));
	printf("栈的大小:%d\n", StackSize(&sk));

	printf("是否空栈<-1.空栈;1非空>:%d\n", StackEmpty(&sk));
}

int main(){
	test();
	system("pause");
	return 0;
}