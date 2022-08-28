#include<stdio.h>
#include<stdlib.h>
void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)
		return;
	//取中位数递归
	int mid = (left + right) >> 1;
	//递归
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int i = left;
	//把两个有序数组中小的一个拷贝到tmp
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] > a[begin2])
			tmp[i++] = a[begin2++];

		else
			tmp[i++] = a[begin1++];
	}
	//把剩余没走完的数组拷贝到tmp
	while (begin1 <= end1)
		tmp[i++] = a[begin1++];
	while (begin2 <= end2)
		tmp[i++] = a[begin2++];
	//把tmp拷贝给a数组
	int j = left;
	while (j <= right)
	{
		a[j] = tmp[j];
		j++;
	}

}
void MergeSort(int* a, int n)//归并
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	_MergeSort(a, 0, n - 1, tmp);
}
void printArray(int* a, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
int main()
{
	int a[] = { 6,1,3,2,7,5,4,3 };
	int n = sizeof(a) / sizeof(a[0]);
	MergeSort(a, n);//非递归
	printArray(a, n);

	return 0;
}