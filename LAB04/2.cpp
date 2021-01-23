#include <iostream>
#include "StackType.h"

using namespace std;

void reverse(StackType stack, StackType& result) {
	StackType temp;
	ItemType item;

	while (!stack.IsEmpty()) {
		item = stack.Top();
		stack.Pop();
		temp.Push(item);
	}

	while (!temp.IsEmpty()) {
		item = temp.Top();
		temp.Pop();
		result.Push(item);
		stack.Push(item);
	}
}

int main() {
	StackType stack, result;
	ItemType item;
	stack.Push(1);
	stack.Push(2);
	stack.Push(3);
	stack.Push(4);
	stack.Push(5);
	stack.Push(6);

	reverse(stack, result);

	while (!result.IsEmpty()) {
		item = result.Top();
		result.Pop();
		cout << item << endl;
	}

	return 0;
}