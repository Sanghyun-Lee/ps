import sys

CACHE = []
MOD = 1000000007


def tiling(n):
    n = int(n)
    if n <= 1:
        return 1

    ret = CACHE[n]
    if ret != -1:
        return ret

    ret = (tiling(n - 1) + tiling(n - 2)) % MOD
    CACHE[n] = ret
    return ret


def asymTiling(n):
    if (n % 2) == 1:
        return (tiling(n) - tiling(n / 2) + MOD) % MOD
    
    ret = tiling(n)
    ret = (ret - tiling(n / 2) + MOD) % MOD
    ret = (ret - tiling(n / 2 - 1) + MOD) % MOD

    return ret


if __name__ ==  "__main__":
    test_case = int(sys.stdin.readline())

    for i in range(test_case):
        count = int(sys.stdin.readline())
        CACHE = [-1 for i in range(count + 1)]
        print(asymTiling(count))
