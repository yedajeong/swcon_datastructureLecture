#include <iostream>
#include "ItemType.h"
#include "sorted.h"

using namespace std;

//Big-O notation: O(n^2)
void MergeList(SortedType list1, SortedType list2, SortedType &result) {
	ItemType item;
	list1.ResetList();
	list2.ResetList();
	
	for (int i = 0; i < list1.LengthIs(); i++) { //n번 실행->O(n)
		list1.GetNextItem(item); //O(1)
		result.InsertItem(item); //O(n)
	}

	for (int i = 0; i < list2.LengthIs(); i++) { //n번 실행->O(n)
		list2.GetNextItem(item); //O(1)
		result.InsertItem(item); //O(n)
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

	list1.InsertItem(item1);
	list1.InsertItem(item2);
	list1.InsertItem(item3);
	list1.InsertItem(item4);
	list1.InsertItem(item5);
	list2.InsertItem(item6);
	list2.InsertItem(item7);
	list2.InsertItem(item8);
	list2.InsertItem(item9);
	list2.InsertItem(item10);

	MergeList(list1, list2, result);

	int idx = 0;
	ItemType getItem;
	result.ResetList();
	for (int i = 0; i < result.LengthIs(); i++) {
		result.GetNextItem(getItem);
		getItem.Print(cout);
		cout << '\t';
	}
}