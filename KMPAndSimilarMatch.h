#pragma once
#ifndef KMP_SIMILAR_H
#define KMP_SIMILAR_H
#include "definition.h"
#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 300
#define m 300
void InitListKMP(SqList& L) {
    // 使用动态内存分配new进行初始化
    L.length = 0;
    L.elem = new Herb[MAXSIZE]();
    return;
}

void FreeListKMP(SqList& L) {
    // 释放内存
    delete[] L.elem;
    return;
}

void ReadFileKMP(SqList& L, string filename) {
    // 从文件中读取中药材信息，将其按顺序存入L.elem指向的数组中
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
    }
    //cout << reg << "test\n";
    return;
}

void GetNext(const char* T, int next[]) {
    // 计算子串T的next数组
        // 计算子串T的next数组
    string c = "1";
    std::string tt = c + T;
    int i = 1, j = 0;
    next[1] = 0;
    next[0] = 0;
    while (i < tt.length()) {
        if (j == 0 || tt[i] == tt[j]) {
            i++, j++;
            next[i] = j;
        }
        else {
            j = next[j];
        }
    }
}

bool KMP(const char* S, const char* T, int next[]) {
    // 利用模式串T的next数组求子串T在主串S中是否存在
    // 如果查找成功则返回true，如果查找失败则返回false
    GetNext(T, next);
    std::string c = "1";
    std::string tt = c + T;
    std::string ss = c + S;
    int i = 1, j = 1;
    while (i < ss.length() && j < tt.length()) {
        if (j == 0 || S[i] == tt[j]) {
            i++; j++;
        }
        else {
            j = next[j];
        }
    }
    if (j >= tt.length())return true;
    else return false;
}

void PrintKMP(char* h)
{
    string s(h);
    s = s.substr(7, 100);
    cout << s << "\n";
}

bool SearchListKMP(SqList& L, char* keyword, int next[]) {
    // 遍历顺序表中药材的生长习性和繁殖方法信息，调用KMP算法
    // 如果在中药材中查找成功则返回true，如果查找失败则返回false
    bool flag = false;
    for (int i = 0; i < L.length; i++) {
        if (KMP(L.elem[i].growth_habits, keyword, next) || KMP(L.elem[i].reproductive, keyword, next)) {
            PrintKMP(L.elem[i].name);
            flag = true;
        }
    }
    return flag;
}
void InitHTSim(HashTable& HT) {
    // 散列表初始化
    HT.key = new Herb[m]();
    HT.length = 0;
    return;
}

int HashSim(char* sname) {
    // 实现散列函数：字符串sname中各字符的下标（从0开始）的平方乘以字符对应的ASCII码值，相加后与299取余
    int sum = 0;
    for (int i = 0; i < strlen(sname); i++)
        sum += ((i) * (i) * int(sname[i]));
    return sum % 299;
}

void generateFeatureVector(const string* herbChannels, int herbChannelsCount, int featureVector[]) {
    // 根据中药材的归经生成特征向量
        // 定义最大归经数量
    const int MAX_CHANNELS = 6;

    // 定义归经字符串数组
    const string channels[MAX_CHANNELS] = { "心", "肝", "脾", "肺", "肾", "胃" };

    //TODO 在此补全函数
    string s(herbChannels[0]);
    s = s.substr(5, 100);
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < herbChannelsCount; j++) {
            if (j == 0) {
                if (channels[i] == s) {
                    featureVector[i] = 1;
                    break;
                }
            }
            else {
                if (channels[i] == herbChannels[j]) {
                    featureVector[i] = 1;
                    break;
                }
            }
        }
    }
    return;
}

void HTInsertSim(HashTable& HT, Herb h) {
    // 往散列表中插入新的中药材
    string test(h.sname);
    string test1 = test.substr(7, 100);
    //cout<<test1<<"\n";
    char test2[100];
    strcpy(test2, test1.c_str());
    int cnt = HashSim(test2);
    while (1)
    {
        if (strcmp(HT.key[cnt].sname, "") == 0) {
            HT.key[cnt] = h;
            return;
        }
        cnt = (cnt + 1) % m;
    }
    return;
}

void ReadFileSim(HashTable& HT, string filename) {
    // 从文件中读取中药材信息，将其存入散列表中
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

        //归经的存入
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

        HTInsertSim(HT, res);
        HT.length++;
    }
    //cout << reg << "test\n";
    return;
}

void PrintSim(HashTable HT, int pos) {
    // 输出特征向量
    string s(HT.key[pos].name);
    s = s.substr(7, 100);
    int FeatureVector[10] = { 0 };
    cout << s << "的特征向量为:";
    generateFeatureVector(HT.key[pos].channel_tropism, HT.key[pos].channel_tropism_num, FeatureVector);
    for (int i = 0; i < 6; i++) {
        cout << FeatureVector[i] << " \n"[i == 5];
    }
}

int SearchHashSim(HashTable HT, char* key) {
    // 在散列表HT中查找中药材英文名称等于key的元素
    // 若找到，则返回散列表的单元标号，否则返回-1
    int cnt = HashSim(key);
    string test(key);
    test = "英文名:" + test;
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

int computeSimilarity(HashTable HT, int p1, int p2) {
    int FeatureVector1[10] = { 0 };
    int FeatureVector2[10] = { 0 };
    generateFeatureVector(HT.key[p1].channel_tropism, HT.key[p1].channel_tropism_num, FeatureVector1);
    generateFeatureVector(HT.key[p2].channel_tropism, HT.key[p2].channel_tropism_num, FeatureVector2);
    int ans = 0;
    for (int i = 0; i < 6; i++) {
        ans += FeatureVector1[i] ^ FeatureVector2[i];
    }
    string s1(HT.key[p1].name), s2(HT.key[p2].name);
    s1 = s1.substr(7, 100);
    s2 = s2.substr(7, 100);
    cout << s1 << "和" << s2 << "的相似度为:" << ans << "\n";
    return 0;
}
#endif // !KMP_SIMILAR_H
