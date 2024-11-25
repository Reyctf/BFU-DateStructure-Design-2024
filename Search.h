#pragma once
#ifndef SEARCH_H
#define SEARCH_H
#include "definition.h"
#include <bits/stdc++.h>
#define MAXSIZE 300
#define m 300
void InitListseq(SqList& L) {
    // ʹ�ö�̬�ڴ����new���г�ʼ��
    L.length = 0;
    L.elem = new Herb[MAXSIZE]();
    return;
}

void FreeListseq(SqList& L) {
    // �ͷ��ڴ�
    delete[] L.elem;
    return;
}

void ReadFileseq(SqList& L, string filename) {
    // ���ļ��ж�ȡ��ҩ����Ϣ�����䰴˳�����L.elemָ���������
    L.length = 0;
    ifstream file(filename);
    string reg;
    bool flag = true;
    while (getline(file, reg, '\n')) {
        if (reg == "#") {
            getline(file, reg, '\n');
            strcpy(L.elem[L.length].name, reg.c_str());
        }
        else strcpy(L.elem[L.length].name, reg.c_str());
        getline(file, reg, '\n');
        strcpy(L.elem[L.length].sname, reg.c_str());
        getline(file, reg, '\n');
        strcpy(L.elem[L.length].growth_habits, reg.c_str());
        getline(file, reg, '\n');
        strcpy(L.elem[L.length].reproductive, reg.c_str());
        getline(file, reg, '\n');
        strcpy(L.elem[L.length].field_management, reg.c_str());
        getline(file, reg, '\n');
        strcpy(L.elem[L.length].pest_control, reg.c_str());
        getline(file, reg, '\n');
        strcpy(L.elem[L.length].harvesting, reg.c_str());
        getline(file, reg, '\n');
        strcpy(L.elem[L.length].taste, reg.c_str());

        //�龭�Ĵ���
        getline(file, reg, '\n');
        stringstream s(reg);
        vector < string > res;
        string ss;
        int cnt = 0;
        while (getline(s, ss, ',')) {
            //cout << ss << "\n";
            L.elem[L.length].channel_tropism[cnt++] = ss;
        }
        L.elem[L.length].channel_tropism_num = cnt;

        getline(file, reg, '\n');
        strcpy(L.elem[L.length].effect, reg.c_str());

        getline(file, reg, '\n');
        strcpy(L.elem[L.length].functional_indications, reg.c_str());
        L.length++;
    }
    //cout << reg << "test\n";
    return;
}

int SeqSearchseq(SqList& L, char* sname) {
    // ��˳���L��˳�������ҩ��Ӣ�����Ƶ���sname������Ԫ��
    // ���ҵ����򷵻ظ�Ԫ���ڱ��е��±꣬���򷵻�-1
    string test(sname);
    test = "Ӣ����:" + test;
    for (int i = 0; i < L.length; i++) {
        if (!strcmp(test.c_str(), L.elem[i].sname)) {
            return i;
        }
    }
    return -1;
}

double GetASLseq(SqList& L) {
    // ���ػ���˳����˳����ҵ�ASL
    int n = L.length;
    double P = 1.0 / n;
    double ans = 0;
    for (int i = 0; i < L.length; i++) {
        ans += (P * (n - i));
    }
    return ans;
}

void Printseq(SqList& L, int pos) {
    // �����ҩ����Ϣ
    cout << L.elem[pos].name << "\n";
    cout << L.elem[pos].sname << "\n";
    cout << L.elem[pos].growth_habits << "\n";
    cout << L.elem[pos].reproductive << "\n";
    cout << L.elem[pos].field_management << "\n";
    cout << L.elem[pos].pest_control << "\n";
    cout << L.elem[pos].harvesting << "\n";
    cout << L.elem[pos].taste << "\n";
    for (int i = 0; i < L.elem[pos].channel_tropism_num; i++) {
        cout << L.elem[pos].channel_tropism[i];
        if (i != L.elem[pos].channel_tropism_num - 1)cout << ",";
    }
    cout << "\n";
    cout << L.elem[pos].effect << "\n";
    cout << L.elem[pos].functional_indications << "\n";
}
void InitListBinseq(SqList& L) {
    // ʹ�ö�̬�ڴ����new���г�ʼ��
    L.length = 0;
    L.elem = new Herb[MAXSIZE]();
    return;
}

void FreeListBinseq(SqList& L) {
    // �ͷ��ڴ�
    delete[] L.elem;
    return;
}

void ReadFileBinseq(SqList& L, string filename) {
    // ���ļ��ж�ȡ��ҩ����Ϣ�����䰴˳�����L.elemָ���������
    L.length = 0;
    ifstream file(filename);
    string reg;
    bool flag = true;
    while (getline(file, reg, '\n')) {
        if (reg == "#") {
            getline(file, reg, '\n');
            strcpy(L.elem[L.length].name, reg.c_str());
        }
        else strcpy(L.elem[L.length].name, reg.c_str());
        getline(file, reg, '\n');
        strcpy(L.elem[L.length].sname, reg.c_str());
        getline(file, reg, '\n');
        strcpy(L.elem[L.length].growth_habits, reg.c_str());
        getline(file, reg, '\n');
        strcpy(L.elem[L.length].reproductive, reg.c_str());
        getline(file, reg, '\n');
        strcpy(L.elem[L.length].field_management, reg.c_str());
        getline(file, reg, '\n');
        strcpy(L.elem[L.length].pest_control, reg.c_str());
        getline(file, reg, '\n');
        strcpy(L.elem[L.length].harvesting, reg.c_str());
        getline(file, reg, '\n');
        strcpy(L.elem[L.length].taste, reg.c_str());

        //�龭�Ĵ���
        getline(file, reg, '\n');
        stringstream s(reg);
        vector < string > res;
        string ss;
        int cnt = 0;
        while (getline(s, ss, ',')) {
            //cout << ss << "\n";
            L.elem[L.length].channel_tropism[cnt++] = ss;
        }
        L.elem[L.length].channel_tropism_num = cnt;

        getline(file, reg, '\n');
        strcpy(L.elem[L.length].effect, reg.c_str());

        getline(file, reg, '\n');
        strcpy(L.elem[L.length].functional_indications, reg.c_str());
        L.length++;
    }
    //cout << reg << "test\n";
    return;
}

bool myCompare(Herb a, Herb b)
{
    std::string aa = a.sname, bb = b.sname;
    return aa > bb;
}

void SortHerbBinseq(SqList& L) {
    // ����ҩ����Ϣ��Ӣ�����Ƶ��ֵ����С��������
    for (int i = 1; i < L.length; i++) {
        for (int j = 0; j < L.length - i; j++) {
            if (myCompare(L.elem[j], L.elem[j + 1])) {
                Herb res = L.elem[j];
                L.elem[j] = L.elem[j + 1];
                L.elem[j + 1] = res;
            }
        }
    }
}

int BinarySearchBinseq(SqList& L, char* sname) {
    // ��˳���L���۰������ҩ��Ӣ�����Ƶ���sname������Ԫ��
    // ���ҵ����򷵻ظ�Ԫ���ڱ��е��±꣬���򷵻�-1
    string test(sname);
    test = "Ӣ����:" + test;
    int l = 0, r = L.length;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (strcmp(L.elem[mid].sname, test.c_str()) == 0)return mid;
        else if (strcmp(L.elem[mid].sname, test.c_str()) < 0)l = mid + 1;
        else r = mid;
    }
    return -1;
}

double GetASLBinseq(SqList& L) {
    // ���ػ���˳�����۰���ҵ�ASL
    int h = log(L.length + 1) / log(2);
    int Last = L.length - (pow(2, h) - 1);
    double ans = 0;
    for (int i = 1; i <= h; i++) {
        ans += i * pow(2, i - 1);
    }
    ans += Last * (h + 1);

    return (double)(ans / L.length);
}

void PrintBinseq(SqList& L, int pos) {
    // �����ҩ��Ϣ
    cout << L.elem[pos].name << "\n";
    cout << L.elem[pos].sname << "\n";
    cout << L.elem[pos].growth_habits << "\n";
    cout << L.elem[pos].reproductive << "\n";
    cout << L.elem[pos].field_management << "\n";
    cout << L.elem[pos].pest_control << "\n";
    cout << L.elem[pos].harvesting << "\n";
    cout << L.elem[pos].taste << "\n";
    for (int i = 0; i < L.elem[pos].channel_tropism_num; i++) {
        cout << L.elem[pos].channel_tropism[i];
        if (i != L.elem[pos].channel_tropism_num - 1)cout << ",";
    }
    cout << "\n";
    cout << L.elem[pos].effect << "\n";
    cout << L.elem[pos].functional_indications << "\n";
}
void InitBSTreeBintree(BSTree& T) {
    // ������������ʼ��
    T = NULL;
    return;
}
void InsertBSTBintree(BSTree& T, Herb e) {
    // ������������T�в����ڹؼ��ֵ���e.sname������Ԫ��ʱ��������Ԫ��
    //
    if (T == NULL)
    {
        T = new BSTNode();
        T->data = e;
        T->rchild = T->lchild = NULL;
        return;
    }
    else if (strcmp(T->data.sname, e.sname) < 0)InsertBSTBintree(T->rchild, e);
    else if (strcmp(T->data.sname, e.sname) > 0)InsertBSTBintree(T->lchild, e);
    return;
}

int ReadFileBintree(BSTree& T, string filename) {
    // ��ȡ�ļ�������InsertBST������ÿ����ҩ�����ݲ������������
    Herb res;
    ifstream file(filename);
    string reg;
    int count = 0;
    while (getline(file, reg, '\n')) {
        if (reg == "#") {
            getline(file, reg, '\n');
            strcpy(res.name, reg.c_str());
        }
        else strcpy(res.name, reg.c_str());
        getline(file, reg, '\n');
        strcpy(res.sname, reg.c_str());
        getline(file, reg, '\n');
        strcpy(res.growth_habits, reg.c_str());
        getline(file, reg, '\n');
        strcpy(res.reproductive, reg.c_str());
        getline(file, reg, '\n');
        strcpy(res.field_management, reg.c_str());
        getline(file, reg, '\n');
        strcpy(res.pest_control, reg.c_str());
        getline(file, reg, '\n');
        strcpy(res.harvesting, reg.c_str());
        getline(file, reg, '\n');
        strcpy(res.taste, reg.c_str());

        //�龭�Ĵ���
        getline(file, reg, '\n');
        stringstream s(reg);
        string ss;
        int cnt = 0;
        while (getline(s, ss, ',')) {
            //cout << ss << "\n";
            res.channel_tropism[cnt++] = ss;
        }
        res.channel_tropism_num = cnt;

        getline(file, reg, '\n');
        strcpy(res.effect, reg.c_str());

        getline(file, reg, '\n');
        strcpy(res.functional_indications, reg.c_str());
        InsertBSTBintree(T, res);
        count++;
    }
    //cout << reg << "test\n";
    //cout<<count<<"\n";
    return count;
}

void PrintBintree(BSTNode* T) {
    // �����ҩ����Ϣ
    cout << T->data.name << "\n";
    cout << T->data.sname << "\n";
    cout << T->data.growth_habits << "\n";
    cout << T->data.reproductive << "\n";
    cout << T->data.field_management << "\n";
    cout << T->data.pest_control << "\n";
    cout << T->data.harvesting << "\n";
    cout << T->data.taste << "\n";
    for (int i = 0; i < T->data.channel_tropism_num; i++) {
        cout << T->data.channel_tropism[i];
        if (i != T->data.channel_tropism_num - 1)cout << ",";
    }
    cout << "\n";
    cout << T->data.effect << "\n";
    cout << T->data.functional_indications << "\n";
}

BSTNode* SearchBSTBintree(BSTree& T, char* sname) {
    // ���Ҷ�Ӧ��ҩ�ģ����ҳɹ����ض�Ӧ������㣬���򷵻�NULL
    BSTree p = T;
    string test(sname);
    test = "Ӣ����:" + test;
    while (p)
    {
        //cout<<p->data.sname<<"\n";
        if (strcmp(p->data.sname, test.c_str()) == 0)return p;
        else if (strcmp(p->data.sname, test.c_str()) > 0)p = p->lchild;
        else p = p->rchild;
    }
    return NULL;
}

int GetSumCmpBintree(BSTree T, int sumCmp) {
    // ͳ�Ʋ��ҳɹ�ʱ���ܱȽϴ���
    if (T != NULL) {
        sumCmp++;
        int temp = sumCmp;
        if (T->lchild)sumCmp += GetSumCmpBintree(T->lchild, temp);
        if (T->rchild)sumCmp += GetSumCmpBintree(T->rchild, temp);
    }
    return sumCmp;
}

double GetASLBintree(BSTree& T, int count) {
    // ���ػ��ڶ������������ҵ�ASL
    return (GetSumCmpBintree(T, 0) / 1.0 / count);
}

void InitListTrie(SqList& L) {
    // ʹ�ö�̬�ڴ����new���г�ʼ��
    L.length = 0;
    L.elem = new Herb[MAXSIZE]();
    return;
}

void FreeListTrie(SqList& L) {
    // �ͷ��ڴ�
    delete[] L.elem;
    return;
}

void ReadFileTrie(SqList& L, string filename) {
    // ���ļ��ж�ȡ��ҩ����Ϣ�����䰴˳�����L.elemָ���������
    L.length = 0;
    ifstream file(filename);
    string reg;
    bool flag = true;
    while (getline(file, reg, '\n')) {
        if (reg == "#") {
            getline(file, reg, '\n');
            strcpy(L.elem[L.length].name, reg.c_str());
        }
        else strcpy(L.elem[L.length].name, reg.c_str());
        getline(file, reg, '\n');
        strcpy(L.elem[L.length].sname, reg.c_str());
        getline(file, reg, '\n');
        strcpy(L.elem[L.length].growth_habits, reg.c_str());
        getline(file, reg, '\n');
        strcpy(L.elem[L.length].reproductive, reg.c_str());
        getline(file, reg, '\n');
        strcpy(L.elem[L.length].field_management, reg.c_str());
        getline(file, reg, '\n');
        strcpy(L.elem[L.length].pest_control, reg.c_str());
        getline(file, reg, '\n');
        strcpy(L.elem[L.length].harvesting, reg.c_str());
        getline(file, reg, '\n');
        strcpy(L.elem[L.length].taste, reg.c_str());

        //�龭�Ĵ���
        getline(file, reg, '\n');
        stringstream s(reg);
        vector < string > res;
        string ss;
        int cnt = 0;
        while (getline(s, ss, ',')) {
            //cout << ss << "\n";
            L.elem[L.length].channel_tropism[cnt++] = ss;
        }
        L.elem[L.length].channel_tropism_num = cnt;

        getline(file, reg, '\n');
        strcpy(L.elem[L.length].effect, reg.c_str());

        getline(file, reg, '\n');
        strcpy(L.elem[L.length].functional_indications, reg.c_str());
        L.length++;
    }
    //cout << reg << "test\n";
    return;
}

TNode* InitTNodeTrie(TrieTree& T) {
    // ��ʼ��Trie�����
    T->herbPtr = NULL;
    for (int i = 0; i < 53; i++) {
        T->child[i] = NULL;
    }
    return T;
}

TNode* BuildTreeTrie(SqList& L) {
    // ����������ʽ�洢���ֵ���
    // �����ɹ��󷵻�ָ�������ָ��
    TrieTree T = new TNode();
    T = InitTNodeTrie(T);
    int pos;
    TrieTree r = T;
    for (int i = 0; i < L.length; i++) {
        r = T;
        for (int j = 7; j < strlen(L.elem[i].sname); j++) {
            // cout<<L.elem[i].sname[j]<<" "<<L.elem[i].sname<<"\n";
            if (L.elem[i].sname[j] >= 'a' && L.elem[i].sname[j] <= 'z')pos = L.elem[i].sname[j] - 'a';
            else if (L.elem[i].sname[j] >= 'A' && L.elem[i].sname[j] <= 'Z')pos = L.elem[i].sname[j] - 'A' + 26;
            else if (L.elem[i].sname[j] == ' ')	pos = 52;
            if (r->child[pos] == NULL) {
                TrieTree p = new TNode;
                p = InitTNodeTrie(p);
                r->child[pos] = p;
                r = p;
            }
            else {//���Ѿ��н������һ����ĸ 
                r = r->child[pos];
            }
            // cout<<pos<<"\n";
        }
        r->herbPtr = &L.elem[i];
    }
    //cout << "OK\n";
    return T;
}

Herb* TrieSearchTrie(TNode* root, char* sname) {
    // �����ֵ����Ĳ���
    // ������ҳɹ��򷵻�ָ�����ҩ�ĵ�ָ�룬�������ʧ���򷵻�NULL
    //cout << "test\n";
    int pos;
    TrieTree temp = root;
    //cout<<"test"<<"\n";
    for (int i = 0; i < strlen(sname); i++) {
        //cout<<sname[i]<<"\n";
        if (sname[i] >= 'a' && sname[i] <= 'z')	pos = sname[i] - 'a';
        else if (sname[i] >= 'A' && sname[i] <= 'Z')pos = sname[i] - 'A' + 26;
        else if (sname[i] == ' ')pos = 52;
        if (temp->child[pos] == NULL)return NULL;
        else {
            temp = temp->child[pos];
        }
    }
    return temp->herbPtr;
}

void PrintTrie(Herb* herb) {
    // �����ҩ����Ϣ
    cout << herb->name << "\n";
    cout << herb->sname << "\n";
    cout << herb->growth_habits << "\n";
    cout << herb->reproductive << "\n";
    cout << herb->field_management << "\n";
    cout << herb->pest_control << "\n";
    cout << herb->harvesting << "\n";
    cout << herb->taste << "\n";
    for (int i = 0; i < herb->channel_tropism_num; i++) {
        cout << herb->channel_tropism[i];
        if (i != herb->channel_tropism_num - 1)cout << ",";
    }
    cout << "\n";
    cout << herb->effect << "\n";
    cout << herb->functional_indications << "\n";
}

double GetASLTrie(SqList& L) {
    // ������ҳɹ�ʱ��ƽ�����ҳ���ASL
    int num = 0;
    for (int i = 0; i < L.length; i++) {
        num += strlen(L.elem[i].sname) - 10;
    }
    return num / 1.0 / L.length;
}

void InitHTOpenadd(HashTable& HT) {
    // ɢ�б��ʼ��
    HT.key = new Herb[m]();
    HT.length = 0;
    return;
}

int Hash(char* sname) {
    // ʵ��ɢ�к������ַ���sname�и��ַ����±꣨��0��ʼ����ƽ�������ַ���Ӧ��ASCII��ֵ����Ӻ���299ȡ��
    int sum = 0;
    for (int i = 0; i < strlen(sname); i++)
        sum += ((i) * (i) * int(sname[i]));
    return sum % 299;
}

void HTInsertOpenadd(HashTable& HT, Herb h, int& sumCmp) {
    // ��ɢ�б��в����µ���ҩ��h
    // �ڲ���Ĺ�����ͳ���ܵıȽϴ���sumCmp
    //cout << "OK\n";
    string test(h.sname);
    string test1 = test.substr(7, 100);
    //cout<<test1<<"\n";
    char test2[100];
    strcpy(test2, test1.c_str());
    int cnt = Hash(test2);
    while (1)
    {
        sumCmp++;
        if (strcmp(HT.key[cnt].sname, "") == 0) {
            HT.key[cnt] = h;
            return;
        }
        cnt = (cnt + 1) % m;
    }
    return;
}

void ReadFileOpenadd(HashTable& HT, int& sumCmp, string filename) {
    // ���ļ��ж�ȡ��ҩ����Ϣ���������ɢ�б�HT��
    Herb res;
    ifstream file(filename);
    string reg;
    while (getline(file, reg, '\n')) {
        if (reg == "#") {
            getline(file, reg, '\n');
            strcpy(res.name, reg.c_str());
        }
        else strcpy(res.name, reg.c_str());
        getline(file, reg, '\n');
        strcpy(res.sname, reg.c_str());
        getline(file, reg, '\n');
        strcpy(res.growth_habits, reg.c_str());
        getline(file, reg, '\n');
        strcpy(res.reproductive, reg.c_str());
        getline(file, reg, '\n');
        strcpy(res.field_management, reg.c_str());
        getline(file, reg, '\n');
        strcpy(res.pest_control, reg.c_str());
        getline(file, reg, '\n');
        strcpy(res.harvesting, reg.c_str());
        getline(file, reg, '\n');
        strcpy(res.taste, reg.c_str());

        //�龭�Ĵ���
        getline(file, reg, '\n');
        stringstream s(reg);
        string ss;
        int cnt = 0;
        while (getline(s, ss, ',')) {
            //cout << ss << "\n";
            res.channel_tropism[cnt++] = ss;
        }
        res.channel_tropism_num = cnt;

        getline(file, reg, '\n');
        strcpy(res.effect, reg.c_str());

        getline(file, reg, '\n');
        strcpy(res.functional_indications, reg.c_str());

        HTInsertOpenadd(HT, res, sumCmp);
        HT.length++;
    }
    //cout << reg << "test\n";
    return;
}

void PrintOpenadd(HashTable HT, int pos) {
    // �����ҩ����Ϣ
    cout << HT.key[pos].name << "\n";
    cout << HT.key[pos].sname << "\n";
    cout << HT.key[pos].growth_habits << "\n";
    cout << HT.key[pos].reproductive << "\n";
    cout << HT.key[pos].field_management << "\n";
    cout << HT.key[pos].pest_control << "\n";
    cout << HT.key[pos].harvesting << "\n";
    cout << HT.key[pos].taste << "\n";
    for (int i = 0; i < HT.key[pos].channel_tropism_num; i++) {
        cout << HT.key[pos].channel_tropism[i];
        if (i != HT.key[pos].channel_tropism_num - 1)cout << ",";
    }
    cout << "\n";
    cout << HT.key[pos].effect << "\n";
    cout << HT.key[pos].functional_indications << "\n";
}

int SearchHashOpenadd(HashTable HT, char* key) {
    // ��ɢ�б�HT�в�����ҩ��Ӣ�����Ƶ���key��Ԫ��
    // ���ҵ����򷵻�ɢ�б�ĵ�Ԫ��ţ����򷵻�-1
    int cnt = Hash(key);
    string test(key);
    test = "Ӣ����:" + test;
    if (strcmp(HT.key[cnt].sname, test.c_str()) == 0) {
        return cnt;
    }
    int res = cnt + 1;
    while (res != cnt)
    {
        if (strcmp(HT.key[res].sname, test.c_str()) == 0) {
            return res;
        }
        else {
            res = (res + 1) % (m - 1);
        }
    }
    return -1;
}

double GetASLOpenadd(HashTable HT, int sumCmp) {
    // ���ػ��ڿ��ŵ�ַ����ɢ�в��ҵ�ASL
    return (sumCmp) / 1.0 / HT.length;
}


void InitListChainadd(LinkList* H) {
    // �����ʼ��
    for (int i = 0; i < m; i++) {
        H[i] = new LNode();
        H[i]->next = NULL;
    }
    return;
}

int HashChainadd(char* sname) {
    // ʵ��ɢ�к������ַ���sname�и��ַ����±꣨��0��ʼ����ƽ�������ַ���Ӧ��ASCII��ֵ����Ӻ���299ȡ��
    int sum = 0;
    for (int i = 0; i < strlen(sname); i++)
        sum += ((i) * (i) * int(sname[i]));
    return sum % 299;
}

void ListInsertChainadd(LinkList* H, Herb f, int& sumCmp) {
    // ��ɢ�б��в����µ���ҩ��f
    // �ڲ���Ĺ�����ͳ���ܵıȽϴ���sumCmp
    string test(f.sname);
    test = test.substr(7, 100);
    char test1[101];
    strcpy(test1, test.c_str());
    int cnt = HashChainadd(test1);

    LinkList p, r = H[cnt];
    sumCmp++;
    while (r->next != NULL)
    {
        sumCmp++;
        r = r->next;
    }
    p = new LNode();
    p->data = f;
    r->next = p;
    return;
}

int ReadFileChainadd(LinkList* H, int& sumCmp, string filename) {
    // ���ļ��ж�ȡ��ҩ����Ϣ���������ɢ�б���
    Herb res;
    ifstream file(filename);
    string reg;
    int count = 0;
    while (getline(file, reg, '\n')) {
        if (reg == "#") {
            getline(file, reg, '\n');
            strcpy(res.name, reg.c_str());
        }
        else strcpy(res.name, reg.c_str());
        getline(file, reg, '\n');
        strcpy(res.sname, reg.c_str());
        getline(file, reg, '\n');
        strcpy(res.growth_habits, reg.c_str());
        getline(file, reg, '\n');
        strcpy(res.reproductive, reg.c_str());
        getline(file, reg, '\n');
        strcpy(res.field_management, reg.c_str());
        getline(file, reg, '\n');
        strcpy(res.pest_control, reg.c_str());
        getline(file, reg, '\n');
        strcpy(res.harvesting, reg.c_str());
        getline(file, reg, '\n');
        strcpy(res.taste, reg.c_str());

        //�龭�Ĵ���
        getline(file, reg, '\n');
        stringstream s(reg);
        string ss;
        int cnt = 0;
        while (getline(s, ss, ',')) {
            //cout << ss << "\n";
            res.channel_tropism[cnt++] = ss;
        }
        res.channel_tropism_num = cnt;

        getline(file, reg, '\n');
        strcpy(res.effect, reg.c_str());

        getline(file, reg, '\n');
        strcpy(res.functional_indications, reg.c_str());

        ListInsertChainadd(H, res, sumCmp);
        count++;
    }
    //cout << reg << "test\n";
    return count;
}

int SearchHLChainadd(LinkList* H, char* key) {
    // ��ɢ�б�HT�в���ҩ��Ӣ�����Ƶ���key��Ԫ��
    // ���ҵ����򷵻�ɢ�б�ĵ�Ԫ��ţ����򷵻�-1
    int cnt = HashChainadd(key);
    string test(key);
    test = "Ӣ����:" + test;
    LinkList p = H[cnt]->next;
    while (p)
    {
        if (strcmp(p->data.sname, test.c_str()) == 0) {
            return cnt;
        }
        p = p->next;
    }
    return -1;
}

double GetASLChainadd(int sumCmp, int count) {
    // ���ػ�������ַ����ɢ�в��ҵ�ASL
    return sumCmp / 1.0 / count;
}

void PrintChainadd(LNode* T, char* sname) {
    // �����ҩ����Ϣ
    string test(sname);
    test = "Ӣ����:" + test;
    while (T) {
        if (!strcmp(T->data.sname, test.c_str())) {
            cout << T->data.name << "\n";
            cout << T->data.sname << "\n";
            cout << T->data.growth_habits << "\n";
            cout << T->data.reproductive << "\n";
            cout << T->data.field_management << "\n";
            cout << T->data.pest_control << "\n";
            cout << T->data.harvesting << "\n";
            cout << T->data.taste << "\n";
            for (int i = 0; i < T->data.channel_tropism_num; i++) {
                cout << T->data.channel_tropism[i];
                if (i != T->data.channel_tropism_num - 1)cout << ",";
            }
            cout << "\n";
            cout << T->data.effect << "\n";
            cout << T->data.functional_indications << "\n";
        }
        T = T->next;
    }
}
#endif // !SEARCH
