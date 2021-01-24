#pragma once
template <class ItemType>
void swap(ItemType& one, ItemType& two);

template<class ItemType>
// Assumes ItemType is either a built-in simple type or a class
// with overloaded relational operators.
struct HeapType
{
  void ReheapDown(int root, int bottom);
  void ReheapUp(int root, int bottom);
  ItemType* elements;   // Array to be allocated dynamically
  
  //lab11-4
  ItemType* info;

  int numElements;
};

template <class ItemType>
void Swap(ItemType& one, ItemType& two)
{
  ItemType temp;
  temp = one;
  one = two;
  two = temp;
}


template<class ItemType>
void HeapType<ItemType>::ReheapUp(int root, int bottom)
// Post: Heap property is restored.
{
  int parent;
  
  if (bottom > root)
  {
    parent = (bottom-1) / 2;
    if (elements[parent] < elements[bottom])
    {
      Swap(elements[parent], elements[bottom]);

	  //lab11-4
	  Swap(info[parent], info[bottom]);

      ReheapUp(root, parent);
    }
  }
}
template<class ItemType>
void HeapType<ItemType>::ReheapDown(int root, int bottom)
// Post: Heap property is restored.
{
  int maxChild;
  int rightChild;
  int leftChild;

  leftChild = root*2+1;
  rightChild = root*2+2;
  if (leftChild <= bottom)
  {
    if (leftChild == bottom)
      maxChild = leftChild;
    else
    {
      if (elements[leftChild] <= elements[rightChild])
        maxChild = rightChild;
      else
        maxChild = leftChild;
    }
    if (elements[root] < elements[maxChild])
    {
      Swap(elements[root], elements[maxChild]);

	  //lab11-4
	  Swap(info[root], info[maxChild]);

      ReheapDown(maxChild, bottom);
    }
  }
}


//lab11-1A
template<class ItemType>
void HeapType<ItemType>::ReheapDown(int root, int bottom)
// root ��带 �����ϰ� ������ ������ heap�� ������ �����ϰ� ����
{
	int maxChild, leftChild, rightChild;
	bool reheaped = false; // root�� �� ��ġ�� ã�ư� reheap�� �Ǹ� True

	leftChild = root * 2 + 1; // root �����κ��� ���� �ڽĳ���� ��ġ ��� 

	while (leftChild <= bottom && !reheaped)
	{
		if (leftChild == bottom) // ���� �ڽ� ��� �ϳ��� �ִ� ���
			maxChild = leftChild;
		else {
			rightChild = root * 2 + 2;
			maxChild = (elements[leftChild] <= elements[rightChild]) ? rightChild : leftChild;
		}

		if (elements[root] < elements[maxChild]) {
			Swap(elements[root], elements[maxChild]);
			root = maxChild; // maxChild �� root�� ���ο� ��ġ�� �� (maxChild�� parent �ڸ� �ٲ㼭 maxChild�� parent �����ϱ�)
			leftChild = root * 2 + 1;
		}
		else
			reheaped = true; //parent�� child���� Ŭ ��
	}
}

//lab11-1B
template<class ItemType>
void HeapType<ItemType>::ReheapUp(int root, int bottom)
// bottom�� ���� ���Ե� ���� ���� �Ʒ� ������ ���� ������ ��带 ����Ŵ
{
	int parent;
	bool reheaped = false; // bottom�� �� ��ġ�� ã�ư��� reheap�� �Ǹ� true

	while (bottom > root && !reheaped)
	{
		parent = (bottom - 2) / 2; // bottom �����κ��� �θ� ����� ��ġ ���

		if (elements[parent] < elements[bottom])
		{
			Swap(elements[parent], elements[bottom]);// bottom�� �θ� ���� �� ��ȯ 
			bottom = parent;  // bottom�� ���� �θ� ����� ��ġ�� ����Ŵ
		}
		else
			reheaped = true;
	}
}

//lab11-1C
//A-O(log2(N)) / B-O(log2(N))