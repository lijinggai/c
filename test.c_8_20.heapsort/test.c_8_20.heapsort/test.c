#include"heap.h"

void Test1()
{
	HP hp;
	int a[] = { 19,27,15,18,28,34,65,49,25,37 };
	int n = sizeof(a) / sizeof(a[0]);

	HeapInit(&hp, a, n);
	HeapPush(&hp, 39);
	Heapprint(&hp);

	HeapPop(&hp);
	Heapprint(&hp);
	HeapDestroy(&hp);
}

int main()
{
	Test1();
	return 0;
}