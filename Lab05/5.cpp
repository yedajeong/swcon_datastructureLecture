#include <iostream>
#include "LabQueType.h"

using namespace std;

int main() {
	QueType queue(5);
	int item;

	queue.Enqueue(2);
	queue.Enqueue(6);
	queue.Enqueue(7);
	queue.Enqueue(4);
	queue.Enqueue(6);
	queue.Dequeue(item);
	queue.Dequeue(item);
	queue.Dequeue(item);
	queue.Enqueue(10); //length == 3;

	while (!queue.IsEmpty()) {
		queue.Dequeue(item);
		cout << item << '\t';
	}

	return 0;
}
