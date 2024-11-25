#pragma once
#ifndef CLUSTERANALYSIS_H
#define CLUSTERANALYSIS_H
#include "definition.h"
#include <bits/stdc++.h>
using namespace std;

void InitListDecision(SqList& L) {
    // ʹ�ö�̬�ڴ����new���г�ʼ��
    L.length = 0;
    L.elem = new Herb[300]();
    return;
}

void FreeListDecision(SqList& L) {
    // �ͷ��ڴ�
    delete[] L.elem;
    return;
}

void ReadFileDecision(SqList& L, string filename) {
    // ���ļ��ж�ȡ��ҩ����Ϣ�����䰴˳�����L.elemָ���������
    L.length = 0;
    ifstream file(filename);
    string reg;
    bool flag = true;
    while (getline(file, reg, '\n')) {
        if (reg == "#") {
            getline(file, reg, '\n');
            reg = reg.substr(7, 100);
            strcpy(L.elem[L.length].name, reg.c_str());
        }
        else {
            reg = reg.substr(7, 100);
            strcpy(L.elem[L.length].name, reg.c_str());
        }
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
        //cout<<L.elem[L.length-1].name<<"\n";
    }
    //cout << reg << "test\n";
    //cout<<L.length<<"\n";
    return;
}

void InitTreeDecision(BiTree& BT)
{// ��ʼ��������
    BT = new BiTNode; BT->lchild = NULL; BT->rchild = NULL; BT->data = {};
    BiTree b1 = new BiTNode; b1->disition = "���ռӹ���Ϊ����"; b1->lchild = NULL; b1->rchild = NULL; b1->data = {};
    BiTree b2 = new BiTNode; b2->disition = "���ռӹ�Ϊ����"; b2->lchild = NULL; b2->rchild = NULL; b2->data = {};
    BiTree b3 = new BiTNode; b3->disition = "�龭�������ڵ���3"; b3->lchild = NULL; b3->rchild = NULL; b3->data = {};
    BiTree b4 = new BiTNode; b4->disition = "�龭����С��3"; b4->lchild = NULL; b4->rchild = NULL; b4->data = {};
    BiTree b5 = new BiTNode; b5->disition = "�龭����θ"; b5->lchild = NULL; b5->rchild = NULL; b5->data = {};
    BiTree b6 = new BiTNode; b6->disition = "�龭������θ"; b6->lchild = NULL; b6->rchild = NULL; b6->data = {};
    BT->lchild = b1;
    BT->rchild = b2;
    b1->lchild = b3;
    b1->rchild = b4;
    b3->lchild = b5;
    b3->rchild = b6;
}

void insertNodeToTreeDecision(BiTree& root, BiTree& node) {
    // �����������
    //cout << node->data.name << "\n";
    BiTree p = root;
    //�жϲ��ռӹ�
    string s(node->data.harvesting);
    s = s.substr(9, 10000);
    if (s == "���ޡ�") {
        p = p->rchild;
    }
    else {
        p = p->lchild;
        //�жϹ龭����
        if (node->data.channel_tropism_num >= 3) {
            p = p->lchild;

            //�ж��Ƿ���θ
            s = node->data.channel_tropism[0];
            s = s.substr(5, 100);
            bool flag = false;
            for (int i = 0; i < node->data.channel_tropism_num; i++) {
                if (i == 0) {
                    if (s == "θ") {
                        flag = true;
                        break;
                    }
                }
                else {
                    if (node->data.channel_tropism[i] == "θ") {
                        flag = true;
                        break;
                    }
                }
            }
            if (flag) {
                p = p->lchild;
            }
            else {
                p = p->rchild;
            }
        }
        else {
            p = p->rchild;
        }
    }
    //  cout << p->data.name << " " << p->disition << "\n";
    int cnt = 0;
    while (p->lchild != NULL) { p = p->lchild; }

    p->lchild = node;
    return;

}

void createDecisionTree(BiTree& BT, SqList L) {
    //��������������ʹ�ö������ṹ�洢
    for (int i = 0; i < L.length; i++) {
        //cout << L.elem[i].name << "\n";
        BiTree node = new BiTNode();
        node->data = L.elem[i];
        node->lchild = node->rchild = NULL;
        node->disition = "";

        insertNodeToTreeDecision(BT, node);

    }
    //cout<<"�������\n";
    return;
}

bool flag = false;
BiTree FindNodeByName(BiTree BT, string name) {
    //����ֲ�����ݹ��ҵ���Ӧ��㣬���������򷵻�NULL
    BiTree p = NULL;
    if (BT == NULL)return NULL;
    if (BT->data.name == name) {
        flag = true;
        return BT;
    }
    else {

        if (!flag)p = FindNodeByName(BT->lchild, name);
        if (!flag)p = FindNodeByName(BT->rchild, name);
        return p;
    }
}

bool flag2 = false;
BiTree FindOriginalFather(BiTree BT, BiTree t) {
    //���Ҷ�������һ���ڵ��ھ������ṹ�еĸ����
    BiTree p = NULL;
    if (BT) {
        if (BT->lchild == t || BT->rchild == t) {
            flag2 = true;
            return BT;
        }
        else {
            if (!flag2)p = FindOriginalFather(BT->lchild, t);
            if (!flag2)p = FindOriginalFather(BT->rchild, t);
            return p;
        }
    }
    else {
        return NULL;
    }
}

void FindClass(BiTree& BT, string name) {
    //������ҩ�Ĳ�ҩ��������������������о�������

    //cout << "OK\n";
    int cnt = 0;
    BiTree p = FindNodeByName(BT, name);
    //cout << p->data.name << "\n";
    while (p != BT) {
        //cout << cnt++;
        //cout << p->disition << "\n";
        if (p->disition != "") {
            cout << p->disition << "\n";
        }
        p = FindOriginalFather(BT, p);
        flag2 = false;
    }
}
#endif // !CLUSTERANALYSIS_H
