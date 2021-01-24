#include <iostream>
#include <cmath>

using namespace std;

//��� ����. ������ ���� ������ �����ø� �˴ϴ�.
float SqrRoot_recursion(float number, float approx, float tol)
{
	if (abs(approx*approx - number) <= tol)
		return approx;
	else
		return SqrRoot_recursion(number, (approx*approx + number) / (2 * approx), tol);
}


//����� ����. ��� �������� �ݺ������� ����ϴ� �κ��� ���ǿ� ���� ������ �˴ϴ�.
float SqrRoot_non_recursion(float number, float approx, float tol)
{
	while (abs(approx*approx - number) > tol)
	{
		approx = (approx*approx + number) / (2 * approx);
	}
	return approx;
}

int main() {
	cout << SqrRoot_recursion(2., 1., 0.1) << endl;
	cout << SqrRoot_non_recursion(2., 1., 0.1) << endl;

	return 0;
}