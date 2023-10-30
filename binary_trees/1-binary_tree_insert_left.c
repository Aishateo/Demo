#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as a _left-child of
 *                           of another in a binary tree.
 * @parent: A pointer to the node to insert the _left-child in.
 * @value: The value to store in the nw node.
 *
 * Return: If parent is NULL or an error occurs - NULL.
 *         Otherwise - a pointer to the nw node.
 *
 * Description: If parent already has a _left-child, the nw node
 *              takes its place and the old _left-child is set as
 *              the _left-child of the nw node.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *nw;

	if (parent == NULL)
		return (NULL);

	nw = binary_tree_node(parent, value);
	if (nw == NULL)
		return (NULL);

	if (parent->_left != NULL)
	{
		nw->_left = parent->_left;
		parent->_left->parent = nw;
	}
	parent->_left = nw;

	return (nw);
}
