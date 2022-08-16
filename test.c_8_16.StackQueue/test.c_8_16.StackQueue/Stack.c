#include "Stack.h"

void StackInit(ST* ps)//初始化
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}
void StackPush(ST* ps, STDataType x)//增加
{
	if (ps->top == ps->capacity)//增容
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* tmp = realloc(ps->a, sizeof(ST) * newcapacity);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
	ps->a[ps->top] = x;
	ps->top++;
}
void StackPop(ST* ps)//删除
{
	assert(ps);
	assert(ps->top > 0);
	ps->top--;
}
STDataType StackTop(ST* ps)//栈顶的元素
{
	assert(ps);
	assert(ps->top > 0);
	return ps->a[ps->top-1];
}
int StackSize(ST* ps)//多少个元素
{
	assert(ps);
	return ps->top;
}
bool StackEmpty(ST* ps)//判断栈是否为空
{
	assert(ps);
	//if (ps->top == 0)
	//	return true;
	//else
	//	return false;
	return ps->top == 0;//等于0为真不等于0为假
}
void StackDestroy(ST* ps)//释放
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top = ps->capacity = 0;
}