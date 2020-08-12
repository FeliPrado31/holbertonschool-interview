#!/usr/bin/python3
"""In a text file, there is a single character H.
Your text editor can execute only two operations in this file:
Copy All and Paste. Given a number n,
write a method that calculates the fewest number of operations 
needed to result in exactly n H characters in the file.
"""


def minOperations(n):
    count = 0
    res = 0
    op = 0

    if n <= 0:
        return 0

    count = 1
    while count != n:
        if n % count == 0:
            res = count
            op += 1
        count = count + res
        op += 1
    return op
