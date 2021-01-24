#pragma once
#include "PQType.h"

typedef int ItemType;
struct NodeType;

class PQStackType
{
public:
	PQStackType(int max);
	~PQStackType();
	bool IsFull() const;
	bool IsEmpty() const;
	void Push(ItemType item);
	void Pop(ItemType &item);
	//ItemType Top();
private:
	PQType<ItemType> pqueue;
	//NodeType* location;
	//NodeType* topPtr;
	int timestamp;
};

/*
//help slide �׸�ó�� LL�߰��ؼ� info, timestamp, next ����
struct NodeType
{
	ItemType info;
	ItemType timestamp;
	NodeType* next;
};
*/

PQStackType::PQStackType(int max)
{
	pqueue = PQType<ItemType>(max);
	timestamp = 0;
	//topPtr = NULL;
	//location = topPtr;
}

PQStackType::~PQStackType()
{
	pqueue.~PQType();
}

void PQStackType::Push(ItemType item)
{
	timestamp++;
	pqueue.Enqueue(timestamp, item);

	/*
	location = new NodeType;
	location->info = item;
	location->timestamp = timestamp;
	location->next = NULL;
	location = location->next;
	*/
}

void PQStackType::Pop(ItemType& item)
{
	//NodeType* predLoc = new NodeType;
	pqueue.Dequeue(item);
	
	/*
	location = topPtr;
	predLoc = location;

	while (location != NULL) {
		if (tStamp == location->timestamp) {
			predLoc->next = location->next;
			item = location->info;
			delete location;
			location = predLoc->next;
			break;
		}
		else {
			predLoc = location;
			location = location->next;
		}
	}

	while (location != NULL)
		location = location->next;
	*/
}

bool PQStackType::IsEmpty() const
{
	if (pqueue.IsEmpty())
		return true;
	
	return false;
}

bool PQStackType::IsFull() const
{
	if (pqueue.IsFull())
		return true;

	return false;
}

//lab11-4
//A. �ֿ켱���� ����: Stack�� ���� ���߿� ���� Time Stamp���� ū ������
//C. LL�� ������ Stack: Push-O(1) Pop-O(1)
//   Priority Queue�� ������ Stack: Push-O(log2(N)) Pop-O(log2(N))