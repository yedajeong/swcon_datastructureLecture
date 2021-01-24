#pragma once
#include "Student.h"

void SelectionSort(Student values[], int numValues);

int MinIndex(Student values[], int startIndex, int endIndex)
{
	int indexOfMin = startIndex;
	for (int index = startIndex + 1; index <= endIndex; index++)
	{
		//strcmp(str1, str2): str1>str2¸é 1, <¸é -1, ==¸é 0
		if (strcmp(values[index].getName(), values[indexOfMin].getName()) < 0)
			indexOfMin = index;
	}
	return indexOfMin;
}


void SelectionSort(Student values[], int numValues)
{
	int endIndex = numValues - 1;
	for (int current = 0; current < endIndex; current++)
		Swap(values[current], values[MinIndex(values, current, endIndex)]);
}