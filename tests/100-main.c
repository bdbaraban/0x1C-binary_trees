#include <stdlib.h>
#include <stdio.h>
#include "../binary_trees.h"

/**
 * launch_test - Test ancestor function and print informations
 *
 * @n1: First node
 * @n2: Second node
 */
void launch_test(binary_tree_t *n1, binary_tree_t *n2)
{
    binary_tree_t *ancestor;

    ancestor = binary_trees_ancestor(n1, n2);
    printf("Ancestor of [%d] & [%d]: ", n1->n, n2->n);
    if (!ancestor)
        printf("(nil)\n");
    else
        printf("%d\n", ancestor->n);
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *nodes[10], *root, *node_98, *node_12, *node_402, *node_54,
		  *node_128, *node_10, *node_45, *node_92, *node_65, **i, **j;

    root = node_98 = binary_tree_node(NULL, 98);
    root->left = node_12 = binary_tree_node(root, 12);
    root->right = node_402 = binary_tree_node(root, 402);
    root->left->right = node_54 = binary_tree_node(root->left, 54);
    root->right->right = node_128 = binary_tree_node(root->right, 128);
    root->left->left = node_10 = binary_tree_node(root->left, 10);
    root->right->left = node_45 = binary_tree_node(root->right, 45);
    root->right->right->left = node_92 = binary_tree_node(root->right->right, 92);
    root->right->right->right = node_65 = binary_tree_node(root->right->right, 65);
    binary_tree_print(root);

    nodes[0] = node_98, nodes[1] = node_12, nodes[2] = node_402;
    nodes[3] = node_54, nodes[4] = node_128, nodes[5] = node_10;
    nodes[6] = node_45, nodes[7] = node_92, nodes[8] = node_65, nodes[9] = NULL;
    for (i = nodes; *i; i++)
	    for (j = nodes; *j; j++)
		    launch_test(*i, *j);
    /*
    launch_test(root->left, root->right);
    launch_test(root->right->left, root->right->right->right);
    launch_test(root->right->right, root->right->right->right);
    launch_test(node_98, node_128);
    launch_test(node_128, node_98);
    launch_test(node_98, node_10);
    launch_test(node_10, node_98);
    */
    return (0);
}
