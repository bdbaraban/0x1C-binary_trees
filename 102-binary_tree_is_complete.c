#include "binary_trees.h"

binary_tree_t *get_right_sibling(const binary_tree_t *node, size_t level);
int is_complete_recursive(const binary_tree_t *tree, size_t level);
int binary_tree_is_complete(const binary_tree_t *tree);

/**
 * get_right_sibling - Finds the sibling to the right of a binary tree node.
 * @node: A pointer to the node to find the right sibling of.
 * @level: The level of the node to check for the given binary tree/subtree.
 *
 * Return: If node is NULL or has no right sibling - NULL.
 *         Otherwise - a pointer to the right sibling node.
 */
binary_tree_t *get_right_sibling(const binary_tree_t *node, size_t level)
{
	if (node->parent == NULL)
		return (NULL);
	if (node->parent->left == node)
		return (node->parent->right);

	if (node->parent->parent == NULL || level < 2)
		return (NULL);
	if (node->parent->parent->right->left == NULL)
		return (node->parent->parent->right->right);
	return (node->parent->parent->right->left);
}

/**
 * is_complete_recursive - Checks if a binary tree is complete recursively.
 * @tree: A pointer to the root node of the tree to check.
 * @level: The level of the current node.
 *
 * Return: If the tree is complete, 1.
 *         Otherwise, 0.
 */
int is_complete_recursive(const binary_tree_t *tree, size_t level)
{
	const binary_tree_t *sibling, *next_child = NULL;
	unsigned char flag = 0;

	if (tree == NULL)
		return (1);

	sibling = tree;
	for (; sibling != NULL; sibling = get_right_sibling(sibling, level))
	{
		if (sibling->left != NULL && next_child == NULL)
			next_child = sibling->left;
		else if (sibling->right != NULL && next_child == NULL)
			next_child = sibling->right;

		if ((sibling->right != NULL && sibling->left == NULL) ||
		    (sibling->left != NULL && flag == 1))
			return (0);
		if (sibling->left != NULL && sibling->right == NULL)
			flag = 1;
	}
	return (is_complete_recursive(next_child, level + 1));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If the tree is complete, 1.
 *         Otherwise, 0.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL || (tree->left == NULL && tree->right != NULL))
		return (0);

	return (is_complete_recursive(tree->left, 1));
}
