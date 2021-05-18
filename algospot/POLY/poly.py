import sys

CACHE = [[-1 for i in range(101)] for j in range(101)]
MOD = 10000000


def poly(n, first):
    if n == first:
        return 1

    ret = CACHE[n][first]
    
    if ret != -1:
        return ret

    ret = 0
    for second in range(1, n - first + 1):
        ret += (second + first - 1) * poly(n - first, second)
        ret %= MOD
    
    CACHE[n][first] = ret
    return ret


if __name__ ==  "__main__":
    test_case = int(sys.stdin.readline())

    for i in range(test_case):
        count = int(sys.stdin.readline())

        ret = 0
        for n in range(1, count + 1):
            ret += poly(count, n)
            ret %= MOD
        print(ret)