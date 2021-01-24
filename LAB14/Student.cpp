#include "Student.h"

//lab14-4
char* Student::Key()
{
	return name;
}

bool Student::operator==(Student stu)
{
	return (strcmp(this->name, stu.name) == 0);
}

bool Student::operator!=(Student stu)
{
	return (strcmp(this->name, stu.name) != 0);
}

Student Student::EmptyKey()
{
	Student empty;
	empty.InitValue(0, (char*)"", 0.0);
	return empty;
}

void Print(ostream& out, Student stu[], int numelement)
{
	for(int i=0; i<numelement; i++)
	{
		stu[i].Print(out);
	}
}
void Student::Print(ostream& out)
{
	out << id << "\t" << name << "\t" << gpa << endl;
}
void Student::InitValue(int _id, char* _name, float _gpa)
{
	id = _id;
	strcpy_s(name, sizeof(name), _name);
	gpa = _gpa;
}
void Student::getValue(int& _id, char* _name, float& _gpa)
{
	_id = id;
	strcpy_s(_name,sizeof(_name), name);
	_gpa = gpa;	
}
char* Student::getName()
{
	return name;
}
void Student::operator = (Student stu)
{
	id = stu.id;
	strcpy_s(name, sizeof(name), stu.name);
	gpa = stu.gpa;
}

void PrintByPointer(ostream& out, Student* values[], int numValues)
{
	for(int i=0; i<numValues; i++)
	{
		(*values[i]).Print(out);
	}
}


