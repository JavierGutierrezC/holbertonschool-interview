#!/usr/bin/python3
""" this module has the method rain """


def rain(walls):
    """
    Integer indicating total amount of rainwater retained
    """
    if len(walls) == 0:
        return 0

    left_v = [0] * len(walls)
    right_v = [0] * len(walls)
    left_v[0] = walls[0]
    right_v[-1] = walls[-1]
    for i in range(1, len(walls)):
        left_v[i] = max(left_v[i - 1], walls[i])

    for i in range(len(walls) - 2, -1, -1):
        right_v[i] = max(right_v[i + 1], walls[i])

    water = 0
    for i in range(len(walls)):
        water += min(right_v[i], left_v[i]) - walls[i]

    return water
