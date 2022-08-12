#include"contact.h"
void IntiContact(struct Contact* pc)//��ʼ��
{
	pc->date = (struct PeoInfo*)malloc(DEFAULT_SZ * sizeof(struct PeoInfo));
	if (pc->date == NULL)
	{
		return;
	}
	pc->size = 0;
	pc->capacity = DEFAULT_SZ;
}
void CheckCapacity(Contact* pc)
{
	//1.�ж������Ƿ���
	if (pc->size == pc->capacity)
	{
		PeoInfo* ptr=realloc(pc->date, (DEFAULT_SZ + 2) * sizeof(PeoInfo));
		if (ptr != NULL)
		{
			pc->date = ptr;
			pc->capacity += 2;
			printf("���ӳɹ�\n");
		}
		else
		{
			printf("����ʧ��\n");
		}
	}
}
char* cmp_char(const void* e1,const void* e2)
{
	return *((char*)e1) - *((char*)e2);
}
static int FindByName(struct Contact* pc,char name[MAX_NAME])
//�ҵõ����ص�ַi���Ҳ�������-1
{
	int i = 0;
	for (i = 0; i < pc->size; i++)
	{
		if (0 == strcmp(pc->date[i].name, name));
		{
			return i;
		}
	}
	return -1;
}
void AddContact(struct Contact* pc)//������ϵ����Ϣ
{
	CheckCapacity(pc);//�ж������Ƿ���
	if (pc->size <pc->capacity)
	{
		printf("����������:>");
		scanf("%s", pc->date[pc->size].name);
		printf("����������:>");
		scanf("%d", &(pc->date[pc->size].age));
		printf("�������Ա�:>");
		scanf("%s", pc->date[pc->size].six);
		printf("������绰:>");
		scanf("%s", pc->date[pc->size].tele);
		printf("�������ַ:>");
		scanf("%s", pc->date[pc->size].addr);
		pc->size++;
		printf("��ӳɹ�\n");
	}
}
void ShowContact(const struct Contact* pc)
{
	if (pc->size == 0)
	{
		printf("û�п��Դ�ӡ��ͨѶ¼");
	}
	else
	{
		int i = 0;
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
			for (i = 0;i < pc->size; i++)
			{
				printf("%-20s\t%-4d\t%-5s\t%-12s\t%-30s\n",
					pc->date[i].name,
					pc->date[i].age,
					pc->date[i].six,
					pc->date[i].tele,
					pc->date[i].addr);
			}
	}
}
void DelContact(struct Contact* pc)
{
	char name[MAX_NAME];
	//1.�ҵ�ɾ���˵�����
	printf("����������˵�����:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("���޴���\n");
	}
	//ɾ�������ϵ�˵���Ϣ
	else
	{ 
		int j = 0;
		for (j = pos; j < pc->size - 1; j++)
		{
	 		pc->date[j], pc->date[j + 1];
			pc->size--;
			printf("ɾ���ɹ�\n");
		}
	}
}
void SearchContact(struct Contact* pc)
{
	//1.������
	char name[MAX_NAME];
	printf("��������������˵�����;>");
	scanf("%s", name);
	int pos = FindByName(pc, name);

	if (pos == -1)
	{
		printf("���޴���\n");
	}
	//2.��ӡ��Ϣ
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-30s\n",
			pc->date[pos].name,
			pc->date[pos].age,
			pc->date[pos].six,
			pc->date[pos].tele,
			pc->date[pos].addr);
	}
}
void ModifyContact(struct Contact* pc)
{
	char name[MAX_NAME];
	printf("������Ҫ�޸��˵�����:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("���޴���\n");
	}
	else
	{
		printf("����������:>");
		scanf("%s", pc->date[pos].name);
		printf("����������:>");
		scanf("%d", &(pc->date[pos].age));
		printf("�������Ա�:>");
		scanf("%s", pc->date[pos].six);
		printf("������绰:>");
		scanf("%s", pc->date[pos].tele);
		printf("�������ַ:>");
		scanf("%s", pc->date[pos].addr);
		printf("�޸ĳɹ�\n");
	}
}
void qsortContact(struct Contact* pc)
{
	qsort(pc->date,pc->size, sizeof(char), cmp_char);
}
void DestroyContact(Contact* pc)//free
{
	free(pc->date);
	pc->date = NULL;
}