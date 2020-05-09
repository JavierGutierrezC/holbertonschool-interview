#!/usr/bin/python3
"""Find number of minimum operations to create string"""


def minOperations(n):
    """a method that calculates the fewest number of operations
    needed to result in exactly n H characters in the file.'"""
    if type(n) is not int:
        return 0
    if n < 1:
        return 0
    x = 1
    p = 0
    cop = pas = 0
    copy = 0
    paste = 1
    ant = 1
    nhp1 = nhp2 = nhp3 = 0
    while x < n:
        if n % (x * 2) == 0:
            if nhp1 == 1:
                nhp1 = 0
            nhp3 = 0
            cop += 1
            ant = x
            pas += 1
            x = 2 * x
            copy += ant
            paste += (2 * ant) - paste
        elif n % x == 0 and x != 1:
            if n % paste == 0:
                ant = paste
                nhp1 = 0
                x = paste
            else:
                ant = x
            nhp3 = 0
            if nhp1 == 0:
                nhp1 = 1
                cop += 1
            pas += 1
            paste += ant
        else:
            nhp1 = 0
            if nhp3 == 0:
                nhp3 = 1
                cop += 1
                ant = x
            x = x + ant
            pas += 1
            paste += ant
        if paste >= n:
            break
    return cop + pas
