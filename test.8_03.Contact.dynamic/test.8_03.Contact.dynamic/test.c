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
	struct  Contact con;//	����1000����С������
	IntiContact(&con);//��ʼ��ͨѶ¼
	do
	{
		menu();
		printf("������:>");
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
			//��Ϊ�Ƕ�̬�ڴ濪�ٵĿգ�ʹ����Ҫ���ظ�ϵͳ���Ա����ڴ�й©
			DestroyContact(&con);//��ֹ�ڴ�й©
			SaveContact(&con);//����ͨѶ¼��Ϣ��Ϣ
			printf("�˳��ɹ�\n");
			break;
		case save:
			SaveContact(&con);
			break;
		default:
			printf("ѡ�����\n");
			break;
		};
	} while (input);
	return 0;
	
}