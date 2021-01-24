#pragma once
#include "Student.h"

void BubbleSort(Student values[], int numValues);

void BubbleDown(Student values[], int startIndex, int endIndex)
{
	for (int index = startIndex; index < endIndex; index++)
	{
		//strcmp(str1, str2): str1>str2¸é 1, <¸é -1, ==¸é 0
		if (strcmp(values[index].getName(), values[index + 1].getName()) > 0)
			Swap(values[index], values[index + 1]);
	}
}

void BubbleSort(Student values[], int numValues)
{
	int current = numValues - 1;

	while (current < 1)
	{
		BubbleDown(values, 0, current);
		current--;
	}
}