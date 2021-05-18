import sys

CACHE = []
MOD = 1000000007


def tiling(n):
    if n <= 1:
        return 1

    ret = CACHE[n]
    if ret != -1:
        return ret

    ret = (tiling(n - 1) + tiling(n - 2)) % MOD
    CACHE[n] = ret
    return ret


if __name__ ==  "__main__":
    test_case = int(sys.stdin.readline())

    for i in range(test_case):
        count = int(sys.stdin.readline())
        CACHE = [-1 for i in range(count + 1)]
        print(tiling(count))