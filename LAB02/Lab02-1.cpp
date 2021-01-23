#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) { //argv[0]은 실행파일 이름
	ifstream fin(argv[1]); //mac file
	ofstream fout(argv[2]); //window file

	char ch;
	while (!fin.eof()) { //파일의 끝이 아닐 때까지 루프 반복
		fin.get(ch);
		if (fin.eof()) //ch받아왔을 때 파일이 끝나면 마지막문자 중복 방지, break 해주기
			break;
		if (fin.bad())
			break;
		if (ch == 0x0D) { //CR이면 0x0D(mac기준) LF면 0x0A(unix,linux기준)
			fout << '\n'; //CR LF쓰기, (window기준) ios::binary로 안받으면 '\n'->CR LF로 합쳐서 인식!
			cout << "개행문자 변경됨" << endl;
		}
		else
			fout << ch;
	}
	fin.close();
	fout.close();

	return 0;
}