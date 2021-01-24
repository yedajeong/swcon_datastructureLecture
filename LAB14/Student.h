#ifndef _STUDENT_H
#define _STUDENT_H

#include <iostream>
using namespace std;

class Student
{
public :
	void Print(ostream& out);
	void InitValue(int _id, char* _name, float _gpa);
	void getValue(int& _id, char* _name, float& _gpa);
	char* getName();
	void operator = (Student stu);

	//lab14-4
	char* Key();
	bool operator ==(Student stu);
	bool operator!=(Student stu);
	Student EmptyKey();

private :
	int id;
	char name[30];
	float gpa;
};

//lab14-3
void Swap(Student*& item1, Student*& item2);

void Swap(Student& item1, Student& item2);

void Print(ostream& out, Student stu[], int numelement);
void PrintByPointer(ostream& out, Student* values[], int numValues);

#endif