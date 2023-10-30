#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree.
 * @tree: A pointer to the root node of the tree to count the leaves of.
 *
 * Return: The number of leaves in the tree.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	if (tree)
	{
		leaves += (!tree->_left && !tree->_right) ? 1 : 0;
		leaves += binary_tree_leaves(tree->_left);
		leaves += binary_tree_leaves(tree->_right);
	}
	return (leaves);
}
