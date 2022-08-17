#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int QDataTyoe;

typedef struct QueueNode
{
	struct QueueNode* next;
	QDataTyoe data;
}QueueNode;
typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
}Queue;
void QueueInit(Queue* pq);//��ʼ��
void QueuePush(Queue* pq, QDataTyoe x);//����
void QueuePop(Queue* pq);//ɾ��
QDataTyoe QueueFront(Queue* pq);//��β��Ԫ��
QDataTyoe QueueBcak(Queue* pq);//��ͷ��Ԫ��
int QueueSize(Queue* pq);//���ٸ�Ԫ��
bool QueueEmpty(Queue* pq);//�ж϶����Ƿ�Ϊ��
void QueukDestroy(Queue* pq);//�ͷ�
