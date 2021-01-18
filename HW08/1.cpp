template <class ItemType>
struct NodeType;

template <class ItemType>
class UnsortedType
{
public:
	UnsortedType();     // Class constructor	
	~UnsortedType();    // Class destructor
	UnsortedType(UnsortedType& list); // Copy constructor

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
	NodeType<ItemType>* tempPtr;
	while (listData != nullptr) {
		tempPtr = listData;
		listData = listData->next;
		delete tempPtr;
	}
	length = 0;
}

template <class ItemType>
UnsortedType<ItemType>::UnsortedType(UnsortedType& list)  // Copy constructor
{
	length = list.length;
	NodeType<ItemType>* location = new NodeType<ItemType>;
	NodeType<ItemType>* listLoc = list.listData;
	
	listData = location;
	location->info = listLoc->info;
	location->next = new NodeType<ItemType>;
	listLoc = listLoc->next;

	while (listLoc != list.listData) {
		location = location->next;
		location->info = listLoc->info;
		location->next = new NodeType<ItemType>;
		listLoc = listLoc->next;
	}

	delete location->next;
	location->next = listData;

}