typedef int QUDataType;

typedef struct QueueNode
{
	struct QueueNode* _next;
	QUDataType _data;
}QueueNode;

typedef struct Queue
{
	QueueNode* Front; // ��ͷ
	QueueNode* Back; // ��β
}Queue;

//��ʼ��
void QueueInit(Queue* pq);

//��ӡ
void QueuePrint(Queue* pq);

//����
void QueueDestory(Queue* pq);

//���
void QueuePush(Queue* pq, QUDataType data);

//����
void QueuePop(Queue* pq);

//��ȡ����
QUDataType QueueFront(Queue* pq);

//��ȡ��β
QUDataType QueueBack(Queue* pq);

//�п�
int QueueEmpty(Queue* pq);

//��ȡ�Ե� ��С
int QueueSize(Queue* pq);

//����
void TestQueue();