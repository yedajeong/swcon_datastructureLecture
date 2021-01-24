#pragma once
// Definition of class PQType, which represents the Priority Queue ADT
class FullPQ{};
class EmptyPQ{};
#include "heap.h"
template<class ItemType>
class PQType
{
public:
  PQType(int);          // parameterized class constructor
  ~PQType();            // class destructor
  //lab11-4
  PQType();
  
  void MakeEmpty();
  // Function: Initializes the queue to an empty state.
  // Post: Queue is empty.
  
  bool IsEmpty() const;
  // Function: Determines whether the queue is empty.
  // Post: Function value = (queue is empty)
  
  bool IsFull() const;
  // Function: Determines whether the queue is full.
  // Post: Function value = (queue is full)
  

	//lab11-4: Enqueue 입력 파라미터 newInfo 추가
  void Enqueue(ItemType newItem, ItemType newInfo);
  // Function: Adds newItem to the rear of the queue.
  // Post: if (the priority queue is full) exception FullPQ is thrown;
  //       else newItem is in the queue.
  

	//lab11-4: Dequeue item에 info[0] 저장
  void Dequeue(ItemType& item);
  // Function: Removes element with highest priority from the queue
  // and returns it in item.
  // Post: If (the priority queue is empty) exception EmptyPQ is thrown;
  //       else highest priority element has been removed from queue.
  //       item is a copy of removed element.
private:
  int length;
  HeapType<ItemType> items;
  int maxItems;
};

template<class ItemType>
PQType<ItemType>::PQType(int max)
{
  maxItems = max;
  items.elements = new ItemType[max];
  
  //lab11-4
  items.info = new ItemType[max];

  length = 0;
}

template<class ItemType>
void PQType<ItemType>::MakeEmpty()
{
  length = 0;
}

template<class ItemType>
PQType<ItemType>::~PQType()
{
  delete[] items.elements;
  
  //lab11-4
  delete[] items.info;
}
template<class ItemType>
void PQType<ItemType>::Dequeue(ItemType& item)
// Post: element with highest priority has been removed 
//       from the queue; a copy is returned in item.
{
  if (length == 0)
    throw EmptyPQ();
  else
  {
    //item = items.elements[0];
	item = items.info[0]; //Dequeue 수정 (item에 info 저장)

    items.elements[0] = items.elements[length-1];
    length--;
    items.ReheapDown(0, length-1);
  }
}

template<class ItemType>
void PQType<ItemType>::Enqueue(ItemType newItem, ItemType newInfo) //Enqueue 수정 (newInfo 추가)
// Post: newItem is in the queue.
{
  if (length == maxItems)
    throw FullPQ();
  else
  {
    length++;
    items.elements[length-1] = newItem;

	//lab11-4
	items.info[length - 1] = newInfo;

    items.ReheapUp(0, length-1);
  }
}
template<class ItemType>
bool PQType<ItemType>::IsFull() const
// Post: Returns true if the queue is full; false, otherwise.
{
  return length == maxItems;
}

template<class ItemType>
bool PQType<ItemType>::IsEmpty() const
// Post: Returns true if the queue is empty; false, otherwise.
{
  return length == 0;
}

