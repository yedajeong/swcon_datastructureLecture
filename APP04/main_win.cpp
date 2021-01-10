 #include "StackType.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string symbol;
    StackType stack;
    bool is_balance = true;

    cin >> symbol;

	// To-Do 1
    // 반복문과 Stack을 이용하여 입력 받은 괄호가 올바른 괄호 문자열인지 판단
    // 아래의 사항은 is_balance가 false
    // 예외사항 1. ( ) 의 짝이 안맞음
    // 예외사항 2. ( 보다 ) 이 많다, 반대의 경우도 동일 => (와 )의 개수 카운팅으로 구현은 X
    // 예외사항 3. (보다 )이 먼저 나와서 먼저 닫아버림

	//'('이면 push, ')'이면 pop 동작 수행
	for (int i = 0; i < symbol.size(); i++) {
		if (symbol[i] == '(')
			stack.Push(symbol[i]);

		else if (stack.IsEmpty()) { //')'이 들어왔는데 지울 '('가 없음
			is_balance = false;
			break;
		}
		else //')'이 들어왔고 지울 '('가 있음
			stack.Pop();
	}

	if (!stack.IsEmpty())
		is_balance = false; //for문 다 돌아도 '('가 다 안지워지고 남아있는 경우


    // 결과 출력
	if (is_balance) cout << "O" << endl;
	else cout << "X" << endl;

    return 0;
}
   