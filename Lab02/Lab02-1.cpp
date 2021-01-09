#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) { //argv[0]�� �������� �̸�
	ifstream fin(argv[1]); //mac file
	ofstream fout(argv[2]); //window file

	char ch;
	while (!fin.eof()) { //������ ���� �ƴ� ������ ���� �ݺ�
		fin.get(ch);
		if (fin.eof()) //ch�޾ƿ��� �� ������ ������ ���������� �ߺ� ����, break ���ֱ�
			break;
		if (fin.bad())
			break;
		if (ch == 0x0D) { //CR�̸� 0x0D(mac����) LF�� 0x0A(unix,linux����)
			fout << '\n'; //CR LF����, (window����) ios::binary�� �ȹ����� '\n'->CR LF�� ���ļ� �ν�!
			cout << "���๮�� �����" << endl;
		}
		else
			fout << ch;
	}
	fin.close();
	fout.close();

	return 0;
}