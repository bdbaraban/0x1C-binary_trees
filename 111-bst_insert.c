#include "binary_trees.h"

/**
 * bst_insert -
 *
 * Return: 
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new = NULL, *tmp = NULL;

	if (tree != NULL)
	{
		if (*tree == NULL)
		{
			new = (bst_t *)binary_tree_node(*tree, value);
			*tree = new;
			binary_tree_print(*tree);
		}
		/*
		else if ((*tree)->left == NULL)
		{
			new = (bst_t *)binary_tree_node(*tree, value);
			(*tree)->left = new;
			binary_tree_print(*tree);
		}
		else if ((*tree)->right == NULL)
		{
			new = (bst_t *)binary_tree_node(*tree, value);
			(*tree)->right = new;
			binary_tree_print(*tree);
		}*/
		else if ((*tree)->n > value)
		{
			new = binary_tree_insert_left(*tree, value);
			binary_tree_print(*tree);
		}
		else if ((*tree)->n < value)
		{
			new = binary_tree_insert_right(*tree, value);
			binary_tree_print(*tree);
		}
		else
		{
			new = (bst_t *)binary_tree_node(*tree, value);
			for (tmp = (*tree)->left->left; tmp; tmp = tmp->left)
				;
			tmp->left = new;
			binary_tree_print(*tree);
		}
	}
	return (new);
}
#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as a left-child of
 *                           of another in a binary tree.
 * @parent: A pointer to the node to insert the left-child in.
 * @value: The value to store in the new node.
 *
 * Return: If parent is NULL or an error occurs - NULL.
 *         Otherwise - a pointer to the new node.
 *
 * Description: If parent already has a left-child, the new node
 *              takes its place and the old left-child is set as
 *              the left-child of the new node.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		new->left = parent->left;
		parent->left->parent = new;
	}
	parent->left = new;

	return (new);
}
#include "binary_trees.h"

/**
 * binary_tree_insert_right - Insert a node as the right-child
 *                            of another in a binary tree.
 * @parent: A pointer to the node to insert the right-child in.
 * @value: The value to store in the new node.
 *
 * Return: If parent is NULL or an error occurs - NULL.
 *         Otherwise - a pointer to the new node.
 *
 * Description: If parent already has a right-child, the new node
 *              takes its place and the old right-child is set as
 *              the right-child of the new node.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		new->right = parent->right;
		parent->right->parent = new;
	}
	parent->right = new;

	return (new);
}
