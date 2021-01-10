#include "SortedType.h"
#include <iostream>

using namespace std;

/*
Program Description
App 06
배열의 길이 N을 입력받음
N개의 숫자를 입력받음
N개의 숫자에 올바른 배열이 되는 배열이 있는지 확인
*/

int main() {
	SortedType<int> StoreArray;
	int arrayLength;

	//TODO 1: 숫자 입력을 받는 부분
	cout << "배열의 크기: ";
	cin >> arrayLength;
	int item;
	for (int i = 0; i < arrayLength; i++) {
		cin >> item;
		StoreArray.InsertItem(item);
	}

	//TODO 2: 
	//리스트의 item들이 올바른 배열이 있는지 검사하는 코드 작성
	int connect = 1, compare = 0;
	bool result = false;
	StoreArray.ResetList();
	StoreArray.GetNextItem(item); //첫 아이템
	compare = item;
	for (int i = 0; i < arrayLength - 1; i++) { //두번째 아이템부터 비교 시작
		StoreArray.GetNextItem(item);
		if (item == compare + 1) { //compare - item 순으로 연결
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
	//검사 결과를 출력하는 코드 작성
	if (result)
		cout << "O" << endl;
	else
		cout << "X" << endl;

	return 0;

}