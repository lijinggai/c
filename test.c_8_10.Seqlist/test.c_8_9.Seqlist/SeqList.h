#pragma once  

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int slDataType;//方便更改数组的类型
//定义结构体取别名为SL
typedef struct Seqlist
{
	slDataType* a;//指针用来开辟动态内存
	int size;//当前元素个数
	int capacity;//容量
}SL;

void print(SL* ps);//打印数组
void InitSeqList(SL* ps);//初始化结构体
void PushBackSeqList(SL* ps,slDataType x);//增加元素
void CheckCapacity(SL* ps);//检查容量
void PopBackSeqList(SL* ps);//减少元素
void PushFrontSeqList(SL* ps,slDataType x);//在a[0]插入有个元素（头插）
void PopFrontSeqList(SL* ps);//删除第一个元素（头删）
int  FindSeqList(SL* ps, slDataType x);//找到了x返回下标，找不到返回-1
void InsertSeqList(SL* ps,int pos, slDataType x);//指定pos下标插入
void EraseSeqList(SL* ps,int pos);//指定pos下标删除
void DestroySeqList(SL* ps);//释放内存，防止内存泄漏