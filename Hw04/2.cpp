#include <iostream>
#include <fstream>
#include <string>
#include "sorted.h"

using namespace std;

//hw04-3: ItemType의 value -> string
//사용자 키보드 입력(1-4 숫자)에 대응시킬 명령어
enum CommandType {STARTING, ENDING, CONTAINING, STOP};

//Words.txt파일로부터 word에 해당하는 단어들만 찾아 sorted list에 저장
void FileToList(SortedType& wordList);

//사용자로부터 키보드 입력을 받아들임
void GetCommand(CommandType& command);

//입력한 pattern으로 시작하는 단어를 찾음
void FindAtStart(SortedType& list, string pattern, ofstream& fout);

//입력한 pattern으로 끝나는 단어를 찾음
void FindAtEnd(SortedType& list, string pattern, ofstream& fout);

//입력한 pattern을 포함하는 단어를 찾음
void FindAtContain(SortedType& list, string pattern, ofstream& fout);

//item에 해당하는 의미를 Words.txt에서 찾아서 사용자의 패턴, 단어, 의미를 화면과 파일에 출력함
void GetMeaning(ItemType& item, ofstream& fout, string pattern);

int main() {
	
	ofstream fout("Patterns.txt");
	CommandType command;
	SortedType wordList;
	string pattern;

	//텍스트파일로부터 단어들만 잘라서 wordList에 저장, 사전 순으로 정렬
	FileToList(wordList);
	
	//사용자로부터 1-4까지 입력, 그에 대응되는 command를 매칭
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
		location = getWord.find(":"); //단어: 의미 로 구성된 getWord에서 :찾기
		getWord = getWord.substr(0, location); //단어에서 콜론 떼고 getWord에 저장

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
		default: //1-4 이외의 입력을 받은 경우만 ok = false, while문 다시 돔
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
		compare.Initialize(meaning.substr(0, location)); //compare.Initialize(Words.txt의 단어)

		if (compare.ComparedTo(item) == EQUAL) { //item이 텍스트 파일 안의 단어들 중에 있는지 검사
			meaning = meaning.substr(location + 2); //해당 item의 의미->콜론+2 인덱스부터 끝까지 끊기
			//화면 출력
			cout << "Pattern: " << pattern << endl;
			cout << "Word: ";
			item.Print(cout);
			cout << endl << "Meaning: " << meaning << endl;

			//파일 출력
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
	int count = 0; //사전에서 조건이 맞는 단어의 수
	userItem.Initialize(pattern); //사용자의 패턴을 ItemType으로 만듦 (wordList의 item들과 비교하기 위함)
	list.ResetList();

	for(int i = 0; i < list.LengthIs(); i++) {
		list.GetNextItem(listItem);
		listItem.Subtract(0, pattern.length(), compare); //리스트 안의 아이템 listItem 가공 ->idx 0부터 pattern의 길이 만큼 compare에 저장
		if (compare.ComparedTo(userItem) == EQUAL) { //사용자의 패턴과 listItem을 가공한 compare이 같음 = 단어를 찾음
			word[count] = listItem;
			count++;
		}
	}

	if (count == 1) { //사전에서 찾은 단어가 한 개일 때
		cout << "<STARTING>" << endl;
		fout << "<STARTING>" << endl;
		GetMeaning(word[0], fout, pattern); //패턴, 단어, 의미 출력
	}

	else if (count > 1) { //사전에서 찾은 단어가 두 개 이상일 때
		cout << "<STARTING>" << endl << "Pattern: " << pattern << endl << "Words: ";
		fout << "<STARTING>" << endl << "Pattern: " << pattern << endl << "Words: ";
		for (int i = 0; i < count; i++) { //의미는 출력하지 않고(GetMeaning함수 x) 단어를 나열만 함
			word[i].Print(cout);
			cout << '\t';
			word[i].Print(fout);
			fout << '\t';
		}
		cout << endl;
		fout << endl;
	}

	else if (count == 0) { //사전에서 단어를 찾지 못함
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
		listItem.Subtract(listItem.LengthIs() - pattern.length(), pattern.length(), compare); //substr시작 인덱스: listItem의 길이-pattern의 길이
		if (compare.ComparedTo(userItem) == EQUAL) {
			word[count] = listItem;
			count++;
		}
	}

	if (count == 1) { //사전에서 찾은 단어가 한 개일 때
		cout << "<ENDING>" << endl;
		fout << "<ENDING>" << endl;
		GetMeaning(word[0], fout, pattern); //패턴, 단어, 의미 출력
	}

	else if (count > 1) { //사전에서 찾은 단어가 두 개 이상일 때
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

	else if (count == 0) { //사전에서 단어를 찾지 못함
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
		if (listItem.IsThere(userItem)) { //userItem.value가 단순히 listItem.value안에 포함돼 있으면 true
			word[count] = listItem;
			count++;
		}
	}

	if (count == 1) { //사전에서 찾은 단어가 한 개일 때
		cout << "<CONTAINING>" << endl;
		fout << "<CONTAINING>" << endl;
		GetMeaning(word[0], fout, pattern); //패턴, 단어, 의미 출력
	}

	else if (count > 1) { //사전에서 찾은 단어가 두 개 이상일 때
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

	else if (count == 0) { //사전에서 단어를 찾지 못함
		cout << "<CONTAINING>\nThere's no " << pattern << " in this dictionary\n";
		fout << "<CONTAINING>\nThere's no " << pattern << " in this dictionary\n";
	}
}