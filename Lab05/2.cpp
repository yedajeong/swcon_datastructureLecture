#include <iostream>
#include "QueType.h"

using namespace std;

void ReplaceItem(QueType& queue, int olditem, int newitem) {
	QueType tempQue;
	int item;

	while (!queue.IsEmpty()) {
		queue.Dequeue(item);
		if (item == olditem)
			tempQue.Enqueue(newitem);
		else
			tempQue.Enqueue(item);
	}

	while (!queue.IsFull()) {
		tempQue.Dequeue(item);
		queue.Enqueue(item);
	}

}

int main() {
	QueType queue(5);
	int item;

	queue.Enqueue(2);
	queue.Enqueue(6);
	queue.Enqueue(7);
	queue.Enqueue(4);
	queue.Enqueue(6);

	//2-1
//	ReplaceItem(queue, 6, 20);
	//2-2
	queue.ReplaceItem(6, 20);

	while (!queue.IsEmpty()) {
		queue.Dequeue(item);
		cout << item << '\t';
	}
}