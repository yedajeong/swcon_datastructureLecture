#include <iostream>
#include "StackTType.h"

using namespace std;

int main() {
	StackType<int> stack;
	stack.Push(1);
	stack.Push(2);
	stack.Push(3);
	stack.Push(4);
	stack.Push(5);
	stack.Push(6);

	while (!stack.IsEmpty()) {
		int result = stack.Top();
		stack.Pop();
		cout << result << endl;
	}
}