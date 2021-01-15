// The following definitions go into file ItemType.cpp. 
#include <fstream>
#include <iostream>
#include <string>
#include "ItemType.h"

ItemType::ItemType()
{ 
  value = "";
}

RelationType ItemType::ComparedTo(ItemType otherItem) const 
{
  if (value < otherItem.value)
    return LESS;
  else if (value > otherItem.value)
    return GREATER;
  else return EQUAL;
}

void ItemType::Initialize(string word) 
{
  value = word;
}

void ItemType::Print(ostream& out) const 
// pre:  out has been opened.
// post: value has been sent to the stream out.
{
  out << value;
}

//hw4-3
//Containing에 사용
bool ItemType::IsThere(ItemType otherItem) {
	if (value.find(otherItem.value) != string::npos) //word를 찾으면 true
		return true;
	return false;
}

//Starting, Ending에 사용
void ItemType::Subtract(int from, int length, ItemType& otherItem) {
	otherItem.Initialize(value.substr(from, length)); //from 인덱스부터 length개의 문자 가져와 ItemType으로 만들기
}

int ItemType::LengthIs() {
	return value.length();
}
