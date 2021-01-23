#include <iostream>
#include "StackType.h"

using namespace std;

void ReplaceItem(StackType &stack, ItemType oldItem, ItemType newItem) {
	StackType temp_stack; //백업용 스택
	ItemType temp_Item; // top을 받는 아이템
	while (!stack.IsEmpty())
	{
		temp_Item = stack.Top();
		if (temp_Item == oldItem)
			temp_stack.Push(newItem);
		else
			temp_stack.Push(temp_Item);
		stack.Pop();
	}
	while (!temp_stack.IsEmpty())
	{
		temp_Item = temp_stack.Top();
		stack.Push(temp_Item);
		temp_stack.Pop();
	}

}

int main() {
	StackType stack;
	ItemType item;
	stack.Push(1);
	stack.Push(5);
	stack.Push(3);
	stack.Push(5);

	//1-A
//	ReplaceItem(stack, 5, 2);

	//1-B
	stack.ReplaceItem(5, 2);

	while(!stack.IsEmpty()) {
		item = stack.Top();
		stack.Pop();
		cout << item << endl;
	}


	
	return 0;
}