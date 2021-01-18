// Linked Stack ADT

typedef int ItemType;
struct NodeType;


class FullStack
// Exception class thrown by Push when stack is full.
{};

class EmptyStack
// Exception class thrown by Pop and Top when stack is emtpy.
{};


class StackType
{
public:

  StackType();
  // Class constructor.
  ~StackType();
  bool IsFull() const;
  // Function: Determines whether the stack is full.
  // Pre:  Stack has been initialized.
  // Post: Function value = (stack is full)
  bool IsEmpty() const;
  // Function: Determines whether the stack is empty.
  // Pre:  Stack has been initialized.
  // Post: Function value = (stack is empty)
  void Push(ItemType item);
  // Function: Adds newItem to the top of the stack.
  // Pre:  Stack has been initialized.
  // Post: If (stack is full), FullStack exception is thrown;
  //     otherwise, newItem is at the top of the stack.
  void Pop();
  // Function: Removes top item from the stack.
  // Pre:  Stack has been initialized.
  // Post: If (stack is empty), EmptyStack exception is thrown;
  //     otherwise, top element has been removed from stack.
  ItemType Top();
  // Function: Returns a copy of top item on the stack.
  // Pre:  Stack has been initialized.
  // Post: If (stack is empty), EmptyStack exception is thrown;
  //     otherwise, top element has been removed from stack.
  
  //hw08-2
  void Copy(StackType& stack);
  // Function: 입력으로 들어온 stack을 메소드를 호출한 객체로 복사한다.
  // Pre: stack은 초기화 돼있어야 한다.
  // Post: stack의 item들이 메소드를 호출한 객체로 복사된다.


private:
  NodeType* topPtr;
};

struct NodeType
{
  ItemType info;
  NodeType* next;
};

