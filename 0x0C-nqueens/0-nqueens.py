#!/usr/bin/python3
import sys


def queens(n):
    count = []
    data = set()
    for i in range(n):
        count.append([0, i])
        data.add(i)

    data_arr = []

    while count:
        [row, i] = count.pop(0)
        while data_arr and (row < data_arr[0][0]):
            data_arr.pop(0)
        if data_arr and (row == data_arr[0][0]):
            data_arr[0] = [row, i]
        else:
            data_arr.insert(0, [row, i])

        nextRow = row + 1

        killZone = set()
        for (r, c) in data_arr:
            killZone.add(c)
            distance = nextRow - r
            if c - distance >= 0:
                killZone.add(c - distance)
            if c + distance < n:
                killZone.add(c + distance)

        local_diff = data.difference(killZone)
        if not local_diff:
            if nextRow == n:
                copy = data_arr.copy()
                copy.reverse()
                print(copy, flush=True)
            data_arr.pop(0)
        else:
            local_diff = list(local_diff)
            local_diff.reverse()
            for position in local_diff:
                count.insert(0, [nextRow, position])


if __name__ == '__main__':
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)
    try:
        n = int(sys.argv[1])
    except:
        print("N must be a number")
        exit(1)
    if int(sys.argv[1]) < 4:
        print("N must be at least 4")
        exit(1)
    queens(n)