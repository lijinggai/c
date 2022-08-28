#include"sort.h"

void InsertSort(int* a, int n)//插入式排序
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
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
void ShellSort(int* a, int n)//希尔排序
{
	//预排序
	//gap>1就是与排序
	//gap==1就是插入排序
	int gap = n;
	while (gap > 1)
	{
		gap = (gap / 3 + 1);//gap除三可能为零,因此加一
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] < tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break; 
				}
			}
			a[end + gap] = tmp;
		}
		printf("gap==%d ", gap);
		printArray(a, n);

	}
}
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void SelectSort(int* a, int n)//选择排序
{
	int left = 0, right = n - 1;
	while(left<right)
	{
		int minIndex = left, maxIndex = left;
		for (int i = left; i < right; i++)
		{
			if (a[minIndex] > a[i])
				minIndex = i;
			if (a[maxIndex] < a[i])
				maxIndex = i;
		}
		Swap(&a[minIndex], &a[left]);
		if (maxIndex == left)
		{
			maxIndex = minIndex;
		}
		Swap(&a[maxIndex], &a[right]);
		left++;
		right--;
	}
}
void ADJustDown(int* a, int n, int root)//调整
{
	int parent = root;
	int child = parent * 2 + 1;//左孩子
	while (child<n)
	{
		if (child + 1 < n && a[child] < a[child + 1])//可能没有右孩子
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else//不交换跳出循环，以免死循环
		{
			break;
		}
	}
}
void HeapSort(int* a, int n)//堆排序
{
	//升序，建大堆
	for (int end = (n - 1 - 1) / 2; end >= 0; end--)
	{
		ADJustDown(a, n, end);
	}
	int end = n - 1;
	while (end>0)
	{
		Swap(&a[0], &a[end]);
		ADJustDown(a, end, 0);
		end--;
	}
}
void BubbleSort(int* a, int n)//冒泡排序
{
	//趟数
	for(int end=n;end>0;end--)
	{
		int exchange = 0;
		//每趟
		for (int i = 1; i < end; i++)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				exchange = 1;
			}
		}
		if (exchange == 0)
		{
			break;
		}
	}
}
//void QuickSort(int* a, int begin,int end)//快速排序
//{
//	if (begin >= end)
//	{
//		return;
//	}
//	int left = begin, right = end;
//	int keyi = left;
//	while (right>left)
//	{
//		//一趟
//		while (right>left && a[right] >= a[keyi])//right>left预防顺序是对的，可能会越界
//		{
//			//找小
//			--right;
//		}
//		while (right>left && a[left] <= a[keyi])
//		{
//			//找大
//			left++;
//		}
//		Swap(&a[left], &a[right]);//交换或者相遇了交换还是没变
//	}
//	int meeti = left;
//	Swap(&a[keyi], &a[meeti]);//把key交换到正确的位置
//	//左子树[begin,meet-1]
//	//右子树[meet+1,end-1]
//
//	QuickSort(a, begin, meeti-1);
//	QuickSort(a, meeti+1, end);
//}
int GetMidIndex(int* a, int left, int right)//三数取中
{
	int mid = (left + right) >> 1;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if(a[mid]>a[right])
		{
			if (a[left] > a[right])
			{
				return left;
			}
			else
			{
				return right;
			}
		}
	}
	else
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[mid] < a[right])
		{
			if (a[right] > a[left])
			{
				return left;
			}
			else
			{
				return right;
			}
		}
	}
}
int PartSort1(int* a, int left, int right)//左右指针法
{
	int midIndex = GetMidIndex(a, left, right);
	Swap(&a[left], &a[midIndex]);
	int keyi = left;
	while (right > left)
	{
		//一趟
		while (right > left && a[right] >= a[keyi])//right>left预防顺序是对的，可能会越界
		{
			//找小
			--right;
		}
		while (right > left && a[left] <= a[keyi])
		{
			//找大
			left++;
		}
		Swap(&a[left], &a[right]);//交换或者相遇了交换还是没变
	}
	Swap(&a[keyi], &a[left]);//把key交换到正确的位置
	return left;
}
int PartSort2(int* a, int left, int right)//挖坑法
{
	int midIndex = GetMidIndex(a, left, right);
	Swap(&a[left], &a[midIndex]);
	int key = a[left];
	while (left < right)
	{
		//找小
		while (left < right && a[right] >= key)
		{
			right--;
		}
		//把数放在左边的坑，右边形成新坑
		a[left] = a[right];
		//找大
		while (left < right && a[left] <= key)
		{
			left++;
		}
		//把数放在右边的坑，左边形成新坑
		a[right] = a[left];
	}
	//相遇了，把key放在相遇的坑
	a[left] = key;
	return left;
}
int PartSort3(int* a, int left, int right)//前后指针法
{
	int keyi = left;
	int prev = left, cur = prev + 1;
	while (cur <= right)
	{
		//while(cur <= right && a[cur] >= a[keyi])
		//{
		//	cur++;
		//}
		//if (cur > right)
		//	break;
		//Swap(&a[++prev], &a[cur]);
		//cur++;//保持perv和cur一前一后
		while (a[cur] < a[keyi] && ++prev != cur)
		{
			Swap(&a[cur], &a[prev]);
		}
		cur++;
	}
	Swap(&a[keyi], &a[prev]);
	return prev;
}
void QuickSort(int* a, int begin, int end)//快速排序
{
	if (begin >= end)
	{
		return;
	}

	//左子树[begin,meet-1]
	//右子树[meet+1,end-1]
	int key = PartSort3(a, begin, end);
	QuickSort(a, begin, key - 1);
	QuickSort(a, key + 1, end);
}