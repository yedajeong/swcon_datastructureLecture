#include "SquareMatrix.h"



SquareMatrix::SquareMatrix(int _length) : length(_length) {};

void SquareMatrix::MakeEmpty(int n) {
	int i, j = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			matrix[i][j] = 0;
	}
	length = n;
}
void SquareMatrix::StoreValue(int i, int j, int value) {
	matrix[i][j] = value;
}
void SquareMatrix::Add(SquareMatrix mat, SquareMatrix &result) {
	for (int i = 0; i < this->length; i++) {
		for (int j = 0; j < this->length; j++)
			result.matrix[i][i] = this->matrix[i][j] + mat.matrix[i][j];
	}
}
void SquareMatrix::Subtract(SquareMatrix mat, SquareMatrix &result) {
	for (int i = 0; i < this->length; i++) {
		for (int j = 0; j < this->length; j++)
			result.matrix[i][i] = this->matrix[i][j] - mat.matrix[i][j];
	}
}
void SquareMatrix::Copy(SquareMatrix mat) {
	for (int i = 0; i < this->length; i++) {
		for (int j = 0; j < this->length; j++)
			this->matrix[i][j] = mat.matrix[i][j];
	}
}