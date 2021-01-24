#include "TreeType.h"
#include "UnsortedType.h"

bool MatchingItem_Unsorted(TreeType &tree, UnsortedType<ItemType> &list)
{
	int list_length = list.LengthIs();
	int tree_length = tree.LengthIs();

	if (list_length != tree_length) //길이를 먼저 비교, 같은지 검사한다.
	{
		return false;
	}
	else
	{
		ItemType item;
		bool found;

		list.ResetList(); //list에 iterator를 사용할 준비를 한다
		for (int i = 0; i < list_length; i++) {
			list.GetNextItem(item); // list에서 하나의 아이템을 가져온다
			tree.RetrieveItem(item, found); //트리에 해당 아이템이 있는지 검색. O(logN)이 걸림.
			if (!found)
				return false;
		}
		return true;
	}
}

bool MatchingItem_Tree(TreeType &tree, UnsortedType<ItemType> &list)
{
	int list_length = list.LengthIs();
	int tree_length = tree.LengthIs();

	if (list_length != tree_length) //길이를 먼저 비교, 같은지 검사한다.
	{
		return false;
	}
	else
	{
		ItemType item;
		bool found;

		//아래 구현과 비교해 볼 때 수행시간 면에서 무슨 차이가 있을까?

		tree.ResetTree(IN_ORDER); // tree에 iterator를 사용할 준비를 한다
		for (int i = 0; i < list_length; i++) {
			tree.GetNextItem(item, IN_ORDER, found); // tree에서 하나의 아이템을 가져온다
			list.RetrieveItem(item, found); // list에 해당 아이템이 있는 검색. O(N)이 걸림.
			if (!found)
				return false;
		}
		return true;
	}
}

int main() {
	TreeType tree;
	UnsortedType<char> list;

	tree.InsertItem('g');
	tree.InsertItem('b');
	tree.InsertItem('k');
	tree.InsertItem('a');
	tree.InsertItem('e');
	tree.InsertItem('h');
	tree.InsertItem('z');

	list.InsertItem('g');
	list.InsertItem('b');
	list.InsertItem('k');
	list.InsertItem('a');
	list.InsertItem('e');
	list.InsertItem('h');
	list.InsertItem('z');

	std::cout << MatchingItem_Unsorted(tree, list) << std::endl;
	std::cout << MatchingItem_Tree(tree, list);

	return 0;
}