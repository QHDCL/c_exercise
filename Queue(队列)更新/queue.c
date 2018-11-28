#include"queue.h"
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>

//初始化
void QueueInit(Queue* pq){
	assert(pq);
	pq->Back = pq->Front = NULL;
}

//创建元素
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

//入对
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
 
//出对
void QueuePop(Queue* pq){
	assert(pq);
	QueueNode* pDel = NULL;

	printf("判空<1.非空 -1.空>:%d\n", QueueEmpty(pq));

	if (pq->Front== pq->Back) { //队列只有一个元素

		pq->Front = pq->Back = NULL;
	}                        
	// 有多个元素
	else{
		pDel = pq->Front;
		pq->Front = pDel->_next;
		free(pDel);
		pDel = NULL;
	}
}	

//获取对首
QUDataType QueueFront(Queue* pq){
	assert(pq); 
	return pq->Front->_data;
}

//获取队尾
QUDataType QueueBack(Queue* pq){
	assert(pq);
	return pq->Back->_data;
}


//获取对的大小
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



//打印
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

//销毁
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

//判空
int QueueEmpty(Queue* pq){
	assert(pq);
	if (pq->Front == NULL){
		return -1;
	}
	return 1;
}






////////////////////////////////////////////////////////
//测试
void TestQueue(){
	Queue Qe;
	QueueInit(&Qe);
	QueuePush(&Qe, 1);
	QueuePush(&Qe, 3);
	QueuePush(&Qe, 4);
	QueuePush(&Qe, 6);
	QueuePush(&Qe, 7);
	QueuePrint(&Qe);

	printf("对头元素:%d\n", QueueFront(&Qe));
	printf("队尾元素:%d\n", QueueBack(&Qe));
	printf("对的大小:%d\n", QueueSize(&Qe));


	QueuePop(&Qe);
	QueuePrint(&Qe);

	QueuePop(&Qe);
	QueuePrint(&Qe);

	printf("对头元素:%d\n", QueueFront(&Qe));
	printf("队尾元素:%d\n", QueueBack(&Qe));
	printf("对的大小:%d\n", QueueSize(&Qe));

	QueuePop(&Qe);
	QueuePrint(&Qe);

	QueuePop(&Qe);
	QueuePrint(&Qe);

	

	printf("对头元素:%d\n", QueueFront(&Qe));
	printf("队尾元素:%d\n", QueueBack(&Qe));
	printf("对的大小:%d\n", QueueSize(&Qe));

	QueuePop(&Qe);
	QueuePop(&Qe);
	//printf("对的大小:%d\n", QueueSize(&Qe));
	
}
