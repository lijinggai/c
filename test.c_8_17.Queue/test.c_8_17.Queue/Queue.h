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
void QueueInit(Queue* pq);//初始化
void QueuePush(Queue* pq, QDataTyoe x);//增加
void QueuePop(Queue* pq);//删除
QDataTyoe QueueFront(Queue* pq);//队尾的元素
QDataTyoe QueueBcak(Queue* pq);//队头的元素
int QueueSize(Queue* pq);//多少个元素
bool QueueEmpty(Queue* pq);//判断队列是否为空
void QueukDestroy(Queue* pq);//释放
