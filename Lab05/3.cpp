#include <iostream>
#include "QueType.h"

using namespace std;

bool Identical(QueType _queue1, QueType _queue2) {
	int item1, item2;
	QueType queue1(_queue1);
	QueType queue2(_queue2);

	while (!queue1.IsEmpty() && !queue2.IsEmpty()) { //둘 중 하나라도 empty면 while 종료
		queue1.Dequeue(item1);
		queue2.Dequeue(item2);
		if (item1 == item2)
			continue;
		else
			return false; //1. item끼리 다른 경우 false
	}

	if (!queue1.IsEmpty() || !queue2.IsEmpty()) //2. queue의 크기 다른 경우 false
		return false;
	else
		return true;
}

int main() {
	QueType queue1(5);
	QueType queue2(5);
	QueType queue3(6);
	QueType queue4(5);
	bool judge;

	queue1.Enqueue(2);
	queue1.Enqueue(6);
	queue1.Enqueue(7);
	queue1.Enqueue(4);
	queue1.Enqueue(6);

	queue2.Enqueue(2);
	queue2.Enqueue(6);
	queue2.Enqueue(7);
	queue2.Enqueue(4);
	queue2.Enqueue(6);

	queue3.Enqueue(2);
	queue3.Enqueue(6);
	queue3.Enqueue(7);
	queue3.Enqueue(4);
	queue3.Enqueue(6);
	queue3.Enqueue(10);

	queue4.Enqueue(2);
	queue4.Enqueue(6);
	queue4.Enqueue(100);
	queue4.Enqueue(4);
	queue4.Enqueue(6);

	//3-1
//	judge = Identical(queue1, queue2);
//	cout << judge << endl;
//	judge = Identical(queue1, queue3);
//	cout << judge << endl;
//	judge = Identical(queue1, queue4);
//	cout << judge << endl;

	//3-2
	judge = queue1.Identical(queue2);
	cout << judge << endl;
	judge = queue1.Identical(queue3);
	cout << judge << endl;
	judge = queue1.Identical(queue4);
	cout << judge << endl;	

	return 0;

}