#include "binary_trees.h"

/**
 * binary_tree_insert_right - Insert a node as the _right-child
 *                            of another in a binary tree.
 * @parent: A pointer to the node to insert the _right-child in.
 * @value: The value to store in the nw node.
 *
 * Return: If parent is NULL or an error occurs - NULL.
 *         Otherwise - a pointer to the nw node.
 *
 * Description: If parent already has a _right-child, the nw node
 *              takes its place and the old _right-child is set as
 *              the _right-child of the nw node.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *nw;

	if (parent == NULL)
		return (NULL);

	nw = binary_tree_node(parent, value);
	if (nw == NULL)
		return (NULL);

	if (parent->_right != NULL)
	{
		nw->_right = parent->_right;
		parent->_right->parent = nw;
	}
	parent->_right = nw;

	return (nw);
}
