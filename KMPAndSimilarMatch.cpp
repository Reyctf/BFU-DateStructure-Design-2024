#include "KMPAndSimilarMatch.h"
#include <bits/stdc++.h>

int KMPKMPSearch() {
	SqList L;
	InitListKMP(L);
	ReadFileKMP(L, "herb.txt");
	char* keyword = new char[100];
	cin >> keyword;
	int next[MAXSIZE];
	for (int i = 0; i < MAXSIZE; i++)
		next[i] = 0;
	GetNext(keyword, next);
	if (!SearchListKMP(L, keyword, next))
		cout << "无匹配" << endl;
	FreeListKMP(L);
	return 0;
}
int HashTableSimilarMatch() {
	HashTable HT;
	InitHTSim(HT);
	string filename = "herb.txt";
	ReadFileSim(HT, filename);
	cin.get();
	char sname1[100], sname2[100]; 
	cin.getline(sname1, 100);
	cin.getline(sname2, 100);
	//cout << sname1 << "\n" << sname2 << "\n";
	int p1 = SearchHashSim(HT, sname1), p2 = SearchHashSim(HT, sname2);
	if (p1 != -1 && p2 != -1) {
		PrintSim(HT, p1);
		PrintSim(HT, p2);
		computeSimilarity(HT, p1, p2);
	}

	else {
		cout << "匹配失败" << endl;
	}
	return 0;
}