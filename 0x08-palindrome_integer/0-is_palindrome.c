#include "palindrome.h"

/**
 * is_palindrome - checks palindrome integers.
 * @n: unsigned integers
 * Return: 1 if it ispalindrome ans 0 if it's not.
 */

int is_palindrome(unsigned long n)
{
  int unit = 0;
  unsigned long int rev_n = 0;
  unsigned long int orig = n;
  while (n >= 1)
    {
      unit = n % 10;
      rev_n = (rev_n *(10)) + unit;
      n = n / 10;
    }
  return (orig == rev_n);
}
