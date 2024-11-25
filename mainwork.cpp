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
			cout << "��лʹ�ã��ټ�\n";
			return 0;
		}
		else if (n == 1) {
			cout << "��������ϵͳ���ù��ܣ���ο���һ���е����ӽ�������\n";

		}
		else if (n == 2) {
			cout << "�������ԵĹ��������ݵ����ӹ���:\n";
			IncreaseOfInformation();
		}
		else if (n == 3) {
			cout << "�������ԵĹ��������ݵ�ɾ������:\n";
			DeletionOfInformation();

		}
		else if (n == 4) {
			cout << "�������ԵĹ��������ݵ��޸Ĺ���:\n";
			ModificationOfInformation();
		}
		else if (n == 5) {
			cout << "�������ԵĹ�����˳������:\n";
			SequentialTableSearch();
		}
		else if (n == 6) {
			cout << "�������ԵĹ�����˳�����ֲ���:\n";
			SequentialTableBinarySearch();
		}
		else if (n == 7) {
			cout << "�������ԵĹ����Ƕ���������:\n";
			BinarySearchTreeSearch();
		}
		else if (n == 8) {
			cout << "�������ԵĹ������ֵ���:\n";
			TtrieSearch();
		}
		else if (n == 9) {
			cout << "�������ԵĹ����ǿ��ŵ�ַ��ϣ:\n";
			OpenAddressingHashSearch();
		}
		else if (n == 10) {
			cout << "�������ԵĹ���������ַ��ϣ:\n";
			ChainAddressingHashSearch();
		}
		else if (n == 11) {
			cout << "�������ԵĹ�����KMP\n";
			KMPKMPSearch();
		}
		else if (n == 12) {
			cout << "�������ԵĹ����ǲ�������\n";
			InsertionSort();
		}
		else if (n == 13) {
			cout << "�������ԵĹ������۰��������\n";
			BinaryInsertionSort();
		}
		else if (n == 14) {
			cout << "�������ԵĹ�����ð������\n";
			BBubbleSort();
		}
		else if (n == 15) {
			cout << "�������ԵĹ����ǹ鲢����\n";
			QquickSort();
		}
		else if (n == 16) {
			cout << "�������ԵĹ����ǹ鲢����\n";
			MmergeSort();
		}
		else if (n == 17) {
			cout << "�������ԵĹ���������ƥ�����\n";
			HashTableSimilarMatch();
		}
		else if (n == 18) {
			cout << "�������ԵĹ����ǻ��ڹ����ʵ��ʶ��\n";
			EentityRecognition();
		}
		else if (n == 19) {
			cout << "�������ԵĹ����ǻ��ڹ���Ĺ�ϵ��ȡ\n";
			RrelationExtraction();
		}
		else if (n == 20) {
			cout << "�������ԵĹ����ǻ����ڽӱ��֪ʶͼ�׹���\n";
			GraphAdjacencyList();
		}
		else if (n == 21) {
			cout << "�������ԵĹ����ǻ���·�������֪ʶͼ�׶����ʴ�\n";
			AdjListSearchHerbsByEntity();
		}
		else if (n == 22) {

		}
		else if (n == 23) {

		}
		else if (n == 24) {

		}
		else if (n == 25) {
			cout << "�������ԵĹ����ǻ��ھ������ķ������\n";
			DecisionTreeClassification();
		}
		else if (n == 26) {
			cout << "�������ԵĹ����ǳ�����һ������ɾ�Ĳ�\n";
			loadReStack();
		}
		else {
			cout << "����������һ��\n";
			cout << "����0�˳�ϵͳ\n";
		}
	}
	return 0;


}