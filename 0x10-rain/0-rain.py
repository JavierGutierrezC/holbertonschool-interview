#!/usr/bin/python3
""" this module has the method rain """


def rain(walls):
    """
    Integer indicating total amount of rainwater retained
    """
    if len(walls) == 0:
        return 0

    left = [0] * len(walls)
    right = [0] * len(walls)

    left_values[0] = walls[0]
    right_values[-1] = walls[-1]
    
    for i in range(1, len(walls)):
        values_left[i] = max(v_l[i - 1], walls[i])

    for i in range(len(walls) - 2, -1, -1):
        values_right[i] = max(v_r[i + 1], walls[i])

    water = 0
    for i in range(len(walls)):
        water += min(v_r[i], v_l[i]) - walls[i]

    return water
