#!/usr/bin/python3
"""Find number of minimum operations to create string"""


def minOperations(n):
    """a method that calculates the fewest number of operations
    needed to result in exactly n H characters in the file.'"""
    i = 1
    p = n
    co = 0
    pa = 0
    if (n < 1):
        return(0)
    else:
        while i < n:
            # print("esto es i", i)
            if (n % 2 == 0):
                n = n / 2
                # print("im n if",n)
                co = co + 1
                pa = pa + 1
            else:
                n = n + 1
                # print("im n else",n)
                n = n / 2
                # print("im n else div",n)
                pa = pa + 1
        a = 0
        for i in range(2, p - 1):
            if (p % i) == 0:
                print(p)
                a = 1
        if a == 0:
            return(p)
        return(co + pa if p % 2 == 0 else co + pa + 1)
