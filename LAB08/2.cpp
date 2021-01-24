#include <iostream>

using namespace std;

int Fibonacci_recursive(int n) {
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return Fibonacci_recursive(n - 2) + Fibonacci_recursive(n - 1);
}

int Fibonacci_non_rec(int n) {
	int bef = 0, aft = 1, result;

	for (int i = 2; i <= n; i++) {
		result = bef + aft;
		bef = aft;
		aft = result;
	}

	return result;
}

//non_recursive �Լ��� ���� �鿡�� �� ȿ�����̶�� �����Ѵ�.
//�ֳ��ϸ� ����Լ��� n�� ������ ���� �Լ� call�� ������� �׸�ŭ ����ϴ� �޸� ������ �þ�� �����̴�.
int main() {
	cout << Fibonacci_recursive(10) << endl;
	cout << Fibonacci_non_rec(10) << endl;

	return 0;
}