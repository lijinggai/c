#include "list.h"
void Test()
{
	SLnode* plist = Init();//��ʼ��
	SLnodePushback(plist, 1);//β��
	SLnodePushback(plist, 2);//β��
	SLnodePushback(plist, 3);//β��
	SLnodePushback(plist,4);//β��
	SLnodePopback(plist);//βɾ
	SLnodePushFront(plist,5);//ͷ��
	SLnodePopFront(plist);//ͷɾ
	print(plist);//��ӡ
	SLnodeDestroy(&plist);//�ͷ�
}
int main()
{
	Test();
	return 0;
}