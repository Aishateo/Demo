#include "search_algos.h"

/**
 * linear_skip - Searches for an algorithm in a sorted singly
 * linked list of integers using linear skip.
 * @list: A pointer to the  head of the linked list to search.
 * @value: The value to search for.
 *  Return: If the value is not present or the head of the list is NULL, NULL.
 * Otherwise, a pointer to the first node where the value is located.
 * Description: Prints a value every time it is compared in the list.
 * Uses the square root of the list size as the _jump _step.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *node, *_jump;

	if (list == NULL)
		return (NULL);

	for (node = _jump = list; _jump->next != NULL && _jump->n < value;)
	{
		node = _jump;
		if (_jump->express != NULL)
		{
			_jump = _jump->express;
			printf("Value checked at index [%ld] = [%d]\n",
					_jump->index, _jump->n);
		}
		else
		{
			while (_jump->next != NULL)
				_jump = _jump->next;
		}
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
			node->index, _jump->index);

	for (; node->index < _jump->index && node->n < value; node = node->next)
		printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);
	printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);

	return (node->n == value ? node : NULL);
}
