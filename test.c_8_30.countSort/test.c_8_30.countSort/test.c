#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void CountSort(int* a,int n)//计数
{
	//找出最大最小
	int min = a[0], max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (min > a[i])
			min = a[i];
		if (max < a[i])
			max = a[i];
	}
	int range = max - min + 1;
	//相对映射
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
	//时间复杂度O（N+range），空间复杂度O（range）
	CountSort(a, n);//计数,只适合一组集中的数据
	print(a, n);
	return 0;
}