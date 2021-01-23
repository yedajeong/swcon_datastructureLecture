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
QueType::QueType(const QueType& other) { //복사 생성자
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

	if (length1 != length2) //크기 다르면 false
		return false;

	else { //크기 같으면 요소 하나씩 비교하기
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
//6 (기존 Enqueue, Dequeue 주석 처리)
void QueType::MinDequeue(ItemType& item) {
	//Dequeue로 값이 삭제됐다 == -1이다
	//Dequeue가 가능한 경우 == Enqueue를 통해 item이 존재하는 경우 == minimum_pos가 Enqueue함수 안에서 이미 계산돼있음
	
	//item에 min값 반환, 해당 자리는 -1로 초기화
	item = items[minimum_pos];
	items[minimum_pos] = -1;

	//새로운 minimum_pos 초기화
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

void QueType::Enqueue(ItemType newitem) { //MinDequeue가 있을 때의 Enqueue함수
	//queue가 비어있는 경우
	if (IsEmpty()) {
		rear = (rear + 1) % maxQue;
		items[rear] = newitem;
	}
	//queue에 다른 아이템이 있는 경우->-1이 있는 경우 / -1이 없는 경우
	else {
		for (int i = 1; i < maxQue; i++) {
			int idx = (front + i) % maxQue;
			//-1로 초기화된 자리에 newitem 저장
			if (items[idx] == -1) {
				items[idx] = newitem;
				break;
			}
			//-1로 초기화된 값이 없는 경우
			else if (idx == rear && items[idx] != -1) {
				rear = (rear + 1) % maxQue;
				items[rear] = newitem;
				break;
			}
		}
	}

	//새로운 minimum_pos 초기화
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

//6_새로 짠 코드
void QueType::MinDequeue(ItemType& item) {
	if (IsEmpty())
		throw EmptyQueue();
	else {
		item = items[minimum_pos];
		items[minimum_pos] = -1;

		//새로운 minimum_pos 업데이트
		int min = items[(front + 1) % maxQue], idx;
		for (int i = 1; i < maxQue; i++) {
			idx = (front + i) % maxQue;
			if (min == -1) { //첫 번째 item (=items[(front + 1) % maxQue]) 이 -1인 경우->두 번째 아이템부터 검사
				min = items[idx];
				minimum_pos = idx;
			}
			else if (items[idx] <= min && items[idx] != -1) { //items[idx] < min 여기에 등호 안넣어줘서 제일 첫번째 아이템이 min인 경우 minimum_pos 업데이트가 안됐음 ㅜㅜ
				min = items[idx];
				minimum_pos = idx;
			}

			if (idx == rear) {//rear까지 검사하면 큐의 모든 원소 검사 완료, for문 종료
				cout << "dequeue후 minimum_pos: " << minimum_pos << endl;
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

	else if (!IsEmpty()) { //비어있지 않은 경우
		bool dequeued = false;

		for (int i = 1; i < maxQue; i++) {
			idx = (front + i) % maxQue;
			if (items[idx] == -1) {
				dequeued = true; //-1로 dequeue된 적 있는 경우
				break; //idx에는 -1의 index 저장됨
			}
			if (idx == rear)
				break;
		}

		if (IsFull() && !dequeued)
			throw FullQueue(); //꽉 찼는데다가 -1로 지워진 공간도 없는 경우 ㄹㅇ 다 찬거

		else if (dequeued) {
			items[idx] = newitem; //-1인 자리에 newitem 넣기
			cout << "enqueue_-1자리에" << endl;
		}

		else {
			rear = (rear + 1) % maxQue;
			items[rear] = newitem;
			cout << "enqueue_rear 뒷자리에" << endl;
		}
	}

	//새로운 minimum_pos 업데이트
	int min = items[(front + 1) % maxQue];
	for (int i = 1; i < maxQue; i++) {
		idx = (front + i) % maxQue;
		if (min == -1) { //첫 번째 item (=items[(front + 1) % maxQue]) 이 -1인 경우->두 번째 아이템부터 검사
			min = items[idx];
			minimum_pos = idx;
		}
		else if (items[idx] <= min && items[idx] != -1) {
			min = items[idx];
			minimum_pos = idx;
		}

		if (idx == rear) {//rear까지 검사하면 큐의 모든 원소 검사 완료, for문 종료
			cout << "enqueue후 minimum_pos: " << minimum_pos << endl;
			break;
		}
	}

}