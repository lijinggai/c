#define _CRT_SECURE_NO_WARNINGS
#define DEFAULT_SZ 3
#define MAX_NAME 20
#define MAX_SIX 5
#define MAX_TELE 11
#define MAX_ADDR 30


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct PeoInfo//����һ��ͨѶ¼�ṹ��
{
	char name[MAX_NAME];
	int age;
	char six[MAX_SIX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;
typedef struct Contact//ͨѶ¼����
{
	struct PeoInfo *date;
	int size;
	int capacity;
}Contact;
enum Option//ö��ѡ���ô���Ŀɶ��Ը���
{
	tui,
	add,
	del,
	search,
	modify,
	show,
	sort
};



void IntiContact(struct Contact* pc);//��ʼ��ͨѶ¼
void AddContact(struct Contact* pc);//������ϵ��
void ShowContact(const struct Contact* pc);//��ʾͨѶ¼
void DelContact(struct Contact* pc);//ɾ����ϵ����Ϣ
void SearchContact(struct Contact* pc);//����ָ���˵���Ϣ
void ModifyContact(struct Contact* pc);//�޸���Ϣ
void qsortContact(struct Contact* pc);//��˳��
void DestroyContact(Contact* pc);