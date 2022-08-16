#pragma once 

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

void StackInit(ST* ps);//��ʼ��
void StackPush(ST* ps, STDataType x);//����
void StackPop(ST* ps);//ɾ��
STDataType StackTop(ST* ps);//ջ����Ԫ��
int StackSize(ST* ps);//���ٸ�Ԫ��
bool StackEmpty(ST* ps);//�ж�ջ�Ƿ�Ϊ��
void StackDestroy(ST* ps);//�ͷ�