#pragma once
#ifndef infoModification
#define infoModification

#include "definition.h"
#include <bits/stdc++.h>
#define MAXSIZE 300
void InitList(SqList& L) {
    // ʹ�ö�̬�ڴ����new���г�ʼ��
    L.length = 0;
    L.elem = new Herb[MAXSIZE];
    return;
}

void FreeList(SqList& L) {
    // �ͷ��ڴ�
    delete[]L.elem;
    return;
}

void ReadFile(SqList& L, string filename) {
    // ���ļ��ж�ȡ��ҩ����Ϣ�����䰴˳�����L.elemָ���������
    L.length = 0;
    ifstream file(filename);
    string reg;
    bool flag = true;
    while (getline(file, reg, '\n'))
    {
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
        vector<string>res;
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

void SaveFile(SqList& L, string filename) {
    // ������ҩ����Ϣ���ļ�
    ofstream file(filename);
    int cnt = 0;
    while (cnt != L.length)
    {
        if (cnt != 0)file << "#\n";
        file << L.elem[cnt].name << "\n";
        file << L.elem[cnt].sname << "\n";
        file << L.elem[cnt].growth_habits << "\n";
        file << L.elem[cnt].reproductive << "\n";
        file << L.elem[cnt].field_management << "\n";
        file << L.elem[cnt].pest_control << "\n";
        file << L.elem[cnt].harvesting << "\n";
        file << L.elem[cnt].taste << "\n";
        //file << L.elem[cnt].channel_tropism_num << "\n";
        for (int i = 0; i < L.elem[cnt].channel_tropism_num; i++) {
            file << L.elem[cnt].channel_tropism[i];
            if (i != L.elem[cnt].channel_tropism_num - 1)file << ",";
        }
        file << "\n";
        file << L.elem[cnt].effect << "\n";
        file << L.elem[cnt].functional_indications << "\n";
        cnt++;
    }
    file.close();
}

void Print(SqList& L) {
    // �����ҩ����Ϣ
    cout << L.elem[L.length - 1].name << "\n";
    cout << L.elem[L.length - 1].sname << "\n";
    cout << L.elem[L.length - 1].growth_habits << "\n";
    cout << L.elem[L.length - 1].reproductive << "\n";
    cout << L.elem[L.length - 1].field_management << "\n";
    cout << L.elem[L.length - 1].pest_control << "\n";
    cout << L.elem[L.length - 1].harvesting << "\n";
    cout << L.elem[L.length - 1].taste << "\n";
    for (int i = 0; i < L.elem[L.length - 1].channel_tropism_num; i++) {
        cout << L.elem[L.length - 1].channel_tropism[i];
        if (i != L.elem[L.length - 1].channel_tropism_num - 1)cout << ",";
    }
    cout << "\n";
    cout << L.elem[L.length - 1].effect << "\n";
    cout << L.elem[L.length - 1].functional_indications << "\n";
}

Herb* myHerbCopy(Herb  a) {
    Herb* test;
    test = new Herb;

    strcpy(test->name, a.name);
    strcpy(test->sname, a.sname);
    strcpy(test->growth_habits, a.growth_habits);
    strcpy(test->reproductive, a.reproductive);
    strcpy(test->field_management, a.field_management);
    strcpy(test->pest_control, a.pest_control);
    strcpy(test->harvesting, a.harvesting);
    strcpy(test->taste, a.taste);
    test->channel_tropism_num = a.channel_tropism_num;
    for (int i = 0; i < a.channel_tropism_num; i++) {
        test->channel_tropism[i] = a.channel_tropism[i];
    }
    strcpy(test->effect, a.effect);
    strcpy(test->functional_indications, a.functional_indications);
    return test;
}

Herb* DeleteHerb(SqList& L, char* name) {
    // ������������ɾ��ָ����ҩ����Ϣ
    // ���ɾ���ɹ�������ָ���ʳ����Ϣ��ָ�룬���򣬷���NULL
    string test(name);
    test = "��ҩ��:" + test;
    int cnt = 0;
    for (cnt = 0; cnt < L.length; cnt++) {
        if (!strcmp(L.elem[cnt].name, test.c_str())) {
            Herb* test = myHerbCopy(L.elem[cnt]);
            for (int i = cnt; i < L.length - 1; i++) {
                strcpy(L.elem[i].sname, L.elem[i + 1].sname);
                strcpy(L.elem[i].growth_habits, L.elem[i + 1].growth_habits);
                strcpy(L.elem[i].reproductive, L.elem[i + 1].reproductive);
                strcpy(L.elem[i].field_management, L.elem[i + 1].field_management);
                strcpy(L.elem[i].pest_control, L.elem[i + 1].pest_control);
                strcpy(L.elem[i].harvesting, L.elem[i + 1].harvesting);
                strcpy(L.elem[i].taste, L.elem[i + 1].taste);
                L.elem[i].channel_tropism_num = L.elem[i + 1].channel_tropism_num;

                // �����龭���飬�����ֵ
                for (int j = 0; j < L.elem[i + 1].channel_tropism_num; j++) {
                    L.elem[i].channel_tropism[j] = L.elem[i + 1].channel_tropism[j];
                }

                strcpy(L.elem[i].effect, L.elem[i + 1].effect);
                strcpy(L.elem[i].functional_indications, L.elem[i + 1].functional_indications);
            }
            L.length--;
            return test;
        }
    }
    return NULL;
}

void Print(Herb* herb) {
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
        if (i != herb->channel_tropism_num - 1) cout << ",";
    }
    cout << "\n";
    cout << herb->effect << "\n";
    cout << herb->functional_indications << "\n";
}

bool ModifyHerb(SqList& L, char* name, string lines[], int n) {
    // ��ҩ�Ĺ龭��Ϣ�޸ģ�
    // ����޸ĳɹ�������true�����򣬷���false
    string test(name);
    test = "��ҩ��:" + test;
    for (int i = 0; i < L.length; i++) {
        if (!strcmp(test.c_str(), L.elem[i].name)) {
            L.elem[i].channel_tropism_num = n;
            for (int j = 0; j < n; j++) {
                L.elem[i].channel_tropism[j] = lines[j];
            }
            L.elem[i].channel_tropism[0] = "�龭:" + L.elem[i].channel_tropism[0];
            return true;
        }
    }
    return false;
}

Herb* getHerb(SqList& L, char* name) {
    // ����ָ���޸ĺ����ҩ����Ϣ��ָ��
    string test(name);
    test = "��ҩ��:" + test;
    for (int i = 0; i < L.length; i++) {
        if (!strcmp(test.c_str(), L.elem[i].name)) {
            return &L.elem[i];
        }
    }
    return NULL;
}
bool InsertHerb(SqList& L) {
    // ������ҩ����Ϣ��������ҩ�ĵĲ�ҩ����Ӣ����������ϰ�ԡ���ֳ������������������Ρ����ռӹ�����ζ���龭����Ч�͹���������Ϣ
    // �������ɹ�������true�����򣬷���false
    string reg;
    getline(cin, reg);
    reg = "��ҩ��:" + reg;
    for (int i = 0; i < L.length; i++) {
        if (L.elem[i].name == reg) {
            return false;
        }
    }
    strcpy(L.elem[L.length].name, reg.c_str());
    getline(cin, reg);
    reg = "Ӣ����:" + reg;
    strcpy(L.elem[L.length].sname, reg.c_str());
    getline(cin, reg);
    reg = "����ϰ��:" + reg;
    strcpy(L.elem[L.length].growth_habits, reg.c_str());
    getline(cin, reg);
    reg = "��ֳ����:" + reg;
    strcpy(L.elem[L.length].reproductive, reg.c_str());
    getline(cin, reg);
    reg = "������:" + reg;
    strcpy(L.elem[L.length].field_management, reg.c_str());
    getline(cin, reg);
    reg = "�������:" + reg;
    strcpy(L.elem[L.length].pest_control, reg.c_str());
    getline(cin, reg);
    reg = "���ռӹ�:" + reg;
    strcpy(L.elem[L.length].harvesting, reg.c_str());
    getline(cin, reg);
    reg = "��ζ:" + reg;
    strcpy(L.elem[L.length].taste, reg.c_str());
    getline(cin, reg);
    L.elem[L.length].channel_tropism_num = reg[0] - '0';
    for (int i = 0; i < L.elem[L.length].channel_tropism_num; i++) {
        getline(cin, reg);
        //cout << reg << "test\n";
        if (i == 0)reg = "�龭:" + reg;
        L.elem[L.length].channel_tropism[i] += reg;
    }
    getline(cin, reg);
    reg = "��Ч:" + reg;
    strcpy(L.elem[L.length].effect, reg.c_str());
    getline(cin, reg);
    reg = "��������:" + reg;
    strcpy(L.elem[L.length].functional_indications, reg.c_str());
    L.length++;
    return true;
}

void SaveFileSave(SqList& L, string filename) {
    // ������ҩ����Ϣ���ļ�
    ofstream file(filename);
    int cnt = 0;
    while (cnt != L.length)
    {
        if (cnt != 0)file << "#\n";
        file << L.elem[cnt].name << "\n";
        file << L.elem[cnt].sname << "\n";
        file << L.elem[cnt].growth_habits << "\n";
        file << L.elem[cnt].reproductive << "\n";
        file << L.elem[cnt].field_management << "\n";
        file << L.elem[cnt].pest_control << "\n";
        file << L.elem[cnt].harvesting << "\n";
        file << L.elem[cnt].taste << "\n";
        //file << L.elem[cnt].channel_tropism_num << "\n";
        for (int i = 0; i < L.elem[cnt].channel_tropism_num; i++) {
            file << L.elem[cnt].channel_tropism[i];
            if (i != L.elem[cnt].channel_tropism_num - 1)file << ",";
        }
        file << "\n";
        file << L.elem[cnt].effect << "\n";
        file << L.elem[cnt].functional_indications << "\n";
        cnt++;
    }
    file.close();
}

void loadFile(SqList& L, string filename) {
    // ���ļ��ж�ȡ��ҩ����Ϣ�����䰴˳�����L.elemָ���������
    L.length = 0;
    ifstream file(filename);
    if (!file) {
        cout << "�ļ���ʧ��\n";
    }
    string reg;
    bool flag = true;
    while (getline(file, reg, '\n'))
    {
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
        vector<string>res;
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
void InitListload(SqList& L) {
    // ʹ�ö�̬�ڴ����new���г�ʼ��
    L.length = 0;
    L.elem = new Herb[300]();
    return;
}

void FreeListload(SqList& L) {
    // �ͷ��ڴ�
    delete[]L.elem;
    return;
}
void Printload(SqList& L) {
    // �����ҩ����Ϣ
    cout << L.elem[L.length - 1].name << "\n";
    cout << L.elem[L.length - 1].sname << "\n";
    cout << L.elem[L.length - 1].growth_habits << "\n";
    cout << L.elem[L.length - 1].reproductive << "\n";
    cout << L.elem[L.length - 1].field_management << "\n";
    cout << L.elem[L.length - 1].pest_control << "\n";
    cout << L.elem[L.length - 1].harvesting << "\n";
    cout << L.elem[L.length - 1].taste << "\n";
    for (int i = 0; i < L.elem[L.length - 1].channel_tropism_num; i++) {
        cout << L.elem[L.length - 1].channel_tropism[i];
        if (i != L.elem[L.length - 1].channel_tropism_num - 1)cout << ",";
    }
    cout << "\n";
    cout << L.elem[L.length - 1].effect << "\n";
    cout << L.elem[L.length - 1].functional_indications << "\n";
}

int loadReStack()
{
    SqList Load;
    InitListload(Load);
    loadFile(Load, "Restack.txt");
    Printload(Load);
    return 0;
}
#endif // !infoModification