#include"queue.h"
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>

//��ʼ��
void QueueInit(Queue* pq){
	assert(pq);
	pq->Back = pq->Front = NULL;
}

//����Ԫ��
QueueNode* BuyQueueNode(Queue* pq, QUDataType data){
	assert(pq);
	QueueNode* NewNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (NewNode == NULL){
		return NULL;
	}
	NewNode->_data = data;
	NewNode->_next = NULL;
	return NewNode;
}

//���
void QueuePush(Queue* pq, QUDataType data){
	assert(pq);
	QueueNode* pCur = BuyQueueNode(pq, data);
	
	if(pq->Front == NULL){
		pq->Front=pq->Back = pCur;
	}
	else{
		pq->Back->_next= pCur;
		pq->Back = pq->Back->_next;
	}
}
 
//����
void QueuePop(Queue* pq){
	assert(pq);
	QueueNode* pDel = NULL;

	printf("�п�<1.�ǿ� -1.��>:%d\n", QueueEmpty(pq));

	if (pq->Front== pq->Back) { //����ֻ��һ��Ԫ��

		pq->Front = pq->Back = NULL;
	}                        
	// �ж��Ԫ��
	else{
		pDel = pq->Front;
		pq->Front = pDel->_next;
		free(pDel);
		pDel = NULL;
	}
}	

//��ȡ����
QUDataType QueueFront(Queue* pq){
	assert(pq); 
	return pq->Front->_data;
}

//��ȡ��β
QUDataType QueueBack(Queue* pq){
	assert(pq);
	return pq->Back->_data;
}


//��ȡ�ԵĴ�С
int QueueSize(Queue* pq){
    assert(pq);
	int count = 0;
	QueueNode* pCur = pq->Front;
	while (pCur){
		count++;
		pCur = pCur->_next;
	}
	free(pCur);
	pCur = NULL;
	return count;
}



//��ӡ
void QueuePrint(Queue* pq){
	assert(pq);
	QueueNode* pCur = pq->Front;
	while (pCur){
		printf("%d ", pCur->_data);
		pCur = pCur->_next;
	}
	free(pCur);
	pCur = NULL;
	printf("\n");
}

//����
void QueueDestory(Queue* pq){
	assert(pq);
	QueueNode* pCur = pq->Front;
	QueueNode*p = NULL;
	while (pCur){
		p = pCur;
		pCur = p->_next;
		free(p);
	}
}

//�п�
int QueueEmpty(Queue* pq){
	assert(pq);
	if (pq->Front == NULL){
		return -1;
	}
	return 1;
}






////////////////////////////////////////////////////////
//����
void TestQueue(){
	Queue Qe;
	QueueInit(&Qe);
	QueuePush(&Qe, 1);
	QueuePush(&Qe, 3);
	QueuePush(&Qe, 4);
	QueuePush(&Qe, 6);
	QueuePush(&Qe, 7);
	QueuePrint(&Qe);

	printf("��ͷԪ��:%d\n", QueueFront(&Qe));
	printf("��βԪ��:%d\n", QueueBack(&Qe));
	printf("�ԵĴ�С:%d\n", QueueSize(&Qe));


	QueuePop(&Qe);
	QueuePrint(&Qe);

	QueuePop(&Qe);
	QueuePrint(&Qe);

	printf("��ͷԪ��:%d\n", QueueFront(&Qe));
	printf("��βԪ��:%d\n", QueueBack(&Qe));
	printf("�ԵĴ�С:%d\n", QueueSize(&Qe));

	QueuePop(&Qe);
	QueuePrint(&Qe);

	QueuePop(&Qe);
	QueuePrint(&Qe);

	

	printf("��ͷԪ��:%d\n", QueueFront(&Qe));
	printf("��βԪ��:%d\n", QueueBack(&Qe));
	printf("�ԵĴ�С:%d\n", QueueSize(&Qe));

	QueuePop(&Qe);
	QueuePop(&Qe);
	//printf("�ԵĴ�С:%d\n", QueueSize(&Qe));
	
}
