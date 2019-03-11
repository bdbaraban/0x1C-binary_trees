#include "binary_trees.h"

void delete_right_branch(binary_tree_t *branch);
void delete_left_branch(binary_tree_t *branch);
void binary_tree_delete(binary_tree_t *tree);

/**
 * delete_right_branch - Delete the entire right
 *                       branch of a binary tree.
 * @branch: A pointer to the root node of the branch to delete.
 */
void delete_right_branch(binary_tree_t *branch)
{
	binary_tree_t *node, *tmp;

	for (node = branch; node != NULL; node = tmp)
	{
		delete_left_branch(node->left);
		tmp = node->right;
		free(node);
	}
}

/**
 * delete_left_branch - Delete the entire left
 *                      branch of a binary tree.
 * @branch: A pointer to the root node of the branch to delete.
 */
void delete_left_branch(binary_tree_t *branch)
{
	binary_tree_t *node, *tmp;

	for (node = branch; node != NULL; node = tmp)
	{
		delete_right_branch(node->right);
		tmp = node->left;
		free(node);
	}
}

/**
 * binary_tree_delete - Deletes a binary tree.
 * @tree: A pointer to the root node of the tree to delete.
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;

	delete_left_branch(tree->left);
	delete_right_branch(tree->right);
	free(tree);
}
