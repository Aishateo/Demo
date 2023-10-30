#include "binary_trees.h"

size_t height(const binary_tree_t *tree);
int balance(const binary_tree_t *tree);
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
		avl_t **nw, int value);
avl_t *avl_insert(avl_t **tree, int value);

/**
 * height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */
size_t height(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		size_t l = 0, r = 0;

		l = tree->_left ? 1 + binary_tree_height(tree->_left) : 1;
		r = tree->_right ? 1 + binary_tree_height(tree->_right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}

/**
 * balance - Measures the balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the balance factor.
 *
 * Return: If tree is NULL, return 0, else return balance factor.
 */
int balance(const binary_tree_t *tree)
{
	return (tree != NULL ? height(tree->_left) - height(tree->_right) : 0);
}

/**
 * avl_insert_recursive - Inserts a value into an AVL tree recursively.
 * @tree: A double pointer to the root node of the AVL tree to insert into.
 * @parent: The parent node of the current working node.
 * @nw: A double pointer to store the nw node.
 * @value: The value to insert into the AVL tree.
 *
 * Return: A pointer to the nw root after insertion, or NULL on failure.
 */
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
		avl_t **nw, int value)
{
	int bfactor;

	if (*tree == NULL)
		return (*nw = binary_tree_node(parent, value));

	if ((*tree)->n > value)
	{
		(*tree)->_left = avl_insert_recursive(&(*tree)->_left, *tree, nw, value);
		if ((*tree)->_left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->_right = avl_insert_recursive(&(*tree)->_right, *tree, nw, value);
		if ((*tree)->_right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	bfactor = balance(*tree);
	if (bfactor > 1 && (*tree)->_left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (bfactor < -1 && (*tree)->_right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (bfactor > 1 && (*tree)->_left->n < value)
	{
		(*tree)->_left = binary_tree_rotate_left((*tree)->_left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bfactor < -1 && (*tree)->_right->n > value)
	{
		(*tree)->_right = binary_tree_rotate_right((*tree)->_right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}

/**
 * avl_insert - Inserts a value into an AVL tree.
 * @tree: A double pointer to the root node of the AVL tree to insert into.
 * @value: The value to insert into the AVL tree.
 *
 * Return: A pointer to the inserted node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *nw = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	avl_insert_recursive(tree, *tree, &nw, value);
	return (nw);
}
