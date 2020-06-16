#include "palindrome.h"

/**
 * is_palindrome - checks palindrome integers.
 * @n: unsigned integers
 * Return: 1 if it ispalindrome ans 0 if it's not.
 */

int is_palindrome(unsigned long n)
{
  int unit = 0;
  unsigned long int diez = 1;
  unsigned long int diez_up = 1;
  unsigned long int rev_n = 0;
  unsigned long int orig = n;
  while (diez >= 1)
    {
      unit = n / diez;
      n = n - (unit * diez);
      rev_n = rev_n + (unit * diez_up);
      diez_up = diez_up * 10;
      diez = diez / 10;
    }
  return (orig == rev_n);
}
