#include "binary_trees.h"


/**
 * binary_tree_node - Creates a node in a binary tree
 * @parent: node to add
 * @value: value inside the node
 * Return: a pointer to the new node
 */
avl_t *binary_tree_node(avl_t *parent, int value)
{
avl_t *newn;

newn = malloc(sizeof(avl_t));
if (newn == NULL)
return (NULL);

newn->n = value;
newn->parent = parent;
newn->left = NULL;
newn->right = NULL;
return (newn);
}

/**
 * heap_insert - inserts the created node into the binary tree
 * @root: head of the binary tree
 * @array: array of elelmnets to be inserted into the binary tree
 * @size: end of the array
 * @start: beginnig of the array
 * Return: pointer of the node created
 */
avl_t *heap_insert(avl_t **root, int size, int start, int *array)
{
int mid = (start + size) / 2;
avl_t *new = NULL;

if (start > size)
return (NULL);
new = binary_tree_node(*root, array[mid]);
if (mid != start)
new->left = heap_insert(&new, mid - 1, start, array);
if (mid != size)
new->right = heap_insert(&new, size, mid + 1, array);
return (new);
}


/**
 * sorted_array_to_avl - sorts the array
 * @array: The array to be sorted in a binary tree
 * @size: Size of the array
 * Return: pointer of the root node of the binary tree
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
avl_t *root = NULL;

root = heap_insert(&root, size - 1, 0, array);
return (root);
}
