import os
import random
import sys
from tokenize import Double
from typing import *
from collections import defaultdict, Counter, deque
from functools import cache, reduce
from itertools import pairwise, combinations, permutations, groupby, accumulate
# from bisect import bisect_lo, bisect_right, insort_left, insort_right
from heapq import *
from math import ceil, comb, gcd, inf, lcm, isqrt, log
from operator import add, sub, mul, floordiv, truediv, and_, or_, xor
from types import GeneratorType

input = sys.stdin.readline
output = lambda x: sys.stdout.write(str(x) + "\n")
outputL = lambda x: sys.stdout.write(" ".join(map(str, x)) + "\n")

read = lambda: sys.stdin.readline().rstrip('\n')
readInt = lambda: int(input())
readInts = lambda: map(int, input().split())
readStr = lambda: read()    
readStrs = lambda: read().rstrip('\n').split()
readArr = lambda: list(readInts())
        

def Solve():
    n = readInt()
    a = readArr()
    b = readArr()

    ans = a[-1]
    for i in range(n - 1):
        if a[i] > b[i + 1]:
            ans += a[i] - b[i + 1];
    
    print(ans)
    pass



T = 1
T = readInt()
def main():
    for _ in range(T):
        Solve()

main()