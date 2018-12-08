#include"stack.h"
#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//��ʼ��
void StackInin(Stack* ps){
	assert(ps);
	ps->_array = (SDataType*)(malloc(sizeof(Stack)));
	if (ps->_array == NULL){
		return;
	}
	ps->_capacity = 0;
	ps->_top = 0;
}


//��ջ
void StackPush(Stack* ps, SDataType x){
	assert(ps);

	ps->_array[ps->_top] = x;
	ps->_top=(ps->_top)+1;
	ps->_capacity++;
}

//��ջ
void StackPop(Stack* ps){
	assert(ps);
	ps->_top=(ps->_top)--;
	ps->_capacity--;
}

//��ȡջ��Ԫ��
SDataType StackTop(Stack* ps){
	assert(ps);
	int top = 0;
	top = ps->_array[ps->_top-1];
	return top;
}

//�п�
int StackEmpty(Stack* ps){
	assert(ps);
	if (ps->_capacity == 0){
		return 0;
	}
	else{
		return 1;
	}
}


//����ջ
void StackDestory(Stack* ps){
	assert(ps);
	ps->_array = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}

//��ȡջ�Ĵ�С
int StackSize(Stack* ps){
	assert(ps);
	return ps->_capacity;
}


//��ӡ
void Stackprint(Stack* ps){
	assert(ps);
	for (int i = 0; i < ps->_top; i++){
		printf("%d ", ps->_array[i]);
	}
	printf("\n");
}
