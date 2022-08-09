#include"SeqList.h"

void TestSeqlist()
{
	SL sl;
	InitSeqList(&sl);//初始化结构体
	PushBackSeqList(&sl, 1);//增加元素
	PushBackSeqList(&sl, 2);
	PushBackSeqList(&sl, 3);
	PushBackSeqList(&sl, 4);
	PushBackSeqList(&sl, 5);
	PushBackSeqList(&sl, 6);
	//PopBackSeqList(&sl);//减少元素
	PushFrontSeqList(&sl, 10);//在a[0]插入有个元素（头插）
	PushFrontSeqList(&sl, 10);//在a[0]插入有个元素（头插）
	PopFrontSeqList(&sl);//删除第一个元素（头删）
	int k = FindSeqList(&sl ,4);//找到了x返回下标，找不到返回-1
	printf("%d\n", k);
	InsertSeqList(&sl, 3 , 20);//指定pos下标插入
	EraseSeqList(&sl,5);//指定pos下标删除
	print(&sl);//打印函数
	DestroySeqList(&sl);//释放动态开辟的内存
}
int main()
{
	TestSeqlist();
	return 0;
}