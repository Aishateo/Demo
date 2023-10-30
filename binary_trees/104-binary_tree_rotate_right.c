#include "binary_trees.h"

/**
 * binary_tree_rotate_right - _right-rotates a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the nw root node after rotation.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pivot, *tmp;

	if (tree == NULL || tree->_left == NULL)
		return (NULL);

	pivot = tree->_left;
	tmp = pivot->_right;
	pivot->_right = tree;
	tree->_left = tmp;
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
