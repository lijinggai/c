#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int datatype;
typedef struct SListNode
{
	datatype data;
	struct SListNode* next;
}SLN;

void SListPrint(SLN* phead);//不改变数值，传数值就好
void SListPushBack(SLN** pphead, datatype x);//会改变数值，所以传地址
void SListPushFront(SLN** pphead, datatype x);//头插
void SListPopBack(SLN** pphdead);//尾删
void SListPopFront(SLN** pphead);//头删
SLN* SListFind(SLN* phead, datatype x);//查找某个数，返回指向这个位置的指针
void SListInsert(SLN** pphead, SLN* pos,datatype x);//在pos位置插入一个节点
void SListDestroy(SLN** pphead);//释放
void SListInsertAfter(SLN* pos,datatype x);//在pos位置之后插入一个节点
void SListErase(SLN**pphead,SLN* pos);//删除pos位置的结构体



