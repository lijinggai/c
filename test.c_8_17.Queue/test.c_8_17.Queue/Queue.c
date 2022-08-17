#include "Queue.h"

void QueueInit(Queue* pq)//初始化
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}
void QueuePush(Queue* pq, QDataTyoe x)//增加
{
	assert(pq);
	QueueNode* newNode =(QueueNode*)malloc(sizeof(QueueNode));
	if (newNode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;
	if (pq->head == NULL)
	{
		pq->head = pq->tail = newNode;
	}
	else
	{
		pq->tail->next = newNode;
		pq->tail = newNode;
	}
}
void QueuePop(Queue* pq)//删除
{
	assert(pq);
	assert(!QueueEmpty);//不为空
	QueueNode* next = pq->head->next;
	free(pq->head);
	pq->head = next;
	if (pq->head == NULL)//全删除要把tail置为NULL
	{
		pq->tail == NULL;
	}
}
bool QueueEmpty(Queue* pq)//判断队列是否为空
{
	assert(&pq);
	return pq->head == NULL;
}
QDataTyoe QueueFront(Queue* pq)//队尾的元素
{
	assert(pq);
	asert(!QueueEmpty);
	return pq->tail->data;
}
QDataTyoe QueueBcak(Queue* pq)//队头的元素
{
	assert(pq);
	assert(!QueueEmpty);
	return pq->head->data;
}
int QueueSize(Queue* pq)//多少个元素

{
	assert(pq);
	QueueNode* cur = pq->head;
	int size = 0;
	while (cur != NULL)
	{
		cur = cur->next;
		size++;
	}
	return size;
}

void QueukDestroy(Queue* pq)//释放
{
	QueueNode* cur = pq->head;
	while (cur != NULL)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
}

