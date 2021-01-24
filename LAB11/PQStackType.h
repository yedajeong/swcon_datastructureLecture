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
private:
	PQType<ItemType> pqueue;
	int timestamp;
};


PQStackType::PQStackType(int max)
{
	pqueue = PQType<ItemType>(max);
	timestamp = 0;
}

PQStackType::~PQStackType()
{
	pqueue.~PQType();
}

void PQStackType::Push(ItemType item)
{
	timestamp++;
	pqueue.Enqueue(timestamp, item);
}

void PQStackType::Pop(ItemType& item)
{

	pqueue.Dequeue(item);
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