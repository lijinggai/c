#include"SList.h"
SLN* BuyListNode(datatype x)//创造节点
{
	SLN* newnode = (SLN*)malloc(sizeof(SLN));
	if (newnode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}
void SListPrint(SLN* phead)//
{
	SLN* src = phead;
	while (src != NULL)
	{
		printf("%d ", src->data);
		src = src->next;
	}
}
void SListPushBack(SLN** pphead, datatype x)//会改变数值，所以传地址
{
	assert(pphead);
	SLN* newnode = BuyListNode(x);//创造节点
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		SLN* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}
void SListPushFront(SLN** pphead, datatype x)//头插
{
	SLN* newnode = BuyListNode(x);//创造节点
	newnode->next =*pphead;
	*pphead = newnode;
}
void SListPopBack(SLN** pphead)//尾删
{
	assert( *pphead != NULL);//如果为NULL，不用进行任何操作
	//1.只有一个元素
	SLN* src =NULL;
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	//2.有2个及以上的元素
	//else
	//{
	//	while (tail->next->next)//指向下两个数的那个数
	//    {
	//		tail = tail->next;
	//	}
	//	free(tail->next->next);
	//	tail->next = NULL;
	//}
	else
	{
		SLN* tail = *pphead;
		while (tail->next)
		{
			src = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		src->next = NULL;
    }
}
void SListPopFront(SLN** pphead)//头删
{
	assert(*pphead != NULL);
		SLN* next = (*pphead)->next;
		free(*pphead);
		*pphead = NULL;
		*pphead = next;
}
SLN* SListFind(SLN* phead, datatype x)//查找某个数，返回指向这个位置的指针
{
	SLN* src = phead;
	while (src)
	{
		if (src->data != x)
		{
			src = src->next;
		}
		else
		{
			return src;
		}
	}
		return NULL;//找不到，返回空指针
}
void SListInsert(SLN** pphead,SLN* pos,datatype x)//在pos位置之前插一个节点
{
	assert(pphead);
	assert(pos);
	SLN* newnode = BuyListNode(x);//头插
	if (*pphead == pos)
	{
		newnode->next = *pphead;
		*pphead = newnode;
	}
	else
	{
		SLN* posprev = *pphead;
		while (posprev->next != pos)
		{
			posprev = posprev->next;
		}
		posprev->next = newnode;
		newnode->next = pos;
	}
}
void SListInsertAfter(SLN* pos, datatype x)//在pos位置之后插入一个节点
{
	assert(pos);
	SLN* newnode = BuyListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}
void SListErase(SLN** pphead, SLN* pos)//删除pos位置的结构体
{
	assert(pphead);
	assert(pos);
	if (pos == *pphead)//删除第一个特殊处理
	{
		*pphead=(*pphead)->next;
		free( pos);
	}
	else
	{
		SLN* cur = *pphead;
		while (cur->next != pos)
		{
			cur = cur->next;
		}
		cur->next = pos->next;
		free(pos);
	}
}
void SListDestroy(SLN** pphead)//释放
{
	SLN* cur = *pphead;
	while (cur)
	{
		SLN* next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;
}
