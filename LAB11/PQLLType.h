#pragma once
#include "SortedType.h"

class FullPQLL {};
class EmptyPQLL {};

//lab11-3
//Heap vs Linked Sorted List: 
//Enqueue: O(log2(N)) / O(N)
//Dequeue: O(log2(N)) / O(1)

template<class ItemType>
class PQLLType
{
public:
	PQLLType(int max);
	~PQLLType();
	void MakeEmpty();
	bool IsEmpty() const;
	bool IsFull() const;
	void Enqueue(ItemType newItem);
	void Dequeue(ItemType& item);
	void Print();
	
private:
	int length;
	SortedType<ItemType> linkedlist;
	//int maxItems; -> IsFull() �Լ����� maxItems ��� linkedlist ��ü�� �޼ҵ带 ����ؼ� ���� �˾Ƴ���
};

template<class ItemType>
PQLLType<ItemType>::PQLLType(int max)
{
	length = 0;
}

template<class ItemType>
void PQLLType<ItemType>::MakeEmpty()
{
	length = 0;
	linkedlist.~SortedType();
}

template<class ItemType>
PQLLType<ItemType>::~PQLLType()
{
	linkedlist.~SortedType();
}

//����Ʈ�� �������� �߰��մϴ�.
template<class ItemType>
void PQLLType<ItemType>::Enqueue(ItemType newItem)
{
	if (linkedlist.IsFull())
		throw FullPQLL();
	else
	{
		length++;
		linkedlist.InsertItem(newItem); // ������ �߰�
	}

}

//����Ʈ�� ���� �տ� �ִ� �������� ��������, 
//�ش� �������� �����մϴ�.
template<class ItemType>
void PQLLType<ItemType>::Dequeue(ItemType& item)
{
	if (length == 0)
		throw EmptyPQLL();
	else {
		linkedlist.ResetList(); // iterator�� ����� �غ�
		linkedlist.GetNextItem(item); //����Ʈ���� �������� ���
		linkedlist.DeleteItem(item); //�ش� ������ ����			
		length--;
	}
}