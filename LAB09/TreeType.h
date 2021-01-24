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

  //lab09-1
  TreeNode* PtrToSuccessorA(TreeNode*& tree);
  TreeNode* PtrToSuccessorB(TreeNode* tree);
  void PrintSuccessor(); //PtrToSuccessor함수 확인

  //lab09-3
  bool IsBST(TreeNode* tree);

  //lab09-4
  int LeafCount();

  //lab09-5
  int SingleParentCount();

private:
  TreeNode* root;
  QueType preQue;
  QueType inQue;
  QueType postQue;
};

