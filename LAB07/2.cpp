#include <iostream>
#include "StackType.h"

using namespace std;

int main() {
	StackType stack, copySt;
	stack.Push('X');
	stack.Push('Y');
	stack.Push('Z');

	copySt.Copy(stack);

	while (!copySt.IsEmpty()) {
		char item = copySt.Top();
		cout << item << endl;
		copySt.Pop();
	}

	return 0;
}