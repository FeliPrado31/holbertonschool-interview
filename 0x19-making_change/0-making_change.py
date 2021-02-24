#!/usr/bin/python3
"""
Given a pile of coins of different values,
determine the fewest number of coins needed
to meet a given amount total
"""


def makeChange(coins, total):
    """
    Given a pile of coins of different values,
    determine the fewest number of coins needed
    to meet a given amount total
    """
    if total <= 0:
        return 0

    tmp = total + 1
    data = {0: 0}

    for i in range(1, total + 1):
        data[i] = tmp

        for coin in coins:
            current = i - coin
            if current < 0:
                continue

            data[i] = min(data[current] + 1, data[i])

    if data[total] == total + 1:
        return -1

    return data[total]
