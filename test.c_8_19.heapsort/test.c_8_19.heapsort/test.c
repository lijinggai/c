//看板书《堆排序》
void Swap(int* p1, int* p2)//交换
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void ADJustDown(int* a,int n,int parent)//调整
{
	int child = parent * 2 +1;//子节点
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] < a[child])//选择子节点小的一个,可能没有右孩纸
		{
			++child;
		}
		if (a[child] < a[parent])//判断父亲节点和子节点大小
		{
			Swap(&a[child], &a[parent]);//交换
			parent = child;
			child = parent * 2 + 1;
		}
		else//子节点比父亲节点小或者等于跳出循环
		{
			break;
		}
	}
}
void ADJustDownRise(int* a, int n, int parent)//调整
{
	int child = parent * 2 + 1;//子节点
	while (child < n)
	{
		if (child+1<n && a[child + 1] > a[child])//选择子节点大的一个,可能没有右孩纸
		{
			++child;
		}
		if (a[child]> a[parent])//判断父亲节点和子节点大小
		{
			Swap(&a[child], &a[parent]);//交换
			parent = child;
			child = parent * 2 + 1;
		}
		else//子节点比父亲节点小或者等于跳出循环
		{
			break;
		}
	}
}
void HeapSort(int* a,int n)//堆排序时间复杂度为n*logn
{
	int i = 0;
	for (i = (n - 1 - 1) / 2; i >= 0; i--)//建堆时间复杂度O(N)
		//n-1-1是找最后一个数，然后-1/2就能找到第一个非叶子节点
	{
		ADJustDownRise(a, n, i);//调整
	}
	int end = n - 1;
	while (end > 0)//时间复杂度为n*logn
	{
		Swap(&a[0], &a[end]);
		//时间复杂度为logn
		ADJustDownRise(a, end, 0);//选出次大
		end--;
	}
}
int main()
{
	//int a[] = { 27,15,19,18,28,34,65,49,25,37 };
	//ADJustDown(a, n, 0);//调整

	int a[] = { 19,27,15,18,28,34,65,49,25,37 };
	int n = sizeof(a) / sizeof(a[0]);
	//堆排序排升序建大堆
	HeapSort(a,n);//堆排序

	return 0;
}