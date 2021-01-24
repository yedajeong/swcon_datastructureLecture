#include "HashTable.h"
#include "Student.h"

int main()
{
	Student stu[100];
	stu[0].InitValue(2003200111, (char*)"ÀÌ¿õÀç", 3.0);
	stu[1].InitValue(2004200121, (char*)"±Ç¿ÀÁØ", 3.2);
	stu[2].InitValue(2005200132, (char*)"±èÁøÀÏ", 2.7);
	
	HashTable<Student> ht(stu[0]);
	ht.InsertItem(stu[0]);
	ht.InsertItem(stu[1]);
	ht.InsertItem(stu[2]);

	char* input = new char[3];
	cin >> input;
	Student myStu;
	myStu.InitValue(0, input, 0.0);
	bool found;

	ht.RetreiveItem(myStu, found);
	cout << endl << myStu.getName() << endl;

	return 0;
}