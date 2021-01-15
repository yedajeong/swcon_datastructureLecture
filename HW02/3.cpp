#include "MatrixType.h"

using namespace std;

enum Menu {New, Add, Sub, Mult, Print, Quit};

int main() {
	MatrixType mat1, mat2, result;
	ofstream fout("matrixOut.txt");
	int key;

	while (1) {
		cout << "\nEnter a key (0~5)\n"
			<< "0: GetNewMatrix\n"
			<< "1: AddMatrices\n"
			<< "2: SubMatrices\n"
			<< "3: MultMatrices\n"
			<< "4: PrintMatrices\n"
			<< "5: Quit\n\n";

		cin >> key;

		switch (key) {
		case New:
			int row, col, value;
			cout << "Enter a row size(1): ";
			cin >> row;
			cout << "Enter a col size(1): ";
			cin >> col;
			mat1.MakeEmpty();
			mat1.SetSize(row, col);
			cout << "Enter a value(1): ";
			cin >> value;
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					mat1.StoreItem(value, i, j);
				}
			}

			cout << "\nEnter a row size(2): ";
			cin >> row;
			cout << "Enter a col size(2): ";
			cin >> col;
			mat2.MakeEmpty();
			mat2.SetSize(row, col);
			cout << "Enter a value(2): ";
			cin >> value;
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					mat2.StoreItem(value, i, j);
				}
			}

			break;

		case Add:
			//AddMatrices
			mat1.Add(mat2, result);
			break;

		case Sub:
			//SubMatrices
			mat1.Sub(mat2, result);
			break;

		case Mult:
			//MultMatrices
			mat1.Mult(mat2, result);
			break;

		case Print:
			//PrintMatrix
			result.Print(fout);
			fout.close();
			break;

		case Quit:
			exit(100);
		}
	}
		
	
	return 0;
}