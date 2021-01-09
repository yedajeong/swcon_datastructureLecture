#include <iostream>
#include "SquareMatrix.h"
using namespace std;

int main() {
	SquareMatrix mat1(3), mat2(3), resultM(3);
	mat1.MakeEmpty(3);
	mat2.MakeEmpty(3);
	resultM.MakeEmpty(3);

	mat1.StoreValue(0, 0, 1);
	mat2.StoreValue(1, 0, 2);
	mat1.Add(mat2, resultM);
	mat1.Subtract(mat2, resultM);
	mat1.Copy(resultM);

	return 0;
}

//���� ��ȹ
/*
 �޼ҵ� �̸�		| input��								| ����Ǵ� output
 --------------------------------------------------------------------------------------------------
 MakeEmpty		| 3										| matrix�� 3�� 3�� ���� ���ҵ��� 0���� �ʱ�ȭ
 StoreValue		| i=0, j=0, value=1						| mat1[0][0]�� 1�� ����
 Add			| mat1 [[1, 0], [0, 0], [0, 0]]			| result [[1, 0], [2, 0], [0, 0]]
				| mat2 [[0, 0], [2, 0], [0, 0]]			|
 Subtract		| mat1 [[1, 0], [0, 0], [0, 0]]			| result [[1, 0], [-2, 0], [0, 0]]
				| mat2 [[0, 0], [2, 0], [0, 0]]			|
 Copy			| result [[1, 0], [-2, 0], [0, 0]]		| mat1 [[1, 0], [-2, 0], [0, 0]]
*/