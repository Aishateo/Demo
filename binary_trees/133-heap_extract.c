#include "binary_trees.h"

#define INIT_NODE {0, NULL, NULL, NULL}

#define CONVERT "0123456789ABCDEF"

#define SETUP_NODE_BLOC { \
	tmp = *root; \
	size = binary_tree_size(*root); \
	binary = &buffer[49]; \
	*binary = 0; \
	}

#define FREE_NODE_BLOC { \
		res = tmp->n; \
		free(tmp); \
		*root = NULL; \
	}

#define SWAP_HEAD_BLOC { \
		head = *root; \
		head = swap_head(head, tmp); \
		res = head->n; \
		free(head); \
		*root = tmp; \
		tmp = perc_down(tmp); \
		*root = tmp; \
	}

#define CONVERT_LOOP { \
		*--binary = CONVERT[size % 2]; \
		size /= 2; \
	}

/**
 * swap - swaps two nodes in binary tree
 * @a: first node
 * @b: second node
 * Return: pointer to root
 */
bst_t *swap(bst_t *a, bst_t *b)
{
	bst_t a_copy = INIT_NODE;

	a_copy.n = a->n;
	a_copy.parent = a->parent;
	a_copy._left = a->_left;
	a_copy._right = a->_right;
	a->parent = b;
	a->_left = b->_left;
	a->_right = b->_right;
	if (b->_left)
		b->_left->parent = a;
	if (b->_right)
		b->_right->parent = a;

	b->parent = a_copy.parent;
	if (a_copy.parent)
	{
		if (a == a_copy.parent->_left)
			a_copy.parent->_left = b;
		else
			a_copy.parent->_right = b;
	}
	if (b == a_copy._left)
	{
		b->_left = a;
		b->_right = a_copy._right;
		if (a_copy._right)
			a_copy._right->parent = b;
	}
	else if (b == a_copy._right)
	{
		b->_right = a;
		b->_left = a_copy._left;
		if (a_copy._left)
			a_copy._left->parent = b;
	}
	while (b->parent)
		b = b->parent;
	return (b);
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: input binary tree
 * Return: number of descendant child nodes
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + binary_tree_size(tree->_left) + binary_tree_size(tree->_right));
}

/**
 * swap_head - helper func to swap head and node
 * @head: pointer to head
 * @node: pointer to node
 * Return: pointer to severed head of tree
 */
heap_t *swap_head(heap_t *head, heap_t *node)
{
	if (node->parent->_left == node)
	{
		node->parent->_left = NULL;
	} else
		node->parent->_right = NULL;
	node->parent = NULL;
	node->_left = head->_left;
	node->_right = head->_right;
	if (head->_left)
		head->_left->parent = node;
	if (head->_right)
		head->_right->parent = node;
	return (head);
}

/**
 * perc_down - percolate head into correct position
 * @node: pointer to head
 * Return: pointer to head of tree
 */
heap_t *perc_down(heap_t *node)
{
	int max;
	heap_t *next = node;

	if (!node)
		return (NULL);
	max = node->n;
	if (node->_left)
		max = MAX(node->_left->n, max);
	if (node->_right)
		max = MAX(node->_right->n, max);
	if (node->_left && max == node->_left->n)
		next = node->_left;
	else if (node->_right && max == node->_right->n)
		next = node->_right;
	if (next != node)
	{
		swap(node, next);
		perc_down(node);
	}
	return (next);
}

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to root of tree
 * Return: value stored in the root node
 */
int heap_extract(heap_t **root)
{
	size_t size, i;
	char *binary, c, buffer[50];
	int res;
	heap_t *tmp, *head;

	if (!root || !*root)
		return (0);
	SETUP_NODE_BLOC;
	if (size == 1)
	{
		FREE_NODE_BLOC;
		return (res);
	}
	do {
		CONVERT_LOOP;
	} while (size);

	for (i = 1; i < strlen(binary); i++)
	{
		c = binary[i];
		if (i == strlen(binary) - 1)
		{
			if (c == '1')
			{
				tmp = tmp->_right;
				break;
			}
			else if (c == '0')
			{
				tmp = tmp->_left;
				break;
			}
		}
		if (c == '1')
			tmp = tmp->_right;
		else if (c == '0')
			tmp = tmp->_left;
	}
	SWAP_HEAD_BLOC;
	return (res);
}
