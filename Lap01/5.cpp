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
구조: int형의 데이터를 저장하고 N*N크기인 정사각형 2차원 배열
연산:
	MakeEmpty(n)
	기능-Matrix의 n 행 열 내부를 0으로 초기화
	조건-n의 최대 크기는 50
	결과-n안의 행 열은 0으로 초기화

	StoreValue(i, j, value)
	기능-value를 matrix의 i행 j열 위치에 저장
	조건-i와 j는 모두 0으로 초기화 된 n행(혹은 열)을 넘길 수 없음
	결과-matrix[i][j]에는 value가 저장

	Add(mat, result)
	기능-mat과 메소드를 호출한 객체의 matrix가 더해지고 그 결과가 result에 저장
	조건-더할 matrix들은 동일한 크기, result행렬도 같은 크기로 초기화
	결과-두 matrix의 합이 result에 저장

	Subtract(mat, result)
	기능-메소드를 호출한 객체의 matrix로부터 mat을 빼고 그 결과가 result에 저장
	조건-빼질 matrix와 뺄 matrix는 동일한 크기, result행렬도 같은 크기로 초기화
	결과-두 matrix의 차가 result에 저장

	Copy(mat)
	기능-mat의 원소들을 matrix에 대응되는 각 위치에 복사
	조건-두 행렬은 동일한 크기로 초기화
	결과-mat과 matrix는 동일한 행렬
*/

//시험 계획
/*
 메소드 이름		| input값								| 예상되는 output
 --------------------------------------------------------------------------------------------------
 MakeEmpty		| 3										| matrix의 3행 3열 안의 원소들이 0으로 초기화
 StoreValue		| i=0, j=0, value=1						| matrix[0][0]에 1이 저장
 Add			| mat.matrix = [[1, 2], [0, 0], [2, 4]] | result.matrix = [[2, 2], [0, 0], [2, 4]]
				| result.matrix = result[3][3]			|
 Subtract		| mat.matrix = [[0, 1], [1, 0], [0, 0]] | result.matrix = [[1, -1], [-1, 0], [0, 0]]
				| result = result[3][3]					|
 Copy			| mat.matrix = [[2, 3], [0, 2], [5, 1]] | 호출한 객체.matrix == [[2, 3], [0, 2], [5, 1]]
*/