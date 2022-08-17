#include "Queue.h"

void QueueInit(Queue* pq)//��ʼ��
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}
void QueuePush(Queue* pq, QDataTyoe x)//����
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
void QueuePop(Queue* pq)//ɾ��
{
	assert(pq);
	assert(!QueueEmpty);//��Ϊ��
	QueueNode* next = pq->head->next;
	free(pq->head);
	pq->head = next;
	if (pq->head == NULL)//ȫɾ��Ҫ��tail��ΪNULL
	{
		pq->tail == NULL;
	}
}
bool QueueEmpty(Queue* pq)//�ж϶����Ƿ�Ϊ��
{
	assert(&pq);
	return pq->head == NULL;
}
QDataTyoe QueueFront(Queue* pq)//��β��Ԫ��
{
	assert(pq);
	asert(!QueueEmpty);
	return pq->tail->data;
}
QDataTyoe QueueBcak(Queue* pq)//��ͷ��Ԫ��
{
	assert(pq);
	assert(!QueueEmpty);
	return pq->head->data;
}
int QueueSize(Queue* pq)//���ٸ�Ԫ��

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

void QueukDestroy(Queue* pq)//�ͷ�
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

