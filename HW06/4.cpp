#include <iostream>
#include "QueType.h"

using namespace std;

ItemType Front(QueType& queue) {
	QueType temp;
	ItemType front, item;

	queue.Dequeue(front);
	temp.Enqueue(front);

	while (!queue.IsEmpty()) {
		queue.Dequeue(item);
		temp.Enqueue(item);
	}

	while (!temp.IsEmpty()) {
		temp.Dequeue(item);
		queue.Enqueue(item);
	}

	return front;
}

int main() {
	QueType queue;
	ItemType item;

	queue.Enqueue('C');
	queue.Enqueue('A');
	queue.Enqueue('F');
	queue.Enqueue('V');

	//4-A
	cout << Front(queue) << endl;
	//4-B
	cout << queue.Front();

	return 0;
}