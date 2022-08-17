#include "Queue.h"

void QueueTest1()
{
	Queue q;
	QueueInit(&q);//初始化
	QueuePush(&q, 1);//增加
	QueuePush(&q, 2);//增加
	QueuePush(&q, 3);//增加
	QueuePush(&q, 4);//增加
	QueuePop(&q);//删除
	QueukDestroy(&q);//释放

}
int main()
{
	QueueTest1();
	return 0;
}