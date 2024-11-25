#pragma once
#ifndef deginition_TS
#define dginition_TS

#include <bits/stdc++.h>
#define MVNum 10000
using namespace std;
typedef struct  HERB {
    char name[100]; // 草药名
    char sname[100]; // 英文名
    char growth_habits[5000]; // 生长习性
    char reproductive[5000]; // 繁殖方法
    char field_management[5000]; // 田间管理
    char pest_control[5000]; // 病虫防治
    char harvesting[5000]; // 采收加工
    char taste[5000]; // 性味
    string channel_tropism[6]; // 归经
    int channel_tropism_num = 0; // 归经数量
    char effect[5000]; // 功效
    char functional_indications[5000]; // 功能主治
}Herb;

typedef struct {
    Herb* elem; // 指向数组的指针
    int length; // 数组的长度
}SqList;

typedef struct {
    // 开放地址法散列表的存储表示
    Herb* key;
    int length;
} HashTable;

typedef struct {
    string relation;    //关系名称
    string rule[10];    //规则数组
} Relation;

typedef struct BSTNode {
    Herb data;                  // 中药材信息
    struct BSTNode* lchild;     // 左孩子指针
    struct BSTNode* rchild;     // 右孩子指针
} BSTNode, * BSTree;

typedef struct BiTNode {
    Herb data;
    struct BiTNode* lchild, * rchild;
    string disition; //决策条件，只有决策条件结点有内容,中草药结点可设置为""
} BiTNode, * BiTree;

typedef struct TNode {
    // 定义字典树结构体
    Herb* herbPtr;              // 中药材指针
    struct TNode* child[53];    // 子结点的指针数组，由26个小写字母，26个大写字母，1个空格组成
} TNode, * TrieTree;

typedef struct LNode {
    Herb data;                  // 食材信息
    struct LNode* next;         // 指向下一级结点
} LNode, * LinkList;


typedef struct ArcNode {
    int adjvex;                     // 该边所指向顶点的位置
    int relationship;               // 表示边的类型，即关系的类型，对应为数组下标 
    struct ArcNode* nextarc;        // 下一条边
} ArcNode;                          // 边结点

typedef struct VNode {
    int entity;                     // 表示顶点的类型，即实体的类型，对应为数组下标
    string info;                    // 表示顶点的内容，即实体的内容
    ArcNode* firstarc;              // 指向第一条依附该顶点的边的指针
} VNode, AdjList[MVNum];

typedef struct {
    AdjList vertices;               // 邻接表
    int vexnum, arcnum;             // 图的当前顶点数和边数
} ALGraph;

// 定义关系数组，用于表示边的类型
string Relationship[] = { "类别","高度","叶","花","果","花期","果期","茎","药材" };

// 定义顶点数组，用于表示实体类型和内容
string Entity[] = { "草药","类别","高度","叶","花","果","花期","果期","茎","药材" };
#endif // !deginition_TS