#include"SList.h"

void Test()
{
	SLN* plist = NULL;//��Ϊ��Ҫһ��ָ��ָ���һ���ṹ��
	SListPushBack(&plist, 1);//��ı���ֵ�����Դ���ַ
	SListPushBack(&plist, 2);//��ı���ֵ�����Դ���ַ
	SListPushBack(&plist,3);//��ı���ֵ�����Դ���ַ
	SListPushFront(&plist, 1);//ͷ��
	//SListpPopFront(&plist);//ͷɾ
	//SListPopBack(&plist);//βɾ
	SLN* pos=SListFind(plist, 1);
	//int i = 1;
	//while (pos)
	//{
	//	printf("��%d��%d�ĵ�ַ��%p\n", i++,pos->data,pos);
	//	pos = SListFind(pos->next, 1);
	//}
	pos = SListFind(plist, 1);
	SListInsert(&plist,pos,10);//��posλ��֮ǰ����һ���ڵ�(���SListFind����)
	SListInsertAfter(pos, 20);//��posλ��֮�����һ���ڵ�
	pos = SListFind(plist, 10);
	//SListErase(&plist, pos);//ɾ��posλ�õĽṹ��
	SListPrint(plist);//���ı���ֵ������ֵ�ͺ�
	SListDestroy(&plist);
}
int main()
{
	Test();
	return 0;
}
