#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *_buff);
void radix_sort(int *array, size_t size);

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int _maximum, i;

	for (_maximum = array[0], i = 1; i < size; i++)
	{
		if (array[i] > _maximum)
			_maximum = array[i];
	}

	return (_maximum);
}

/**
 * radix_counting_sort - Sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * @sig: The significant digit to sort on.
 * @_buff: A buffer to store the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *_buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / sig) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		_buff[count[(array[i] / sig) % 10] - 1] = array[i];
		count[(array[i] / sig) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = _buff[i];
}

/**
 * radix_sort - Sort an array of integers in ascending
 *              order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int _maximum, sig, *_buff;

	if (array == NULL || size < 2)
		return;

	_buff = malloc(sizeof(int) * size);
	if (_buff == NULL)
		return;

	_maximum = get_max(array, size);
	for (sig = 1; _maximum / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, _buff);
		print_array(array, size);
	}

	free(_buff);
}
