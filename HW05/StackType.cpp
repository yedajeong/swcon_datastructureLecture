// File: StackType.cpp

#include "StackType.h"
#include <iostream>
StackType::StackType()
{
  top = -1;
}

bool StackType::IsEmpty() const
{
  return (top == -1);
}

bool StackType::IsFull() const
{
  return (top ==  MAX_ITEMS-1);
}

void StackType::Push(ItemType newItem)
{
  if( IsFull() )
    throw FullStack();
  top++;
  items[top] = newItem;
}

//3
ItemType StackType::Pop()
{
  if( IsEmpty() )
    throw EmptyStack();
  ItemType item = items[top];
  top--;
  return item;
}

//3-B
ItemType StackType::Top()
{
  if ( IsEmpty() )
    throw EmptyStack();
  else
	return items[top];
}    

//4-B
bool StackType::Identical(StackType other) {
	for (int i = 0; i < MAX_ITEMS; i++) {
		if (this->items[i] != other.items[i])
			return false;
	}

	return true;
}