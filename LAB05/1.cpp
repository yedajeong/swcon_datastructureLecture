#include <iostream>
#include "QueType.h"

using namespace std;

int main() {
	QueType queue(10);
	ItemType item;

	while (!queue.IsFull()) {
		item = rand() % 21; //0~20������ ��
		cout << "enqueue�� ��: " << item << endl;
		queue.Enqueue(item);
	}

	cout << endl;

	while (!queue.IsEmpty()) {
		queue.Dequeue(item);
		cout << "dequeue�� ��: " << item << endl;
	}

	return 0;
}