#include <iostream>
#include "QueType.h"

using namespace std;

int main() {
	QueType queue(6);
	int item;

	queue.Enqueue(5);
	queue.Enqueue(4);
	queue.Enqueue(2);
	queue.Enqueue(3);
	queue.Enqueue(1);
	queue.Enqueue(8);
	queue.MinDequeue(item); //5 4 2 3 -1 8
	cout << item << '\t'; //1
	queue.Enqueue(10); //5 4 2 3 10 8
	
	for (int i = 0; i < 5; i++) {
		queue.MinDequeue(item);
		cout << item << '\t'; //2 3 4 5 8
	}

	return 0;
}
