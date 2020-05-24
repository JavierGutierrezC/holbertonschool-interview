#include <stdlib.h>
#include <stdio.h>
#include "sandpiles.h"
/**
* print_grid - prints grid number 1
* @grid: Grid number 1
* Return: void function has no return
*/
static void print_grid(int grid[3][3])
{
int i, j;
for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
{
if (j)
printf(" ");
printf("%d", grid[i][j]); }
printf("\n"); }
}
/**
 * sandpiles_sum - sum of two sandpiles
 * @grid1: first grid
 * @grid2: Second grid
 * Return: Void function, no return
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
int i = 0, j = 0, stable = 0, counter = 0, flag = 0;
while (counter == 0)
{
stable = 0;
if (flag != 0)
{
for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
{
grid2[i][j] = grid1[i][j];
if (grid1[i][j] <= 3)
stable++; } }
if (stable == 9)
break;
printf("=\n");
print_grid(grid1); }
stable = 0;
for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
{
if (flag != 0)
{
if (grid2[i][j] > 3)
{
grid1[i][j] = grid1[i][j] - 4;
if (j > 0)
grid1[i][j - 1] = (grid1[i][j - 1]) + 1;
if (i > 0)
grid1[i - 1][j] = (grid1[i - 1][j]) + 1;
if (i < 2)
grid1[i + 1][j] = (grid1[i + 1][j]) + 1;
if (j < 2)
grid1[i][j + 1] = (grid1[i][j + 1]) + 1; }
else
stable++; }
else
grid1[i][j] = grid1[i][j] + grid2[i][j]; } }
flag = 1; } }
