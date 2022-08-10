//输出一个数vol把一个数组中相同的删除
#include<stdio.h>
void print(int arr[],int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main()
{
	int arr[] = { 1,2,3,5,7,1,2,3,4,3,3};
	int vol = 0;
	scanf_s("%d",&vol);
	int dst = 0;
	int src = 0;
	int size = sizeof(arr) / sizeof(arr[0]);
	print(arr, size);
	while (src <size)
	{
		if (arr[src] != vol)
		{
			arr[dst] = arr[src];
			src++;
			dst++;
		}
		else
		{
			src++;
		}
	}
	print(arr,dst);
	return 0;
}