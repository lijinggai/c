#include"SeqList.h"

void TestSeqlist()
{
	SL sl;
	InitSeqList(&sl);//��ʼ���ṹ��
	PushBackSeqList(&sl, 1);//����Ԫ��
	PushBackSeqList(&sl, 2);
	PushBackSeqList(&sl, 3);
	PushBackSeqList(&sl, 4);
	PushBackSeqList(&sl, 5);
	PushBackSeqList(&sl, 6);
	//PopBackSeqList(&sl);//����Ԫ��
	PushFrontSeqList(&sl, 10);//��a[0]�����и�Ԫ�أ�ͷ�壩
	PushFrontSeqList(&sl, 10);//��a[0]�����и�Ԫ�أ�ͷ�壩
	PopFrontSeqList(&sl);//ɾ����һ��Ԫ�أ�ͷɾ��
	int k = FindSeqList(&sl ,4);//�ҵ���x�����±꣬�Ҳ�������-1
	printf("%d\n", k);
	InsertSeqList(&sl, 3 , 20);//ָ��pos�±����
	EraseSeqList(&sl,5);//ָ��pos�±�ɾ��
	print(&sl);//��ӡ����
	DestroySeqList(&sl);//�ͷŶ�̬���ٵ��ڴ�
}
int main()
{
	TestSeqlist();
	return 0;
}