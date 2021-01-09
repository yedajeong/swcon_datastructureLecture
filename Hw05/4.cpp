#include <iostream>
#include "StackType.h"

using namespace std;

//4-A
bool Identical(StackType stack1, StackType stack2) {
	ItemType item1, item2;

	while (!stack1.IsEmpty()) {
		item1 = stack1.Pop();
		item2 = stack2.Pop();
		if (item1 != item2)
			return false;
	}

	if (stack2.IsEmpty())
		return true;

	else
		return false;
}

int main() {
	StackType stack1, stack2, stack3;
	ItemType item1, item2, item3, item4;
	item1 = 'B';
	item2 = 'C';
	item3 = 'A';
	item4 = 'D';

	stack1.Push(item1);
	stack1.Push(item2);
	stack1.Push(item3);

	stack2.Push(item1);
	stack2.Push(item2);
	stack2.Push(item3);
	stack2.Push(item4);

	stack3.Push(item1);
	stack3.Push(item2);
	stack3.Push(item4);

	//4-A
	cout << Identical(stack1, stack1) << endl;
	cout << Identical(stack1, stack2) << endl;
	cout << Identical(stack1, stack3) << endl;

	//4-B
	cout << stack1.Identical(stack1) << endl;
	cout << stack1.Identical(stack2) << endl;
	cout << stack1.Identical(stack3) << endl;

	return 0;
}