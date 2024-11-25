#include "ReStack.cpp"
#include "infoModification.cpp"
#include "SORT.cpp"
#include "knowledgeGraphOrEntity.cpp"
#include "clusterAnalysisOrDecisionTree.cpp"
#include "Search.cpp"
#include "KMPAndSimilarMatch.cpp"

#include <bits/stdc++.h>
int main()
{
	int n = 0;
	while (cin >> n) {
		if (n == 0) {
			cout << "感谢使用，再见\n";
			return 0;
		}
		else if (n == 1) {
			cout << "即将进行系统调用功能，请参考第一题中的例子进行输入\n";

		}
		else if (n == 2) {
			cout << "即将测试的功能是数据的增加功能:\n";
			IncreaseOfInformation();
		}
		else if (n == 3) {
			cout << "即将测试的功能是数据的删除功能:\n";
			DeletionOfInformation();

		}
		else if (n == 4) {
			cout << "即将测试的功能是数据的修改功能:\n";
			ModificationOfInformation();
		}
		else if (n == 5) {
			cout << "即将测试的功能是顺序表查找:\n";
			SequentialTableSearch();
		}
		else if (n == 6) {
			cout << "即将测试的功能是顺序表二分查找:\n";
			SequentialTableBinarySearch();
		}
		else if (n == 7) {
			cout << "即将测试的功能是二叉排序树:\n";
			BinarySearchTreeSearch();
		}
		else if (n == 8) {
			cout << "即将测试的功能是字典树:\n";
			TtrieSearch();
		}
		else if (n == 9) {
			cout << "即将测试的功能是开放地址哈希:\n";
			OpenAddressingHashSearch();
		}
		else if (n == 10) {
			cout << "即将测试的功能是链地址哈希:\n";
			ChainAddressingHashSearch();
		}
		else if (n == 11) {
			cout << "即将测试的功能是KMP\n";
			KMPKMPSearch();
		}
		else if (n == 12) {
			cout << "即将测试的功能是插入排序\n";
			InsertionSort();
		}
		else if (n == 13) {
			cout << "即将测试的功能是折半插入排序\n";
			BinaryInsertionSort();
		}
		else if (n == 14) {
			cout << "即将测试的功能是冒泡排序\n";
			BBubbleSort();
		}
		else if (n == 15) {
			cout << "即将测试的功能是归并排序\n";
			QquickSort();
		}
		else if (n == 16) {
			cout << "即将测试的功能是归并排序\n";
			MmergeSort();
		}
		else if (n == 17) {
			cout << "即将测试的功能是相似匹配分析\n";
			HashTableSimilarMatch();
		}
		else if (n == 18) {
			cout << "即将测试的功能是基于规则的实体识别\n";
			EentityRecognition();
		}
		else if (n == 19) {
			cout << "即将测试的功能是基于规则的关系抽取\n";
			RrelationExtraction();
		}
		else if (n == 20) {
			cout << "即将测试的功能是基于邻接表的知识图谱构建\n";
			GraphAdjacencyList();
		}
		else if (n == 21) {
			cout << "即将测试的功能是基于路径推理的知识图谱多跳问答\n";
			AdjListSearchHerbsByEntity();
		}
		else if (n == 22) {

		}
		else if (n == 23) {

		}
		else if (n == 24) {

		}
		else if (n == 25) {
			cout << "即将测试的功能是基于决策树的分类分析\n";
			DecisionTreeClassification();
		}
		else if (n == 26) {
			cout << "即将测试的功能是撤销上一步的增删改查\n";
			loadReStack();
		}
		else {
			cout << "请重新输入一次\n";
			cout << "输入0退出系统\n";
		}
	}
	return 0;


}