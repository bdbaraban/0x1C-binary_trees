#include "binary_trees.h"

int is_leaf(const binary_tree_t *node);
size_t depth(const binary_tree_t *tree);
const binary_tree_t *get_leaf(const binary_tree_t *tree);
int is_perfect_recursive(const binary_tree_t *tree, size_t leaf_depth);
int binary_tree_is_perfect(const binary_tree_t *tree);

/**
 * is_leaf - Checks if a node is a leaf of a binary tree.
 * @node: A pointer to the node to check.
 *
 * Return: If the node is a leaf - 1.
 *         Otherwise - 0.
 */
int is_leaf(const binary_tree_t *node)
{
	if (node == NULL || node->left != NULL || node->right != NULL)
		return (0);
	return (1);
}

/**
 * depth - Returns the depth of a given
 *                     node in a binary tree.
 * @tree: A pointer to the node to measure the depth of.
 *
 * Return: The depth of node.
 */
size_t depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + depth(tree->parent) : 0);
}

/**
 * get_leaf - Returns a leaf of a binary tree.
 * @tree: A pointer to the root node of the tree to find a leaf in.
 *
 * Return: A pointer to the first encountered leaf.
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (tree->left != NULL)
		return (get_leaf(tree->left));
	if (tree->right != NULL)
		return (get_leaf(tree->right));
	return (tree);
}

/**
 * is_perfect_recursive - Checks if a binary tree
 *                        is perfect recursively.
 * @tree: A pointer to the root node of the tree to check.
 * @leaf_depth: The depth of one leaf in the binary tree.
 *
 * Return: If the tree is perfect - 0.
 *         Otherwise - 1.
 */
int is_perfect_recursive(const binary_tree_t *tree, size_t leaf_depth)
{
	int ret = 0;

	if (tree != NULL)
	{
		if (is_leaf(tree) == 1)
			return ((depth(tree) == leaf_depth) ? 1 : 0);
		ret = is_perfect_recursive(tree->left, leaf_depth);
		ret = is_perfect_recursive(tree->right, leaf_depth);
	}
	return (ret);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If tree is NULL or is not perfect - 0.
 *         Otherwise - 1.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int ret = 0;
	size_t leaf_depth;

	if (tree != NULL)
	{
		leaf_depth = depth(get_leaf(tree));
		ret = is_perfect_recursive(tree, leaf_depth);
	}
	return (ret);
}
