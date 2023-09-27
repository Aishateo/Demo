#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int _tmp;

	_tmp = *a;
	*a = *b;
	*b = _tmp;
}

/**
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t _g, i, j;

	if (array == NULL || size < 2)
		return;

	for (_g = 1; _g < (size / 3);)
		_g = _g * 3 + 1;

	for (; _g >= 1; _g /= 3)
	{
		for (i = _g; i < size; i++)
		{
			j = i;
			while (j >= _g && array[j - _g] > array[j])
			{
				swap_ints(array + j, array + (j - _g));
				j -= _g;
			}
		}
		print_array(array, size);
	}
}
