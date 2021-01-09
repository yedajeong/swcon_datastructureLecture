// The following declarations and definitions go into file 
// ItemType.h. 
#pragma once
#include <fstream>
#include <string>
const int MAX_ITEMS = 50;
enum RelationType  {LESS, GREATER, EQUAL};

using namespace std;

class ItemType 
{ 
public:
  ItemType();
  RelationType ComparedTo(ItemType) const;
  void Print(ostream&) const;
  void Initialize(string);
  //hw4-3
  bool IsThere(ItemType);
  void Subtract(int, int, ItemType&);
  int LengthIs();
private:
	string value;
};
 
