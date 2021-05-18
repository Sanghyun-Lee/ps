import sys

SEQUENCE = []
CACHE = []
SIZE = 0


def makeSequence(index):
    ret = CACHE[index + 1]

    if ret != -1:
        return ret

    ret = 1
    for i in range(index + 1, SIZE):
        if index == -1 or SEQUENCE[index] < SEQUENCE[i]:
            ret = max(ret, 1 + makeSequence(i))
            CACHE[index + 1] = ret

    return ret


if __name__ ==  "__main__":
    test_case = int(sys.stdin.readline())

    for i in range(test_case):
        SIZE = int(sys.stdin.readline())
        SEQUENCE = list(map(int, sys.stdin.readline().split()))
        CACHE = [-1 for n in range(SIZE + 1)]

        print(makeSequence(-1) - 1)
