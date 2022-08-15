#include "list.h"
SLnode* BuyNewNode(datatype x)//�½ڵ�
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
SLnode* Init()//��ʼ��
{
	SLnode* phead = (SLnode*)malloc(sizeof(SLnode));//�ڱ�λ
	if (phead != NULL)
	{
		phead->next = phead;
		phead->prev = phead;
	}
	return phead;
}
void SLnodePushback(SLnode* phead,datatype x)//β��
{
	assert(phead);
	//SLnode* newNode = BuyNewNode(x);
	//SLnode* tail = phead->prev;
	//tail->next = newNode;
	//newNode->prev = tail;
	//newNode->next = phead;
	//phead->prev = newNode;
	SLnodeInsert(phead, x);//��SListInsert����
}
void print(SLnode* phead)//��ӡ
{
	assert(phead);
	SLnode* cur = phead->next;
	while (cur!= phead)
	{
		printf("%d ", cur->date);
		cur = cur->next;
	}
}
void SLnodePopback(SLnode* phead)//βɾ
{
	assert(phead);
	assert(phead->prev != phead);//û�п�ɾ������

	SLnode* tail = phead->prev;
	SLnode* prev = tail->prev;
	free(tail);
	tail = NULL;
	prev->next = phead;
	phead->prev = prev;
}
void SLnodePushFront(SLnode* phead, datatype x)//ͷ��
{
	//SLnode* newNode = BuyNewNode(x);
	//SLnode* next = phead->next;

	//newNode->prev = phead;
	//phead->next = newNode;

	//newNode->next = next;
	//next->prev = newNode;
	SLnodeInsert(phead->next, x);//��SListInsert����
}
void SLnodePopFront(SLnode* phead)//ͷɾ
{
	assert(phead);
	assert(phead->next != phead);//����Ϊ��
	SLnode* next = phead->next;
	SLnode* nextNext = phead->next->next;

	phead->next = nextNext;
	nextNext->prev = phead;
	free(next);
}

SLnode* SLnodeFind(SLnode* phead, datatype x)//��
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
void SLnodeInsert(SLnode* pos, datatype x)//��pos֮ǰλ�ò���
{
	assert(pos);
	SLnode* newNode = BuyNewNode(x);
	SLnode* posPrev = pos->prev;
	posPrev->next = newNode;
	newNode->prev = posPrev;
	pos->prev = newNode;
	newNode->next = pos;
}
void SLnodeErase(SLnode* pos)//ɾ��
{
	assert(pos);
	SLnode* next = pos->next;
	SLnode* prev = pos->prev;
	prev->next = next;
	next->prev = prev;
	free(pos);
	pos = NULL;
}
void SLnodeDestroy(SLnode** phead)//�ͷ�
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

