#!/usr/bin/env python


"""gcd.py: Euclidean algorithm"""


__author__  = "Ronald Kaiser"


def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)


def gcds(s, a, b):
    "Returns the number of mod operations"
    return s if b == 0 else gcds(s + 1, b, a % b)

