#include <iostream>
#include "unsorted.h"

using namespace std;

int main() {
	ItemType item;
	UnsortedType list;
	int k, num;
	cin >> k;

	for (int count = 0; count < k; count++) {
		cin >> num;
		if (num != 0) {
			item.Initialize(num); //입력받은 int를 item객체의 value에 저장
			list.InsertItem(item); //item을 list에 추가
		}
		
		else {
			list.DeleteItem(item); //제일 최근 item->info배열의 가장 끝에 들어있음
			list.ResetList(); //다시 마지막 item을 업데이트하기위해 pos=-1
			for (int i = 0; i < list.LengthIs(); i++)
				list.GetNextItem(item); //item.value에는 삭제한 후 제일 최근에 넣은 값이 저장
		}
	}

	cout << endl << list.Total() << endl;

}