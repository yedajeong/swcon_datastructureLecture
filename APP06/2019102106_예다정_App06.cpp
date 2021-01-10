#include "SortedType.h"
#include <iostream>

using namespace std;

/*
Program Description
App 06
�迭�� ���� N�� �Է¹���
N���� ���ڸ� �Է¹���
N���� ���ڿ� �ùٸ� �迭�� �Ǵ� �迭�� �ִ��� Ȯ��
*/

int main() {
	SortedType<int> StoreArray;
	int arrayLength;

	//TODO 1: ���� �Է��� �޴� �κ�
	cout << "�迭�� ũ��: ";
	cin >> arrayLength;
	int item;
	for (int i = 0; i < arrayLength; i++) {
		cin >> item;
		StoreArray.InsertItem(item);
	}

	//TODO 2: 
	//����Ʈ�� item���� �ùٸ� �迭�� �ִ��� �˻��ϴ� �ڵ� �ۼ�
	int connect = 1, compare = 0;
	bool result = false;
	StoreArray.ResetList();
	StoreArray.GetNextItem(item); //ù ������
	compare = item;
	for (int i = 0; i < arrayLength - 1; i++) { //�ι�° �����ۺ��� �� ����
		StoreArray.GetNextItem(item);
		if (item == compare + 1) { //compare - item ������ ����
			connect++;
		}
		else {
			connect = 1;
		}	

		if (connect == 5) {
			result = true;
			break;
		}
		compare = item;
	}

	//TODO 3:
	//�˻� ����� ����ϴ� �ڵ� �ۼ�
	if (result)
		cout << "O" << endl;
	else
		cout << "X" << endl;

	return 0;

}