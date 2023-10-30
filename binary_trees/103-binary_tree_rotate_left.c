#include "binary_trees.h"

/**
 * binary_tree_rotate_left - _left-rotates a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the nw root node after rotation.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pivot, *tmp;

	if (tree == NULL || tree->_right == NULL)
		return (NULL);

	pivot = tree->_right;
	tmp = pivot->_left;
	pivot->_left = tree;
	tree->_right = tmp;
	if (tmp != NULL)
		tmp->parent = tree;
	tmp = tree->parent;
	tree->parent = pivot;
	pivot->parent = tmp;
	if (tmp != NULL)
	{
		if (tmp->_left == tree)
			tmp->_left = pivot;
		else
			tmp->_right = pivot;
	}

	return (pivot);
}
