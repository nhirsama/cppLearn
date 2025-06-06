#  A. Energy Crystals
import math


def nhir():
    n = int(input())
    a, b, c = 0, 0, 0
    ans = 0
    while a < n:
        a = min(n, 2 * b + 1)
        a, b = b, a
        b, c = c, b
        ans += 1
    print(ans)


__T = int(input())
for __ in range(__T):
    nhir()
