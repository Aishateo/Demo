#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/* Original code from http://stackoverflow.com/a/13755911/5184480 */

/**
 * print_t - Stores recursively each level in an array of strings
 *
 * @tree: Pointer to the node to print
 * @offset: Offset to print
 * @depth: Depth of the node
 * @s: Buffer
 *
 * Return: length of printed tree after process
 */
static int print_t(const binary_tree_t *tree, int offset, int depth, char **s)
{
	char b[6];
	int _left, _right, isleft, _width, i;

	if (!tree)
		return (0);
	isleft = (tree->parent && tree->parent->_left == tree);
	_width = sprintf(b, "(%03d)", tree->n);
	_left = print_t(tree->_left, offset, depth + 1, s);
	_right = print_t(tree->_right, offset + _left + _width, depth + 1, s);
	for (i = 0; i < _width; i++)
		s[depth][offset + _left + i] = b[i];
	if (depth && isleft)
	{
		for (i = 0; i < _width + _right; i++)
			s[depth - 1][offset + _left + _width / 2 + i] = '-';
		s[depth - 1][offset + _left + _width / 2] = '.';
	}
	else if (depth && !isleft)
	{
		for (i = 0; i < _left + _width; i++)
			s[depth - 1][offset - _width / 2 + i] = '-';
		s[depth - 1][offset + _left + _width / 2] = '.';
	}
	return (_left + _width + _right);
}

/**
 * _height - Measures the height of a binary tree
 *
 * @tree: Pointer to the node to measures the height
 *
 * Return: The height of the tree starting at @node
 */
static size_t _height(const binary_tree_t *tree)
{
	size_t height_lft;
	size_t height_rgt;

	height_lft = tree->_left ? 1 + _height(tree->_left) : 0;
	height_rgt = tree->_right ? 1 + _height(tree->_right) : 0;
	return (height_lft > height_rgt ? height_lft : height_rgt);
}

/**
 * binary_tree_print - Prints a binary tree
 *
 * @tree: Pointer to the root node of the tree to print
 */
void binary_tree_print(const binary_tree_t *tree)
{
	char **s;
	size_t height, i, j;

	if (!tree)
		return;
	height = _height(tree);
	s = malloc(sizeof(*s) * (height + 1));
	if (!s)
		return;
	for (i = 0; i < height + 1; i++)
	{
		s[i] = malloc(sizeof(**s) * 255);
		if (!s[i])
			return;
		memset(s[i], 32, 255);
	}
	print_t(tree, 0, 0, s);
	for (i = 0; i < height + 1; i++)
	{
		for (j = 254; j > 1; --j)
		{
			if (s[i][j] != ' ')
				break;
			s[i][j] = '\0';
		}
		printf("%s\n", s[i]);
		free(s[i]);
	}
	free(s);
}
