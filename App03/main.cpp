#include <iostream>
#include "SortedType.h"

using namespace std;

int main()
{
    SortedType sorted_list;
    
    
    // Input row, col, index
    ItemType temp;
    int row, col;
    int index;
    cin >> row >> col;
    cin >> index;
    
    // To-Do 2
    // row, col만큼의 2차원 ItemType array를 할당
    ItemType** data = NULL;
	data = new ItemType*[row];
	for (int i = 0; i < row; i++)
		data[i] = new ItemType[col];
    
    // To-Do 3
    // sorted_list에 item insert 후 resetlist
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			temp.Initialize((i + 1)*(j + 1));
			data[i][j] = temp;
			sorted_list.InsertItem(temp);
		}
	}

	for (int i = 0; i < row; i++)
		delete[] data[i];
	delete[] data;

    sorted_list.ResetList();
    
    // To-Do 4
    // Get next item으로 해당인덱스로 접근
	for (int i = 0; i < index; i++)
		sorted_list.GetNextItem(temp);
    
    // To-Do 5
    // 출력
	temp.Print(cout);

    return 0;
}
