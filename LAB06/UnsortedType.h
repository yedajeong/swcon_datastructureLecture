// Header file for Unsorted List ADT.  
template <class ItemType>
struct NodeType;

// Assumption:  ItemType is a type for which the operators "<" 
// and "==" are defined?ither an appropriate built-in type or
// a class that overloads these operators.

template <class ItemType>
class UnsortedType
{
public:
  UnsortedType();     // Class constructor	
  ~UnsortedType();    // Class destructor

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

  void GetNextItem(ItemType& item);
  // Gets the next element in list.
  // Pre:  Current position is defined.
  //       Element at current position is not last in list.
  // Post: Current position is updated to next position.
  //       item is a copy of element at current position.

  //3-D
  void MergeLists(UnsortedType<ItemType> &other, UnsortedType<ItemType> &result);

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
UnsortedType<ItemType>::UnsortedType()  // Class constructor
{
  length = 0;
  listData = NULL;
}

template <class ItemType>
UnsortedType<ItemType>::~UnsortedType()
// Class destructor
{
  MakeEmpty();
}  
template<class ItemType>
bool UnsortedType<ItemType>::IsFull() const
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
int UnsortedType<ItemType>::LengthIs() const
// Post: Number of items in the list is returned.
{
  return length;
}
template <class ItemType>
void UnsortedType<ItemType>::MakeEmpty()
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
void UnsortedType<ItemType>::RetrieveItem(ItemType& item, 
    bool& found)
// Pre:  Key member(s) of item is initialized.
// Post: If found, item's key matches an element's key in the 
//       list and a copy of that element has been stored in item;
//       otherwise, item is unchanged. 
{
    bool moreToSearch;
    NodeType<ItemType>* location;

    location = listData;
    found = false;
    moreToSearch = (location != NULL);

    while (moreToSearch && !found)
    {
        if (item == location->info)
        {
            found = true;
            item = location->info;
        }
        else
        {
            location = location->next;
            moreToSearch = (location != NULL);
        }
    }
}
template <class ItemType>
void UnsortedType<ItemType>::InsertItem(ItemType item)
// item is in the list; length has been incremented.
{
    NodeType<ItemType>* location;

    location = new NodeType<ItemType>;
    location->info = item;
    location->next = listData;
    listData = location;
    length++;
}

/* //4 ���� ��
template <class ItemType>
void UnsortedType<ItemType>::DeleteItem(ItemType item)
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
}
*/

/*4-A
template <class ItemType>
void UnsortedType<ItemType>::DeleteItem(ItemType item) {
	NodeType<ItemType>* predLoc = NULL;
	currentPos = listData;

	while (currentPos != NULL) {
		if (currentPos->info == item) {
			if (predLoc == NULL) //currentPos�� ù ��° Node ������
				listData = currentPos->next;
			else
				predLoc->next = currentPos->next;

			delete currentPos;
			length--;
			break;
		}
		else {
			predLoc = currentPos;
			currentPos = currentPos->next;
		}
	}
} */

//���� ���� 4-A
template <class ItemType>
void UnsortedType<ItemType>::DeleteItem(ItemType item) {
	NodeType<ItemType>* predLoc = NULL;
	NodeType<ItemType>* location = listData;

	while (location != NULL) {
		if (location->info == item) {
			if (location == listData) { //���� ù ��° ����� ���
				listData = location->next;
				delete location;
				length--;
				break;
			}
			else {
				predLoc->next = location->next;
				delete location;
				length--;
				break;
			}
		}
		predLoc = location;
		location = location->next;
	}
}

/*
//4-B
template <class ItemType>
void UnsortedType<ItemType>::DeleteItem(ItemType item) {
	NodeType<ItemType>* predLoc = NULL;
	currentPos = listData;

	while (currentPos != NULL) {
		if (currentPos->info == item) {
			if (predLoc == NULL) { //currentPos�� ù ��° Node ������
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
}
*/

//���� ���� 4-B
template <class ItemType>
void UnsortedType<ItemType>::DeleteItem(ItemType item) {
	NodeType<ItemType>* predLoc = NULL;
	NodeType<ItemType>* location = listData;

	while (location != NULL) {
		if (location->info == item) {
			if (predLoc == NULL) { //���� ù ��° ����� ���
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
void UnsortedType<ItemType>::ResetList()
// Post: Current position has been initialized.
{
  currentPos = NULL;
}
 
template <class ItemType>
void UnsortedType<ItemType>::GetNextItem(ItemType& item)
// Post:  Current position has been updated; item is current item.
{
  if (currentPos == NULL)
    currentPos = listData;
  else
    currentPos = currentPos->next;
  item = currentPos->info;
} 

/*
//3-D
template <class ItemType>
void UnsortedType<ItemType>::MergeLists(UnsortedType<ItemType> &other, UnsortedType<ItemType> &result) {
	NodeType<ItemType>* newNode = new NodeType<ItemType>;
	NodeType<ItemType>* ptr = listData;
	result.currentPos = newNode;

	//host�� item���� �ֱ�
	while (ptr != NULL) {
		if (result.listData == NULL) //result�� �ƹ� item�� ���� ��� listData�� �ƹ��͵� ���������� ����
			result.listData = result.currentPos;

		result.currentPos = newNode;
		newNode = new NodeType<ItemType>;

		result.currentPos->info = ptr->info;
		result.currentPos->next = newNode;

		ptr = ptr->next;
		result.length++;
	}

	//other�� item �ֱ�
	ptr = other.listData;
	while (ptr != NULL) {
		//result�� host�� item�� �����Ƿ� result.listData�� ���̻� NULL�� �ƴ�
		result.currentPos = newNode;
		newNode = new NodeType<ItemType>;

		result.currentPos->info = ptr->info;
		result.currentPos->next = newNode;

		ptr = ptr->next;
		result.length++;
	}

	delete newNode;
	result.currentPos->next = NULL;
}
*/

//���� ���� 3-D
template <class ItemType>
void UnsortedType<ItemType>::MergeLists(UnsortedType<ItemType> &other, UnsortedType<ItemType> &result) {
	NodeType<ItemType>* ptr1 = listData;
	NodeType<ItemType>* ptr2 = other.listData;
	NodeType<ItemType>* newNode = new NodeType<ItemType>;
	NodeType<ItemType>* location = newNode;
	result.listData = location;
	location->next = NULL;

	while (ptr1 != NULL) {
		if (location->next != NULL)
			location = location->next; //result�� ù ��� �ƴϸ� ���� ���� �Ѿ��, ù ���� ù ������ ä���
		location->info = ptr1->info;
		ptr1 = ptr1->next;
		newNode = new NodeType<ItemType>;
		location->next = newNode;
		result.length++;
	}

	while (ptr2 != NULL) {
		location = location->next;
		location->info = ptr2->info;
		ptr2 = ptr2->next;
		newNode = new NodeType<ItemType>;
		location->next = newNode;
		result.length++;
	}

	delete newNode;
	location->next = NULL;
}