#ifndef _BINARY_TREES_H
#define _BINARY_TREES_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */

typedef struct binary_tree_s
{
  int n;
  struct binary_tree_s *parent;
  struct binary_tree_s *left;
  struct binary_tree_s *right;
} binary_tree_t;

typedef struct binary_tree_s heap_t;


binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

heap_t *heap_insert(heap_t **root, int value);

void binary_tree_print(const binary_tree_t *);


int binary_tree_is_perfect(const binary_tree_t *tree);

size_t height(const binary_tree_t *tree);
size_t size(const binary_tree_t *tree);
int power(int base, unsigned int exponent);


#endif
