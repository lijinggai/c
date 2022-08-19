#include"contact.h"
void menu()
{
	printf("###########################\n");
	printf("#####1.add    2.del    ####\n");
	printf("#####3.search 4.modify  ###\n");
	printf("#####5.show   6.sort   ####\n");
	printf("#####7.save   0.exit ######\n");
	printf("###########################\n");
}

int main()
{
	int input = 0;
	struct  Contact con;//	创建1000个大小的数组
	IntiContact(&con);//初始化通讯录
	do
	{
		menu();
		printf("请输入:>");
		scanf("%d", &input);
		switch (input)
		{
		case add:
			AddContact(&con);
			break;
		case del:
			DelContact(&con);
			break;
		case search:
			SearchContact(&con);
			break;
		case modify:
			ModifyContact(&con);
			break;
		case show:
			ShowContact(&con);
			break;
		case sort:
			qsortContact(&con);
			break;
		case tui:
			//因为是动态内存开辟的空，使用完要返回给系统，以避免内存泄漏
			DestroyContact(&con);//防止内存泄漏
			SaveContact(&con);//保存通讯录信息信息
			printf("退出成功\n");
			break;
		case save:
			SaveContact(&con);
			break;
		default:
			printf("选择错误\n");
			break;
		};
	} while (input);
	return 0;
	
}