#include "Stack.h"
void Test()
{
	ST st;
	StackInit(&st);//初始化
	StackPush(&st, 1);//增加
	StackPush(&st, 2);//增加
	StackPush(&st, 3);//增加
	StackPush(&st, 4);//增加
	StackPop(&st);//删除
	StackPop(&st);//删除
	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}
	

	StackDestroy(&st);//释放

}
int main()
{
	Test();
	return 0;
}