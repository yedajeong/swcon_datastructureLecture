#include "customDLL.h"

customDLL::customDLL()  // Class constructor
{
	length = 0;
	LineType* header = new LineType;
	LineType* tailer = new LineType;

	header->next = tailer;
	tailer->back = header;
	header->back = NULL;
	tailer->next = NULL;
	header->info = STX; // ASCII 2 -> STX
	tailer->info = ETX; // ASCII 3 -> ETX


	listData = header;
	currentLine = header;
}

customDLL::~customDLL()
// Class destructor
{
	MakeEmpty();
}

bool customDLL::IsFull() const
// Returns true if there is no room for another ItemType 
//  on the free store; false otherwise.
{
	LineType* location;
	try
	{
		location = new LineType;
		delete location;
		return false;
	}
	catch (std::bad_alloc exception)
	{
		return true;
	}
}

int customDLL::LengthIs() const
// Post: Number of items in the list is returned.
{
	return length;
}

void customDLL::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
	LineType* tempPtr;

	while (listData != NULL)
	{
		tempPtr = listData;
		listData = listData->next;
		delete tempPtr;
	}
	length = 0;
}


void customDLL::InsertItem(ItemType item)
// item is in the list; length has been incremented.
{
	LineType* location;

	//GoToBottom();

	location = new LineType;
	location->info = item;
	location->back = currentLine;
	location->next = currentLine->next;
	currentLine->next->back = location;
	currentLine->next = location;
	currentLine = location;
	length++;
}


void customDLL::GetNextItem(ItemType& item)
// Post:  Current position has been updated; item is current item.
{
	if (currentLine == NULL)
		currentLine = listData;
	else
		currentLine = currentLine->next;

	item = currentLine->info;
}

void customDLL::GoToHeader() {
	// You can change the code if necessary.
	while (currentLine->back != NULL)
		currentLine = currentLine->back;
}

void customDLL::GoToBottom() {
	// You can change the code if necessary.
	while (currentLine->next != NULL)
		currentLine = currentLine->next;

	currentLine = currentLine->back;
}

void customDLL::MoveLeft(int offset) {
	// To-Do : Implement move left if necessary
	// Input your code START
	for (int i = 0; i < offset; i++) {
		if (currentLine->back != NULL) //currentLine의 back이 NULL이면(=Header) currentLine 이동 x
			currentLine = currentLine->back;
	}

	// Input your code END
}
void customDLL::MoveRight(int offset) {
	// To-Do : Implement move right if necessary
	// Input your code START
	for (int i = 0; i < offset; i++) {
		if (currentLine->next != NULL) 
			currentLine = currentLine->next;
	}
	if (currentLine->next == NULL) //currentLine의 next가 NULL이면(=Trailer) 한 칸 앞으로 이동
		currentLine = currentLine->back;

	// Input your code END
}

void customDLL::DeleteCurrent() {
	// To-Do : Implement Delete if necessary
	// Input your code START
	if (currentLine->back != NULL && currentLine->next != NULL) { //Header or Trailer 아닌 경우 == 지울 line 있는 경우
		LineType *deleteLine = currentLine;
		LineType *predLine = currentLine->back;
		predLine->next = currentLine->next;
		(currentLine->next)->back = predLine;
		currentLine = predLine;
		delete deleteLine;

		// After that, length is -1
		length--;
	}

	// Input your code END
}
ItemType* customDLL::Decoding() {
	// To-Do : Implement Delete if necessary
	// Input your code START
	customDLL temp;
	ItemType* result = nullptr; //Change to your own initial value
	ItemType item;

	GoToHeader();
	temp.GoToHeader();

	for(int i = 0; i < length; i++) {
		GetNextItem(item);

		switch (item) {
		case '>':
			temp.MoveRight(1);
//			cout << "move right" << endl;
			break;
		case '<':
			temp.MoveLeft(1);
//			cout << "move left" << endl;
			break; 
		case '-':
			temp.DeleteCurrent();
//			cout << "backspace" << endl;
			break;
		case '_':
			temp.MoveRight(1);
			temp.DeleteCurrent();
//			cout << "delete" << endl;
			break;
		default:
			temp.InsertItem(item);
//			cout << "insert" << endl;
			break;
		}

	}

	temp.GoToHeader();
	result = new ItemType[temp.length];
	for (int i = 0; i < temp.length; i++) {
		temp.GetNextItem(item);
		result[i] = item;
		//cout << result[i] << ": result 배열에 item 넣기" << endl;
	}
	result[temp.length] = '\0';

	// Input your code END
	// After that, return result
	return result; //LineType의 info는 ItemType == char
	
	//string type 배열에 넣을 거니까 char* result로 반환
}

void customDLL::Print(){
	GoToHeader();
	ItemType tmp;
	for (int i = 0; i < length; i++) {
		GetNextItem(tmp);
		cout << tmp;
	}
	cout << endl;
}