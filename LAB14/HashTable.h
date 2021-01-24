#pragma once
#include <string>

#include <iostream>
using namespace std;

const int MAX_ITEMS = 100;

template <class ItemType>
class HashTable
{
public:
	HashTable(ItemType item);
	int Hash(char* key) const;
	void InsertItem(ItemType item);
	void RetreiveItem(ItemType &item, bool &found);
private:
	ItemType info[MAX_ITEMS];
	ItemType emptyItem;
	int length;
};

template <class ItemType>
HashTable<ItemType>::HashTable(ItemType item)
{
	length = 0;
	emptyItem = item.EmptyKey();
	for (int i = 0; i < MAX_ITEMS; i++)
		info[i] = emptyItem;
}

int getIntFromString(char* key);

template <class ItemType>
int HashTable<ItemType>::Hash(char *key) const
{
	return (getIntFromString(key) % MAX_ITEMS);
}

// returns an integer hash value for key for a 15 bit
int getIntFromString(char *key)
{
	int sum = 0;
	int len = strlen(key);
	if (len % 2 == 1) len++; // make len even
	for (int j = 0; j < len; j += 2)
		sum = (sum + 100 * key[j] + key[j + 1]) % 19937;
	return sum;
}

template<class ItemType>
void HashTable<ItemType>::InsertItem(ItemType item)
{
	int location;
	location = Hash(item.Key());
	
	//À½¼ö³ª¿È
	location = abs(location);

	while (info[location] != this->emptyItem)
		location = (location + 1) % MAX_ITEMS;
	info[location] = item;
	length++;
}

template<class ItemType>
void HashTable<ItemType>::RetreiveItem(ItemType &item, bool &found)
{
	int location;
	int startLoc;
	bool moreToSearch = true;

	startLoc = Hash(item.Key());
	location = startLoc;
	do
	{
		if (info[location] == item || info[location] == emptyItem)
			moreToSearch = false;
		else
			location = (location + 1) % MAX_ITEMS;
	} while (moreToSearch);
	
	found = (info[location] == item);

	if (found)
		item = info[location];
}