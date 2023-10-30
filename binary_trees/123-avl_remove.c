#include "binary_trees.h"

/**
 * bal - Measures balance factor of a AVL
 * @tree: tree to go through
 * Return: balanced factor
 */
void bal(avl_t **tree)
{
	int bval;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->_left == NULL && (*tree)->_right == NULL)
		return;
	bal(&(*tree)->_left);
	bal(&(*tree)->_right);
	bval = binary_tree_balance((const binary_tree_t *)*tree);
	if (bval > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (bval < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}
/**
 * successor - get the next successor i mean the min node in the _right subtree
 * @node: tree to check
 * Return: the min value of this tree
 */
int successor(bst_t *node)
{
	int _left = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		_left = successor(node->_left);
		if (_left == 0)
		{
			return (node->n);
		}
		return (_left);
	}

}
/**
 *remove_type - function that removes a node depending of its children
 *@root: node to remove
 *Return: 0 if it has no children or other value if it has
 */
int remove_type(bst_t *root)
{
	int new_value = 0;

	if (!root->_left && !root->_right)
	{
		if (root->parent->_right == root)
			root->parent->_right = NULL;
		else
			root->parent->_left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->_left && root->_right) || (!root->_right && root->_left))
	{
		if (!root->_left)
		{
			if (root->parent->_right == root)
				root->parent->_right = root->_right;
			else
				root->parent->_left = root->_right;
			root->_right->parent = root->parent;
		}
		if (!root->_right)
		{
			if (root->parent->_right == root)
				root->parent->_right = root->_left;
			else
				root->parent->_left = root->_left;
			root->_left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		new_value = successor(root->_right);
		root->n = new_value;
		return (new_value);
	}
}
/**
 * bst_remove - remove a node from a BST tree
 * @root: root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->_left, value);
	else if (value > root->n)
		bst_remove(root->_right, value);
	else if (value == root->n)
	{
		type = remove_type(root);
		if (type != 0)
			bst_remove(root->_right, type);
	}
	else
		return (NULL);
	return (root);
}

/**
 * avl_remove - remove a node from a AVL tree
 * @root: root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_a = (avl_t *) bst_remove((bst_t *) root, value);

	if (root_a == NULL)
		return (NULL);
	bal(&root_a);
	return (root_a);
}
