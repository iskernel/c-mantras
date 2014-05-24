#include"cm_searching.h"

uint LinearSearch(number key, number array[], number arraySize)
{
	uint i;
	for (i = 0; i < arraySize && array[i] != key; i++)
		;
	return i;
}

uint SentinelLinearSearch(number key, number array[], number arraySize)
{
	uint i;
	array[arraySize] = key;
	for (i = 0; array[i] != key; i++)
		;
	return i;
}

uint BinarySearch(number key, number array[], number arraySize)
{
	uint left = 0, right = arraySize - 1, middle;
	do
	{
		middle = (left + right) / 2;
		(key > array[middle]) ? (left = middle + 1) : (right = middle - 1);
	} while (array[middle] != key && left <= right);
	return (array[middle] != key) ? arraySize : middle;
}

uint ImprovedBinarySearch(number key, number array[], number arraySize)
{
	uint left = 0, right = arraySize, middle;
	do
	{
		middle = (left + right) / 2;
		(key > array[middle]) ? (left = middle + 1) : (right = middle);
	} while (left < right);
	return (((right >= arraySize) || (right < arraySize && array[right] == key)) ?
			arraySize : right);
}

uint InterpolationSearch(number key, number array[], number arraySize)
{
	uint middle, left = 0, right = arraySize - 1;
	if (key <= array[right] && key >= array[left])
		do
		{
			middle = left
					+ (key - array[left]) * (right - left)
							/ (array[right] - array[left]);
			if (key > array[middle])
				left = middle + 1;
			else
				right = middle - 1;
		} while (array[middle] != key && left < right
				&& array[left] != array[right] && key >= array[left]
				&& key <= array[right]);
	return middle;
}

