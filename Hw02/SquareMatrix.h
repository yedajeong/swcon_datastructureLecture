#pragma once

const int MAX_ROWS = 50;
const int MAX_COLS = 50;
class SquareMatrix {
private:
	int matrix[MAX_ROWS][MAX_COLS];
	int length;
public:
	SquareMatrix(int _length);
	void MakeEmpty(int n);
	void StoreValue(int i, int j, int value);
	void Add(SquareMatrix mat, SquareMatrix &result);
	void Subtract(SquareMatrix mat, SquareMatrix &result);
	void Copy(SquareMatrix mat);
};

