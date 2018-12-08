#pragma once

#define MAXSIZE  100

typedef int SDataType;

//静态栈
//typedef struct Stack{
//	SDataType _array[MAXSIZE];
//	int _top;
//}Stack;

//动态栈
typedef struct Stack{
	SDataType*  _array;  //首地址
	int _capacity;		//容量
	int _top;      //栈顶
}Stack;

//初始化
void StackInin(Stack* ps);

//打印
void Stackprint(Stack* ps);

//销毁栈
void StackDestory(Stack* ps);

////检测容量
//void Stackcapacity(Stack* ps);

//入栈
void StackPush(Stack* ps, SDataType x);

//出栈
void StackPop(Stack* ps);

//获取栈顶元素
SDataType StackTop(Stack* ps);

//判空
int StackEmpty(Stack* ps);

//获取栈的大小
int StackSize(Stack* ps);

