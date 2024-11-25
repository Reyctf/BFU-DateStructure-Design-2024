
#ifndef RESTACK_H
#define RESTACK_H
#include "definition.h"
#include <bits/stdc++.h>

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
    L.elem = new Herb[300];
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

#endif // !RESTACK
