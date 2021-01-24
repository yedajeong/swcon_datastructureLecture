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

  //lab08-1
  void PrintSumSquares();

  //lab08-5
  void Sort(NodeType<ItemType>* location);
  void PrintSort();
 
//lab08-5
protected:
  //NodeType<ItemType>* MinLoc(NodeType<ItemType>* location, NodeType<ItemType>* minLoc);
  NodeType<ItemType>* MinLoc(NodeType<ItemType> *location);
	

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

//lab08-1
template <class ItemType>
void UnsortedType<ItemType>::PrintSumSquares()
{
	using namespace std;

	//a, b, c, d, e�� ������ ���� �� ���
	//cout << SumSquares_a(listData) << endl;  //  a �� �Լ�
	//cout << SumSquares_b(listData) << endl;  //  b �� �Լ�
	//cout << SumSquares_c(listData) << endl;  //  c �� �Լ�
	//cout << SumSquares_d(listData) << endl;  //  d �� �Լ�
	cout << SumSquares_e(listData) << endl;  //  e �� �Լ�
};

//base case�� ���� �Լ��� ������ڸ��� return���� ���� 0�� ��ȯ�ϰ� ����ȴ�.
//���� ��� ���� ������ list == NULL �̸� 0�� return �ϵ��� �����Ѵ�.
template <class ItemType>
ItemType SumSquares_a(NodeType<ItemType>* list) {
	if (list == NULL)
		return 0;
	else if (list != NULL)
		return (list->info * list->info) + SumSquares_a(list->next);
}

//SumSquares�� ��� �Լ��� �ƴϰ� sum�� info�� ���� ���� ���ϰ� ���� �ʴ�.
template <class ItemType>
ItemType SumSquares_b(NodeType<ItemType>* list) {
	int sum = 0;
	if (list != NULL) {
		sum = list->info * list->info;
		sum += SumSquares_b(list->next);
	}
	else if (list == NULL)
		sum += 0;
	return sum;
}

//������ ���� ����
template <class ItemType>
ItemType SumSquares_c(NodeType<ItemType>* list) {
	if (list == NULL)
		return 0;
	else
		return list->info * list->info + SumSquares_c(list->next);
}

//������ ���� ����
template <class ItemType>
ItemType SumSquares_d(NodeType<ItemType>* list) {
	if (list->next == NULL)
		return list->info * list->info;
	else
		return list->info * list->info + SumSquares_d(list->next);
}

//general case�� return ���� �������� �ʾ� ������ ��带 ������ �� ���ķ� 0�� ����ؼ� ���ϰ� �ȴ�.
template <class ItemType>
ItemType SumSquares_e(NodeType<ItemType>* list) {
	if (list == NULL)
		return 0;
	else {
		return list->info * list->info + SumSquares_e(list->next);
	}
}


//lab08-5

//int Ÿ���� �ӽ� ���� ������ �����.
//MinLoc�Լ��� ���� ���� ���� ��ġ�� �ľ�, �� ���� �ӽ� ���� ������ �����Ѵ�.
//���� ����Ű�� �ִ� ����� info�� MinLoc�� info�� �����ϰ�, �ӽ� ������ 
//�ּҰ����� location�� info�� �ٲ㰡�鼭 ������ �����Ѵ�.

//Sort�Լ��� �Ķ���ʹ� listData�� �Ѱ��ش�.
//***���� ���� location�� ������ ����̰ų� ����Ʈ�� minimum ���� ���´ٸ� ��� �ɱ�? �� �� efficient�ϰ� �����Ϸ���?
template <class ItemType>
void UnsortedType<ItemType>::Sort(NodeType<ItemType> *location)
{
	NodeType<ItemType> *minPtr; //�ּҰ��� ����Ű�� ������
	ItemType temp;

	if (location != NULL && location->next!=NULL)  //empty ����Ʈ�� �ƴϰ� location�� ������ ��尡 �ƴ� ���_general case
	{
		//minPtr = MinLoc(location, location);  // ***
		minPtr = MinLoc(location);
		if (minPtr == location)  //���� location�� ����Ʈ�� miinmum���� ������ ���
			Sort(location->next);
		else {
			temp = minPtr->info;
			minPtr->info = location->info;
			location->info = temp;
			Sort(location->next);
		}
		//���� location�� ������ ���� do nothing
	}
	// base case�� do nothing, base case: �� ����Ʈ or ������ ��� �� ��� Sort�ʿ� x
}

/* //***�κ� ���� ��
template <class ItemType>
void UnsortedType<ItemType>::Sort(NodeType<ItemType> *location)
{
	NodeType<ItemType> *minPtr; //�ּҰ��� ����Ű�� ������
	ItemType temp;

	if (location != NULL) // empty ����Ʈ�� �ƴϸ�_general case
	{
		minPtr = MinLoc(location, location);  // ***
		//minPtr = MinLoc(location);
		temp = minPtr->info;
		minPtr->info = location->info;
		location->info = temp;
		Sort(location->next);
	}
	// base case�� do nothing
}
*/


/* //MinLoc 1��° ����
//�Լ� ȣ�� �� �Ķ���ͷ� Ŭ���� ���� ������ listData�� �Ѱ����� �Ѵ�.
// -> Sort �Լ� ù ��° ȣ�� �� listData ����, Sort�ȿ��� minLoc ȣ�� �� listData �״�� �Ѿ
template <class ItemType>
NodeType<ItemType>* UnsortedType<ItemType>::MinLoc(NodeType<ItemType> *location, NodeType<ItemType>* minPtr)
{
	if (location != NULL) //general case
	{
		if (location->info < minPtr->info)
			minPtr = location;
		return MinLoc(location->next, minPtr); // ���� ���� �Լ� ��� ȣ��
	}
	else  // base case
		return minPtr;
}
*/

//MinLoc 2��° ����
//�Լ� ȣ�� �� �Ķ���ͷ� Ŭ���� ���� ������ listData�� �Ѱ����� �Ѵ�.
template <class ItemType>
NodeType<ItemType>* UnsortedType<ItemType>::MinLoc(NodeType<ItemType> *location) {
	if (location == NULL) // base case: ���� ����Ʈ�� empty (listData�� NULL) �� ��
		return NULL;
	else if (location->next == NULL) // another base case : ����Ʈ�� ������ ��� 
		return location;
	else { // general case: location != NULL
		NodeType<ItemType> *minPtr = MinLoc(location->next);
		if (location->info < minPtr->info) // minPtr�� ���� NULL�� �ƴ�. Why? -> ���� �� ������ �����ؼ� ���� ����� ���س����� ���� 
			minPtr = location;
		return minPtr;
	}
}


template <class ItemType>
void UnsortedType<ItemType>::PrintSort()
{
	using namespace std;
	NodeType<ItemType>* location = listData;

	Sort(listData);

	while (location != NULL) {
		cout << location->info << endl;
		location = location->next;
	}
};