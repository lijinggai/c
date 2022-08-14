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
//		//判断pRead是否开辟成功，没有返回什么都不干
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//		//读文件
//	printf("%C", fgetc(pRead));
//	printf("%C", fgetc(pRead));
//	printf("%C", fgetc(pRead));
//	fclose(pRead);
//	pRead = NULL;
//	return 0;
//}
//int main()
//{
//	int ch = fgetc(stdin);//从键盘上读取
//	fputc(ch, stdout);//用屏幕书写
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
	//fseek(pf, 2, SEEK_SET);//初始位置想右偏移2个字节
	fgetc(pf);//因为fgetc获取了一个字节所以偏移为1
	long n = ftell(pf);//获取当前位置相较于初始位置的偏移
	printf("%d\n", n);
	fclose(pf);
	pf == NULL;
}
