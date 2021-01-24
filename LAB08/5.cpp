#include <iostream>
#include "UnsortedType.h"

using namespace std;

int main() {
	UnsortedType<int> list;
	list.InsertItem(5);
	list.InsertItem(7);
	list.InsertItem(1);
	list.InsertItem(4);

	list.PrintSort();

	return 0;
}