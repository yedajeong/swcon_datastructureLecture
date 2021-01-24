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
	//int maxItems; -> IsFull() 함수에서 maxItems 대신 linkedlist 객체의 메소드를 사용해서 개수 알아내기
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

//리스트에 아이템을 추가합니다.
template<class ItemType>
void PQLLType<ItemType>::Enqueue(ItemType newItem)
{
	if (linkedlist.IsFull())
		throw FullPQLL();
	else
	{
		length++;
		linkedlist.InsertItem(newItem); // 아이템 추가
	}

}

//리스트의 가장 앞에 있는 아이템을 가져오고, 
//해당 아이템을 삭제합니다.
template<class ItemType>
void PQLLType<ItemType>::Dequeue(ItemType& item)
{
	if (length == 0)
		throw EmptyPQLL();
	else {
		linkedlist.ResetList(); // iterator를 사용할 준비
		linkedlist.GetNextItem(item); //리스트에서 아이템을 얻고
		linkedlist.DeleteItem(item); //해당 아이템 삭제			
		length--;
	}
}