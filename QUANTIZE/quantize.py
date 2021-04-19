import sys

NUMS = []
CACHE = []
pSUM = []
pSqSUM = []
COUNT = -1
LEN = -1
INF = 987654321


def precalc():
    NUMS.sort()

    pSUM[0] = NUMS[0]
    pSqSUM[0] = NUMS[0] * NUMS[0]

    for i in range(1, LEN):
        pSUM[i] = pSUM[i - 1] + NUMS[i]
        pSqSUM[i] = pSqSUM[i - 1] + NUMS[i] * NUMS[i]


def minError(low, high):
    if low == 0:
        low_sum = 0
        low_sq = 0
    else:
        low_sum = pSUM[low - 1]
        low_sq = pSqSUM[low - 1]
    s = pSUM[high] - low_sum
    sq = pSqSUM[high] - low_sq

    m = int(0.5 + float(s) / (high - low + 1))
    ret = sq - 2 * m * s + m * m * (high - low + 1)

    return ret


def quantize(f, p):
    if f == LEN:
        return 0
    if p == 0:
        return INF

    ret = CACHE[f][p - 1]
    if ret != -1:
        return ret

    ret = INF
    for i in range(f, LEN):
        ret = min(ret, minError(f, i) + quantize(i + 1, p - 1))
        CACHE[f][p - 1] = ret
    return ret


if __name__ ==  "__main__":
    test_case = int(sys.stdin.readline())

    for i in range(test_case):
        LEN, COUNT = map(int, sys.stdin.readline().split())
        NUMS = list(map(int, sys.stdin.readline().split()))

        CACHE = [[-1 for i in range(LEN + 1)] for j in range(LEN + 1)]
        pSUM = [-1 for i in range(LEN + 1)]
        pSqSUM = [-1 for i in range(LEN + 1)]

        precalc()
        print(quantize(0, COUNT))