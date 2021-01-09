#include <iostream>
#include "QueType.h"

QueType::QueType(int max)
// Parameterized class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
{
  maxQue = max + 1;
  front = maxQue - 1;
  rear = maxQue - 1;
  items = new ItemType[maxQue];
  //6
  minimum_pos = 0;
}
QueType::QueType()          // Default class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
{
  maxQue = 501;
  front = maxQue - 1;
  rear = maxQue - 1;
  items = new ItemType[maxQue];
  //6
  minimum_pos = 0;
}
QueType::~QueType()         // Class destructor
{
  delete [] items;
}

void QueType::MakeEmpty()
// Post: front and rear have been reset to the empty state.
{
  front = maxQue - 1;
  rear = maxQue - 1;
}

bool QueType::IsEmpty() const
// Returns true if the queue is empty; false otherwise.
{
  return (rear == front);
}

bool QueType::IsFull() const
// Returns true if the queue is full; false otherwise.
{
  return ((rear + 1) % maxQue == front);
}

/*
void QueType::Enqueue(ItemType newItem)
// Post: If (queue is not full) newItem is at the rear of the queue;
//       otherwise a FullQueue exception is thrown.  
{
  if (IsFull())
    throw FullQueue();
  else
  {
    rear = (rear +1) % maxQue;
    items[rear] = newItem;
  }
}

void QueType::Dequeue(ItemType& item)
// Post: If (queue is not empty) the front of the queue has been 
//       removed and a copy returned in item; 
//       othersiwe a EmptyQueue exception has been thrown.
{
  if (IsEmpty())
    throw EmptyQueue();
  else
  {
    front = (front + 1) % maxQue;
    item = items[front];
  }
}
*/

//2-2
void QueType::ReplaceItem(ItemType oldItem, ItemType newItem) {
	for (int i = 0; i < maxQue; i++) {
		if (items[i] == oldItem)
			items[i] = newItem;
	}
}

//3-2
QueType::QueType(const QueType& other) { //���� ������
	this->front = other.front;
	this->rear = other.rear;
	this->maxQue = other.maxQue;
	this->items = new ItemType[other.maxQue];

	int idx;
	for (int i = 1; i < maxQue; i++) {
		idx = (front + i) % maxQue;
		this->items[idx] = other.items[idx];
	}
}

bool QueType::Identical(QueType _queue) {
	QueType queue(_queue);
	int length1 = 0, length2 = 0, idx;

	for (int i = 1; i < maxQue; i++) {
		idx = (front + i) % maxQue;
		if (idx == rear) {
			length1++;
			break;
		}
		else
			length1++;
	}

	for (int i = 1; i < queue.maxQue; i++) {
		idx = (queue.front + i) % queue.maxQue;
		if (idx == queue.rear) {
			length2++;
			break;
		}
		else
			length2++;
	}

	if (length1 != length2) //ũ�� �ٸ��� false
		return false;

	else { //ũ�� ������ ��� �ϳ��� ���ϱ�
		int i = (front + 1) % maxQue, j = (queue.front + 1) % queue.maxQue;
		while (i <= rear && j <= queue.rear) {
			if (this->items[i] != queue.items[j])
				return false;
			else {
				i = (i + 1) % maxQue;
				j = (j + 1) % maxQue;
			}
		}
		return true;
	}
	
}

//4-2
int QueType::LengthIs() {
	int queLength = 0, idx;
	
	for (int i = 1; i < maxQue; i++) {
		idx = (front + i) % maxQue;
		if (idx == rear) {
			queLength++;
			break;
		}
		else
			queLength++;
	}
	
	return queLength;
}

/*
//6 (���� Enqueue, Dequeue �ּ� ó��)
void QueType::MinDequeue(ItemType& item) {
	//Dequeue�� ���� �����ƴ� == -1�̴�
	//Dequeue�� ������ ��� == Enqueue�� ���� item�� �����ϴ� ��� == minimum_pos�� Enqueue�Լ� �ȿ��� �̹� ��������
	
	//item�� min�� ��ȯ, �ش� �ڸ��� -1�� �ʱ�ȭ
	item = items[minimum_pos];
	items[minimum_pos] = -1;

	//���ο� minimum_pos �ʱ�ȭ
	int min = items[(front + 1) % maxQue], idx;

	for (int i = 1; i < maxQue; i++) {
		idx = (front + i) % maxQue;
		if (min == -1)
			min = items[idx];
		else if (items[idx] <= min && items[idx] != -1) {
			minimum_pos = idx;
			min = items[idx];
		}
	}
}

void QueType::Enqueue(ItemType newitem) { //MinDequeue�� ���� ���� Enqueue�Լ�
	//queue�� ����ִ� ���
	if (IsEmpty()) {
		rear = (rear + 1) % maxQue;
		items[rear] = newitem;
	}
	//queue�� �ٸ� �������� �ִ� ���->-1�� �ִ� ��� / -1�� ���� ���
	else {
		for (int i = 1; i < maxQue; i++) {
			int idx = (front + i) % maxQue;
			//-1�� �ʱ�ȭ�� �ڸ��� newitem ����
			if (items[idx] == -1) {
				items[idx] = newitem;
				break;
			}
			//-1�� �ʱ�ȭ�� ���� ���� ���
			else if (idx == rear && items[idx] != -1) {
				rear = (rear + 1) % maxQue;
				items[rear] = newitem;
				break;
			}
		}
	}

	//���ο� minimum_pos �ʱ�ȭ
	int min = items[(front + 1) % maxQue], idx;
	for (int i = 1; i < maxQue; i++) {
		idx = (front + i) % maxQue;
		if (min == -1)
			min = items[idx];
		else if (items[idx] < min && items[idx] != -1) {
			minimum_pos = idx;
			min = items[idx];
		}
	}
} */

//6_���� § �ڵ�
void QueType::MinDequeue(ItemType& item) {
	if (IsEmpty())
		throw EmptyQueue();
	else {
		item = items[minimum_pos];
		items[minimum_pos] = -1;

		//���ο� minimum_pos ������Ʈ
		int min = items[(front + 1) % maxQue], idx;
		for (int i = 1; i < maxQue; i++) {
			idx = (front + i) % maxQue;
			if (min == -1) { //ù ��° item (=items[(front + 1) % maxQue]) �� -1�� ���->�� ��° �����ۺ��� �˻�
				min = items[idx];
				minimum_pos = idx;
			}
			else if (items[idx] <= min && items[idx] != -1) { //items[idx] < min ���⿡ ��ȣ �ȳ־��༭ ���� ù��° �������� min�� ��� minimum_pos ������Ʈ�� �ȵ��� �̤�
				min = items[idx];
				minimum_pos = idx;
			}

			if (idx == rear) {//rear���� �˻��ϸ� ť�� ��� ���� �˻� �Ϸ�, for�� ����
				cout << "dequeue�� minimum_pos: " << minimum_pos << endl;
				break;
			}
		}
	}
}

void QueType::Enqueue(ItemType newitem) {
	int idx;

	if (IsEmpty()) {
		rear = (rear + 1) % maxQue;
		items[rear] = newitem;
	}

	else if (!IsEmpty()) { //������� ���� ���
		bool dequeued = false;

		for (int i = 1; i < maxQue; i++) {
			idx = (front + i) % maxQue;
			if (items[idx] == -1) {
				dequeued = true; //-1�� dequeue�� �� �ִ� ���
				break; //idx���� -1�� index �����
			}
			if (idx == rear)
				break;
		}

		if (IsFull() && !dequeued)
			throw FullQueue(); //�� á�µ��ٰ� -1�� ������ ������ ���� ��� ���� �� ����

		else if (dequeued) {
			items[idx] = newitem; //-1�� �ڸ��� newitem �ֱ�
			cout << "enqueue_-1�ڸ���" << endl;
		}

		else {
			rear = (rear + 1) % maxQue;
			items[rear] = newitem;
			cout << "enqueue_rear ���ڸ���" << endl;
		}
	}

	//���ο� minimum_pos ������Ʈ
	int min = items[(front + 1) % maxQue];
	for (int i = 1; i < maxQue; i++) {
		idx = (front + i) % maxQue;
		if (min == -1) { //ù ��° item (=items[(front + 1) % maxQue]) �� -1�� ���->�� ��° �����ۺ��� �˻�
			min = items[idx];
			minimum_pos = idx;
		}
		else if (items[idx] <= min && items[idx] != -1) {
			min = items[idx];
			minimum_pos = idx;
		}

		if (idx == rear) {//rear���� �˻��ϸ� ť�� ��� ���� �˻� �Ϸ�, for�� ����
			cout << "enqueue�� minimum_pos: " << minimum_pos << endl;
			break;
		}
	}

}