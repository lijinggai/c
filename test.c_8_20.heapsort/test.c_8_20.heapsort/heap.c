#include"heap.h"
void Swap(datatype* p1, datatype* p2)//����
{
	datatype tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void ADJustDownRise(datatype* a, int n, datatype parent)//����
{
	datatype child = parent * 2 + 1;//�ӽڵ�
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])//ѡ���ӽڵ���һ��,����û���Һ�ֽ
		{
			++child;
		}
		if (a[child] > a[parent])//�жϸ��׽ڵ���ӽڵ��С
		{
			Swap(&a[child], &a[parent]);//����
			parent = child;
			child = parent * 2 + 1;
		}
		else//�ӽڵ�ȸ��׽ڵ�С���ߵ�������ѭ��
		{
			break;
		}
	}
}
void HeapInit(HP* php, datatype* a, int n)
{
	assert(php);
	php->a = (datatype*)malloc(sizeof(datatype) * n);
	if (php->a == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	memcpy(php->a, a, sizeof(datatype)*n);//������a���ݿ�����PHP->a
	php->capacity = php->size = n;
	//����
	int i = 0;
	for (i = (php->size - 1 - 1) / 2; i >= 0; --i)
	{
		ADJustDownRise(php->a, php->size, i);
	}
}
void ADjustUp(int* a, int child)//���ϵ���
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
void HeapPush(HP* php, datatype x)//����
{
	if (php->size == php->capacity)//����
	{
		datatype* tmp = (datatype*)realloc(php->a,(php->capacity) * 2 * (sizeof(datatype)));
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		php->a = tmp;
		php->a[php->size] = x;
		++php->size;
		ADjustUp(php->a, php->size - 1);//���ϵ���
	}
}
void HeapPop(HP* php)//ɾͷ
{
	assert(php);
	assert(php->size);
	Swap(&php->a[0], &php->a[php->size - 1]);
	--php->size;
	ADJustDownRise(php->a, php->size, 0);
}
datatype HeapTop(HP* php)//ͷ
{
	assert(php);
	assert(php->size);
	return php->a[0];
}
bool HeapEmpty(HP* php)//Ϊ��
{
	assert(php);
	return php->size == 0;
}
int Heapsize(HP* php)//����
{
	assert(php);
	return php->size;
}
void HeapDestroy(HP* php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->size = php->capacity = 0;

}
void Heapprint(HP* php)
{
	for (int i = 0; i < php->size; i++)
	{
		printf("%d ", php->a[i]);
	}
	printf("\n");
	int num = 0;
	int level = 1;
	int i = 0;
	for (i = 0; i < php->size; i++)
	{
		printf("%d ", php->a[i]);
		num++;
		if (num == level)
		{
			printf("\n");
			level *= 2;
			num = 0;
		}
	}
}
