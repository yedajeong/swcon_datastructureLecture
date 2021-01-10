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
    // �ݺ����� Stack�� �̿��Ͽ� �Է� ���� ��ȣ�� �ùٸ� ��ȣ ���ڿ����� �Ǵ�
    // �Ʒ��� ������ is_balance�� false
    // ���ܻ��� 1. ( ) �� ¦�� �ȸ���
    // ���ܻ��� 2. ( ���� ) �� ����, �ݴ��� ��쵵 ���� => (�� )�� ���� ī�������� ������ X
    // ���ܻ��� 3. (���� )�� ���� ���ͼ� ���� �ݾƹ���

	//'('�̸� push, ')'�̸� pop ���� ����
	for (int i = 0; i < symbol.size(); i++) {
		if (symbol[i] == '(')
			stack.Push(symbol[i]);

		else if (stack.IsEmpty()) { //')'�� ���Դµ� ���� '('�� ����
			is_balance = false;
			break;
		}
		else //')'�� ���԰� ���� '('�� ����
			stack.Pop();
	}

	if (!stack.IsEmpty())
		is_balance = false; //for�� �� ���Ƶ� '('�� �� ���������� �����ִ� ���


    // ��� ���
	if (is_balance) cout << "O" << endl;
	else cout << "X" << endl;

    return 0;
}
   