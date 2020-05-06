#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect.
 * @tree: pointer of the tree.
 *
 * Return: If the binary tree is perfect, the function will return 1. Else,
 * the function will return 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
  size_t h, elem = 1, i;

  if (!tree)
    return (0);
  else if (!tree->left && !tree->right)
    return (1);

  h = height(tree);

  for (i = 1; i <= h; i++)
    elem += power(2, i);

  return (size(tree) == elem ? 1 : 0);
}

/**
 * height - measures the height of a binary tree
 * @tree: pointer of the binary tree.
 *
 * Return: height of the binary tree.
 */
size_t height(const binary_tree_t *tree)
{
  size_t lh = 0, rh = 0;

  if (!tree)
    return (0);

  if (tree->left)
    lh = height(tree->left) + 1;
  if (tree->right)
    rh = height(tree->right) + 1;

  return (lh > rh ? lh : rh);
}

/**
 * size - Returns the size of the binary tree.
 * @tree: pointer to the tree.
 *
 * Return: size of the binary tree.
 */
size_t size(const binary_tree_t *tree)
{
  size_t s = 0;

  if (!tree)
    return (0);

  s++;
  if (tree->left)
    s += size(tree->left);
  if (tree->right)
    s += size(tree->right);

  return (s);
}

/**
 * power - returns the exponential value of a number
 * @base: base number
 * @exponent: exponent number
 * Return: result
 */
int power(int base, unsigned int exponent)
{
  int count, result;

  if (exponent == 0)
    return (1);
  result = 1;
  for (count = 0; count < (int)exponent; count++)
    {
      result *= base;
    }
  return (result);
}
