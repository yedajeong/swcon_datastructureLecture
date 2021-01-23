#include <iostream>
#include "TextEditor.h"

using namespace std;

//lab07-3-b
TextEditor::TextEditor()
{
	Header->back = NULL;
	strcpy(Header->newline, "---Top of file---");
	Header->next = Trailer;

	Trailer->back = Header;
	strcpy(Trailer->newline, "---Bottom of file---");
	Trailer->next = NULL;

	currentLine = Header;
}

//lab07-3-c
void TextEditor::GoToTop() {
	while (currentLine->back != NULL)
		currentLine = currentLine->back;
	currentLine = currentLine->next;
}

void TextEditor::GoToBottom() {
	while (currentLine->next != NULL)
		currentLine = currentLine->next;
	currentLine = currentLine->back;
}

//lab07-3-d
//O(1)이 되는 경우: GoToTop - currentLine이 Header를 가리킬 때 / GoToBottom - currentLine이 Trailer를 가리킬 때

//lab07-3-e
void TextEditor::InsertItem(const char* input) {
	LineType *inputText = new LineType;
	strcpy(inputText->newline, input);

	if (currentLine == Trailer) {
		Header->next = inputText;
		Trailer->back = inputText;
		inputText->back = Header;
		inputText->next = Trailer;
	}

	else {
		inputText->back = currentLine;
		inputText->next = currentLine->next;
		currentLine->next = inputText;
		(inputText->next)->back = inputText;
	}

	currentLine = inputText;
}
