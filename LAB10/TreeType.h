#pragma once
#include <iostream>
#include <string>
#include <fstream>
typedef char ItemType;
struct TreeNode;
#include "QueType.h"
enum OrderType {PRE_ORDER, IN_ORDER, POST_ORDER};
class TreeType
{
public:
  TreeType();                     // constructor
 ~TreeType();                    // destructor
  TreeType(const TreeType& originalTree); 
  void operator=(const TreeType& originalTree);
  // copy constructor
  void MakeEmpty();
  bool IsEmpty() const;
  bool IsFull() const;
  int LengthIs() const; 
  void RetrieveItem(ItemType& item, bool& found);
  void InsertItem(ItemType item);
  void DeleteItem(ItemType item);
  void ResetTree(OrderType order); 
  void GetNextItem (ItemType& item, OrderType order, 
       bool& finished);
  void Print(std::ofstream& outFile) const;

  //lab10-1
  void Ancestors(ItemType value);

  //lab10-2
  void Ancestors_re(ItemType value);

private:
  TreeNode* root;
  QueType preQue;
  QueType inQue;
  QueType postQue;
};

