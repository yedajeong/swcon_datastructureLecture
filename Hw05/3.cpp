#include <iostream>
#include "StackType.h"

using namespace std;

//3-A
ItemType Top(StackType& stack) {
	ItemType item;
	if (stack.IsEmpty())
		throw EmptyStack();
	else {
		item = stack.Pop();
		stack.Push(item);
		return item;
	}	
}

int main() {
	StackType stack;
	ItemType item1, item2, item3;
	item1 = 'B';
	item2 = 'C';
	item3 = 'A';

	stack.Push(item1);
	stack.Push(item2);
	stack.Push(item3);

	cout << Top(stack) << endl;
	cout << stack.Top() << endl;
}