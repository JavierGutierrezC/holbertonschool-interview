#include "sort.h"

void swap_int(int *a, int *b);
void heapify(int *array, size_t size, size_t i, size_t tot_size);

/**
* swap_int - changes de values of two elemts
* @a: element a
* @b: element b
*/

void swap_int(int *a, int *b)
{
int a1 = *a;
int b1 = *b;

*a = b1;
*b = a1;
}

/**
* heapify - rearenges the order
* @array: pointer to the array
* @size: size of array
* @i: position in array
* @tot_size: total size
*/

void heapify(int *array, size_t size, size_t i, size_t tot_size)
{
size_t largest = i;
size_t l = 2 * i + 1;
size_t r = 2 * i + 2;

if (l < size && array[l] > array[largest])
largest = l;

if (r < size && array[r] > array[largest])
largest = r;

if (largest != i)
{
swap_int(&array[i], &array[largest]);
print_array(array, tot_size);
heapify(array, size, largest, tot_size);
}
}

/**
* heap_sort - heap sort algorithm
* @array: The array to sort
* @size: Number of elements in @array
*/
void heap_sort(int *array, size_t size)
{
size_t i;
size_t tot_size = size;

if (array != NULL)
{
for (i = size / 2 - 1; (int)i >= 0; i--)
heapify(array, size, i, tot_size);
for (i = size - 1; i > 0; i--)
{
swap_int(&array[0], &array[i]);
print_array(array, size);
heapify(array, i, 0, tot_size);
}
}
}
