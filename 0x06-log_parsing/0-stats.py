#!/usr/bin/python3
"""
Write a script that reads stdin line by line and computes metrics
"""

import sys


size = 0
count = 0
status_code = {
    '200': 0,
    '301': 0,
    '400': 0,
    '401': 0,
    '403': 0,
    '404': 0,
    '405': 0,
    '500': 0,

}

try:
    for line in sys.stdin:
        data = line.split(" ")
        if len(data) > 2:
            size = data[-1]
            code = data[-2]

            if code in status_code:
                status_code[code] += 1

            size += int(size)
            count += 1
            if count == 10:
                print("File size: {:d}".format(size))
                res = sorted(status_code.keys())
                for key in res:
                    if status_code[key] is not 0:
                        print("{}: {}".format(key, status_code[key]))
                count = 0

except Exception:
    pass

finally:
    print("File size: {}".format(size))
    res = sorted(status_code.keys())
    for key in res:
        if status_code[key] is not 0:
            print("{}: {}".format(key, status_code[key]))
