#!/usr/bin/python3
"""
Given a list of non-negative integers representing walls of width 1,
calculate how much water will be retained after it rains.
"""


def rain(walls):
    """
    Given a list of non-negative integers representing walls of width 1,
    calculate how much water will be retained after it rains.
    """
    if(not len(walls)):
        return 0

    lenght = len(walls) - 1
    pre = walls[0]
    prevIndex = 0
    tmp = 0
    data = 0

    for i in range(1, lenght + 1):
        if (walls[i] >= pre):
            pre = walls[i]
            prevIndex = i
            tmp = 0
        else:
            data += pre - walls[i]
            tmp += pre - walls[i]

    if (prevIndex < lenght):
        data -= tmp
        pre = walls[i]

        for i in range(lenght, prevIndex - 1, -1):
            if (walls[i] >= pre):
                pre = walls[i]
            else:
                data += pre - walls[i]

    return data
