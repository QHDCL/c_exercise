#pragma once

#define MAXSIZE  100

typedef int SDataType;

//��̬ջ
//typedef struct Stack{
//	SDataType _array[MAXSIZE];
//	int _top;
//}Stack;

//��̬ջ
typedef struct Stack{
	SDataType*  _array;  //�׵�ַ
	int _capacity;		//����
	int _top;      //ջ��
}Stack;

//��ʼ��
void StackInin(Stack* ps);

//��ӡ
void Stackprint(Stack* ps);

//����ջ
void StackDestory(Stack* ps);

////�������
//void Stackcapacity(Stack* ps);

//��ջ
void StackPush(Stack* ps, SDataType x);

//��ջ
void StackPop(Stack* ps);

//��ȡջ��Ԫ��
SDataType StackTop(Stack* ps);

//�п�
int StackEmpty(Stack* ps);

//��ȡջ�Ĵ�С
int StackSize(Stack* ps);

