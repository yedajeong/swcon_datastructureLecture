#include "SortedType.h"

int main() {
	SortedType<char> list;
	
	list.InsertItem('X');
	list.InsertItem('Y');
	list.InsertItem('Z');

	list.PrintReverse();

	return 0;
}