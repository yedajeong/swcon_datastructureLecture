#pragma once

class TextEditor
{
public:
	//lab07-3-b
	TextEditor();
	//lab07-3-c
	void GoToTop();
	void GoToBottom();
	//lab07-3-d
	void InsertItem(const char* input);

private:
	LineType *Header;
	LineType *Trailer;
	LineType *currentLine;
};

//lab07-3-a
struct LineType {
	LineType* back;
	char newline[80];
	LineType* next;
};