#include <iostream>

using namespace std;

class FullStack
	// Exception class thrown by Push when stack is full.
{};

class EmptyStack
	// Exception class thrown by Pop and Top when stack is emtpy.
{};

const int MAX_ITEMS = 200;

class DoubleStack
{
public:

	DoubleStack();

	bool IsFull() const;

	bool IsEmpty() const;

	void Push(int item);

	void Print() const;

private:
	int top_small;
	int top_big;
	int  items[MAX_ITEMS];
};

int main() {
	DoubleStack stack;
	stack.Push(1);
	stack.Push(2);
	stack.Push(3);
	stack.Push(4);
	stack.Push(5);
	stack.Push(1001);
	stack.Push(1002);
	stack.Push(1003);
	stack.Push(1004);
	stack.Push(1005);

	stack.Print();

	return 0;
}

DoubleStack::DoubleStack()
{
	top_small = -1;
	top_big = 200;
}


bool DoubleStack::IsEmpty() const
{
	return (top_small == -1 && top_big == 200);
}

bool DoubleStack::IsFull() const
{
	return (top_small + 1 == top_big);
}

void DoubleStack::Push(int newItem)
{
	if (IsFull())
		throw FullStack();

	if (newItem <= 1000) {
		top_small++;
		items[top_small] = newItem;
	}
	else {
		top_big--;
		items[top_big] = newItem;
	}
}

void DoubleStack::Print() const
{
	if (IsEmpty())
		throw EmptyStack();

	for (int front = top_small; 0 <= front; front--)
		cout << items[front] << endl;
	cout << endl;
	for (int back = top_big; back <= 199; back++)
		cout << items[back] << endl;
}