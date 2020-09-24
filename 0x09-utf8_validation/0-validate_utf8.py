#!/usr/bin/python3
"""
Write a method that determines if a given
data set represents a valid UTF-8 encoding.
"""


def validUTF8(data):
    bytes = 0

    for byte in data:
        byte = byte & 0xFF

        if bytes:
            bit = byte >> 6
            if (bit == 1 or bit == 3):
                return False
            bytes -= 1
            continue

        while 5 - bytes and byte & (1 << (7 - bytes)):
            bytes += 1
        if (bytes == 1 or bytes > 4):
            return False

    return False if bytes else True
