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

void Swap(int* p1, int* p2);//交换
void ADJustDownRise(int* a, int n, int parent);//调整

void HeapInit(HP* php,datatype* a,int n);
void HeapDestroy(HP* php);
void HeapPush(HP* php, datatype x);
//重要
void HeapPop(HP* php);//删头
datatype HeapTop(HP* php);//头
bool HeapEmpty(HP* php);//为空
int Heapsize(HP* php);//个数
void Heapprint(HP* php);
