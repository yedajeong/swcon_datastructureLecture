#include <iostream>
#include "SortedType.h"

using namespace std;

int main() {
	SortedType<int> list;
	int item;

	list.InsertItem(1);
	list.InsertItem(2);
	list.InsertItem(3);
	list.InsertItem(3);
	list.InsertItem(4);
	//list ป๓ลย: 1-2-3-3-4

	//5-A: 1-2-3-4
	//5-B: 1-2-4
	list.DeleteItem(3);

	list.ResetList();
	for (int i = 0; i < list.LengthIs(); i++) {
		list.GetNextItem(item);
		cout << item << endl;
	}
	
	return 0;
}