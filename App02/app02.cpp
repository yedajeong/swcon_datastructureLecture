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
			item.Initialize(num); //�Է¹��� int�� item��ü�� value�� ����
			list.InsertItem(item); //item�� list�� �߰�
		}
		
		else {
			list.DeleteItem(item); //���� �ֱ� item->info�迭�� ���� ���� �������
			list.ResetList(); //�ٽ� ������ item�� ������Ʈ�ϱ����� pos=-1
			for (int i = 0; i < list.LengthIs(); i++)
				list.GetNextItem(item); //item.value���� ������ �� ���� �ֱٿ� ���� ���� ����
		}
	}

	cout << endl << list.Total() << endl;

}