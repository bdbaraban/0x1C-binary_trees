#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree.
 * @tree: A double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: a pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (tree)
	{
		bst_t *curr = *tree;

		if (curr == NULL)
			return (*tree = (bst_t *)binary_tree_node(curr, value));

		if (value == curr->n)
			return (NULL);

		if (value < curr->n)
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
	return (NULL);
}
