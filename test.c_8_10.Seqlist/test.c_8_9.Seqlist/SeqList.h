#pragma once  

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int slDataType;//����������������
//����ṹ��ȡ����ΪSL
typedef struct Seqlist
{
	slDataType* a;//ָ���������ٶ�̬�ڴ�
	int size;//��ǰԪ�ظ���
	int capacity;//����
}SL;

void print(SL* ps);//��ӡ����
void InitSeqList(SL* ps);//��ʼ���ṹ��
void PushBackSeqList(SL* ps,slDataType x);//����Ԫ��
void CheckCapacity(SL* ps);//�������
void PopBackSeqList(SL* ps);//����Ԫ��
void PushFrontSeqList(SL* ps,slDataType x);//��a[0]�����и�Ԫ�أ�ͷ�壩
void PopFrontSeqList(SL* ps);//ɾ����һ��Ԫ�أ�ͷɾ��
int  FindSeqList(SL* ps, slDataType x);//�ҵ���x�����±꣬�Ҳ�������-1
void InsertSeqList(SL* ps,int pos, slDataType x);//ָ��pos�±����
void EraseSeqList(SL* ps,int pos);//ָ��pos�±�ɾ��
void DestroySeqList(SL* ps);//�ͷ��ڴ棬��ֹ�ڴ�й©