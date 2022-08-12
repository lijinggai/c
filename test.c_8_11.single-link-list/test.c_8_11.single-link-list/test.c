#include"SList.h"

void Test()
{
	SLN* plist = NULL;//因为需要一个指针指向第一个结构体
	SListPushBack(&plist, 1);//会改变数值，所以传地址
	SListPushBack(&plist, 2);//会改变数值，所以传地址
	SListPushBack(&plist,3);//会改变数值，所以传地址
	SListPushFront(&plist, 1);//头插
	//SListpPopFront(&plist);//头删
	//SListPopBack(&plist);//尾删
	SLN* pos=SListFind(plist, 1);
	//int i = 1;
	//while (pos)
	//{
	//	printf("第%d个%d的地址是%p\n", i++,pos->data,pos);
	//	pos = SListFind(pos->next, 1);
	//}
	pos = SListFind(plist, 1);
	SListInsert(&plist,pos,10);//在pos位置之前插入一个节点(需和SListFind连用)
	SListInsertAfter(pos, 20);//在pos位置之后插入一个节点
	pos = SListFind(plist, 10);
	//SListErase(&plist, pos);//删除pos位置的结构体
	SListPrint(plist);//不改变数值，传数值就好
	SListDestroy(&plist);
}
int main()
{
	Test();
	return 0;
}
