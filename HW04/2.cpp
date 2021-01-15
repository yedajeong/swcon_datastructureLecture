#include <iostream>
#include <fstream>
#include <string>
#include "sorted.h"

using namespace std;

//hw04-3: ItemType�� value -> string
//����� Ű���� �Է�(1-4 ����)�� ������ų ��ɾ�
enum CommandType {STARTING, ENDING, CONTAINING, STOP};

//Words.txt���Ϸκ��� word�� �ش��ϴ� �ܾ�鸸 ã�� sorted list�� ����
void FileToList(SortedType& wordList);

//����ڷκ��� Ű���� �Է��� �޾Ƶ���
void GetCommand(CommandType& command);

//�Է��� pattern���� �����ϴ� �ܾ ã��
void FindAtStart(SortedType& list, string pattern, ofstream& fout);

//�Է��� pattern���� ������ �ܾ ã��
void FindAtEnd(SortedType& list, string pattern, ofstream& fout);

//�Է��� pattern�� �����ϴ� �ܾ ã��
void FindAtContain(SortedType& list, string pattern, ofstream& fout);

//item�� �ش��ϴ� �ǹ̸� Words.txt���� ã�Ƽ� ������� ����, �ܾ�, �ǹ̸� ȭ��� ���Ͽ� �����
void GetMeaning(ItemType& item, ofstream& fout, string pattern);

int main() {
	
	ofstream fout("Patterns.txt");
	CommandType command;
	SortedType wordList;
	string pattern;

	//�ؽ�Ʈ���Ϸκ��� �ܾ�鸸 �߶� wordList�� ����, ���� ������ ����
	FileToList(wordList);
	
	//����ڷκ��� 1-4���� �Է�, �׿� �����Ǵ� command�� ��Ī
	GetCommand(command);

	while (command != STOP) {
		switch (command) {
		case STARTING:
			cout << "Pattern: ";
			cin >> pattern;
			FindAtStart(wordList, pattern, fout);
			break;
		case ENDING:
			cout << "Pattern: ";
			cin >> pattern;
			FindAtEnd(wordList, pattern, fout);
			break;
		case CONTAINING:
			cout << "Pattern: ";
			cin >> pattern;
			FindAtContain(wordList, pattern, fout);
			break;
		}
		GetCommand(command);
	}

	fout.close();

	return 0;
}

void FileToList(SortedType& wordList) {
	ItemType item;
	string getWord;
	int location;
	
	ifstream fin("Words.txt");

	while (!fin.eof()) {
		getline(fin, getWord);
		location = getWord.find(":"); //�ܾ�: �ǹ� �� ������ getWord���� :ã��
		getWord = getWord.substr(0, location); //�ܾ�� �ݷ� ���� getWord�� ����

		item.Initialize(getWord);
		wordList.InsertItem(item);
	}
	fin.close();
}

void GetCommand(CommandType& command) {
	int menu;

	cout << "1. STARTING <pattern>" << endl
		<< "2. ENDING <pattern>" << endl
		<< "3. CONTAINING <pattern>" << endl
		<< "4. STOP" << endl
		<< "Enter Number(1-4): " << endl;
	cin >> menu;

	bool ok = false;
	while (!ok) {
		ok = true;
		switch (menu) {
		case 1:
			command = STARTING;
			break;
		case 2:
			command = ENDING;
			break;
		case 3:
			command = CONTAINING;
			break;
		case 4:
			command = STOP;
			break;
		default: //1-4 �̿��� �Է��� ���� ��츸 ok = false, while�� �ٽ� ��
			cout << "Number entered is not one of the specified uppercase commands.\n"
				<< "Reenter and press return.\n";
			cin >> menu;
			ok = false;
			break;
		}
	}
}

void GetMeaning(ItemType& item, ofstream& fout, string pattern) {
	ItemType compare;
	string meaning;
	int location;

	ifstream fin("Words.txt");

	while (!fin.eof()) {
		getline(fin, meaning);
		location = meaning.find(":");
		compare.Initialize(meaning.substr(0, location)); //compare.Initialize(Words.txt�� �ܾ�)

		if (compare.ComparedTo(item) == EQUAL) { //item�� �ؽ�Ʈ ���� ���� �ܾ�� �߿� �ִ��� �˻�
			meaning = meaning.substr(location + 2); //�ش� item�� �ǹ�->�ݷ�+2 �ε������� ������ ����
			//ȭ�� ���
			cout << "Pattern: " << pattern << endl;
			cout << "Word: ";
			item.Print(cout);
			cout << endl << "Meaning: " << meaning << endl;

			//���� ���
			fout << "Pattern: " << pattern << endl;
			fout << "Word: ";
			item.Print(fout);
			fout << endl << "Meaning: " << meaning << endl;
			break;
		}			
	}

	fin.close();
}

void FindAtStart(SortedType& list, string pattern, ofstream& fout) {
	ItemType listItem, userItem, compare, word[MAX_ITEMS];
	int count = 0; //�������� ������ �´� �ܾ��� ��
	userItem.Initialize(pattern); //������� ������ ItemType���� ���� (wordList�� item��� ���ϱ� ����)
	list.ResetList();

	for(int i = 0; i < list.LengthIs(); i++) {
		list.GetNextItem(listItem);
		listItem.Subtract(0, pattern.length(), compare); //����Ʈ ���� ������ listItem ���� ->idx 0���� pattern�� ���� ��ŭ compare�� ����
		if (compare.ComparedTo(userItem) == EQUAL) { //������� ���ϰ� listItem�� ������ compare�� ���� = �ܾ ã��
			word[count] = listItem;
			count++;
		}
	}

	if (count == 1) { //�������� ã�� �ܾ �� ���� ��
		cout << "<STARTING>" << endl;
		fout << "<STARTING>" << endl;
		GetMeaning(word[0], fout, pattern); //����, �ܾ�, �ǹ� ���
	}

	else if (count > 1) { //�������� ã�� �ܾ �� �� �̻��� ��
		cout << "<STARTING>" << endl << "Pattern: " << pattern << endl << "Words: ";
		fout << "<STARTING>" << endl << "Pattern: " << pattern << endl << "Words: ";
		for (int i = 0; i < count; i++) { //�ǹ̴� ������� �ʰ�(GetMeaning�Լ� x) �ܾ ������ ��
			word[i].Print(cout);
			cout << '\t';
			word[i].Print(fout);
			fout << '\t';
		}
		cout << endl;
		fout << endl;
	}

	else if (count == 0) { //�������� �ܾ ã�� ����
		cout << "<STARTING>\nThere's no " << pattern << " in this dictionary\n";
		fout << "<STARTING>\nThere's no " << pattern << " in this dictionary\n";
	}
}

void FindAtEnd(SortedType& list, string pattern, ofstream& fout) {
	ItemType listItem, userItem, compare, word[MAX_ITEMS];
	int count = 0;
	userItem.Initialize(pattern);
	list.ResetList();

	for (int i = 0; i < list.LengthIs(); i++) {
		list.GetNextItem(listItem);
		listItem.Subtract(listItem.LengthIs() - pattern.length(), pattern.length(), compare); //substr���� �ε���: listItem�� ����-pattern�� ����
		if (compare.ComparedTo(userItem) == EQUAL) {
			word[count] = listItem;
			count++;
		}
	}

	if (count == 1) { //�������� ã�� �ܾ �� ���� ��
		cout << "<ENDING>" << endl;
		fout << "<ENDING>" << endl;
		GetMeaning(word[0], fout, pattern); //����, �ܾ�, �ǹ� ���
	}

	else if (count > 1) { //�������� ã�� �ܾ �� �� �̻��� ��
		cout << "<ENDING>" << endl << "Pattern: " << pattern << endl << "Words: ";
		fout << "<ENDING>" << endl << "Pattern: " << pattern << endl << "Words: ";
		for (int i = 0; i < count; i++) {
			word[i].Print(cout);
			cout << '\t';
			word[i].Print(fout);
			fout << '\t';
		}
		cout << endl;
		fout << endl;
	}

	else if (count == 0) { //�������� �ܾ ã�� ����
		cout << "<ENDING>\nThere's no " << pattern << " in this dictionary\n";
		fout << "<ENDING>\nThere's no " << pattern << " in this dictionary\n";
	}
}

void FindAtContain(SortedType& list, string pattern, ofstream& fout) {
	ItemType listItem, userItem, word[MAX_ITEMS];
	int count = 0;
	userItem.Initialize(pattern);
	list.ResetList();

	for (int i = 0; i < list.LengthIs(); i++) {
		list.GetNextItem(listItem);
		if (listItem.IsThere(userItem)) { //userItem.value�� �ܼ��� listItem.value�ȿ� ���Ե� ������ true
			word[count] = listItem;
			count++;
		}
	}

	if (count == 1) { //�������� ã�� �ܾ �� ���� ��
		cout << "<CONTAINING>" << endl;
		fout << "<CONTAINING>" << endl;
		GetMeaning(word[0], fout, pattern); //����, �ܾ�, �ǹ� ���
	}

	else if (count > 1) { //�������� ã�� �ܾ �� �� �̻��� ��
		cout << "<CONTAINING>" << endl << "Pattern: " << pattern << endl << "Words: ";
		fout << "<CONTAINING>" << endl << "Pattern: " << pattern << endl << "Words: ";
		for (int i = 0; i < count; i++) {
			word[i].Print(cout);
			cout << '\t';
			word[i].Print(fout);
			fout << '\t';
		}
		cout << endl;
		fout << endl;
	}

	else if (count == 0) { //�������� �ܾ ã�� ����
		cout << "<CONTAINING>\nThere's no " << pattern << " in this dictionary\n";
		fout << "<CONTAINING>\nThere's no " << pattern << " in this dictionary\n";
	}
}