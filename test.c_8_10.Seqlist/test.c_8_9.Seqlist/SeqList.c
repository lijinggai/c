#include "SeqList.h"

void DestroySeqList(SL* ps)//�ͷ��ڴ�
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
void InitSeqList(SL * ps)//��ʼ��
{
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}
void CheckCapacity(SL* ps)//�������
{
	if (ps->capacity == ps->size)
	{
		//ʹ����Ŀ�������ж�    1.��û�����ڴ�  2.�����ڴ棬��������
		int NewCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		//���û�п��ٿռ�realloc���Ե�mallocʹ��
		slDataType* tmp = (slDataType*)realloc(ps->a, NewCapacity * sizeof(slDataType));
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);//û�п��ٳɹ�ֱ���˳�����
		}
		ps->a = tmp;
		ps->capacity = NewCapacity;
	}
}
void PushBackSeqList(SL* ps, slDataType x)//����Ԫ��
{
	CheckCapacity(ps);//�������
	//3�������ڴ棬����û��
	ps->a[ps->size] = x;
	ps->size++;		
}
void PopBackSeqList(SL* ps)//
{
	//ps->a[ps->size] = 0;����ʡ�ԣ���Ϊ�ڴ�ʹ�����λ�����ݻᱻ�еĸ���   ps->a[ps->size] = x;
	assert(ps->size > 0);//����ps->size������Ϊ��������Խ�����
	ps->size--;
}
void PushFrontSeqList(SL* ps, slDataType x)//��a[0]�����и�Ԫ�أ�ͷ�壩
{
	CheckCapacity(ps);//�������
	//Ų������
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end+1] = ps->a[end];
		--end;
	}
	ps->a[0] = x;
	ps->size++;
}
void PopFrontSeqList(SL* ps)//ɾ����һ��Ԫ�أ�ͷɾ��
{
	assert(ps->size > 0);//����
	int begin = 1;//�ѵڶ�������ֵ����һ��Ԫ��
	for (begin = 1; begin < ps->size; begin++)
	{
		ps->a[begin - 1] = ps->a[begin];
	}
	ps->size--;
}
int  FindSeqList(SL* ps, slDataType x)//�ҵ���x�����±꣬�Ҳ�������-1
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if(ps->a[i]==x)
			return i;
	}
	return - 1;
}
void InsertSeqList(SL* ps, int pos, slDataType x)//ָ��pos�±����
{
	int i = 0;
	for (i = ps->size; i > pos; i--)
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[pos] = x;
	ps->size++;
}
void EraseSeqList(SL* ps, int pos)//ָ��pos�±�ɾ��
{
	int i = 0;
	for (i = pos; i < ps->size; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

