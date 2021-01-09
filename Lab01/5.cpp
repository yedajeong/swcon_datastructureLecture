#include <iostream>
using namespace std;

const int MAX_ROWS = 50;
const int MAX_COLS = 50;
class SquareMatrix {
private:
	int matrix[50][50];
public:
	void MakeEmpty(int n) {
		int i, j = 0;
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++)
				matrix[i][j] = 0;
		}
	}
	void StoreValue(int i, int j, int value) {
		matrix[i][j] = value;
	}
	void Add(SquareMatrix &mat, SquareMatrix &result) {
		for (int i = 0; i < MAX_ROWS; i++) {
			for (int j = 0; j < MAX_COLS; j++)
				result.matrix[i][i] = this->matrix[i][j] + mat.matrix[i][j];
		}
	}
	void Subtract(SquareMatrix &mat, SquareMatrix &result) {
		for (int i = 0; i < MAX_ROWS; i++) {
			for (int j = 0; j < MAX_COLS; j++)
				result.matrix[i][i] = this->matrix[i][j] - mat.matrix[i][j];
		}
	}
	void Copy(SquareMatrix &mat) {
		for (int i = 0; i < MAX_ROWS; i++) {
			for (int j = 0; j < MAX_COLS; j++)
				this->matrix[i][j] = mat.matrix[i][j];
		}
	}
};

//SquareMatrix Specification
/*
����: int���� �����͸� �����ϰ� N*Nũ���� ���簢�� 2���� �迭
����:
	MakeEmpty(n)
	���-Matrix�� n �� �� ���θ� 0���� �ʱ�ȭ
	����-n�� �ִ� ũ��� 50
	���-n���� �� ���� 0���� �ʱ�ȭ

	StoreValue(i, j, value)
	���-value�� matrix�� i�� j�� ��ġ�� ����
	����-i�� j�� ��� 0���� �ʱ�ȭ �� n��(Ȥ�� ��)�� �ѱ� �� ����
	���-matrix[i][j]���� value�� ����

	Add(mat, result)
	���-mat�� �޼ҵ带 ȣ���� ��ü�� matrix�� �������� �� ����� result�� ����
	����-���� matrix���� ������ ũ��, result��ĵ� ���� ũ��� �ʱ�ȭ
	���-�� matrix�� ���� result�� ����

	Subtract(mat, result)
	���-�޼ҵ带 ȣ���� ��ü�� matrix�κ��� mat�� ���� �� ����� result�� ����
	����-���� matrix�� �� matrix�� ������ ũ��, result��ĵ� ���� ũ��� �ʱ�ȭ
	���-�� matrix�� ���� result�� ����

	Copy(mat)
	���-mat�� ���ҵ��� matrix�� �����Ǵ� �� ��ġ�� ����
	����-�� ����� ������ ũ��� �ʱ�ȭ
	���-mat�� matrix�� ������ ���
*/

//���� ��ȹ
/*
 �޼ҵ� �̸�		| input��								| ����Ǵ� output
 --------------------------------------------------------------------------------------------------
 MakeEmpty		| 3										| matrix�� 3�� 3�� ���� ���ҵ��� 0���� �ʱ�ȭ
 StoreValue		| i=0, j=0, value=1						| matrix[0][0]�� 1�� ����
 Add			| mat.matrix = [[1, 2], [0, 0], [2, 4]] | result.matrix = [[2, 2], [0, 0], [2, 4]]
				| result.matrix = result[3][3]			|
 Subtract		| mat.matrix = [[0, 1], [1, 0], [0, 0]] | result.matrix = [[1, -1], [-1, 0], [0, 0]]
				| result = result[3][3]					|
 Copy			| mat.matrix = [[2, 3], [0, 2], [5, 1]] | ȣ���� ��ü.matrix == [[2, 3], [0, 2], [5, 1]]
*/