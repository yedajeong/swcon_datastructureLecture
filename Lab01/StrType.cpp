#include <cctype>
#include <fstream>
#include <iostream>
#include <cstring>

#include "StrType.h"
#include <cctype> 
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

//6-A
/*
RelationType StrType::ComparedTo(StrType &otherString) {
	RelationType result;
	if (strcmp(this->letters, otherString.letters) == -1) //other이 더 큼
		return result = LESS;
	else if (strcmp(this->letters, otherString.letters) == 0) //같음->문자열 길이 달라도(짧은 거 기준 앞부분까지 같을 때)길이 더 긴 걸 크다고 판정
		return result = EQUAL;
	else if (strcmp(this->letters, otherString.letters) == 1) //self가 더 큼
		return result = GREATER;
}
*/

//6-B
RelationType StrType::ComparedTo(StrType &otherString) {
	int idx = 0;
	RelationType result;

	//idx=0 일 때 검사
	if (this->letters[idx] > otherString.letters[idx])
		return result = GREATER;
	else if (this->letters[idx] < otherString.letters[idx])
		return result = LESS;

	//제일 첫 문자 같은 경우 while문 실행
	while (idx < strlen(this->letters) && idx < strlen(otherString.letters) && this->letters[idx] == otherString.letters[idx]) {
		idx++; //idx=1 부터 검사
		if (this->letters[idx] == otherString.letters[idx]) {
			continue;
		}
		else if (this->letters[idx] > otherString.letters[idx])
			return result = GREATER;
		else
			return result = LESS;
	}

	if (strlen(this->letters) > strlen(otherString.letters))
		return result = GREATER;
	else if (strlen(this->letters) < strlen(otherString.letters))
		return result = LESS;
	else
		return result = EQUAL;
}


// Prototypes of auxiliary functions.
// Note: If skip is true, non-allowable leading characters are
//  skipped. If end-of-file is encountered while skipping
//  characters, the empty string is returned. If the number
//  of allowable characters exceeds MAX_CHARS, the rest are
//  read and discarded.

void GetAlphaNum(bool skip, char letters[], std::ifstream& inFile);
// Post: letters array contains only alphanumeric characters.

//void GetAlpha(bool skip, char letters[], std::ifstream& inFile);
// Post: letters array contains only alphabetic characters.

//void GetNonWhite(bool skip, char letters[], std::ifstream& inFile);
// Post: letters array contains only non-whitespace characters.

void GetTilNew(bool skip, char letters[], std::ifstream& inFile);
// Post: letters array contains everything up to newline character.

void StrType::GetStringFile(bool skip, InType charsAllowed, std::ifstream& inFile)
{
  switch (charsAllowed)
  {
    case ALPHA_NUM : GetAlphaNum(skip, letters, inFile); 
                     break;
//    case ALPHA     : GetAlpha(skip, letters, inFile);
//                     break;
//    case NON_WHITE : GetNonWhite(skip, letters, inFile);
 //                    break;
    case NOT_NEW   : GetTilNew(skip, letters, inFile);
                     break;
  }
}

void GetAlphaNum(bool skip, char letters[], std::ifstream& inFile)
// Post: If skip is true, non-alphanumeric letters are skipped.
//       Alphanumeric characters are read and stored until a
//       non-alphanumeric character is read or MAX_CHARS characters
//       have been stored. If the stream is not in the fail state,
//       the last character read was a non-alphanumeric character.
{
  using namespace std;
  char letter;
  int count = 0;

  if (skip)
  {// skip non-alphanumeric characters
    inFile.get(letter);
    while (!isalnum(letter) && inFile)
      inFile.get(letter);
  }
  else
    inFile.get(letter);
  if (!inFile || !isalnum(letter))
  // No legal character found; empty string returned.
    letters[0] = '\0';
  else
  {// Read and collect characters.
    do
    {
      letters[count] = letter;
      count++;
      inFile.get(letter);
    } while (isalnum(letter) && inFile && (count < MAX_CHARS));

    letters[count] = '\0';
    // Skip extra characters if necessary.
    if (count == MAX_CHARS && isalnum(letter))
      do
      {
        inFile.get(letter);
      } while (isalnum(letter) && inFile);
  }
      
}

void GetTilNew(bool skip, char letters[], std::ifstream& inFile)
// Post: If skip is true, newline characters are skipped.
//       All characters are read and stored until a newline
//       character is read or MAX_CHARS characters have been
//       stored. If the stream is not in the fail state, the
//       last character read was a newline character.
{
  using namespace std;
  char letter;
  int count = 0;
  if (skip)
  {// skip newlines.
      inFile.get(letter);
      while ((letter == '\n') &&inFile)
        inFile.get(letter);
  }
  else
    inFile.get(letter);
  if (!inFile || letter == '\n')
    letters[0] = '\0';
  else
  {// Read and collect characters.
    do
    {
      letters[count] = letter;
      count++;
      inFile.get(letter);
    } while ((letter != '\n') && inFile && (count < MAX_CHARS));

    letters[count] = '\0';
    // Skip extra characters if necessary.
    if (count == MAX_CHARS && letter != '\n')

    do
    {
      inFile.get(letter);
    } while ((letter != '\n') && inFile);
  }
}

void StrType::PrintToScreen(bool newLine)
// Post:  letters has been sent to the output stream.
{
  if (newLine)
  cout  << endl;
  cout  << letters;
}

void StrType::MakeEmpty()
{
  letters[0] = '\0';
}  

void StrType::PrintToFile(bool newLine, ofstream& outFile)
{
  if (newLine)
    outFile << endl;
    outFile << letters;
}
     
void StrType::CopyString(StrType& newString)
// Post: letters has been copied into newString.letters.
{ 
  strcpy(newString.letters, letters);
}

int StrType::LengthIs()
{
  return strlen(letters);
}
