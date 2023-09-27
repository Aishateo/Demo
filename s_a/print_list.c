#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list)
{
	int _i;

	_i = 0;
	while (list)
	{
		if (_i > 0)
			printf(", ");
		printf("%d", list->n);
		++_i;
		list = list->next;
	}
	printf("\n");
}
