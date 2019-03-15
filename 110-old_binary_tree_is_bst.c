#include "binary_trees.h"
#include "limits.h"
int is_bst_helper(const binary_tree_t *tree, int *largest);

#define VERBOSE 0

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int tracker = INT_MIN;

	if (tree == NULL)
		return (0);
	return (is_bst_helper(tree, &tracker));
}


/**
 * is_left - checks if a node is a left child of some other node
 * @node: A pointer to the node to be checked.
 * Return: 1 if is a left child, otherwise 0
 */
int is_left(const binary_tree_t *node)
{
	if (node && node->parent)
		return (node->parent->left == node);
	return (0);
}
/**
 * is_right - checks if a node is a right child of some other node
 * @node: A pointer to the node to be checked.
 * Return: 1 if is a right child, otherwise 0
 */
int is_right(const binary_tree_t *node)
{
	if (node && node->parent)
		return (node->parent->right == node);
	return (0);
}

#if !VERBOSE
/**
 * is_bst_helper - checks if a binary tree is a valid Binary Search Tree.
 * @tree: A pointer to the root node of the tree to check.
 * @largest: Value of largest node visited so far.
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int is_bst_helper(const binary_tree_t *tree, int *largest)
{
	int ret = 1;

	if (tree != NULL)
	{
		ret *= is_bst_helper(tree->left, largest);
		if (tree->n < *largest)
			return (0);
		*largest = tree->n;
		if (is_left(tree) && !(tree->n < tree->parent->n))
			return (0);
		if (is_right(tree) && !(tree->n > tree->parent->n))
			return (0);
		ret *= is_bst_helper(tree->right, largest);
	}
	return (ret);
}
#else
/**
 * is_bst_helper - checks if a binary tree is a valid Binary Search Tree.
 * @tree: A pointer to the root node of the tree to check.
 * @largest: Value of largest node visited so far.
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int is_bst_helper(const binary_tree_t *tree, int *largest)
{
	int ret = 1;

	if (tree)
	{
		printf("Moving to %d\n", tree->n);
		ret *= is_bst_helper(tree->left, largest);
		printf("done with left tree for %d: %d\n", tree->n, ret);
		printf("largest = %d\n", *largest);
		if (tree->n < *largest)
			return (0);
		*largest = tree->n;
		printf("largest = %d\n", *largest);
		if (is_left(tree))
			printf("%d is %s than %d\n",
				tree->n,
				(tree->n < tree->parent->n) ? "smaller" : "larger",
				tree->parent->n);
		if (is_left(tree) && !(tree->n < tree->parent->n))
		{
			printf("%d is left child\n", tree->n);
			return (0);
		}
		if (is_right(tree))
			printf("%d is %s than %d\n",
				tree->n,
				(tree->n < tree->parent->n) ? "smaller" : "larger",
				tree->parent->n);
		if (is_right(tree) && !(tree->n > tree->parent->n))
		{
			printf("%d is right child\n", tree->n);
			return (0);
		}
		ret *= is_bst_helper(tree->right, largest);
		printf("done with right tree for %d: %d\n", tree->n, ret);
		if (tree->parent)
			printf("Moving back to %d\n", tree->parent->n);
	}
	return (ret);
}
#endif /* VERBOSE */
