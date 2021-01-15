#include <iostream>
#include "QueType.h"

using namespace std;

int main() {
	QueType queue, temp, copy;
	ItemType secondElement, last, item;
	int second = 0;

	queue.Enqueue('C');
	queue.Enqueue('A'); //secondElement
	queue.Enqueue('F');
	queue.Enqueue('V'); //last

	//a.
	while (!queue.IsEmpty()) {
		second++;
		if (second == 2) {
			queue.Dequeue(secondElement);
			temp.Enqueue(secondElement);
		}
		else {
			queue.Dequeue(item);
			temp.Enqueue(item);
		}
	}

	while (!temp.IsEmpty()) {
		temp.Dequeue(item);
		queue.Enqueue(item);
	}
	cout << "secondElement: ";
	cout << secondElement << endl << endl;

	//b.
	while (!queue.IsEmpty()) {
		queue.Dequeue(last); //last�� item �����
		temp.Enqueue(last);
	}

	while (!temp.IsEmpty()) {
		temp.Dequeue(item);
		if (item == last) //���� ť���� last ����α�
			continue;
		queue.Enqueue(item);
	}
	cout << "last: ";
	cout << last << endl << endl;

	//c.
	queue.Enqueue('V'); //b.���� ����� last �ٽ� ť�� �ֱ�
	while (!queue.IsEmpty()) {
		queue.Dequeue(last); //last�� item �����
		temp.Enqueue(last);
	}

	while (!temp.IsEmpty()) {
		temp.Dequeue(item);
		queue.Enqueue(item);
	}
	cout << "last: ";
	cout << last << endl << endl;

	//d.
	while (!queue.IsEmpty()) {
		queue.Dequeue(item);
		temp.Enqueue(item);
	}

	while (!temp.IsEmpty()) {
		temp.Dequeue(item);
		queue.Enqueue(item);
		copy.Enqueue(item);
	}
	cout << "copy queue's item: " << endl;
	while (!copy.IsEmpty()) {
		copy.Dequeue(item);
		cout << item << endl;
	}

	return 0;
}