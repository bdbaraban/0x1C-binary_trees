#include "binary_trees.h"

/**
 * bst_insert -
 *
 * Return: 
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (tree)
	{
		bst_t *curr = *tree;
		if (curr == NULL)
		{
			return (*tree = (bst_t *)binary_tree_node(curr, value));
		}
		else if (value <= curr->n)
		{
			if (curr->left != NULL)
				return (bst_insert(&curr->left, value));
			return (curr->left = (bst_t *)binary_tree_node(curr, value));
		}
		/*else if (value > (*curr)->n) */
		if (curr->right != NULL)
			return (bst_insert(&curr->right, value));
		return (curr->right = (bst_t *)binary_tree_node(curr, value));
	}
	else
		return (NULL);
}
		/*if (*tree == NULL)
		{
			new = (bst_t *)binary_tree_node(*tree, value);
			binary_tree_print(*tree);
		}
		else if (value < (*tree)->n)
		{
			new = bst_insert(&((*tree)->left), value);
		}
		else if (value > (*tree)->n)
		{
			new = bst_insert(&((*tree)->right), value);
		}*/
	/*	else
		{
			new = (bst_t *)binary_tree_node(*tree, value);
			for (tmp = (*tree)->left->left; tmp; tmp = tmp->left)
				;
			tmp->left = new;
			binary_tree_print(*tree);
		}
*/

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
