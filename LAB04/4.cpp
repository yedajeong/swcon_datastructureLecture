#include <iostream>
#include "StackType.h"

using namespace std;

void ReplaceItem(StackType &stack, ItemType oldItem, ItemType newItem) {
	StackType replace;
	ItemType item;
	while (!stack.IsEmpty()) {
		item = stack.Top();
		if (item == oldItem)
			item = newItem;
		replace.Push(item);
		stack.Pop();
	}
	//replace에는 stack의 last부터 first 순으로 들어가있음(stack과 거꾸로)
	while (!replace.IsEmpty()) {
		item = replace.Top();
		stack.Push(item);
		replace.Pop();
	}
}

int main() {
	StackType stack;
	stack.Push(8);
	stack.Push(3);
	stack.Push(9);
	stack.Push(8);
	stack.Push(3);
	stack.Push(7);
	stack.Push(5);
	stack.Push(3);

//	ReplaceItem(stack, 3, 5);
	stack.ReplaceItem(3, 5);
	ItemType item;

	while (!stack.IsEmpty()) {
		item = stack.Top();
		stack.Pop();
		cout << "Item: " << item << endl;
	}

	return 0;
}