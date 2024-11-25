#include "clusterAnalysisOrDecisionTree.h"
#include <bits/stdc++.h>
int DecisionTreeClassification() {
    SqList L;
    InitListDecision(L);
    string originFilename = "herb.txt";
    ReadFileDecision(L, originFilename);

    BiTree BT;
    InitTreeDecision(BT);

    createDecisionTree(BT, L);

    string herbName;
    cin >> herbName;

    FindClass(BT, herbName);

    FreeListDecision(L);
    return 0;
}