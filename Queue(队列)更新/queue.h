typedef int QUDataType;

typedef struct QueueNode
{
	struct QueueNode* _next;
	QUDataType _data;
}QueueNode;

typedef struct Queue
{
	QueueNode* Front; // 队头
	QueueNode* Back; // 队尾
}Queue;

//初始化
void QueueInit(Queue* pq);

//打印
void QueuePrint(Queue* pq);

//销毁
void QueueDestory(Queue* pq);

//入队
void QueuePush(Queue* pq, QUDataType data);

//出队
void QueuePop(Queue* pq);

//获取对首
QUDataType QueueFront(Queue* pq);

//获取队尾
QUDataType QueueBack(Queue* pq);

//判空
int QueueEmpty(Queue* pq);

//获取对的 大小
int QueueSize(Queue* pq);

//测试
void TestQueue();