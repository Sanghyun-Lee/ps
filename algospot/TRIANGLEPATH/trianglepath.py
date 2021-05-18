import sys

PATH = []
CACHE = []
DEPTH = -1


def pathMemoized(y, x):
    if y >= DEPTH - 1:
        return PATH[y][x]

    ret = CACHE[y][x]
    if ret == -1:
        CACHE[y][x] = PATH[y][x] + max(pathMemoized(y + 1, x), pathMemoized(y + 1, x + 1))
        return CACHE[y][x]

    return CACHE[y][x]


if __name__ ==  "__main__":
    test_case = int(sys.stdin.readline())

    for i in range(test_case):
        DEPTH = int(sys.stdin.readline())

        for i in range(DEPTH):
            PATH.append(list(map(int, sys.stdin.readline().split())))
            CACHE.append([-1 for n in range(i + 1)])

        print(pathMemoized(0, 0))
        PATH.clear()
        CACHE.clear()
