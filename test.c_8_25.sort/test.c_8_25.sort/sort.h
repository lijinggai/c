#pragma once
#include<stdio.h>
#include<stdlib.h>



void InsertSort(int* a, int n);//����ʽ����
void printArray(int* a, int n);

void ShellSort(int* a, int n);//ϣ������

void SelectSort(int* a, int n);//ѡ������

void ADJustDown(int* a, int n, int root);//����
void HeapSort(int* a, int n);//������

void BubbleSort(int* a, int n);//ð������

void QuickSort(int* a, int begin,int end);//��������