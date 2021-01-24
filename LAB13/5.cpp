#include <iostream>
#include "HeapSort.cpp"
using namespace std;

int main()
{
	int ary[9];

	ary[0] = 25;
	ary[1] = 17;
	ary[2] = 36;
	ary[3] = 2;
	ary[4] = 3;
	ary[5] = 100;
	ary[6] = 1;
	ary[7] = 19;
	ary[8] = 7;

	HeapSort(ary, 9);

	return 0;
}