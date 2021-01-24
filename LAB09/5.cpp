#include <iostream>
#include "TreeType.h"

using namespace std;

int main() {
	TreeType tree;
	tree.InsertItem('k');
	tree.InsertItem('o');
	tree.InsertItem('x');
	tree.InsertItem('d');
	tree.InsertItem('f');
	tree.InsertItem('a');
	tree.InsertItem('z');

	cout << tree.SingleParentCount();

	return 0;
}