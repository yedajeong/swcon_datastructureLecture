// Header file for Unsorted List ADT.  
template <class ItemType>
struct NodeType;

// Assumption:  ItemType is a type for which the operators "<" 
// and "==" are defined-either an appropriate built-in type or
// a class that overloads these operators.

template <class ItemType>
class SortedType
{
public:
  SortedType();     // Class constructor	
  ~SortedType();    // Class destructor

  bool IsFull() const;
  // Determines whether list is full.
  // Post: Function value = (list is full)

  int  LengthIs() const;
  // Determines the number of elements in list.
  // Post: Function value = number of elements in list.

  void MakeEmpty();
  // Initializes list to empty state.
  // Post:  List is empty.

  void RetrieveItem(ItemType& item, bool& found);
  // Retrieves list element whose key matches item's key 
  // (if present).
  // Pre:  Key member of item is initialized.
  // Post: If there is an element someItem whose key matches 
  //       item's key, then found = true and item is a copy 
  //       of someItem; otherwise found = false and item is 
  //       unchanged. 
  //       List is unchanged.
  
  void InsertItem(ItemType item); 
  // Adds item to list.
  // Pre:  List is not full.
  //       item is not in list. 
  // Post: item is in list.

  void DeleteItem(ItemType item);
  // Deletes the element whose key matches item's key.
  // Pre:  Key member of item is initialized.
  //       One and only one element in list has a key matching
  //       item's key.
  // Post: No element in list has a key matching item's key.

  void ResetList();
  // Initializes current position for an iteration through the
  // list.
  // Post: Current position is prior to list.

  void GetNextItem(ItemType&);
  // Gets the next element in list.
  // Pre:  Current position is defined.
  //       Element at current position is not last in list.
  // Post: Current position is updated to next position.
  //       item is a copy of element at current position.

  //3-B
  void MergeLists(SortedType<ItemType> &other, SortedType<ItemType> &result);

private:
  NodeType<ItemType>* listData;
  int length;
  NodeType<ItemType>* currentPos;
};
template<class ItemType>
struct NodeType
{
    ItemType info;
    NodeType* next;
};
template <class ItemType>
SortedType<ItemType>::SortedType()  // Class constructor
{
  length = 0;
  listData = NULL;
}
template<class ItemType>
bool SortedType<ItemType>::IsFull() const
// Returns true if there is no room for another ItemType 
//  on the free store; false otherwise.
{
  NodeType<ItemType>* location;
  try
  {
    location = new NodeType<ItemType>;
    delete location;
    return false;
  }
  catch(std::bad_alloc exception)
  {
    return true;
  }
}
template <class ItemType>
int SortedType<ItemType>::LengthIs() const
// Post: Number of items in the list is returned.
{
  return length;
}
template <class ItemType>
void SortedType<ItemType>::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
    NodeType<ItemType>* tempPtr;

    while (listData != NULL)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
    length = 0;
}
template <class ItemType>
void SortedType<ItemType>::RetrieveItem(ItemType& item, 
     bool& found)
{
  bool moreToSearch;
  NodeType<ItemType>* location;

  location = listData;
  found = false;
  moreToSearch = (location != NULL);

  while (moreToSearch && !found)
  {
    if (location->info < item)
    {
      location = location->next;
      moreToSearch = (location != NULL);
    }
    else if (item == location->info)
    {
      found = true;
      item = location->info;
    }
    else
      moreToSearch = false;
  }
}

template <class ItemType>
void SortedType<ItemType>::InsertItem(ItemType item)
{
  NodeType<ItemType>* newNode;  // pointer to node being inserted
  NodeType<ItemType>* predLoc;  // trailing pointer
  NodeType<ItemType>* location; // traveling pointer
  bool moreToSearch;

  location = listData;
  predLoc = NULL;
  moreToSearch = (location != NULL);

  // Find insertion point.
  while (moreToSearch)
  {
    if (location->info < item)
    {
      predLoc = location;
      location = location->next;
      moreToSearch = (location != NULL);
    }
    else
      moreToSearch = false;
  }

  // Prepare node for insertion
  newNode = new NodeType<ItemType>;
  newNode->info = item;
  // Insert node into list.
  if (predLoc == NULL)         // Insert as first
  {
    newNode->next = listData;
    listData = newNode;
  }
  else
  {
    newNode->next = location;
    predLoc->next = newNode;
  }
  length++;
}

/*//5 수정 전
template <class ItemType>
void SortedType<ItemType>::DeleteItem(ItemType item)
// Pre:  item's key has been initialized.
//       An element in the list has a key that matches item's.
// Post: No element in the list has a key that matches item's.
{
    NodeType<ItemType>* location = listData;
    NodeType<ItemType>* tempLocation;

    // Locate node to be deleted.
    if (item == listData->info)
    {
        tempLocation = location;
        listData = listData->next;		// Delete first node.
    }
    else
    {
        while (!(item==(location->next)->info))
          location = location->next;

        // Delete node at location->next
        tempLocation = location->next;
        location->next = (location->next)->next;
    }
    delete tempLocation;
    length--;
}*/

/*//5-A
template <class ItemType>
void SortedType<ItemType>::DeleteItem(ItemType item) {
	NodeType<ItemType>* predLoc = NULL;
	currentPos = listData;

	while (currentPos->info <= item) {
		if (currentPos->info == item) {
			if (predLoc == NULL) //currentPos가 첫 번째 Node 포인팅
				listData = currentPos->next;
			else
				predLoc->next = currentPos->next;
			
			delete currentPos;
			length--;
			break; //중복 아이템x, 하나 삭제하면 종료
		}
		else {
			predLoc = currentPos;
			currentPos = currentPos->next;
		}
	}
}*/

//새로 만든 5-A
template <class ItemType>
void SortedType<ItemType>::DeleteItem(ItemType item) {
	NodeType<ItemType>* location = listData;
	NodeType<ItemType>* predLoc = NULL;

	while (location != NULL || location->info > item) {
		if (location->info == item) {
			if (location == listData) {
				listData = location->next;
				delete location;
				location = listData;
				length--;
				break;
			}
			else {
				predLoc->next = location->next;
				delete location;
				location = predLoc->next;
				length--;
				break;
			}
		}
		predLoc = location;
		location = location->next;
	}
}

/*
//5-B
template <class ItemType>
void SortedType<ItemType>::DeleteItem(ItemType item) {
	NodeType<ItemType>* predLoc = NULL;
	currentPos = listData;

	while (currentPos->info <= item) {
		if (currentPos->info == item) {
			if (predLoc == NULL) {
				listData = currentPos->next;
				delete currentPos;
				currentPos = listData;
			}
			else {
				predLoc->next = currentPos->next;
				delete currentPos;
				currentPos = predLoc->next;
			}
			length--;
		}
		else {
			predLoc = currentPos;
			currentPos = currentPos->next;
		}
	}
}*/

//새로 만든 5-B
template <class ItemType>
void SortedType<ItemType>::DeleteItem(ItemType item) {
	NodeType<ItemType>* location = listData;
	NodeType<ItemType>* predLoc = NULL;

	while (location != NULL && location->info <= item) { //sortedList->정렬, 찾는 아이템보다 크면 더이상 검색 안해도 됨
		if (location->info == item) {
			if (location == listData) {
				listData = location->next;
				delete location;
				location = listData;
			}
			else {
				predLoc->next = location->next;
				delete location;
				location = predLoc->next;
			}
			length--;
		}
		else {
			predLoc = location;
			location = location->next;
		}
	}
}

template <class ItemType>
void SortedType<ItemType>::ResetList()
// Post: Current position has been initialized.
{
  currentPos = NULL;
}
 
template <class ItemType>
void SortedType<ItemType>::GetNextItem(ItemType& item)
// Post:  Current position has been updated; item is 
//        current item.
{
  if (currentPos == NULL)
    currentPos = listData;
  item = currentPos->info; 
  currentPos = currentPos->next;

} 

template <class ItemType>
SortedType<ItemType>::~SortedType()
// Post: List is empty; all items have been deallocated.
{
    NodeType<ItemType>* tempPtr;

    while (listData != NULL)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
  }

/*
//3-B
//원래 currentPos->location(노드타입 가리키는 포인터) / currentPos는 iteration할 때 필요한 포인터니까 다른 포인터변수 만들어서 사용하기
template <class ItemType>
void SortedType<ItemType>::MergeLists(SortedType<ItemType> &other, SortedType<ItemType> &result) {
	NodeType<ItemType>* ptr1 = listData; //host의 LL을 계속 추적
	NodeType<ItemType>* ptr2 = other.listData; //other의 LL을 계속 추적
	
	NodeType<ItemType>* newNode = new NodeType<ItemType>; //새 노드 생성하고 시작
	NodeType<ItemType>* location = newNode;
	result.listData = location;

	while (ptr1 != NULL && ptr2 != NULL) { //둘 다 NULL이 아닐 때만 계속 비교, 하나라도 끝에 다다르면 while문 종료, 남은 list item은 result 뒤에 붙이기
		result.location = newNode; //location: item을 저장할 노드
		newNode = new NodeType<ItemType>; //location의 next를 채우기 위한 새 노드

		if (ptr1->info < ptr2->info) {
			result.location->info = ptr1->info;
			result.location->next = newNode; //정보를 채운 노드(=location이 위치한 노드)와 새 노드를 연결
			ptr1 = ptr1->next;
		}
		else {
			result.location->info = ptr2->info;
			result.location->next = newNode;
			ptr2 = ptr2->next;
		}
		result.length++;
	}
	
	if (ptr1 == NULL && ptr2 != NULL) { //other의 LL item이 더 많은 경우
		while (ptr2 != NULL) {
			result.location = newNode;
			newNode = new NodeType<ItemType>;
			result.location->info = ptr2->info;
			ptr2 = ptr2->next;
			result.length++;
		}
	}

	else if (ptr1 != NULL && ptr2 == NULL) { //host의 LL item이 더 많은 경우
		while (ptr1 != NULL) {
			result.location = newNode;
			newNode = new NodeType<ItemType>;
			result.location->info = ptr1->info;
			ptr1 = ptr1->next;
			result.length++;
		}
	}

	delete newNode;
	result.location->next = NULL;
}*/

//새로 만든 3-B
template <class ItemType>
void SortedType<ItemType>::MergeLists(SortedType<ItemType> &other, SortedType<ItemType> &result) {
	//원래 과제 코드에서는 location 안만들고 result.currentPos로 함, iteration에 영향 없는지? currentPos 바꾸면 안되는 건가..
	NodeType<ItemType>* ptr1 = listData;
	NodeType<ItemType>* ptr2 = other.listData;
	NodeType<ItemType>* newNode = new NodeType<ItemType>;
	NodeType<ItemType>* location = newNode;
	result.listData = location;
	location->next = NULL;

	while (ptr1 != NULL && ptr2 != NULL) {
		if (location->next != NULL) //location->next가 newNode가 아닌 NULL이면 제일 첫 노드!
			location = location->next; //먼저 location을 다음 노드로 옮긴 뒤 info, next 채우기 시작
		if (ptr1->info < ptr2->info) {
			location->info = ptr1->info;
			ptr1 = ptr1->next;
		}

		else if (ptr1->info > ptr2->info) {
			location->info = ptr2->info;
			ptr2 = ptr2->next;
		}

		result.length++;
		newNode = new NodeType<ItemType>;
		location->next = newNode;
	}

	if (ptr1 != NULL) { //host의 데이터가 더 많음
		while (ptr1 != NULL) {
			location = location->next;
			location->info = ptr1->info;
			ptr1 = ptr1->next;
			newNode = new NodeType<ItemType>;
			location->next = newNode;
			result.length++;
		}
	}

	else if (ptr2 != NULL) { //other의 데이터가 더 많음
		while (ptr2 != NULL) {
			location = location->next;
			location->info = ptr2->info;
			ptr2 = ptr2->next;
			newNode = new NodeType<ItemType>;
			location->next = newNode;
			result.length++;
		}
	}

	delete newNode;
	location->next = NULL;

}