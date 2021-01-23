#include <iostream>
#include "UnsortedType.h"

using namespace std;

int main() {
	UnsortedType<int> list;
	int item;
	
	list.InsertItem(4);
	list.InsertItem(1);
	list.InsertItem(10);
	list.InsertItem(8);
	list.InsertItem(10);
	//list ป๓ลย: 10-8-10-1-4;

	//4-A: 8-10-1-4
	//4-B: 8-1-4
	list.DeleteItem(10);
//	list.DeleteItem(7);
	
	list.ResetList();
	for (int i = 0; i < list.LengthIs(); i++) {
		list.GetNextItem(item);
		cout << item << endl;
	}

	return 0;
}