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

void SListPrint(SLN* phead);//���ı���ֵ������ֵ�ͺ�
void SListPushBack(SLN** pphead, datatype x);//��ı���ֵ�����Դ���ַ
void SListPushFront(SLN** pphead, datatype x);//ͷ��
void SListPopBack(SLN** pphdead);//βɾ
void SListPopFront(SLN** pphead);//ͷɾ
SLN* SListFind(SLN* phead, datatype x);//����ĳ����������ָ�����λ�õ�ָ��
void SListInsert(SLN** pphead, SLN* pos,datatype x);//��posλ�ò���һ���ڵ�
void SListDestroy(SLN** pphead);//�ͷ�
void SListInsertAfter(SLN* pos,datatype x);//��posλ��֮�����һ���ڵ�
void SListErase(SLN**pphead,SLN* pos);//ɾ��posλ�õĽṹ��



