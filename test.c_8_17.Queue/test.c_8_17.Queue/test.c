#include "Queue.h"

void QueueTest1()
{
	Queue q;
	QueueInit(&q);//��ʼ��
	QueuePush(&q, 1);//����
	QueuePush(&q, 2);//����
	QueuePush(&q, 3);//����
	QueuePush(&q, 4);//����
	QueuePop(&q);//ɾ��
	QueukDestroy(&q);//�ͷ�

}
int main()
{
	QueueTest1();
	return 0;
}