#include"sort.h"

void InsertSort(int* a, int n)//����ʽ����
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
void ShellSort(int* a, int n)//ϣ������
{
	//Ԥ����
	//gap>1����������
	//gap==1���ǲ�������
	int gap = n;
	while (gap > 1)
	{
		gap = (gap / 3 + 1);//gap��������Ϊ��,��˼�һ
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
void SelectSort(int* a, int n)//ѡ������
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
void ADJustDown(int* a, int n, int root)//����
{
	int parent = root;
	int child = parent * 2 + 1;//����
	while (child<n)
	{
		if (child + 1 < n && a[child] < a[child + 1])//����û���Һ���
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else//����������ѭ����������ѭ��
		{
			break;
		}
	}
}
void HeapSort(int* a, int n)//������
{
	//���򣬽����
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
void BubbleSort(int* a, int n)//ð������
{
	//����
	for(int end=n;end>0;end--)
	{
		int exchange = 0;
		//ÿ��
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
//void QuickSort(int* a, int begin,int end)//��������
//{
//	if (begin >= end)
//	{
//		return;
//	}
//	int left = begin, right = end;
//	int keyi = left;
//	while (right>left)
//	{
//		//һ��
//		while (right>left && a[right] >= a[keyi])//right>leftԤ��˳���ǶԵģ����ܻ�Խ��
//		{
//			//��С
//			--right;
//		}
//		while (right>left && a[left] <= a[keyi])
//		{
//			//�Ҵ�
//			left++;
//		}
//		Swap(&a[left], &a[right]);//�������������˽�������û��
//	}
//	int meeti = left;
//	Swap(&a[keyi], &a[meeti]);//��key��������ȷ��λ��
//	//������[begin,meet-1]
//	//������[meet+1,end-1]
//
//	QuickSort(a, begin, meeti-1);
//	QuickSort(a, meeti+1, end);
//}
int GetMidIndex(int* a, int left, int right)//����ȡ��
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
int PartSort1(int* a, int left, int right)//����ָ�뷨
{
	int midIndex = GetMidIndex(a, left, right);
	Swap(&a[left], &a[midIndex]);
	int keyi = left;
	while (right > left)
	{
		//һ��
		while (right > left && a[right] >= a[keyi])//right>leftԤ��˳���ǶԵģ����ܻ�Խ��
		{
			//��С
			--right;
		}
		while (right > left && a[left] <= a[keyi])
		{
			//�Ҵ�
			left++;
		}
		Swap(&a[left], &a[right]);//�������������˽�������û��
	}
	Swap(&a[keyi], &a[left]);//��key��������ȷ��λ��
	return left;
}
int PartSort2(int* a, int left, int right)//�ڿӷ�
{
	int midIndex = GetMidIndex(a, left, right);
	Swap(&a[left], &a[midIndex]);
	int key = a[left];
	while (left < right)
	{
		//��С
		while (left < right && a[right] >= key)
		{
			right--;
		}
		//����������ߵĿӣ��ұ��γ��¿�
		a[left] = a[right];
		//�Ҵ�
		while (left < right && a[left] <= key)
		{
			left++;
		}
		//���������ұߵĿӣ�����γ��¿�
		a[right] = a[left];
	}
	//�����ˣ���key���������Ŀ�
	a[left] = key;
	return left;
}
int PartSort3(int* a, int left, int right)//ǰ��ָ�뷨
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
		//cur++;//����perv��curһǰһ��
		while (a[cur] < a[keyi] && ++prev != cur)
		{
			Swap(&a[cur], &a[prev]);
		}
		cur++;
	}
	Swap(&a[keyi], &a[prev]);
	return prev;
}
void QuickSort(int* a, int begin, int end)//��������
{
	if (begin >= end)
	{
		return;
	}

	//������[begin,meet-1]
	//������[meet+1,end-1]
	int key = PartSort3(a, begin, end);
	QuickSort(a, begin, key - 1);
	QuickSort(a, key + 1, end);
}