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

//non_recursive 함수가 성능 면에서 더 효율적이라고 생각한다.
//왜냐하면 재귀함수는 n이 증가할 수록 함수 call이 잦아지고 그만큼 사용하는 메모리 공간도 늘어나기 때문이다.
int main() {
	cout << Fibonacci_recursive(10) << endl;
	cout << Fibonacci_non_rec(10) << endl;

	return 0;
}