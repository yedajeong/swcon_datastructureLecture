#include <iostream>
#include "sorted.h"

using namespace std;

//hw04-1: ItemTypeÀÇ value -> int
void SplitLists(SortedType list, ItemType& item, SortedType& list1, SortedType& list2) {
	int idx = -1;
	ItemType listItem;
	
	list.ResetList();
	for (int location = 0; location < list.LengthIs(); location++) {
		list.GetNextItem(listItem);
		if (listItem.ComparedTo(item) == LESS || listItem.ComparedTo(item) == EQUAL)
			idx++;
		else
			break;
	}
	
	list.ResetList();
	for (int i = 0; i <= idx; i++) {
		list.GetNextItem(listItem);
		list1.InsertItem(listItem);
	}
	for (idx++; idx < list.LengthIs(); idx++) {
		list.GetNextItem(listItem);
		list2.InsertItem(listItem);
	}
}

int main() {
	SortedType list1, list2, result;
	ItemType item1, item2, item3, item4, item5, item6, item7, item8, item9, item10;

	item1.Initialize(3);
	item2.Initialize(1);
	item3.Initialize(11);
	item4.Initialize(9);
	item5.Initialize(2);
	item6.Initialize(5);
	item7.Initialize(14);
	item8.Initialize(7);
	item9.Initialize(17);
	item10.Initialize(13);

	result.InsertItem(item1);
	result.InsertItem(item2);
	result.InsertItem(item3);
	result.InsertItem(item4);
	result.InsertItem(item5);
	result.InsertItem(item6);
	result.InsertItem(item7);
	result.InsertItem(item8);
	result.InsertItem(item9);
	result.InsertItem(item10);

//	SplitLists(result, item6, list1, list2);
	result.SplitLists(item6, list1, list2);

	ItemType getItem;
	list1.ResetList();
	for (int i = 0; i < list1.LengthIs(); i++) {
		list1.GetNextItem(getItem);
		getItem.Print(cout);
		cout << '\t';
	}

	cout << endl;

	list2.ResetList();
	for (int i = 0; i < list2.LengthIs(); i++) {
		list2.GetNextItem(getItem);
		getItem.Print(cout);
		cout << '\t';
	}

	return 0;
}