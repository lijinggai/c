#include "SeqList.h"

void DestroySeqList(SL* ps)//释放内存
{
	free(ps->a);
	ps->a = NULL;
}
void print(SL* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; ++i)
	{
		printf("%d ", ps->a[i]);
	}
}
void InitSeqList(SL * ps)//初始化
{
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}
void CheckCapacity(SL* ps)//检查容量
{
	if (ps->capacity == ps->size)
	{
		//使用三目操作符判断    1.还没开辟内存  2.开辟内存，容量满了
		int NewCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		//如果没有开辟空间realloc可以当malloc使用
		slDataType* tmp = (slDataType*)realloc(ps->a, NewCapacity * sizeof(slDataType));
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);//没有开辟成功直接退出程序
		}
		ps->a = tmp;
		ps->capacity = NewCapacity;
	}
}
void PushBackSeqList(SL* ps, slDataType x)//增加元素
{
	CheckCapacity(ps);//检查容量
	//3开辟了内存，容量没满
	ps->a[ps->size] = x;
	ps->size++;		
}
void PopBackSeqList(SL* ps)//
{
	//ps->a[ps->size] = 0;可以省略，因为在此使用这个位置内容会被行的覆盖   ps->a[ps->size] = x;
	assert(ps->size > 0);//断言ps->size不可以为负数否则越界访问
	ps->size--;
}
void PushFrontSeqList(SL* ps, slDataType x)//在a[0]插入有个元素（头插）
{
	CheckCapacity(ps);//检查容量
	//挪动数组
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end+1] = ps->a[end];
		--end;
	}
	ps->a[0] = x;
	ps->size++;
}
void PopFrontSeqList(SL* ps)//删除第一个元素（头删）
{
	assert(ps->size > 0);//断言
	int begin = 1;//把第二个数赋值给第一个元素
	for (begin = 1; begin < ps->size; begin++)
	{
		ps->a[begin - 1] = ps->a[begin];
	}
	ps->size--;
}
int  FindSeqList(SL* ps, slDataType x)//找到了x返回下标，找不到返回-1
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if(ps->a[i]==x)
			return i;
	}
	return - 1;
}
void InsertSeqList(SL* ps, int pos, slDataType x)//指定pos下标插入
{
	int i = 0;
	for (i = ps->size; i > pos; i--)
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[pos] = x;
	ps->size++;
}
void EraseSeqList(SL* ps, int pos)//指定pos下标删除
{
	int i = 0;
	for (i = pos; i < ps->size; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

