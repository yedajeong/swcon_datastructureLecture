#include <iostream>

using namespace std;

int BinarySearchA(int array[], int sizeOfArray, int value) {
	int first, last, midPoint;
	first = 0;
	last = sizeOfArray - 1;

	while (first <= last) {
		midPoint = (first + last) / 2;
		if (value < array[midPoint]) //LESS
			last = midPoint - 1;
		else if (value > array[midPoint]) //GREATER
			first = midPoint + 1;
		else //EQUAL
			return midPoint;
	}
	return -1; //first > last인 경우 찾지 못함
}

int BinarySearchB(int array[], int sizeOfArray, int value) { //작거나 같은 값 중 최댓값
	int first, last, midPoint;
	first = 0;
	last = sizeOfArray - 1;

	while (first <= last) {
		midPoint = (first + last) / 2;
		if (value < array[midPoint]) //LESS
			last = midPoint - 1;
		else if (value > array[midPoint]) //GREATER
			first = midPoint + 1;
		else //EQUAL
			return midPoint;
	}
	return last;
}

int BinarySearchC(int array[], int sizeOfArray, int value) { //크거나 같은 값 중 최솟값
	int first, last, midPoint;
	first = 0;
	last = sizeOfArray - 1;

	while (first <= last) {
		midPoint = (first + last) / 2;
		if (value < array[midPoint]) //LESS
			last = midPoint - 1;
		else if (value > array[midPoint]) //GREATER
			first = midPoint + 1;
		else //EQUAL
			return midPoint;
	}
	return first;
}

int main() {
	int list[10] = { 1, 2, 4, 5, 6, 8, 9, 10 };
	int resultIdx = BinarySearchA(list, sizeof(list) / sizeof(list[0]), 11);
	cout << resultIdx << endl; //-1 리턴 (없음)
	resultIdx = BinarySearchB(list, sizeof(list) / sizeof(list[0]), 7);
	cout << resultIdx << endl; //4 리턴 list[4] = 6
	resultIdx = BinarySearchC(list, sizeof(list) / sizeof(list[0]), 3);
	cout << resultIdx << endl; //2 리턴 list[2] = 4

	return 0;
}