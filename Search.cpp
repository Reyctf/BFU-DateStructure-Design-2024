#include "Search.h"
#include "ReStack.cpp"
#include <bits/stdc++.h>
int SequentialTableSearch() {
    SqList L;
    InitListseq(L);
    string originFilename = "herb.txt";
    ReadFileseq(L, originFilename);
    cin.get();
    char sname[100];
    cin.getline(sname, 100);
    int pos = SeqSearchseq(L, sname);
    if (pos != -1) {
        Printseq(L, pos);
        double ASL = GetASLseq(L);
        cout << "ASL为：" << fixed << setprecision(2) << ASL << endl;
    }
    else {
        cout << "查找失败" << endl;
    }
    FreeListseq(L);
    return 0;
}
int SequentialTableBinarySearch() {
    SqList L;
    InitListBinseq(L);
    string originFilename = "herb.txt";
    ReadFileBinseq(L, originFilename);
    cin.get();
    char sname[100];
    cin.getline(sname, 100);
    SortHerbBinseq(L);
    int pos = BinarySearchBinseq(L, sname);
    if (pos != -1) {
        PrintBinseq(L, pos);
        double ASL = GetASLBinseq(L);
        cout << "ASL为：" << fixed << setprecision(2) << ASL << endl;
    }
    else {
        cout << "查找失败" << endl;
    }
    FreeListBinseq(L);
    return 0;
}
int BinarySearchTreeSearch() {
    BSTree T = NULL;
    InitBSTreeBintree(T);
    int count = 0;
    string originFilename = "herb.txt";
    count = ReadFileBintree(T, originFilename);
    cin.get();
    char sname[100];
    cin.getline(sname, 100);
    BSTNode* t = SearchBSTBintree(T, sname);
    if (t != NULL) {
        PrintBintree(t);
        double ASL = GetASLBintree(T, count);
        cout << "ASL为：" << fixed << setprecision(2) << ASL;
    }
    else
        cout << "查找失败";
    return 0;
}
int TtrieSearch() {
    SqList L;
    InitListTrie(L);
    string originFilename = "herb.txt";
    ReadFileTrie(L, originFilename);
    TNode* root = BuildTreeTrie(L);
    cin.get();
    char* sname = new char[100];
    cin.getline(sname, 100);
    Herb* herb = TrieSearchTrie(root, sname);
    if (herb != NULL) {
        PrintTrie(herb);
        double ASL = GetASLTrie(L);
        cout << "ASL为：" << fixed << setprecision(2) << ASL << endl;
    }
    else
        puts("查找失败");
    FreeListTrie(L);
    return 0;
}
int OpenAddressingHashSearch() {
    HashTable HT;
    InitHTOpenadd(HT);
    string filename = "herb.txt";
    int sumCmp = 0; //  ڲ   Ĺ     ͳ ƱȽϴ        ڼ   ASL
    ReadFileOpenadd(HT, sumCmp, filename);
    cin.get();
    char sname[100]; //     Ҫ   ҵ   ҩ  Ӣ      
    cin.getline(sname, 100);
    int pos = SearchHashOpenadd(HT, sname);
    if (pos != -1) {
        PrintOpenadd(HT, pos);
        double ASL = GetASLOpenadd(HT, sumCmp);
        cout << "ASL为：" << fixed << setprecision(2) << ASL << endl;
    }
    else {
        cout << "查找失败" << endl;
    }
    return 0;
}
int ChainAddressingHashSearch() {
    LinkList H[m];
    InitListChainadd(H);
    string filename = "herb.txt";
    int count = 0;	//   ¼  ҩ     ݵ     
    int sumCmp = 0; //  ڲ   Ĺ     ͳ ƱȽϴ        ڼ   ASL
    count = ReadFileChainadd(H, sumCmp, filename);
    cin.get();
    char sname[100]; //     Ҫ   ҵ   ҩ  Ӣ      
    cin.getline(sname, 100);
    int pos = SearchHLChainadd(H, sname);
    if (pos != -1) {
        LinkList p = H[pos]->next; //    ҳɹ     pָ      ͷ   
        PrintChainadd(p, sname);
        double ASL = GetASLChainadd(sumCmp, count);
        cout << "ASL为：" << fixed << setprecision(2) << ASL << endl;
    }
    else {
        cout << "查找失败" << endl;
    }
    return 0;
}