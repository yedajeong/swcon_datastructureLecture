#include <iostream>
#include "PQStackType.h"

using namespace std;

//PQType�� Enqueue, Dequeue ����
//Heap�� info ������� �߰�, ReheapUp, ReheapDown ����
int main() {
	PQStackType pqstack(4);
	int item;

	pqstack.Push(3);
	pqstack.Push(4);
	pqstack.Push(1);
	pqstack.Push(2);

	pqstack.Pop(item);

	cout << item << endl; //2

	return 0;
}