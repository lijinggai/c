#pragma warning(disable:4996)
#include<string.h>
#include<stdio.h>
#include<errno.h>
//int main()
//{
//	FILE* pWrite=fopen("test.txt", "w");
//	if (pWrite == NULL)
//	{
//		printf("%s\n", strerror(errno)); 
//		return 0;
//	}
//	fputc('b', pWrite);
//	fputc('i', pWrite);
//	fputc('t', pWrite);
//	fclose(pWrite);
//	pWrite = NULL;
//	return 0;
//}
//int main()
//{
//	FILE* pRead = fopen("test.txt", "r");
//	if (pRead == NULL)
//	{
//		//�ж�pRead�Ƿ񿪱ٳɹ���û�з���ʲô������
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//		//���ļ�
//	printf("%C", fgetc(pRead));
//	printf("%C", fgetc(pRead));
//	printf("%C", fgetc(pRead));
//	fclose(pRead);
//	pRead = NULL;
//	return 0;
//}
//int main()
//{
//	int ch = fgetc(stdin);//�Ӽ����϶�ȡ
//	fputc(ch, stdout);//����Ļ��д
//
//	return 0;
//}
int main()
{
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		return 0;
	}
	//fseek(pf, 2, SEEK_SET);//��ʼλ������ƫ��2���ֽ�
	fgetc(pf);//��Ϊfgetc��ȡ��һ���ֽ�����ƫ��Ϊ1
	long n = ftell(pf);//��ȡ��ǰλ������ڳ�ʼλ�õ�ƫ��
	printf("%d\n", n);
	fclose(pf);
	pf == NULL;
}
