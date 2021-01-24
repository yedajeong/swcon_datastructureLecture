#include <fstream>
#include "TreeType.h"
#include "SortedType.h"

using namespace std;

void MakeTree(TreeType &tree, SortedType<int> &list);
void AddElement(TreeType& tree, int Array[], int from, int to);

int main() {
	SortedType<int> list;
	TreeType tree;

	list.InsertItem(1);
	list.InsertItem(2);
	list.InsertItem(3);
	list.InsertItem(4);
	list.InsertItem(5);
	list.InsertItem(6);
	list.InsertItem(7);

	MakeTree(tree, list);

	ofstream fout("4_result.txt");
	tree.Print(fout);

	return 0;
}

void MakeTree(TreeType &tree, SortedType<int> &list)
{

	int length = list.LengthIs();  //리스트 크기를 얻는다
	int * array = new int[length];  //동적 배열 할당
	int item_info;
	int i;

	list.ResetList();

	for (i = 0; i < length; i++)
	{
		list.GetNextItem(item_info);
		array[i] = item_info;
	}

	AddElement(tree, array, 0, length - 1);

	delete[] array;  // 동적 배열 삭제
}

void AddElement(TreeType& tree, int Array[], int front, int rear)
{
	int mid; //중간 값을 기록하는 변수
	if (front <= rear) { //함수의 종료조건
		mid = (front + rear) / 2;
		tree.InsertItem(Array[mid]);
		cout << Array[mid] << "\t";
		AddElement(tree, Array, front, mid - 1);
		AddElement(tree, Array, mid + 1, rear);
	}
}
