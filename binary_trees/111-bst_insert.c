#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree.
 * @tree: A double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *curr, *nw;

	if (tree != NULL)
	{
		curr = *tree;

		if (curr == NULL)
		{
			nw = binary_tree_node(curr, value);
			if (nw == NULL)
				return (NULL);
			return (*tree = nw);
		}

		if (value < curr->n) /* insert in _left subtree */
		{
			if (curr->_left != NULL)
				return (bst_insert(&curr->_left, value));

			nw = binary_tree_node(curr, value);
			if (nw == NULL)
				return (NULL);
			return (curr->_left = nw);
		}
		if (value > curr->n) /* insert in _right subtree */
		{
			if (curr->_right != NULL)
				return (bst_insert(&curr->_right, value));

			nw = binary_tree_node(curr, value);
			if (nw == NULL)
				return (NULL);
			return (curr->_right = nw);
		}
	}
	return (NULL);
}
