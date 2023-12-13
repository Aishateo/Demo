#include "search_algos.h"

/**
 * jump_list - Searches for an algorithm in a sorted singly
 * linked list of integers using _jump search.
 * @list: A pointer to the  head of the linked list to search.
 * @size: The number of nodes in the list.
 * @value: The value to search for.
 * Return: If the value is not present or the head of the list is NULL, NULL.
 * Otherwise, a pointer to the first node where the value is located.
 * Description: Prints a value every time it is compared in the list.
 * Uses the square root of the list size as the _jump _step.
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t _step, step_size;
	listint_t *node, *_jump;

	if (list == NULL || size == 0)
		return (NULL);

	_step = 0;
	step_size = sqrt(size);
	for (node = _jump = list; _jump->index + 1 < size && _jump->n < value;)
	{
		node = _jump;
		for (_step += step_size; _jump->index < _step; _jump = _jump->next)
		{
			if (_jump->index + 1 == size)
				break;
		}
		printf("Value checked at index [%ld] = [%d]\n", _jump->index, _jump->n);
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
			node->index, _jump->index);

	for (; node->index < _jump->index && node->n < value; node = node->next)
		printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);
	printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);

	return (node->n == value ? node : NULL);
}
