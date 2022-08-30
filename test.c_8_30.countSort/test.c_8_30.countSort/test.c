#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void CountSort(int* a,int n)//����
{
	//�ҳ������С
	int min = a[0], max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (min > a[i])
			min = a[i];
		if (max < a[i])
			max = a[i];
	}
	int range = max - min + 1;
	//���ӳ��
	int* count = (int*)malloc(sizeof(int) * range);
	if (count == NULL)
	{
		printf("malooc fail\n");
		exit(-1);
	}
	memset(count, 0, sizeof(int) * range);
	for (int i = 0; i < n; i++)
	{
		count[a[i] - min]++;
	}
	int i = 0;
	for (int j = 0; j < range; j++)
	{
		while (count[j]--)
		{
			a[i++] = j + min;
		}
	}
	free(count);
	count = NULL;
}
void print(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}
int main()
{
	int a[] = { 10,15,15,16,14 };
	int n = sizeof(a) / sizeof(a[0]);
	//ʱ�临�Ӷ�O��N+range�����ռ临�Ӷ�O��range��
	CountSort(a, n);//����,ֻ�ʺ�һ�鼯�е�����
	print(a, n);
	return 0;
}