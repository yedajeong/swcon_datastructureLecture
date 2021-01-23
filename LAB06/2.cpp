#include <iostream>
#include "QueType.h"

using namespace std;

template <class ItemType>
void ReplaceItem(QueType<ItemType> &queue, ItemType oldItem, ItemType newItem) {
	QueType<ItemType> temp_que;
	ItemType temp_item;

	while (!queue.IsEmpty()) {
		queue.Dequeue(temp_item);
		if (temp_item == oldItem)
			temp_que.Enqueue(newItem);
		else
			temp_que.Enqueue(temp_item);
	}
	
	while (!temp_que.IsEmpty()) {
		temp_que.Dequeue(temp_item);
		queue.Enqueue(temp_item);
	}
}

int main() {
	QueType<int> queue;
	int item;
	queue.Enqueue(4);
	queue.Enqueue(2);
	queue.Enqueue(1);
	queue.Enqueue(2);

	//2-A
//	ReplaceItem(queue, 2, 9);

	//2-B
	queue.ReplaceItem(2, 9);
	queue.ReplaceItem(3, 900);

	while (!queue.IsEmpty()) {
		queue.Dequeue(item);
		cout << item << endl;
	}

	return 0;
}