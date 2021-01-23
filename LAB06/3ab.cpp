#include <iostream>
#include "SortedType.h"

using namespace std;

template <class ItemType>
void MergeLists(SortedType<ItemType> &l_a, SortedType<ItemType> &l_b, SortedType<ItemType> &result) {
	ItemType get_item;
	l_a.ResetList();
	l_b.ResetList();
	result.MakeEmpty();

	for (int i = 0; i < l_a.LengthIs(); i++) {
		l_a.GetNextItem(get_item);
		result.InsertItem(get_item);
	}
	
	for (int i = 0; i < l_b.LengthIs(); i++) {
		l_b.GetNextItem(get_item);
		result.InsertItem(get_item);
	}
}

int main() {
	SortedType<int> la, lb, result;
	int item;

	la.InsertItem(1);
	la.InsertItem(3);
	la.InsertItem(5);
	la.InsertItem(7);
	la.InsertItem(9);

	lb.InsertItem(2);
	lb.InsertItem(4);
	lb.InsertItem(6);
	lb.InsertItem(8);
	lb.InsertItem(10);

	//3-A
//	MergeLists(la, lb, result);

	//3-B
	la.MergeLists(lb, result);

	result.ResetList();
	for (int i = 0; i < result.LengthIs(); i++) {
		result.GetNextItem(item);
		cout << item << endl;
	}
	//°á°ú: la+lb = 1-2-3-4-5-6-7-8-9-10-null

	return 0;
}