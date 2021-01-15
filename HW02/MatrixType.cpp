#include "MatrixType.h"

MatrixType::MatrixType() {
	numRows = 0;
	numCols = 0;
}
void MatrixType::MakeEmpty() {
	//pre: values배열은 0으로 초기화하고 이후 저장되는 값은 0을 제외한다.
	//post: values 안의 모든 값이 0으로 초기화된다.
	for (int i = 0; i < MAX_ROWS; i++) {
		for (int j = 0; j < MAX_COLS; j++)
			values[i][j] = 0;
	}
}
void MatrixType::SetSize(int rowsSize, int colSize) {
	//pre: rowSize와 colSize는 모두 MAX_ROWS와 MAX_COLS를 넘지 않는다.
	//post: numRows에 rowSize가, numCols에 colSize가 각각 저장된다.
	numRows = rowsSize;
	numCols = colSize;
}
void MatrixType::StoreItem(int item, int row, int col) {
	//pre: row는 numRows를, col은 numCols를 넘지 않고 item은 0이 아니다.
	//post: values의 [row][col]위치에 item이 저장된다.
	values[row][col] = item;
}
void MatrixType::Add(MatrixType otherOperand, MatrixType& result) {
	//pre: otherOperand와 numRows, numCols가 각각 같아야 한다.
	//post: otherOperand.values와 this->values가 더해져 result.values에 저장된다.
	if (this->AddSubCompatible(otherOperand)) {
		result.MakeEmpty();
		result.SetSize(this->numRows, this->numCols);
		for (int i = 0; i < numRows; i++) {
			for (int j = 0; j < numCols; j++)
				result.StoreItem(this->values[i][j] + otherOperand.values[i][j], i, j);
		}
	}
}
void MatrixType::Sub(MatrixType otherOperand, MatrixType& result) {
	//pre: otherOperand와 numRows, numCols가 각각 같아야 한다.
	//post: otherOperand.values를 this->values에서 뺀 값이 result.values에 저장된다.
	if (this->AddSubCompatible(otherOperand)) {
		result.MakeEmpty();
		result.SetSize(this->numRows, this->numCols);
		for (int i = 0; i < numRows; i++) {
			for (int j = 0; j < numCols; j++)
				result.StoreItem(this->values[i][j] - otherOperand.values[i][j], i, j);
		}
	}
}
void MatrixType::Mult(MatrixType otherOperand, MatrixType& result) {
	//pre: otherOperand.values의 행과 this->values의 열의 크기가 같아야한다.
	//post: otherOperand.values와 this->values가 곱해져 result.values에 저장된다.
	if (this->MultCompatible(otherOperand)) {
		result.MakeEmpty();
		result.SetSize(this->numRows, otherOperand.numCols); //n*r 곱하기 r*s = n*s
		int resultVal = 0;
		int resultIdx = 0;
		for (int i = 0; i < this->numRows; i++) {
			for (int j = 0; j < otherOperand.numCols; j++, resultIdx++) {
				if (resultIdx == otherOperand.numCols)
					resultIdx = 0;
				for (int k = 0; k < this->numCols; k++) //or otherOperand.numRows
					resultVal += this->values[i][k] * otherOperand.values[k][j];
				result.StoreItem(resultVal, i, resultIdx);
				resultVal = 0;
			}
		}
	}
}
void MatrixType::Print(ofstream& outfile) {
	//pre: numRows와 numCols이 각각 0이 아니어야 한다.
	//post: numRows * numCols 만큼의 values 값이 2차원 테이블로 출력된다.
	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j < numCols; j++)
			outfile << values[i][j] << "\t";
		outfile << endl;
	}
}
bool MatrixType::AddSubCompatible(MatrixType otherOperand) {
	//pre: 두 객체의 numRows, numCols변수가 초기화되어야 한다.
	//post: 두 객체의 numRows끼리, numCols끼리 값이 같은 경우 true를 반환, 그렇지 않으면 false를 반환한다.
	if (this->numRows == otherOperand.numRows && this->numCols == otherOperand.numCols)
		return true;
	else
		return false;
}
bool MatrixType::MultCompatible(MatrixType otherOperand) {
	//pre: 두 객체의 numRows, numCols변수가 초기화되어야 한다.
	//post: this->numCols와 otherOperand.numRows가 값이 같은 경우 true를 반환, 그렇지 않으면 false를 반환한다.
	if (this->numCols == otherOperand.numRows)
		return true;
	else
		return false;
}