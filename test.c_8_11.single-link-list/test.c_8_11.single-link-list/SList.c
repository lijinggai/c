#include"SList.h"
SLN* BuyListNode(datatype x)//����ڵ�
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
void SListPushBack(SLN** pphead, datatype x)//��ı���ֵ�����Դ���ַ
{
	assert(pphead);
	SLN* newnode = BuyListNode(x);//����ڵ�
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
void SListPushFront(SLN** pphead, datatype x)//ͷ��
{
	SLN* newnode = BuyListNode(x);//����ڵ�
	newnode->next =*pphead;
	*pphead = newnode;
}
void SListPopBack(SLN** pphead)//βɾ
{
	assert( *pphead != NULL);//���ΪNULL�����ý����κβ���
	//1.ֻ��һ��Ԫ��
	SLN* src =NULL;
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	//2.��2�������ϵ�Ԫ��
	//else
	//{
	//	while (tail->next->next)//ָ�������������Ǹ���
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
void SListPopFront(SLN** pphead)//ͷɾ
{
	assert(*pphead != NULL);
		SLN* next = (*pphead)->next;
		free(*pphead);
		*pphead = NULL;
		*pphead = next;
}
SLN* SListFind(SLN* phead, datatype x)//����ĳ����������ָ�����λ�õ�ָ��
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
		return NULL;//�Ҳ��������ؿ�ָ��
}
void SListInsert(SLN** pphead,SLN* pos,datatype x)//��posλ��֮ǰ��һ���ڵ�
{
	assert(pphead);
	assert(pos);
	SLN* newnode = BuyListNode(x);//ͷ��
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
void SListInsertAfter(SLN* pos, datatype x)//��posλ��֮�����һ���ڵ�
{
	assert(pos);
	SLN* newnode = BuyListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}
void SListErase(SLN** pphead, SLN* pos)//ɾ��posλ�õĽṹ��
{
	assert(pphead);
	assert(pos);
	if (pos == *pphead)//ɾ����һ�����⴦��
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
void SListDestroy(SLN** pphead)//�ͷ�
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
