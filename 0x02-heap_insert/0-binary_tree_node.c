#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_node - Insert a new node in a binary tree.
 *
 * @parent: pointer to first node
 * @value: value that new node will have.
 * Return: new_node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
  binary_tree_t *newNode;

  newNode = malloc(sizeof(binary_tree_t));
  if (newNode == NULL)
    return (NULL);
  newNode->n = value;
  newNode->parent = parent;
  newNode->left = NULL;
  newNode->right = NULL;
  return (newNode);
}
