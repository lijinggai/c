#include "sort.h"


void TestInsertSort()//≤Â»Î≈≈–Ú
{
	int a[] = { 5,2,4,6,6,5,1,3 };
	int n = sizeof(a) / sizeof(a[0]);
	InsertSort(a, n);
	printArray(a, n);

}
void TestShellSort()//œ£∂˚≈≈–Ú
{
	int a[] = { 5,2,4,6,6,5,1,3,9,5,8,3,2 };
	int n = sizeof(a) / sizeof(a[0]);
	ShellSort(a, n);//œ£∂˚≈≈–Ú
	printArray(a, n);
}
void TestSelectSort()//—°‘Ò≈≈–Ú
{
	int a[] = { 5,2,4,6,6,5,1,3,9,5,8,3,2 };
	int n = sizeof(a) / sizeof(a[0]);
	SelectSort(a, n);//—°‘Ò≈≈–Ú
	printArray(a, n);
}
void TestHeapSort()//∂—≈≈–Ú
{
	int a[] = { 1,7,3,8,2,2,6,8,9,8,0 };
	int n = sizeof(a) / sizeof(a[0]);
	HeapSort(a, n);//∂—≈≈–Ú
	printArray(a, n);
}
void TestBubbleSort()//√∞≈›≈≈–Ú
{
	int a[] = { 1,7,3,8,2,2,6,8,9,8,0 };
	int n = sizeof(a) / sizeof(a[0]);
	BubbleSort(a, n);//√∞≈›≈≈–Ú
	printArray(a, n);
}
void TestQuickSort()//øÏÀŸ≈≈–Ú
{
	int a[] = { 6,1,3,2,7,5,4,3 };
	int n = sizeof(a) / sizeof(a[0]);
	QuickSort(a,0,n-1);//øÏÀŸ≈≈–Ú
	printArray(a, n);
}

void Sort()
{
	//TestInsertSort();//≤Â»Î≈≈–Ú
	//TestShellSort();//œ£∂˚≈≈–Ú
	//TestSelectSort();//—°‘Ò≈≈–Ú
	//TestHeapSort();//∂—≈≈–Ú
	//TestBubbleSort();//√∞≈›≈≈–Ú
	TestQuickSort();//øÏÀŸ≈≈–Ú
}
int main()
{
	Sort();
	return 0;
}