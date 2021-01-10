#include <iostream>
#include "VecType.h"

using namespace std;

int main()
{
	VecType a(2, 5, 8);
	VecType b(3, 4, 7);
	int ip;

	ip = a.inner(b);
	cout << ip << endl;

	VecType c = a + b;
	cout << c << endl;

	return 0;
}
