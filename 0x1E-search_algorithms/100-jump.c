#include "search_algos.h"

/**
  * jump_search - Searches for a value in a sorted array
  * of integers using _jump search.
  *
  * @array: A pointer to the first element of the array to search.
  * @size: The number of elements in the array.
  * @value: The value to search for.
  * Return: If the value is not present or the array is NULL, -1.
  * Otherwise, the first index where the value is located.
  * Description: Prints a value every time it is compared in the array.
  * Uses the square root of the array size as the _jump _step.
  */
int jump_search(int *array, size_t size, int value)
{
	size_t i, _jump, _step;

	if (array == NULL || size == 0)
		return (-1);

	_step = sqrt(size);
	for (i = _jump = 0; _jump < size && array[_jump] < value;)
	{
		printf("Value checked array[%ld] = [%d]\n", _jump, array[_jump]);
		i = _jump;
		_jump += _step;
	}

	printf("Value found between indexes [%ld] and [%ld]\n", i, _jump);

	_jump = _jump < size - 1 ? _jump : size - 1;
	for (; i < _jump && array[i] < value; i++)
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
	printf("Value checked array[%ld] = [%d]\n", i, array[i]);

	return (array[i] == value ? (int)i : -1);
}
