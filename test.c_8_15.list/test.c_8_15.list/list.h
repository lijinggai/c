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


SLnode* Init();//初始化
void SLnodePushback(SLnode* phead, datatype x);//尾插
void SLnodePopback(SLnode* phead);//尾删
void SLnodePushFront(SLnode* phead, datatype x);//头插
void SLnodePopFront(SLnode* phead);//头删
SLnode* SLnodeFind(SLnode* phead, datatype x);//找
void SLnodeInsert(SLnode* pos, datatype x);//在pos位置插入
void SLnodeErase(SLnode* pos);//删除
void print(SLnode* phead);//打印
void SLnodeDestroy(SLnode** phead);//释放

