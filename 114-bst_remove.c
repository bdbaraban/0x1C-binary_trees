#include "binary_trees.h"

/**
 * bst_delete - Deletes a node from a binary search tree.
 * @root: A pointer to the root node of the BST.
 * @node: A pointer to node to delete from the BST.
 *
 * Return: A pointer to the new root node after deletion.
 */
bst_t *bst_delete(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *successor = NULL;

	if (node->left != NULL && node->right == NULL)
		successor = node->left;

	else if (node->right != NULL && node->right->left == NULL)
		successor = node->right;

	else if (node->right != NULL && node->right->left != NULL)
	{
		successor = node->right->left;
		if (successor->right != NULL)
		{
			node->right->left = successor->right;
			node->right->left->parent = node->right;
			if (successor->left != NULL)
			{
				node->right->left->left = successor->left;
				successor->left->parent = node->right->left;
			}
		}
		else
		{
			node->right->left = successor->left;
			if (successor->left != NULL)
				node->right->left->parent = node->right;
		}
		successor->left = node->left;
		successor->right = node->right;
		node->right->parent = node->left->parent = successor;
	}
	free(node);

	if (successor != NULL)
		successor->parent = parent;
	if (parent != NULL && parent->left == node)
		parent->left = successor;
	else if (parent != NULL)
		parent->right = successor;
	return (parent == NULL ? successor : root);
}

/**
 * bst_remove_recursive - Removes a node from a binary search tree recursively.
 * @root: A pointer to the root node of the BST to remove a node from.
 * @node: A pointer to the current node in the BST.
 * @value: The value to remove from the BST.
 *
 * Return: A pointer to the root node after deletion.
 */
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
			return (bst_delete(root, node));
		if (node->n > value)
			return (bst_remove_recursive(root, node->left, value));
		return (bst_remove_recursive(root, node->right, value));
	}
	return (NULL);
}
/**
 * bst_remove - Removes a node from a binary search tree.
 * @root: A pointer to the root node of the BST to remove a node from.
 * @value: The value to remove in the BST.
 *
 * Return: A pointer to the new root node after deletion.
 *
 * Description: If the node to be deleted has two children, it
 *              is replaced with its first in-order successor.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_remove_recursive(root, root, value));
}
