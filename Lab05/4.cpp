#include <iostream>
#include "QueType.h"

using namespace std;

int LengthIs(QueType& queue) {
	QueType tempQue;
	int item, length = 0;
	while (!queue.IsEmpty()) {
		queue.Dequeue(item);
		length++;
		tempQue.Enqueue(item);
	}
	
	while (!queue.IsFull()) {
		tempQue.Dequeue(item);
		queue.Enqueue(item);
	}

	return length;
}

int main() {
	QueType queue(5);

	queue.Enqueue(2);
	queue.Enqueue(6);
	queue.Enqueue(7);
	queue.Enqueue(4);
	queue.Enqueue(6);

	//4-1
//	cout << LengthIs(queue);

	//4-2
	cout << queue.LengthIs();

	return 0;
}