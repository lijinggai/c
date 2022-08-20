//�����顶������
void Swap(int* p1, int* p2)//����
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void ADJustDown(int* a,int n,int parent)//����
{
	int child = parent * 2 +1;//�ӽڵ�
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] < a[child])//ѡ���ӽڵ�С��һ��,����û���Һ�ֽ
		{
			++child;
		}
		if (a[child] < a[parent])//�жϸ��׽ڵ���ӽڵ��С
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
void ADJustDownRise(int* a, int n, int parent)//����
{
	int child = parent * 2 + 1;//�ӽڵ�
	while (child < n)
	{
		if (child+1<n && a[child + 1] > a[child])//ѡ���ӽڵ���һ��,����û���Һ�ֽ
		{
			++child;
		}
		if (a[child]> a[parent])//�жϸ��׽ڵ���ӽڵ��С
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
void HeapSort(int* a,int n)//������ʱ�临�Ӷ�Ϊn*logn
{
	int i = 0;
	for (i = (n - 1 - 1) / 2; i >= 0; i--)//����ʱ�临�Ӷ�O(N)
		//n-1-1�������һ������Ȼ��-1/2�����ҵ���һ����Ҷ�ӽڵ�
	{
		ADJustDownRise(a, n, i);//����
	}
	int end = n - 1;
	while (end > 0)//ʱ�临�Ӷ�Ϊn*logn
	{
		Swap(&a[0], &a[end]);
		//ʱ�临�Ӷ�Ϊlogn
		ADJustDownRise(a, end, 0);//ѡ���δ�
		end--;
	}
}
int main()
{
	//int a[] = { 27,15,19,18,28,34,65,49,25,37 };
	//ADJustDown(a, n, 0);//����

	int a[] = { 19,27,15,18,28,34,65,49,25,37 };
	int n = sizeof(a) / sizeof(a[0]);
	//�����������򽨴��
	HeapSort(a,n);//������

	return 0;
}