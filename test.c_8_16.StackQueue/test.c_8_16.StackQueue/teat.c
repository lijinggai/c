#include "Stack.h"
void Test()
{
	ST st;
	StackInit(&st);//��ʼ��
	StackPush(&st, 1);//����
	StackPush(&st, 2);//����
	StackPush(&st, 3);//����
	StackPush(&st, 4);//����
	StackPop(&st);//ɾ��
	StackPop(&st);//ɾ��
	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}
	

	StackDestroy(&st);//�ͷ�

}
int main()
{
	Test();
	return 0;
}