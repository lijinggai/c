//对一组数右转k个数
#include<stdio.h>
void Reverse(int* arr,int laft, int right)
{
	while (laft < right)
	{
		int tmp = arr[laft];
		arr[laft] = arr[right];
		arr[right] = tmp;
		laft++;
		right--;
	}
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int k = 0;
	scanf_s("%d", &k);
	if (k >= 7)
	{
		k %= 7;
	}
	int size = sizeof(arr) / sizeof(arr[0]);
	//右旋0--size-k-1的数
	Reverse(arr,0, size - k - 1);
	//右旋size-k-1--sezi-1
	Reverse(arr,size-k, size - 1);
	//右旋整体
	Reverse(arr,0,size-1);
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}