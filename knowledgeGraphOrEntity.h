#pragma once
#ifndef GRAPH_ENTITY_H
#define GRAPH_ENTITY_H
#include "definition.h"
#include <bits/stdc++.h>


bool EntityRecognition(const char* S, const char* T) {
    // S为非结构化文本，T为规则
    // 如果匹配成功返回true，否则返回false
    // 输出所有匹配到的实体
    std::string s = T;
    std::string text = S;
    bool flag = false;
    //std::cout<<s.length()<<"\n";
    for (int i = 0; i < text.length(); i++) {
        int j = 0;
        int cnt = 0;
        std::string ans;
        for (; j < s.length();) {
            if (s[j] == '*') {
                //std::cout<<1<<"\n";
                ans = ans + text[i] + text[i + 1];
                //std::cout<<ans<<"\n";
                i += 2;
                cnt++;
                j++;
                continue;
            }
            if (s[j] == text[i]) {
                i++;
                j++;
                continue;
            }
            if (s[j] != text[i]) {
                i = i - (cnt * 2) - (j - cnt);
                break;
            }
        }
        if (j == s.length()) {
            std::cout << ans << "\n";
            flag = true;
        }
    }
    return flag;
}



bool BF(std::string ans, std::string text)
{
    for (int i = 0, j; i < text.length(); i++) {
        for (j = 0; j < ans.length();) {
            if (ans[j] == text[i]) {
                j++;
                i++;
            }
            else break;
        }
        i = i - j;
        if (j == ans.length()) {
            return true;
        }
    }
    return false;
}

std::string Get_Rule(std::string rule)
{
    std::string ans = "";
    int n = rule.length() - 1;
    for (int i = 1; i < n; i++) {
        ans += rule[i];
    }
    //std::cout<<ans<<"\n";
    return ans;

}

bool RelationExtraction(char* text, char* entity1, char* entity2, Relation* r) {
    // 如果实体之间存在关系返回true，否则返回false
    // 输出所有存在的三元组
    bool flag = false;
    std::string Text = text, A = entity1, B = entity2;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if (r[i].rule[j] == "")break;
            std::string res = Get_Rule(r[i].rule[j]);
            std::string ans = A + res + B;
            if (BF(ans, text)) {
                std::cout << A << "-" << r[i].relation << "-" << B << "\n";
                flag = true;
            }
        }
    }
    return flag;
}

int LocateVex(ALGraph& G, string str) {
    // 返回str在AdjList中的位置
    for (int i = 0; i < G.vexnum; i++) {
        if (G.vertices[i].info == str)
            return i;
    }
}

int LocateEntity(string str) {
    // 返回str在Entity数组中的位置
    for (int i = 0; i < 10; i++) {
        if (Entity[i] == str)
            return i;
    }
}

int LocateRelationship(string str) {
    // 返回str在Relationship数组中的位置
    for (int i = 0; i < 9; i++) {
        if (Relationship[i] == str)
            return i;
    }
}

void InitALGraph(ALGraph& G) {
    // 初始化邻接表
    G.vexnum = G.arcnum = 0;
    for (int i = 0; i < MVNum; i++) {
        G.vertices[i].firstarc = NULL;
    }
}

void CreateAdjList(ALGraph& G, string filename) {
    // 从filename中按顺序读取实体存入邻接表
    //若读取的元素word中含有换行符，可用word.erase(word.find_last_not_of(" \n\r\t") + 1)去掉 (word类型为string）
    ifstream file(filename);
    while (!file.eof())
    {
        std::string res;
        file >> G.vertices[G.vexnum].info;
        file >> res;
        //cout<<res<<"\n";
        G.vertices[G.vexnum].entity = LocateEntity(res);
        G.vertices[G.vexnum].firstarc = NULL;
        G.vexnum++;
    }
    return;
}

void CreateUDG(ALGraph& G, string filename) {
    // 从filename中按顺序三元组存入邻接表
    //若读取的元素word中含有换行符，可用word.erase(word.find_last_not_of(" \n\r\t") + 1)去掉 (word类型为string）
    ifstream file(filename);
    std::string s1, s2, re;
    while (!file.eof())
    {
        file >> s1 >> re >> s2;
        //cout<<s1<<" "<<re<<" "<<s2<<"\n";
        int i = LocateVex(G, s1), j = LocateVex(G, s2);
        ArcNode* test1 = new ArcNode, * test2 = new ArcNode;
        test1->relationship = LocateRelationship(re);
        test1->adjvex = j;
        test1->nextarc = G.vertices[i].firstarc;
        G.vertices[i].firstarc = test1;

        test2->relationship = LocateRelationship(re);
        test2->adjvex = i;
        test2->nextarc = G.vertices[j].firstarc;
        G.vertices[j].firstarc = test2;
        G.arcnum++;
    }
}

void PrintGraph(ALGraph& G) {
    //	按格式输出知识图谱
    for (int i = 0; i < G.vexnum; i++) {
        ArcNode* p = G.vertices[i].firstarc;
        if (p == NULL) {
            continue;
        }
        else {
            while (p) {
                cout << G.vertices[i].info << ' ';
                cout << p->relationship << " ";
                cout << G.vertices[p->adjvex].info << " ";
                cout << endl;
                p = p->nextarc;
            }
        }
    }
}

void SearchHerbsByEntity(ALGraph& G, const string& entityName) {
    // 执行问答功能，entityName是输入的问答条件
    /*cout << "OK\n";
    return;*/
    int cnt = 0;
    for (int i = 0; i < G.vexnum; i++) {
        ArcNode* p = G.vertices[i].firstarc;
        bool flag = false;
        if (p == NULL) {
            continue;
        }
        else {
            while (p)
            {
                //cout << cnt++ << "\n";
                ArcNode* q = G.vertices[i].firstarc;
                while (q && !flag) {
                    //cout << G.vertices[q->adjvex].info << " " << entityName << "\n";
                    if (G.vertices[q->adjvex].info == entityName) {
                        //cout << "OK\n";
                        flag = true;
                        break;
                    }
                    q = q->nextarc;
                }
                if (flag) {
                    cout << G.vertices[i].info << "->";
                    cout << Relationship[p->relationship] << "->";
                    cout << G.vertices[p->adjvex].info << "\n";
                }
                p = p->nextarc;
            }
        }
    }
}

#endif // !GRAPH_ENTITY_H
