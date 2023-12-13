#include "search_algos.h"

/**
  * _binary_search - Searches for a value in a sorted array
  * of integers using binary search.
  * @array: A pointer to the first element of the array to search.
  * @_left: The starting index of the [sub]array to search.
  * @_right: The ending index of the [sub]array to search.
  * @value: The value to search for.
  * Return: If the value is not present or the array is NULL, -1.
  * Otherwise, the index where the value is located.
  * Description: Prints the [sub]array being searched after each change.
  */
int _binary_search(int *array, size_t _left, size_t _right, int value)
{
	size_t i;

	if (array == NULL)
		return (-1);

	while (_right >= _left)
	{
		printf("Searching in array: ");
		for (i = _left; i < _right; i++)
			printf("%d, ", array[i]);
		printf("%d\n", array[i]);

		i = _left + (_right - _left) / 2;
		if (array[i] == value)
			return (i);
		if (array[i] > value)
			_right = i - 1;
		else
			_left = i + 1;
	}

	return (-1);
}

/**
  * exponential_search - Searches for a value in a sorted array
  *                      of integers using exponential search.
  * @array: A pointer to the first element of the array to search.
  * @size: The number of elements in the array.
  * @value: The value to search for.
  *
  * Return: If the value is not present or the array is NULL, -1.
  *         Otherwise, the index where the value is located.
  *
  * Description: Prints a value every time it is compared in the array.
  */
int exponential_search(int *array, size_t size, int value)
{
	size_t i = 0, _right;

	if (array == NULL)
		return (-1);

	if (array[0] != value)
	{
		for (i = 1; i < size && array[i] <= value; i = i * 2)
			printf("Value checked array[%ld] = [%d]\n", i, array[i]);
	}

	_right = i < size ? i : size - 1;
	printf("Value found between indexes [%ld] and [%ld]\n", i / 2, _right);
	return (_binary_search(array, i / 2, _right, value));
}
