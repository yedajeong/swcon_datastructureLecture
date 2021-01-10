// Definition of class PQType, which represents the Priority Queue ADT
class FullPQ{};
class EmptyPQ{};
#include "SortedType.h"

template<class ItemType>
class PQType
{
public:
  PQType();          // parameterized class constructor
  ~PQType();            // class destructor
  
  void MakeEmpty();
  // Function: Initializes the queue to an empty state.
  // Post: Queue is empty.
  
  bool IsEmpty() const;
  // Function: Determines whether the queue is empty.
  // Post: Function value = (queue is empty)
  
  bool IsFull() const;
  // Function: Determines whether the queue is full.
  // Post: Function value = (queue is full)
  
  void Enqueue(int priority, ItemType newItem);
  // Function: Adds newItem to the rear of the queue.
  // Post: if (the priority queue is full) exception FullPQ is thrown;
  //       else newItem is in the queue.
  
  //void Dequeue(ItemType& item);
  void Dequeue(ItemType& item, int priority);
  // Function: Removes element with highest priority from the queue
  // and returns it in item.
  // Post: If (the priority queue is empty) exception EmptyPQ is thrown;
  //       else highest priority element has been removed from queue.
  //       item is a copy of removed element.

	//app11
    void Ordering(int** orderList, int M);
	void Swap(NodeType<ItemType>* loc1, NodeType<ItemType>* loc2);
	void PrioritySorting(SortedType<ItemType>& list);

private:
  int length;
 SortedType<ItemType> linkedList;
 SortedType<ItemType> priorSorted;
  //int maxItems;
};

template<class ItemType>
PQType<ItemType>::PQType()
{
  length = linkedList.LengthIs();
}

template<class ItemType>
void PQType<ItemType>::MakeEmpty()
{
  length = 0;
}

template<class ItemType>
PQType<ItemType>::~PQType()
{
	linkedList.MakeEmpty();
}

template<class ItemType>
void PQType<ItemType>::Ordering(int** orderList, int M)
{
    // Input Your Code
    // You only need to write the code that changes the priority according to the orderlist.
	int first, later, firstPrior = 0, laterPrior = 0, search, fixed;
	NodeType<ItemType>* location;

	for (int i = 0; i < M; i++)
	{
		first = orderList[i][0];
		later = orderList[i][1];

		//priority 찾기
		location = linkedList.listData;
		while (location != NULL)
		{
			if (location->info == first)
				firstPrior = location->priority;
			else if (location->info == later)
				laterPrior = location->priority;
			location = location->next;
		}

		if (first > later && firstPrior < laterPrior)
		{
			//Swap
			location = linkedList.listData;
			while (location != NULL)
			{
				if (location->info == first)
					location->priority = laterPrior;
				else if (location->info == later)
					location->priority = firstPrior;
				location = location->next;
			}
		}

		//first고정, later부터 탐색
		search = later;
		fixed = first;
		location = linkedList.listData;
		NodeType<ItemType>* compareLoc = location;
		while (location != NULL)
		{
			if (location->info == search)
			{
				compareLoc = location->next;
				break;
			}
			else
				location = location->next;
		}

		while (compareLoc != NULL)
		{
			if (compareLoc->info == fixed)
			{
				compareLoc = compareLoc->next;
				continue;
			}
			else if (location->priority < compareLoc->priority)
				Swap(location, compareLoc);
			compareLoc = compareLoc->next;
		}

		//이전 조건 만족시키는지 확인
		if (i != 0)
		{
			for (int j = 0; j < i; j++)
			{
				first = orderList[j][0];
				later = orderList[j][1];

				//priority 찾기
				location = linkedList.listData;
				while (location != NULL)
				{
					if (location->info == first)
						firstPrior = location->priority;
					else if (location->info == later)
						laterPrior = location->priority;
					location = location->next;
				}

				if (first > later && firstPrior < laterPrior)
				{
					//Swap
					location = linkedList.listData;

					while (location != NULL)
					{
						if (location->info == first)
							location->priority = laterPrior;
						else if (location->info == later)
							location->priority = firstPrior;
						location = location->next;
					}
				}
			}
		}
	}
}

//priority swap함수
template<class ItemType>
void PQType<ItemType>::Swap(NodeType<ItemType>* loc1, NodeType<ItemType>* loc2)
{
	int temp = loc1->priority;
	loc1->priority = loc2->priority;
	loc2->priority = temp;
}

/*
template<class ItemType>
void PQType<ItemType>::Dequeue(ItemType& item)
// Post: element with highest priority has been removed 
//       from the queue; a copy is returned in item.
{
  if (length == 0)
    throw EmptyPQ();
  else
  {
	
	priorSorted.ResetList();
    priorSorted.GetNextItem(item);
	priorSorted.DeleteItem(item);
    length--;
  
  }
}
*/

template<class ItemType>
void PQType<ItemType>::Dequeue(ItemType& item, int prior)
// Post: element with highest priority has been removed 
//       from the queue; a copy is returned in item.
{
	if (length == 0)
		throw EmptyPQ();
	else
	{
		NodeType<ItemType>* location = linkedList.listData;
		while (location != NULL)
		{
			if (location->priority == prior)
			{
				item = location->info;
				linkedList.DeleteItem(item);
				length--;
				break;
			}
			else
				location = location->next;
		}
	}
}

template<class ItemType>
void PQType<ItemType>::Enqueue(int priority, ItemType newItem)
// Post: newItem is in the queue.
{
  if (linkedList.IsFull())
    throw FullPQ();
  else
  {
    length++;
	linkedList.InsertItem(priority, newItem);
  }
}
template<class ItemType>
bool PQType<ItemType>::IsFull() const
// Post: Returns true if the queue is full; false, otherwise.
{
  return linkedList.IsFull();
}

template<class ItemType>
bool PQType<ItemType>::IsEmpty() const
// Post: Returns true if the queue is empty; false, otherwise.
{
  return length == 0;
}

