#include "list.h"
SLnode* BuyNewNode(datatype x)//新节点
{
	SLnode* newNode = (SLnode*)malloc(sizeof(SLnode));
	if (newNode == NULL)
	{
		return 0;
	}
	newNode->date = x;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}
SLnode* Init()//初始化
{
	SLnode* phead = (SLnode*)malloc(sizeof(SLnode));//哨兵位
	if (phead != NULL)
	{
		phead->next = phead;
		phead->prev = phead;
	}
	return phead;
}
void SLnodePushback(SLnode* phead,datatype x)//尾插
{
	assert(phead);
	//SLnode* newNode = BuyNewNode(x);
	//SLnode* tail = phead->prev;
	//tail->next = newNode;
	//newNode->prev = tail;
	//newNode->next = phead;
	//phead->prev = newNode;
	SLnodeInsert(phead, x);//与SListInsert互用
}
void print(SLnode* phead)//打印
{
	assert(phead);
	SLnode* cur = phead->next;
	while (cur!= phead)
	{
		printf("%d ", cur->date);
		cur = cur->next;
	}
}
void SLnodePopback(SLnode* phead)//尾删
{
	assert(phead);
	assert(phead->prev != phead);//没有可删的内容

	SLnode* tail = phead->prev;
	SLnode* prev = tail->prev;
	free(tail);
	tail = NULL;
	prev->next = phead;
	phead->prev = prev;
}
void SLnodePushFront(SLnode* phead, datatype x)//头插
{
	//SLnode* newNode = BuyNewNode(x);
	//SLnode* next = phead->next;

	//newNode->prev = phead;
	//phead->next = newNode;

	//newNode->next = next;
	//next->prev = newNode;
	SLnodeInsert(phead->next, x);//与SListInsert互用
}
void SLnodePopFront(SLnode* phead)//头删
{
	assert(phead);
	assert(phead->next != phead);//链表为空
	SLnode* next = phead->next;
	SLnode* nextNext = phead->next->next;

	phead->next = nextNext;
	nextNext->prev = phead;
	free(next);
}

SLnode* SLnodeFind(SLnode* phead, datatype x)//找
{
	assert(phead);
	SLnode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->date == x)
		{
			return cur;
		}		
		cur = cur->next;
	}
	return NULL;
}
void SLnodeInsert(SLnode* pos, datatype x)//在pos之前位置插入
{
	assert(pos);
	SLnode* newNode = BuyNewNode(x);
	SLnode* posPrev = pos->prev;
	posPrev->next = newNode;
	newNode->prev = posPrev;
	pos->prev = newNode;
	newNode->next = pos;
}
void SLnodeErase(SLnode* pos)//删除
{
	assert(pos);
	SLnode* next = pos->next;
	SLnode* prev = pos->prev;
	prev->next = next;
	next->prev = prev;
	free(pos);
	pos = NULL;
}
void SLnodeDestroy(SLnode** phead)//释放
{
	assert(phead);
	SLnode* cur =(*phead)->next;
	while (cur != *phead)
	{
		SLnode* next = cur->next;
		free(cur);
		cur = NULL;
	}
	free(*phead);
	*phead = NULL;
}

