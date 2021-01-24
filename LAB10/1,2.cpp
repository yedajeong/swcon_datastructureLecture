#include "TreeType.h"

int main() {
	TreeType tree;

	tree.InsertItem('k');
	tree.InsertItem('d');
	tree.InsertItem('o');
	tree.InsertItem('m');
	tree.InsertItem('n');
	tree.InsertItem('x');

	tree.Ancestors('x'); //k, o
	tree.Ancestors('l'); //Ã£À» ¼ö x

	tree.Ancestors_re('x'); //o, k

	return 0;
}