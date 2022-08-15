#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>
typedef int datatype;
typedef struct ListNode
{
	datatype date;
	struct ListNode* next;
	struct ListNode* prev;
}SLnode;


SLnode* Init();//��ʼ��
void SLnodePushback(SLnode* phead, datatype x);//β��
void SLnodePopback(SLnode* phead);//βɾ
void SLnodePushFront(SLnode* phead, datatype x);//ͷ��
void SLnodePopFront(SLnode* phead);//ͷɾ
SLnode* SLnodeFind(SLnode* phead, datatype x);//��
void SLnodeInsert(SLnode* pos, datatype x);//��posλ�ò���
void SLnodeErase(SLnode* pos);//ɾ��
void print(SLnode* phead);//��ӡ
void SLnodeDestroy(SLnode** phead);//�ͷ�

