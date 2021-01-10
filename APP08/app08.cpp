#include <iostream>
#include <string>
#include "StackTType.h"
using namespace std;


bool isBalance(string inp) {

	// 균형 잡힌 괄호 문자열인지 검사
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

	// Stack을 이용해서 올바른 괄호 문자열인지 검사
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

	// 입력이 빈문자열이 경우
	if (inp == "") {

		return x;
	}
	else {

		// 균형잡힌 괄호 문자열 y, z 분리
		for (int i = 0; i < x.length(); i++) {
			y = x.substr(0, i + 1); //idx 0부터 i+1개만큼 자르기
			z = x.substr(i + 1); //idx i+1부터 끝까지 자르기

			if (isBalance(y))
				break;

		}
		// 올바른 괄호 문자열 처리
		if (isCorrect(y)){
			return y + solution(z);
		}
		// 아닌 경우에 대한 처리
		else {
			//4.1 빈 문자열의 첫 번째 문자로 '(' 붙임
			string temp = "";
			temp += "(";

			//4.2 문자열 z에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙임
			temp += solution(z);

			//4.3  ')'를 다시 붙임 
			temp += ")";

			//4.4 y의 첫 번째와 마지막 문자 제거, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙임
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

