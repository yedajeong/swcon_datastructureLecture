#include <iostream>
#include "TreeType.h"
using namespace std;


int main() {

	TreeType tree;

	int node_num = 0;
	int num = 0;

	cin >> node_num;
	for (int i = 0; i < node_num; i++) {
		cin >> num;
		tree.InsertItem(num);
	}

	int node1 = 0;
	int node2 = 0;

	cin >> node1 >> node2;

	//TODO : 가장 가까운 공통 조상 구하기
	int length1;
	int length2;
	ItemType* parent1 = tree.Anscestors(node1, node_num, length1);
	ItemType* parent2 = tree.Anscestors(node2, node_num, length2);

	ItemType sameParent;

	cout << endl << endl;
	cout << length1 << endl << length2 << endl;

	for (int i = 0; i < length1; i++) {
		ItemType compare = parent1[i];
		for (int j = 0; j < length2; j++) {
			if (compare == parent2[j]) {
				sameParent = parent2[j];
			}
		}
	}

	cout << sameParent << endl;

	return 0;
}