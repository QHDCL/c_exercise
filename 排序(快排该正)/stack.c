#include"stack.h"
#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//初始化
void StackInin(Stack* ps){
	assert(ps);
	ps->_array = (SDataType*)(malloc(sizeof(Stack)));
	if (ps->_array == NULL){
		return;
	}
	ps->_capacity = 0;
	ps->_top = 0;
}


//入栈
void StackPush(Stack* ps, SDataType x){
	assert(ps);

	ps->_array[ps->_top] = x;
	ps->_top=(ps->_top)+1;
	ps->_capacity++;
}

//出栈
void StackPop(Stack* ps){
	assert(ps);
	ps->_top=(ps->_top)--;
	ps->_capacity--;
}

//获取栈顶元素
SDataType StackTop(Stack* ps){
	assert(ps);
	int top = 0;
	top = ps->_array[ps->_top-1];
	return top;
}

//判空
int StackEmpty(Stack* ps){
	assert(ps);
	if (ps->_capacity == 0){
		return 0;
	}
	else{
		return 1;
	}
}


//销毁栈
void StackDestory(Stack* ps){
	assert(ps);
	ps->_array = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}

//获取栈的大小
int StackSize(Stack* ps){
	assert(ps);
	return ps->_capacity;
}


//打印
void Stackprint(Stack* ps){
	assert(ps);
	for (int i = 0; i < ps->_top; i++){
		printf("%d ", ps->_array[i]);
	}
	printf("\n");
}
