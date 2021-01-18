#include <iostream>
#include "SortedType.h"

using namespace std;

//hw07-1-c
template <class ItemType>
void SplitLists(SortedType<ItemType>& self, SortedType<ItemType>& list1, SortedType<ItemType>& list2, ItemType item) {
	ItemType getItem;
	self.ResetList();

	for (int i = 0; i < self.LengthIs(); i++) {
		self.GetNextItem(getItem);
		if (getItem <= item)
			list1.InsertItem(getItem);
		else
			list2.InsertItem(getItem);
	}

}

int main() {
	SortedType<int> self, list1, list2;
	int item;

	self.InsertItem(5);
	self.InsertItem(22);
	self.InsertItem(4);
	self.InsertItem(19);
	self.InsertItem(10);

	//1-b
//	self.SplitLists(list1, list2, 15);
	//1-d
	SplitLists(self, list1, list2, 15);

	list1.ResetList();
	list2.ResetList();
	for (int i = 0; i < list1.LengthIs(); i++) {
		list1.GetNextItem(item);
		cout << item << "\t";
	}

	cout << endl;

	for (int i = 0; i < list2.LengthIs(); i++) {
		list2.GetNextItem(item);
		cout << item << "\t";
	}

	return 0;
}