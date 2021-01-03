#include "VecType.h"


VecType::VecType(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}


int VecType::getX() { return x; }


int VecType::getY() { return y; }


int VecType::getZ() { return z; }


int VecType::inner(VecType v) {
	int result = this->x * v.getX() + this->y * v.getY() + this->z * v.getZ();
	return result;
}


VecType VecType::operator+(const VecType& v) {
	VecType result(this->x + v.x, this->y + v.y, this->z + v.z);
	return result;
}

ostream& operator<<(ostream& cout, const VecType& v) {
	cout << '[' << v.x() << v.y() << v.z() << ']';
	return cout;
}
