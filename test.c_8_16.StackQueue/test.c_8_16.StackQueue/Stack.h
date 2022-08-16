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

void StackInit(ST* ps);//初始化
void StackPush(ST* ps, STDataType x);//增加
void StackPop(ST* ps);//删除
STDataType StackTop(ST* ps);//栈顶的元素
int StackSize(ST* ps);//多少个元素
bool StackEmpty(ST* ps);//判断栈是否为空
void StackDestroy(ST* ps);//释放