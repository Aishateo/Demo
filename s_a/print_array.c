#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
	size_t _i;

	_i = 0;
	while (array && _i < size)
	{
		if (_i > 0)
			printf(", ");
		printf("%d", array[_i]);
		++_i;
	}
	printf("\n");
}
