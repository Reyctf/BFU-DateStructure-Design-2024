#include "knowledgeGraphOrEntity.h"
#include <bits/stdc++.h>

int EentityRecognition() {
	char* keyword = new char[100];
	char text[10000];
	cin >> keyword >> text;
	if (!EntityRecognition(text, keyword))
		cout << "��ƥ��" << endl;;
	return 0;
}
void InitRelation(Relation* r) {
	r[0].relation = "��Ч";
	r[0].rule[0] = "A����B";
	r[0].rule[1] = "A��ЧΪB";
	r[0].rule[2] = "A������B";
	r[0].rule[3] = "A������B";
	r[0].rule[4] = "A����B";

	r[1].relation = "����";
	r[1].rule[0] = "A�ɷ���B";
	r[1].rule[1] = "A�߱��˷���B";
	r[1].rule[2] = "A��������B";
	r[1].rule[3] = "A������Ԥ��B";

	r[2].relation = "��ζ";
	r[2].rule[0] = "A����ζ��B";
	r[2].rule[1] = "A����ζΪB";

	r[3].relation = "����";
	r[3].rule[0] = "A����B";
	r[3].rule[1] = "A��Ҫ��B";
	r[3].rule[2] = "A�ֽ��B";
}

int RrelationExtraction() {
	char* entity1 = new char[100];
	char* entity2 = new char[100];
	char text[10000];
	Relation* r = new Relation[10];;
	InitRelation(r);
	cin >> entity1;
	getchar();
	cin >> entity2;
	getchar();
	cin >> text;
	if (!RelationExtraction(text, entity1, entity2, r))
		cout << "ʵ��֮�䲻���ڹ�ϵ" << endl;
	return 0;
}
int GraphAdjacencyList() {
	ALGraph G;
	InitALGraph(G);
	CreateAdjList(G, "entity.txt");
	CreateUDG(G, "relation.txt");
	PrintGraph(G);
	return 0;
}
int AdjListSearchHerbsByEntity() {
	ALGraph G;
	InitALGraph(G);
	CreateAdjList(G, "entity.txt");
	CreateUDG(G, "relation.txt");
	string entityToSearch;
	cin >> entityToSearch;
	SearchHerbsByEntity(G, entityToSearch);

	return 0;
}