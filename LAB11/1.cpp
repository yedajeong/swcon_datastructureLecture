#include <iostream>
#include "PQType.h"

using namespace std;

int main() {
	PQType<char> pq(10);
	char item;
	
	pq.Enqueue('J'); //root
	pq.Enqueue('H');
	pq.Enqueue('I');
	pq.Enqueue('D');
	pq.Enqueue('G');
	pq.Enqueue('F');
	pq.Enqueue('A');
	pq.Enqueue('B');
	pq.Enqueue('C');
	pq.Enqueue('E'); //bottom

	pq.Dequeue(item);

	cout << item << endl;

	return 0;
}