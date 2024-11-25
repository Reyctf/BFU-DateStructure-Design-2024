#pragma once
#ifndef deginition_TS
#define dginition_TS

#include <bits/stdc++.h>
#define MVNum 10000
using namespace std;
typedef struct  HERB {
    char name[100]; // ��ҩ��
    char sname[100]; // Ӣ����
    char growth_habits[5000]; // ����ϰ��
    char reproductive[5000]; // ��ֳ����
    char field_management[5000]; // ������
    char pest_control[5000]; // �������
    char harvesting[5000]; // ���ռӹ�
    char taste[5000]; // ��ζ
    string channel_tropism[6]; // �龭
    int channel_tropism_num = 0; // �龭����
    char effect[5000]; // ��Ч
    char functional_indications[5000]; // ��������
}Herb;

typedef struct {
    Herb* elem; // ָ�������ָ��
    int length; // ����ĳ���
}SqList;

typedef struct {
    // ���ŵ�ַ��ɢ�б�Ĵ洢��ʾ
    Herb* key;
    int length;
} HashTable;

typedef struct {
    string relation;    //��ϵ����
    string rule[10];    //��������
} Relation;

typedef struct BSTNode {
    Herb data;                  // ��ҩ����Ϣ
    struct BSTNode* lchild;     // ����ָ��
    struct BSTNode* rchild;     // �Һ���ָ��
} BSTNode, * BSTree;

typedef struct BiTNode {
    Herb data;
    struct BiTNode* lchild, * rchild;
    string disition; //����������ֻ�о����������������,�в�ҩ��������Ϊ""
} BiTNode, * BiTree;

typedef struct TNode {
    // �����ֵ����ṹ��
    Herb* herbPtr;              // ��ҩ��ָ��
    struct TNode* child[53];    // �ӽ���ָ�����飬��26��Сд��ĸ��26����д��ĸ��1���ո����
} TNode, * TrieTree;

typedef struct LNode {
    Herb data;                  // ʳ����Ϣ
    struct LNode* next;         // ָ����һ�����
} LNode, * LinkList;


typedef struct ArcNode {
    int adjvex;                     // �ñ���ָ�򶥵��λ��
    int relationship;               // ��ʾ�ߵ����ͣ�����ϵ�����ͣ���ӦΪ�����±� 
    struct ArcNode* nextarc;        // ��һ����
} ArcNode;                          // �߽��

typedef struct VNode {
    int entity;                     // ��ʾ��������ͣ���ʵ������ͣ���ӦΪ�����±�
    string info;                    // ��ʾ��������ݣ���ʵ�������
    ArcNode* firstarc;              // ָ���һ�������ö���ıߵ�ָ��
} VNode, AdjList[MVNum];

typedef struct {
    AdjList vertices;               // �ڽӱ�
    int vexnum, arcnum;             // ͼ�ĵ�ǰ�������ͱ���
} ALGraph;

// �����ϵ���飬���ڱ�ʾ�ߵ�����
string Relationship[] = { "���","�߶�","Ҷ","��","��","����","����","��","ҩ��" };

// ���嶥�����飬���ڱ�ʾʵ�����ͺ�����
string Entity[] = { "��ҩ","���","�߶�","Ҷ","��","��","����","����","��","ҩ��" };
#endif // !deginition_TS