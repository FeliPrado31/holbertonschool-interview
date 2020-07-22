#!/usr/bin/python3
"""test"""


def canUnlockAll(boxes):
    """ Test """
    if not boxes:
        return False

    keys = {0}
    end = False

    while not end:
        flag = False
        for i in range(len(boxes)):
            if i in keys:
                for key in boxes[i]:
                    if key not in keys:
                        flag = True
                    keys.add(key)
        end = True if not flag else False
    return len(keys) == len(boxes)
