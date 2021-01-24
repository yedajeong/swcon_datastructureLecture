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

	//a, b, c, d, e의 문제를 수정 후 출력
	//cout << SumSquares_a(listData) << endl;  //  a 번 함수
	//cout << SumSquares_b(listData) << endl;  //  b 번 함수
	//cout << SumSquares_c(listData) << endl;  //  c 번 함수
	//cout << SumSquares_d(listData) << endl;  //  d 번 함수
	cout << SumSquares_e(listData) << endl;  //  e 번 함수
};

//base case가 없어 함수가 실행되자마자 return문을 만나 0을 반환하고 종료된다.
//따라서 재귀 종료 조건인 list == NULL 이면 0을 return 하도록 수정한다.
template <class ItemType>
ItemType SumSquares_a(NodeType<ItemType>* list) {
	if (list == NULL)
		return 0;
	else if (list != NULL)
		return (list->info * list->info) + SumSquares_a(list->next);
}

//SumSquares가 재귀 함수가 아니고 sum에 info의 제곱 값을 더하고 있지 않다.
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

//수정할 사항 없음
template <class ItemType>
ItemType SumSquares_c(NodeType<ItemType>* list) {
	if (list == NULL)
		return 0;
	else
		return list->info * list->info + SumSquares_c(list->next);
}

//수정할 사항 없음
template <class ItemType>
ItemType SumSquares_d(NodeType<ItemType>* list) {
	if (list->next == NULL)
		return list->info * list->info;
	else
		return list->info * list->info + SumSquares_d(list->next);
}

//general case의 return 값이 더해지지 않아 마지막 노드를 만났을 때 이후로 0만 계속해서 곱하게 된다.
template <class ItemType>
ItemType SumSquares_e(NodeType<ItemType>* list) {
	if (list == NULL)
		return 0;
	else {
		return list->info * list->info + SumSquares_e(list->next);
	}
}


//lab08-5

//int 타입의 임시 저장 공간을 만든다.
//MinLoc함수를 통해 작은 값의 위치를 파악, 그 값을 임시 저장 공간에 저장한다.
//현재 가리키고 있는 노드의 info를 MinLoc의 info에 대입하고, 임시 저장한 
//최소값으로 location의 info를 바꿔가면서 정렬을 구현한다.

//Sort함수의 파라메터는 listData를 넘겨준다.
//***에서 현재 location이 마지막 노드이거나 리스트의 minimum 값을 갖는다면 어떻게 될까? 좀 더 efficient하게 수정하려면?
template <class ItemType>
void UnsortedType<ItemType>::Sort(NodeType<ItemType> *location)
{
	NodeType<ItemType> *minPtr; //최소값을 가리키는 포인터
	ItemType temp;

	if (location != NULL && location->next!=NULL)  //empty 리스트가 아니고 location이 마지막 노드가 아닌 경우_general case
	{
		//minPtr = MinLoc(location, location);  // ***
		minPtr = MinLoc(location);
		if (minPtr == location)  //현재 location이 리스트의 miinmum값을 가지는 경우
			Sort(location->next);
		else {
			temp = minPtr->info;
			minPtr->info = location->info;
			location->info = temp;
			Sort(location->next);
		}
		//현재 location이 마지막 노드면 do nothing
	}
	// base case는 do nothing, base case: 빈 리스트 or 마지막 노드 인 경우 Sort필요 x
}

/* //***부분 수정 전
template <class ItemType>
void UnsortedType<ItemType>::Sort(NodeType<ItemType> *location)
{
	NodeType<ItemType> *minPtr; //최소값을 가리키는 포인터
	ItemType temp;

	if (location != NULL) // empty 리스트가 아니면_general case
	{
		minPtr = MinLoc(location, location);  // ***
		//minPtr = MinLoc(location);
		temp = minPtr->info;
		minPtr->info = location->info;
		location->info = temp;
		Sort(location->next);
	}
	// base case는 do nothing
}
*/


/* //MinLoc 1번째 구현
//함수 호출 시 파라미터로 클래스 내부 변수인 listData가 넘겨져야 한다.
// -> Sort 함수 첫 번째 호출 시 listData 받음, Sort안에서 minLoc 호출 시 listData 그대로 넘어감
template <class ItemType>
NodeType<ItemType>* UnsortedType<ItemType>::MinLoc(NodeType<ItemType> *location, NodeType<ItemType>* minPtr)
{
	if (location != NULL) //general case
	{
		if (location->info < minPtr->info)
			minPtr = location;
		return MinLoc(location->next, minPtr); // 다음 노드로 함수 재귀 호출
	}
	else  // base case
		return minPtr;
}
*/

//MinLoc 2번째 구현
//함수 호출 시 파라미터로 클래스 내부 변수인 listData가 넘겨져야 한다.
template <class ItemType>
NodeType<ItemType>* UnsortedType<ItemType>::MinLoc(NodeType<ItemType> *location) {
	if (location == NULL) // base case: 원래 리스트가 empty (listData가 NULL) 일 때
		return NULL;
	else if (location->next == NULL) // another base case : 리스트의 마지막 노드 
		return location;
	else { // general case: location != NULL
		NodeType<ItemType> *minPtr = MinLoc(location->next);
		if (location->info < minPtr->info) // minPtr은 절대 NULL이 아님. Why? -> 제일 끝 노드부터 시작해서 앞의 노드들과 비교해나가기 때문 
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