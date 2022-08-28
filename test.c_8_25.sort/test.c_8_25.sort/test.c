#include "sort.h"


void TestInsertSort()//��������
{
	int a[] = { 5,2,4,6,6,5,1,3 };
	int n = sizeof(a) / sizeof(a[0]);
	InsertSort(a, n);
	printArray(a, n);

}
void TestShellSort()//ϣ������
{
	int a[] = { 5,2,4,6,6,5,1,3,9,5,8,3,2 };
	int n = sizeof(a) / sizeof(a[0]);
	ShellSort(a, n);//ϣ������
	printArray(a, n);
}
void TestSelectSort()//ѡ������
{
	int a[] = { 5,2,4,6,6,5,1,3,9,5,8,3,2 };
	int n = sizeof(a) / sizeof(a[0]);
	SelectSort(a, n);//ѡ������
	printArray(a, n);
}
void TestHeapSort()//������
{
	int a[] = { 1,7,3,8,2,2,6,8,9,8,0 };
	int n = sizeof(a) / sizeof(a[0]);
	HeapSort(a, n);//������
	printArray(a, n);
}
void TestBubbleSort()//ð������
{
	int a[] = { 1,7,3,8,2,2,6,8,9,8,0 };
	int n = sizeof(a) / sizeof(a[0]);
	BubbleSort(a, n);//ð������
	printArray(a, n);
}
void TestQuickSort()//��������
{
	int a[] = { 6,1,3,2,7,5,4,3 };
	int n = sizeof(a) / sizeof(a[0]);
	QuickSort(a,0,n-1);//��������
	printArray(a, n);
}

void Sort()
{
	//TestInsertSort();//��������
	//TestShellSort();//ϣ������
	//TestSelectSort();//ѡ������
	//TestHeapSort();//������
	//TestBubbleSort();//ð������
	TestQuickSort();//��������
}
int main()
{
	Sort();
	return 0;
}