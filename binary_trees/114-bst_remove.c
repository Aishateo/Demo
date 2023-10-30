#include "binary_trees.h"

bst_t *inorder_successor(bst_t *root);
bst_t *bst_delete(bst_t *root, bst_t *node);
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value);
bst_t *bst_remove(bst_t *root, int value);

/**
 * inorder_successor - Returns the minimum value of a binary search tree.
 * @root: A pointer to the root node of the BST to search.
 *
 * Return: The minimum value in @tree.
 */
bst_t *inorder_successor(bst_t *root)
{
	while (root->_left != NULL)
		root = root->_left;
	return (root);
}

/**
 * bst_delete - Deletes a node from a binary search tree.
 * @root: A pointer to the root node of the BST.
 * @node: A pointer to the node to delete from the BST.
 *
 * Return: A pointer to the nw root node after deletion.
 */
bst_t *bst_delete(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *successor = NULL;

	/* No children or _right-child only */
	if (node->_left == NULL)
	{
		if (parent != NULL && parent->_left == node)
			parent->_left = node->_right;
		else if (parent != NULL)
			parent->_right = node->_right;
		if (node->_right != NULL)
			node->_right->parent = parent;
		free(node);
		return (parent == NULL ? node->_right : root);
	}

	/* _left-child only */
	if (node->_right == NULL)
	{
		if (parent != NULL && parent->_left == node)
			parent->_left = node->_left;
		else if (parent != NULL)
			parent->_right = node->_left;
		if (node->_left != NULL)
			node->_left->parent = parent;
		free(node);
		return (parent == NULL ? node->_left : root);
	}

	/* Two children */
	successor = inorder_successor(node->_right);
	node->n = successor->n;

	return (bst_delete(root, successor));
}

/**
 * bst_remove_recursive - Removes a node from a binary search tree recursively.
 * @root: A pointer to the root node of the BST to remove a node from.
 * @node: A pointer to the current node in the BST.
 * @value: The value to remove from the BST.
 *
 * Return: A pointer to the root node after deletion.
 */
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
			return (bst_delete(root, node));
		if (node->n > value)
			return (bst_remove_recursive(root, node->_left, value));
		return (bst_remove_recursive(root, node->_right, value));
	}
	return (NULL);
}

/**
 * bst_remove - Removes a node from a binary search tree.
 * @root: A pointer to the root node of the BST to remove a node from.
 * @value: The value to remove in the BST.
 *
 * Return: A pointer to the nw root node after deletion.
 *
 * Description: If the node to be deleted has two children, it
 *              is replaced with its first in-order successor.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_remove_recursive(root, root, value));
}
