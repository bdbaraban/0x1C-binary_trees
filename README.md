# C - Binary trees

This was a partner project in which we learned about the details, advantages,
and disadvantages of using trees as data structures. We learned about how to
qualify trees as well as how to traverse them. Throughout the project, we
implemented binary, binary search, AVL, and Max Binary Heap trees.

## Helper Files

* [tests](./tests): Folder of test files for all tasks. Provided by Holberton
School.
* [binary_tree_print.c](./binary_tree_print.c): C function that prints binary
trees in a pretty way.
* [binary_trees.h](./binary_trees.h): Header file containing definitions and
prototypes for all types and functions written for the project.

Data Structures
```
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s heap_t;
```

Function Prototypes

| File                             | Prototype                                                                                        |
| -------------------------------- | ------------------------------------------------------------------------------------------------ |
| `binary_tree_print.c`            | `void binary_tree_print(const binary_tree_t *tree)`                                              |
| `0-binary_tree_node.c`           | `binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);`                             |
| `1-binary_tree_insert_left.c`    | `binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);`                      |
| `2-binary_tree_insert_right.c`   | `binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);`                     |
| `3-binary_tree_delete.c`         | `void binary_tree_delete(binary_tree_t *tree);`                                                  |
| `4-binary_tree_is_leaf.c`        | `int binary_tree_is_leaf(const binary_tree_t *node);`                                            |
| `5-binary_tree_is_root.c`        | `int binary_tree_is_root(const binary_tree_t *node);`                                            |
| `6-binary_tree_preorder.c`       | `void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));`                       |
| `7-binary_tree_inorder.c`        | `void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));`                        |
| `8-binary_tree_postorder.c`      | `void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));`                      |
| `9-binary_tree_height.c`         | `size_t binary_tree_height(const binary_tree_t *tree);`                                          |
| `10-binary_tree_depth.c`         | `size_t binary_tree_depth(const binary_tree_t *tree);`                                           |
| `11-binary_tree_size.c`          | `size_t binary_tree_size(const binary_tree_t *tree);`                                            |
| `12-binary_tree_leaves.c`        | `size_t binary_tree_leaves(const binary_tree_t *tree);`                                          |
| `13-binary_tree_nodes.c`         | `size_t binary_tree_nodes(const binary_tree_t *tree);`                                           |
| `14-binary_tree_balance.c`       | `int binary_tree_balance(const binary_tree_t *tree);`                                            |
| `15-binary_tree_is_full.c`       | `int binary_tree_is_full(const binary_tree_t *tree);`                                            |
| `16-binary_tree_is_perfect.c`    | `int binary_tree_is_perfect(const binary_tree_t *tree);`                                         |
| `17-binary_tree_sibling.c`       | `binary_tree_t *binary_tree_sibling(binary_tree_t *node);`                                       |
| `18-binary_tree_uncle.c`         | `binary_tree_t *binary_tree_uncle(binary_tree_t *node);`                                         |
| `100-binary_trees_ancestor.c`    | `binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second);` |
| `101-binary_tree_levelorder.c`   | `void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));`                     |
| `102-binary_tree_is_complete.c`  | `int binary_tree_is_complete(const binary_tree_t *tree);`                                        |
| `103-binary_tree_rotate_left.c`  | `binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);`                                   |
| `104-binary_tree_rotate_right.c` | `binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);`                                  |

## Tasks

* **0. New node**
  * [0-binary_tree_node.c](./0-binary_tree_node.c): C function that creates a
binary tree node with a given parent and value.
  * Returns a pointer to the new node, or `NULL` on failure.

* **1. Insert left**
  * [1-binary_tree_insert](./1-binary_tree_insert): C function that inserts a
node as the left-child of another.
  * Returns a pointer to the new node, or `NULL` on failure.
  * If the given `parent` already contains a left node, the new node takes its
place and the old left-child becomes the left-child of the new node.

* **2. Insert right**
  * [2-binary_tree_insert_right.c](./2-binary_tree_insert_right.c): C function that
inserts a node as the right-child of another.
  * Returns a pointer to the new node, or `NULL` on failure.
  * If the given `parent` already contains a right node, the new node takes its
place and the old right-child becomes the right-child of the new node.

* **3. Delete**
  * [3-binary_tree_delete.c](./3-binary_tree_delete.c): C function that deletes
an entire binary tree.

* **4. Is leaf**
  * [4-binary_tree_is_leaf.c](./4-binary_tree_is_leaf.c): C function that checks
if a given node is a leaf.
  * Returns `1` if the node is a leaf, `0` otherwise.

* **5. Is root**
  * [5-binary_tree_is_root.c](./5-binary_tree_is_root.c): C function that checks
if a given node is a root.
  * Returns `1` if the node is a root, `0` otherwise.

* **6. Pre-order traversal**
  * [6-binary_tree_preorder.c](./6-binary_tree_preorder.c): C function that
traverses a tree using pre-order traversal.

* **7. In-order traversal**
  * [7-binary_tree_inorder.c](./7-binary_tree_inorder.c): C function that
traverses a tree using in-order traversal.

* **8. Post-order traversal**
  * [8-binary_tree_postorder.c](./8-binary_tree_postorder.c): C function that
traverses a tree using post-order traversal.

* **9. Height**
  * [9-binary_tree_height.c](./9-binary_tree_height.c): C function that returns
the height of a binary tree.

* **10. Depth**
  * [10-binary_tree_depth.c](./10-binary_tree_depth.c): C function that returns
the depth of a given node in a binary tree.

* **11. Size**
  * [11-binary_tree_size.c](./11-binary_tree_size.c): C function that returns
the size of a binary tree.

* **12. Leaves**
  * [12-binary_tree_leaves.c](./12-binary_tree_leaves.c): C function that returns
the number of leaves in a binary tree.

* **13. Nodes**
  * [13-binary_tree_nodes.c](./13-binary_tree_nodes.c): C function that returns
the number of nodes in a binary tree with at least one child.

* **14. Balance factor**
  * [14-binary_tree_balance.c](./14-binary_tree_balance.c): C function that
returns the balance factor of a binary tree.

* **15. Is full**
  * [15-binary_tree_is_full.c](./15-binary_tree_is_full.c): C function that
checks if a binary tree is full.
  * Returns `1` if a tree is full, `0` otherwise.

* **16. Is perfect**
  * [16-binary_tree_is_perfect.c](./16-binary_tree_is_perfect.c): C function
that checks if a binary tree is perfect.
  * Returns `1` if a tree is perfect, `0` otherwise.

* **17. Sibling**
  * [17-binary_tree_sibling.c](./17-binary_tree_sibling.c): C function that
returns a pointer to the sibling of a given node in a binary tree.
  * Returns `NULL` if no sibling is found.

* **18. Uncle**
  * [18-binary_tree_uncle.c](./18-binary_tree_uncle.c): C function that
returns a pointer to the uncle of a given node in a binary tree.
  * Returns `NULL` if no uncle is found.

* **19. Lowest common ancestor**
  * [100-binary_trees_ancestor.c](./100-binary_trees_ancestor.c): C function
that returns a pointer to the lowest common ancestor node of two given nodes
in a binary tree.
  * Returns `NULL` if no common ancestor is found.

* **20. Level-order traversal**
  * [101-binary_tree_levelorder.c](./101-binary_tree_levelorder.c): C function
that traverses a binary tree using level-order traversal.

* **21. Is complete**
  * [102-binary_tree_is_complete.c](./102-binary_tree_is_complete.c): C function
that checks if a binary tree is complete.
  * Returns `1` if the tree is complete, `0` otherwise.

* **22. Rotate left**
  * [103-binary_tree_rotate_left.c](./103-binary_tree_rotate_left.c): C function
that performs a left-rotation on a binary tree.
  * Returns a pointer to the new root node of the tree after rotation.

* **23. Rotate right**
  * [104-binary_tree_rotate_right.c](./104-binary_tree_rotate_right.c): C function
that performs a right-rotation on a binary tree.
  * Returns a pointer to the new root node of the tree after rotation.

* **24. Is BST**
  * `110-binary_tree_is_bst.c`
  * Write a function that checks if a binary tree is a valid Binary Search Tree

* **25. BST - Insert**
  * `111-bst_insert.c`
  * Write a function that inserts a value in a Binary Search Tree

* **26. BST - Array to BST**
  * `112-array_to_bst.c`
  * Write a function that builds a Binary Search Tree from an array

* **27. BST - Search**
  * `113-bst_search.c`
  * Write a function that searches for a value in a Binary Search Tree

* **28. BST - Remove**
  * `114-bst_remove.c`
  * Write a function that removes a node from a Binary Search Tree

* **29. Big O #BST**
  * `115-O`
  * What are the average time complexities of those operations on a Binary Search Tree (one answer per line):

* **30. Is AVL**
  * `120-binary_tree_is_avl.c`
  * Write a function that checks if a binary tree is a valid AVL Tree

* **31. AVL - Insert**
  * `121-avl_insert.c`
  * Write a function that inserts a value in an AVL Tree

* **32. AVL - Array to AVL**
  * `122-array_to_avl.c`
  * Write a function that builds an AVL tree from an array

* **33. AVL - Remove**
  * `123-avl_remove.c`
  * Write a function that removes a node from an AVL tree

* **34. AVL - From sorted array**
  * `124-sorted_array_to_avl.c`
  * Write a function that builds an AVL tree from an array

* **35. Big O #AVL Tree**
  * `125-O`
  * What are the average time complexities of those operations on an AVL Tree (one answer per line):

* **36. Is Binary heap**
  * `130-binary_tree_is_heap.c`
  * Write a function that checks if a binary tree is a valid Max Binary Heap

* **37. Heap - Insert**
  * `131-heap_insert.c`
  * Write a function that inserts a value in Max Binary Heap

* **38. Heap - Array to Binary Heap**
  * `132-array_to_heap.c`
  * Write a function that builds a Max Binary Heap tree from an array

* **39. Heap - Extract**
  * `133-heap_extract.c`
  * Write a function that extracts the root node of a Max Binary Heap

* **40. Heap - Sort**
  * `134-heap_to_sorted_array.c`
  * Write a function that converts a Binary Max Heap to a sorted array of integers

* **41. Big O #Binary Heap**
  * `135-O`
  * What are the average time complexities of those operations on a Binary Heap (one answer per line):

## Authors

* **Brennan Dov Baraban** - <[bdbaraban](https://github.com/bdbaraban)>
* **Fernando González-Morales** - <[fgonza52](https://github.com/fgonza52)>
