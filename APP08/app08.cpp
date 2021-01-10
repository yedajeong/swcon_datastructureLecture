#include <iostream>
#include <string>
#include "StackTType.h"
using namespace std;


bool isBalance(string inp) {

	// ���� ���� ��ȣ ���ڿ����� �˻�
	char ch[sizeof(inp) / sizeof(inp[0])];
	strcpy_s(ch, inp.c_str());
	
	int open = 0, close = 0;
	for (int i = 0; i < inp.length(); i++) {
		if (ch[i] == '(')
			open++;
		else if (ch[i] == ')')
			close++;
	}

	if (open == close)
		return true;
	else
		return false;
}

bool isCorrect(string inp) {

	// Stack�� �̿��ؼ� �ùٸ� ��ȣ ���ڿ����� �˻�
	StackType<char> stack;
	char ch[sizeof(inp) / sizeof(inp[0])];
	strcpy_s(ch, inp.c_str());

	for (int i = 0; i < inp.length(); i++) {
		if (ch[i] == '(')
			stack.Push(ch[i]);
		else if (ch[i] == ')') {
			if (stack.IsEmpty())
				return false;
			else
				stack.Pop();
		}
	}

	return true;
}

string solution(string inp) {


	string x = inp;
	string y = "";
	string z = "";
	string answer = "";

	// �Է��� ���ڿ��� ���
	if (inp == "") {

		return x;
	}
	else {

		// �������� ��ȣ ���ڿ� y, z �и�
		for (int i = 0; i < x.length(); i++) {
			y = x.substr(0, i + 1); //idx 0���� i+1����ŭ �ڸ���
			z = x.substr(i + 1); //idx i+1���� ������ �ڸ���

			if (isBalance(y))
				break;

		}
		// �ùٸ� ��ȣ ���ڿ� ó��
		if (isCorrect(y)){
			return y + solution(z);
		}
		// �ƴ� ��쿡 ���� ó��
		else {
			//4.1 �� ���ڿ��� ù ��° ���ڷ� '(' ����
			string temp = "";
			temp += "(";

			//4.2 ���ڿ� z�� ���� 1�ܰ���� ��������� ������ ��� ���ڿ��� �̾� ����
			temp += solution(z);

			//4.3  ')'�� �ٽ� ���� 
			temp += ")";

			//4.4 y�� ù ��°�� ������ ���� ����, ������ ���ڿ��� ��ȣ ������ ����� �ڿ� ����
			y = y.substr(1, y.length() - 2);
			string reverseY = "";
			for (int i = 0; i < y.length(); i++) {
				if (y[i] == '(')
					reverseY += ")";
				else if (y[i] == ')')
					reverseY += "(";
			}
			temp += reverseY;
			return temp;
		}

	}


	return answer;
}

int main() {

	string inp;
	string answer;

	cin >> inp;

	answer = solution(inp);

	cout << answer;

	return 0;
}

