#!/usr/bin/python3
"""
Write a script that reads stdin line by line and computes metrics
"""

import sys


total_size = 0
counter = 0
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
        line_list = line.split(" ")
        if len(line_list) > 2:
            size = line_list[-1]
            code = line_list[-2]
            if code in status_code:
                status_code[code] += 1

            total_size += int(size)
            counter += 1
            if counter == 10:
                print("File size: {:d}".format(total_size))
                s_code = sorted(status_code.keys())
                for key in s_code:
                    if status_code[key] is not 0:
                        print("{}: {}".format(key, status_code[key]))
                counter = 0
except Exception:
    pass
finally:
    print("File size: {}".format(total_size))
    s_code = sorted(status_code.keys())
    for key in s_code:
        if status_code[key] is not 0:
            print("{}: {}".format(key, status_code[key]))
