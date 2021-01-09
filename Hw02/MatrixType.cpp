#include "MatrixType.h"

MatrixType::MatrixType() {
	numRows = 0;
	numCols = 0;
}
void MatrixType::MakeEmpty() {
	//pre: values�迭�� 0���� �ʱ�ȭ�ϰ� ���� ����Ǵ� ���� 0�� �����Ѵ�.
	//post: values ���� ��� ���� 0���� �ʱ�ȭ�ȴ�.
	for (int i = 0; i < MAX_ROWS; i++) {
		for (int j = 0; j < MAX_COLS; j++)
			values[i][j] = 0;
	}
}
void MatrixType::SetSize(int rowsSize, int colSize) {
	//pre: rowSize�� colSize�� ��� MAX_ROWS�� MAX_COLS�� ���� �ʴ´�.
	//post: numRows�� rowSize��, numCols�� colSize�� ���� ����ȴ�.
	numRows = rowsSize;
	numCols = colSize;
}
void MatrixType::StoreItem(int item, int row, int col) {
	//pre: row�� numRows��, col�� numCols�� ���� �ʰ� item�� 0�� �ƴϴ�.
	//post: values�� [row][col]��ġ�� item�� ����ȴ�.
	values[row][col] = item;
}
void MatrixType::Add(MatrixType otherOperand, MatrixType& result) {
	//pre: otherOperand�� numRows, numCols�� ���� ���ƾ� �Ѵ�.
	//post: otherOperand.values�� this->values�� ������ result.values�� ����ȴ�.
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
	//pre: otherOperand�� numRows, numCols�� ���� ���ƾ� �Ѵ�.
	//post: otherOperand.values�� this->values���� �� ���� result.values�� ����ȴ�.
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
	//pre: otherOperand.values�� ��� this->values�� ���� ũ�Ⱑ ���ƾ��Ѵ�.
	//post: otherOperand.values�� this->values�� ������ result.values�� ����ȴ�.
	if (this->MultCompatible(otherOperand)) {
		result.MakeEmpty();
		result.SetSize(this->numRows, otherOperand.numCols); //n*r ���ϱ� r*s = n*s
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
	//pre: numRows�� numCols�� ���� 0�� �ƴϾ�� �Ѵ�.
	//post: numRows * numCols ��ŭ�� values ���� 2���� ���̺�� ��µȴ�.
	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j < numCols; j++)
			outfile << values[i][j] << "\t";
		outfile << endl;
	}
}
bool MatrixType::AddSubCompatible(MatrixType otherOperand) {
	//pre: �� ��ü�� numRows, numCols������ �ʱ�ȭ�Ǿ�� �Ѵ�.
	//post: �� ��ü�� numRows����, numCols���� ���� ���� ��� true�� ��ȯ, �׷��� ������ false�� ��ȯ�Ѵ�.
	if (this->numRows == otherOperand.numRows && this->numCols == otherOperand.numCols)
		return true;
	else
		return false;
}
bool MatrixType::MultCompatible(MatrixType otherOperand) {
	//pre: �� ��ü�� numRows, numCols������ �ʱ�ȭ�Ǿ�� �Ѵ�.
	//post: this->numCols�� otherOperand.numRows�� ���� ���� ��� true�� ��ȯ, �׷��� ������ false�� ��ȯ�Ѵ�.
	if (this->numCols == otherOperand.numRows)
		return true;
	else
		return false;
}