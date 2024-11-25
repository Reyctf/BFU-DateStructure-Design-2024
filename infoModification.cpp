#include "infoModification.h"
#include "ReStack.cpp"
#include <bits/stdc++.h>
int IncreaseOfInformation() {
	SqList L;
	InitList(L);
	string originFilename = "herb.txt";
	string newFilename = "new_herb.txt";
	ReadFile(L, originFilename);
	SaveFileSave(L, "StackHber.txt");
	if (InsertHerb(L)) {
		SaveFile(L, newFilename);
		ReadFile(L, newFilename);
		Print(L);
	}
	else {
		cout << "增加失败" << endl;
	}
	FreeList(L);
	return 0;
}
bool check(SqList& L, char* name) {
	for (int i = 0; i < L.length; i++) {
		if (strcmp(name, L.elem[i].name) == 0) {
			return false;
		}
	}
	return true;
}

int DeletionOfInformation() {
	SqList L;
	InitList(L);
	string originFilename = "herb.txt";
	string newFilename = "new_herb.txt";
	char name[100];
	cin >> name;
	ReadFile(L, originFilename);
	Herb* herb = DeleteHerb(L, name);
	SaveFileSave(L, "StackHber.txt");
	if (herb) {
		SaveFile(L, newFilename);
		ReadFile(L, newFilename);
		if (check(L, name))
			Print(herb);
		else
			cout << "删除失败" << endl;
	}
	else {
		cout << "删除失败" << endl;
	}
	FreeList(L);
	return 0;
}

int ModificationOfInformation() {
	SqList L;
	InitList(L);
	string originFilename = "herb.txt";
	string newFilename = "new_herb.txt";
	char name[100];
	cin >> name;
	int n;
	string lines[6];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> lines[i];
	}
	ReadFile(L, originFilename);
	SaveFileSave(L, "StackHber.txt");
	if (ModifyHerb(L, name, lines, n)) {
		SaveFile(L, newFilename);
		ReadFile(L, newFilename);
		Herb* herb = getHerb(L, name);
		if (herb)
			Print(herb);
		else
			cout << "修改失败" << endl;
	}
	else {
		cout << "修改失败" << endl;
	}
	FreeList(L);
	return 0;
}