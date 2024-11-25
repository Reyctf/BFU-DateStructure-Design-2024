#include "knowledgeGraphOrEntity.h"
#include <bits/stdc++.h>

int EentityRecognition() {
	char* keyword = new char[100];
	char text[10000];
	cin >> keyword >> text;
	if (!EntityRecognition(text, keyword))
		cout << "无匹配" << endl;;
	return 0;
}
void InitRelation(Relation* r) {
	r[0].relation = "功效";
	r[0].rule[0] = "A具有B";
	r[0].rule[1] = "A功效为B";
	r[0].rule[2] = "A有利于B";
	r[0].rule[3] = "A有益于B";
	r[0].rule[4] = "A可以B";

	r[1].relation = "防治";
	r[1].rule[0] = "A可防治B";
	r[1].rule[1] = "A具备了防治B";
	r[1].rule[2] = "A可以治疗B";
	r[1].rule[3] = "A有利于预防B";

	r[2].relation = "性味";
	r[2].rule[0] = "A的性味是B";
	r[2].rule[1] = "A的性味为B";

	r[3].relation = "包含";
	r[3].rule[0] = "A包括B";
	r[3].rule[1] = "A主要有B";
	r[3].rule[2] = "A分解成B";
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
		cout << "实体之间不存在关系" << endl;
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