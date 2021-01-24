#include "TreeType.h"

int Smaller(TreeType tree, char value)
{
	ItemType item;
	bool finished = false;
	int count = 0;

	tree.ResetTree(IN_ORDER); //1.left 2.self 3.right

	do {
		tree.GetNextItem(item, IN_ORDER, finished);

		if (value > item)
			count++;
		else
			finished = true;
	} while (!finished);

	return count;
}

int main() {
	TreeType tree;

	tree.InsertItem('k');
	tree.InsertItem('f');
	tree.InsertItem('o');
	tree.InsertItem('c');
	tree.InsertItem('g');
	tree.InsertItem('p');
	tree.InsertItem('a');

	std::cout << Smaller(tree, 'g');

	return 0;
}