#!/usr/bin/python3
import sys


def queens(n):
    paths = []
    safe_zone = set()
    for column in range(n):
        paths.append([0, column])
        safe_zone.add(column)

    track = []

    while paths:
        [row, column] = paths.pop(0)
        while track and (row < track[0][0]):
            track.pop(0)
        if track and (row == track[0][0]):
            track[0] = [row, column]
        else:
            track.insert(0, [row, column])

        nextRow = row + 1

        dead_zone = set()
        for (r, c) in track:
            dead_zone.add(c)
            distance = nextRow - r
            if c - distance >= 0:
                dead_zone.add(c - distance)
            if c + distance < n:
                dead_zone.add(c + distance)

        data = safe_zone.difference(dead_zone)
        if not data:
            if nextRow == n:
                copy = track.copy()
                copy.reverse()
                print(copy, flush=True)
            track.pop(0)
        else:
            data = list(data)
            data.reverse()
            for position in data:
                paths.insert(0, [nextRow, position])


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