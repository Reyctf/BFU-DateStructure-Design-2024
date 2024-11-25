#pragma once
#ifndef CLUSTERANALYSIS_H
#define CLUSTERANALYSIS_H
#include "definition.h"
#include <bits/stdc++.h>
using namespace std;

void InitListDecision(SqList& L) {
    // 使用动态内存分配new进行初始化
    L.length = 0;
    L.elem = new Herb[300]();
    return;
}

void FreeListDecision(SqList& L) {
    // 释放内存
    delete[] L.elem;
    return;
}

void ReadFileDecision(SqList& L, string filename) {
    // 从文件中读取中药材信息，将其按顺序存入L.elem指向的数组中
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

        //归经的存入
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
{// 初始化二叉树
    BT = new BiTNode; BT->lchild = NULL; BT->rchild = NULL; BT->data = {};
    BiTree b1 = new BiTNode; b1->disition = "采收加工不为暂无"; b1->lchild = NULL; b1->rchild = NULL; b1->data = {};
    BiTree b2 = new BiTNode; b2->disition = "采收加工为暂无"; b2->lchild = NULL; b2->rchild = NULL; b2->data = {};
    BiTree b3 = new BiTNode; b3->disition = "归经数量大于等于3"; b3->lchild = NULL; b3->rchild = NULL; b3->data = {};
    BiTree b4 = new BiTNode; b4->disition = "归经数量小于3"; b4->lchild = NULL; b4->rchild = NULL; b4->data = {};
    BiTree b5 = new BiTNode; b5->disition = "归经含有胃"; b5->lchild = NULL; b5->rchild = NULL; b5->data = {};
    BiTree b6 = new BiTNode; b6->disition = "归经不含有胃"; b6->lchild = NULL; b6->rchild = NULL; b6->data = {};
    BT->lchild = b1;
    BT->rchild = b2;
    b1->lchild = b3;
    b1->rchild = b4;
    b3->lchild = b5;
    b3->rchild = b6;
}

void insertNodeToTreeDecision(BiTree& root, BiTree& node) {
    // 结点插入二叉树
    //cout << node->data.name << "\n";
    BiTree p = root;
    //判断采收加工
    string s(node->data.harvesting);
    s = s.substr(9, 10000);
    if (s == "暂无。") {
        p = p->rchild;
    }
    else {
        p = p->lchild;
        //判断归经数量
        if (node->data.channel_tropism_num >= 3) {
            p = p->lchild;

            //判断是否含有胃
            s = node->data.channel_tropism[0];
            s = s.substr(5, 100);
            bool flag = false;
            for (int i = 0; i < node->data.channel_tropism_num; i++) {
                if (i == 0) {
                    if (s == "胃") {
                        flag = true;
                        break;
                    }
                }
                else {
                    if (node->data.channel_tropism[i] == "胃") {
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
    //构建决策树，并使用二叉树结构存储
    for (int i = 0; i < L.length; i++) {
        //cout << L.elem[i].name << "\n";
        BiTree node = new BiTNode();
        node->data = L.elem[i];
        node->lchild = node->rchild = NULL;
        node->disition = "";

        insertNodeToTreeDecision(BT, node);

    }
    //cout<<"创建完成\n";
    return;
}

bool flag = false;
BiTree FindNodeByName(BiTree BT, string name) {
    //根据植物名递归找到对应结点，若不存在则返回NULL
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
    //查找二叉树中一个节点在决策树结构中的父结点
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
    //根据中药材草药名，输出其所经历的所有决策条件

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
