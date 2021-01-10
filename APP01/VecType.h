#pragma once
#include <iostream>

class VecType
{
private:
	int x, y, z;
public:
	VecType(int _x, int _y, int _z);
	int getX();
	int getY();
	int getZ();
	int inner(VecType v);
	VecType operator+(const VecType& v);
	friend ostream& operator<<(ostream& cout, const VecType& v);
};
