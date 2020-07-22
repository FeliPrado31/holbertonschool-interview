#!/usr/bin/python3
"""test func"""

def canUnlockAll(boxes):
    """ test """
    keys = {0}
    canFinish = False

    while not canFinish:
        flag = False
        for i in range(len(boxes)):
            if i in keys:
                for key in boxes[i]:
                    if key not in keys:
                        flag = True
                    keys.add(key)
        canFinish = True if not flag else False
    return len(keys) == len(boxes)
