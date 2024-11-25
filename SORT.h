#pragma once
#ifndef SORT_H
#define SORT_H
#include "definition.h"
#include <bits/stdc++.h>
#define MAXSIZE 300
void InitListSort(SqList& L) {
    // ʹ�ö�̬�ڴ����new���г�ʼ��
    L.length = 1;
    L.elem = new Herb[MAXSIZE];
    return;
}

void FreeListSort(SqList& L) {
    // �ͷ��ڴ�
    delete[] L.elem;
    return;
}

void ReadFileSort(SqList& L, string filename) {
    // ���ļ��ж�ȡ��ҩ����Ϣ�����䰴˳�����L.elemָ���������
    L.length = 1;
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

void Print(Herb h)
{
    string s(h.sname);
    s = s.substr(7, 100);
    cout << s << "\n";
}

void InsertSort(SqList& L, int& kcn, int& rmn) {
    // ��˳���L��ֱ�Ӳ������򣬴Ӻ���ǰ˳��Ƚ�
    // ע��L.elem[0]�����ڱ���Ԫ
    // �����������ҩ��Ӣ�����ơ�KCN��RMN
    for (int i = 2, j; i < L.length; i++) {
        if (strcmp(L.elem[i].sname, L.elem[i - 1].sname) < 0) {
            kcn++;
            L.elem[0] = L.elem[i];
            L.elem[i] = L.elem[i - 1];
            rmn += 2;
            for (j = i - 2; strcmp(L.elem[0].sname, L.elem[j].sname) < 0 && j >= 0; j--)
            {
                L.elem[j + 1] = L.elem[j];
                rmn++;
                kcn++;
            }
            kcn++;
            L.elem[j + 1] = L.elem[0];
            rmn++;
        }
        else kcn++;
    }
    for (int i = 1; i < L.length; i++) {
        Print(L.elem[i]);
    }
    std::cout << "�ܵĹؼ��ֱȽϴ���KCNΪ��" << kcn << "\n";
    std::cout << "�ܵļ�¼�ƶ�����RMNΪ��" << rmn << "\n";
}
void BInsertSort(SqList& L, int& kcn, int& rmn) {
    // ��˳������۰��������
    // ע��L.elem[0]�����ڱ���Ԫ
    // �����������ҩ��Ӣ�����ơ�KCN��RMN
    for (int i = 2, j; i < L.length; i++) {
        L.elem[0] = L.elem[i];
        int l = 1, r = i - 1;
        rmn++;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (strcmp(L.elem[0].sname, L.elem[mid].sname) < 0)r = mid - 1;
            else l = mid + 1;
            kcn++;
        }
        for (j = i - 1; j >= r + 1; j--) {
            L.elem[j + 1] = L.elem[j];
            rmn++;
        }
        L.elem[r + 1] = L.elem[0];
        rmn++;
    }
    for (int i = 1; i < L.length; i++) {
        Print(L.elem[i]);
    }
    std::cout << "�ܵĹؼ��ֱȽϴ���KCNΪ��" << kcn << "\n";
    std::cout << "�ܵļ�¼�ƶ�����RMNΪ��" << rmn << "\n";



}

void BubbleSort(SqList& L, int& kcn, int& rmn) {
    // ��˳���L��ð������
    // ע��elem[0]����
    // �����������ҩ��Ӣ�����ơ�KCN��RMN
    int m = L.length - 1;
    bool flag = true;
    while (m > 0 && flag)
    {
        flag = false;
        for (int j = 1; j < m; j++) {
            if (strcmp(L.elem[j].sname, L.elem[j + 1].sname) >= 0) {
                flag = true;
                Herb t = L.elem[j];
                L.elem[j] = L.elem[j + 1];
                L.elem[j + 1] = t;
                kcn++;
                rmn += 3;
            }
            else kcn++;
        }
        m--;
    }
    for (int i = 1; i < L.length; i++) {
        Print(L.elem[i]);
    }
    std::cout << "�ܵĹؼ��ֱȽϴ���KCNΪ��" << kcn << "\n";
    std::cout << "�ܵļ�¼�ƶ�����RMNΪ��" << rmn << "\n";
}


int Partition(SqList& L, int low, int high, int& kcn, int& rmn) {
    // ��˳����е��ӱ�elem[low..high]����һ�����򣬷�������λ��
    // ���ӱ�ĵ�һ����¼�������¼
    // ע��L.elem[0]�����������¼
    L.elem[0] = L.elem[low];
    string priv = L.elem[low].sname;
    rmn++;
    while (low < high)
    {
        while (low < high && strcmp(L.elem[high].sname, priv.c_str()) >= 0) { high--; kcn++; }
        if (low != high)kcn++;

        L.elem[low] = L.elem[high];
        rmn++;

        while (low < high && strcmp(L.elem[low].sname, priv.c_str()) <= 0) { low++; kcn++; }
        if (low != high)kcn++;

        L.elem[high] = L.elem[low];
        rmn++;
    }

    L.elem[low] = L.elem[0];
    rmn++;
    return low;
}

void QSort(SqList& L, int low, int high, int& kcn, int& rmn) {
    // ����ǰ�ó�ֵ��low=1; high=L.length;
    // ��˳���L�е�������L.elem[low.high]����������
    if (low < high) {
        int piv = Partition(L, low, high, kcn, rmn);
        QSort(L, low, piv - 1, kcn, rmn);
        QSort(L, piv + 1, high, kcn, rmn);
    }
}

void QuickSort(SqList& L) {
    // ��˳�������������
    // �����������ҩ��Ӣ�����ơ�KCN��RMN
    int kcn = 0, rmn = 0;
    QSort(L, 1, L.length - 1, kcn, rmn);
    for (int i = 1; i < L.length; i++) {
        Print(L.elem[i]);
    }
    std::cout << "�ܵĹؼ��ֱȽϴ���KCNΪ��" << kcn << "\n";
    std::cout << "�ܵļ�¼�ƶ�����RMNΪ��" << rmn << "\n";
}

void sort(SqList& L, SqList& sq, int start, int end, int mid, int& kcn, int& rmn) {
    int i = start, j = mid + 1, k = start;
    while (i <= mid && j <= end) {
        if (strcmp(L.elem[i].sname, L.elem[j].sname) > 0)
            sq.elem[k++] = L.elem[j++];
        else
            sq.elem[k++] = L.elem[i++];
        kcn++;
    }
    while (i <= mid) { sq.elem[k++] = L.elem[i++]; }
    while (j <= end) { sq.elem[k++] = L.elem[j++]; }
    for (i = start; i <= end; i++) { L.elem[i] = sq.elem[i]; rmn++; }
}

void Merge(SqList& L, SqList& sq, int start, int end, int& kcn, int& rmn) {
    int mid;
    if (start < end) {
        mid = start + (end - start) / 2;//�������int
        Merge(L, sq, start, mid, kcn, rmn);
        Merge(L, sq, mid + 1, end, kcn, rmn);
        sort(L, sq, start, end, mid, kcn, rmn);
    }
}

void MergeSort(SqList& L, int& kcn, int& rmn) {

    SqList sq;
    InitListSort(sq);
    int start = 1, end = L.length - 1;

    Merge(L, sq, start, end, kcn, rmn);
    for (int i = 1; i < L.length; i++) {
        string s(L.elem[i].sname);
        s = s.substr(7, 100);
        cout << s << "\n";
    }
    cout << "�ܵĹؼ��ֱȽϴ���KCNΪ��" << kcn << "\n";
    cout << "�ܵļ�¼�ƶ�����RMNΪ��" << rmn << "\n";
}
#endif // !SORT_H
