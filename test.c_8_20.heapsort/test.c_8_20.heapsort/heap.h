#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<string.h>
typedef int datatype;
typedef struct Heap
{

	datatype* a;
	int size;
	int capacity;
}HP;

void Swap(int* p1, int* p2);//����
void ADJustDownRise(int* a, int n, int parent);//����

void HeapInit(HP* php,datatype* a,int n);
void HeapDestroy(HP* php);
void HeapPush(HP* php, datatype x);
//��Ҫ
void HeapPop(HP* php);//ɾͷ
datatype HeapTop(HP* php);//ͷ
bool HeapEmpty(HP* php);//Ϊ��
int Heapsize(HP* php);//����
void Heapprint(HP* php);
