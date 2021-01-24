#include <iostream>
#include "TreeType.h"

using namespace std;

int main() {
	TreeType tree1, tree2;

	//case 1
	tree1.InsertItem('D');
	tree1.InsertItem('A');
	tree1.InsertItem('Y');
	tree1.InsertItem('Z');
	tree1.PrintSuccessor(); //A

	//case 2
	tree2.InsertItem('D');
	tree2.InsertItem('Y');
	tree2.InsertItem('A');
	tree2.InsertItem('C');
	tree2.InsertItem('Z');
	tree2.PrintSuccessor(); //A

	return 0;
}