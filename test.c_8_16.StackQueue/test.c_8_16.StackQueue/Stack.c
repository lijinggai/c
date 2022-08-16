#include "Stack.h"

void StackInit(ST* ps)//��ʼ��
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}
void StackPush(ST* ps, STDataType x)//����
{
	if (ps->top == ps->capacity)//����
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
void StackPop(ST* ps)//ɾ��
{
	assert(ps);
	assert(ps->top > 0);
	ps->top--;
}
STDataType StackTop(ST* ps)//ջ����Ԫ��
{
	assert(ps);
	assert(ps->top > 0);
	return ps->a[ps->top-1];
}
int StackSize(ST* ps)//���ٸ�Ԫ��
{
	assert(ps);
	return ps->top;
}
bool StackEmpty(ST* ps)//�ж�ջ�Ƿ�Ϊ��
{
	assert(ps);
	//if (ps->top == 0)
	//	return true;
	//else
	//	return false;
	return ps->top == 0;//����0Ϊ�治����0Ϊ��
}
void StackDestroy(ST* ps)//�ͷ�
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top = ps->capacity = 0;
}