#include "TreeType.h"
#include "UnsortedType.h"

bool MatchingItem_Unsorted(TreeType &tree, UnsortedType<ItemType> &list)
{
	int list_length = list.LengthIs();
	int tree_length = tree.LengthIs();

	if (list_length != tree_length) //���̸� ���� ��, ������ �˻��Ѵ�.
	{
		return false;
	}
	else
	{
		ItemType item;
		bool found;

		list.ResetList(); //list�� iterator�� ����� �غ� �Ѵ�
		for (int i = 0; i < list_length; i++) {
			list.GetNextItem(item); // list���� �ϳ��� �������� �����´�
			tree.RetrieveItem(item, found); //Ʈ���� �ش� �������� �ִ��� �˻�. O(logN)�� �ɸ�.
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

	if (list_length != tree_length) //���̸� ���� ��, ������ �˻��Ѵ�.
	{
		return false;
	}
	else
	{
		ItemType item;
		bool found;

		//�Ʒ� ������ ���� �� �� ����ð� �鿡�� ���� ���̰� ������?

		tree.ResetTree(IN_ORDER); // tree�� iterator�� ����� �غ� �Ѵ�
		for (int i = 0; i < list_length; i++) {
			tree.GetNextItem(item, IN_ORDER, found); // tree���� �ϳ��� �������� �����´�
			list.RetrieveItem(item, found); // list�� �ش� �������� �ִ� �˻�. O(N)�� �ɸ�.
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