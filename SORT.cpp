#include "SORT.h"
#include "definition.h"
#include <bits/stdc++.h>
using namespace std;

int InsertionSort() {
	SqList L;
	InitListSort(L);
	string filename = "herb.txt";
	ReadFileSort(L, filename);
	int kcn = 0;
	int rmn = 0;
	InsertSort(L, kcn, rmn);
	FreeListSort(L);
	return 0;
}
int BinaryInsertionSort() {
	SqList L;
	InitListSort(L);
	string filename = "herb.txt";
	ReadFileSort(L, filename);
	int kcn = 0;
	int rmn = 0;
	BInsertSort(L, kcn, rmn);
	FreeListSort(L);
	return 0;
}
int BBubbleSort() {
	SqList L;
	InitListSort(L);
	string filename = "herb.txt";
	ReadFileSort(L, filename);
	int kcn = 0;
	int rmn = 0;
	BubbleSort(L, kcn, rmn);
	FreeListSort(L);
	return 0;
}
int MmergeSort() {
	SqList L;
	InitListSort(L);
	string filename = "herb.txt";
	ReadFileSort(L, filename);
	int kcn = 0;
	int rmn = 0;
	MergeSort(L, kcn, rmn);
	FreeListSort(L);
	return 0;
}
int QquickSort() {
	SqList L;
	InitListSort(L);
	string filename = "herb.txt";
	ReadFileSort(L, filename);
	QuickSort(L);
	FreeListSort(L);
	return 0;
}