#include <iostream>
#include "UnsortedType.h"

using namespace std;

template <class ItemType>
void MergeLists(UnsortedType<ItemType> &l_a, UnsortedType<ItemType> &l_b, UnsortedType<ItemType> &result) {
	ItemType item;
	UnsortedType<ItemType> temp;
	l_a.ResetList();
	l_b.ResetList();

	//unsorted list -> 후입 선출
	for (int i = 0; i < l_a.LengthIs(); i++) {
		l_a.GetNextItem(item);
		temp.InsertItem(item);
	}

	for (int i = 0; i < l_b.LengthIs(); i++) {
		l_b.GetNextItem(item);
		temp.InsertItem(item);
	}

	temp.ResetList();
	for (int i = 0; i < temp.LengthIs(); i++) {
		temp.GetNextItem(item);
		result.InsertItem(item);
	}

}

int main() {
	UnsortedType<int> la, lb, result;
	int item;

	la.InsertItem(3);
	la.InsertItem(1);
	la.InsertItem(9);
	la.InsertItem(5);
	la.InsertItem(7);
	//리스트 안에서 순서: 7-5-9-1-3-null
	
	lb.InsertItem(6);
	lb.InsertItem(2);
	lb.InsertItem(4);
	lb.InsertItem(10);
	lb.InsertItem(8);
	//리스트 안에서 순서: 8-10-4-2-6-null

	//3-C
	MergeLists(la, lb, result);

	//3-D
//	la.MergeLists(lb, result);

	result.ResetList();
	for (int i = 0; i < result.LengthIs(); i++) {
		result.GetNextItem(item);
		cout << item << endl;
	}
	//결과: la+lb = 7-5-9-1-3-8-10-4-2-6-null

	return 0;
}