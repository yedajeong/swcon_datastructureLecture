#include <iostream>
#include <string>

using namespace std;

const int MAX_ITEMS = 50;

class GroceryStore {
private:
	string stuff[MAX_ITEMS];
	int price[MAX_ITEMS];
	int length;
public:
	void CheckOut(string buy) {
		int idx = RetrieveItem(this->stuff, buy); //int RetriveItem(string* stuff, string buy)
		if (idx != -1) //RetrieveItem: buy 찾지 못하면 -1 반환
			DeleteItem(this->stuff, , this->price, idx); //void DeleteItem(string* stuff, int* price, int idx)
		else
			cout << "there's no ' " << buy << " ' in our grocery store.\n";
	}
};