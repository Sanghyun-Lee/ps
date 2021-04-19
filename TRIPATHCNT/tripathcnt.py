import sys

PATH = []
CACHE = []
PATH_CACHE = []
DEPTH = -1


def path(y, x):
    if y == DEPTH - 1:
        return PATH[y][x]

    ret = PATH_CACHE[y][x]
    if ret != -1:
        return ret
    
    PATH_CACHE[y][x] = PATH[y][x] + max(path(y + 1, x), path(y + 1, x + 1))
    return PATH_CACHE[y][x]


def count(y, x):
    if y == DEPTH - 1:
        return 1

    ret = CACHE[y][x]
    if ret != -1:
        return ret

    ret = 0
    a = path(y + 1, x)
    b = path(y + 1, x + 1)

    if a >= b:
        ret += count(y + 1, x)
    if a <= b:
        ret += count(y + 1, x + 1)

    CACHE[y][x] = ret
    return CACHE[y][x]


if __name__ ==  "__main__":
    test_case = int(sys.stdin.readline())

    for i in range(test_case):
        DEPTH = int(sys.stdin.readline())

        for i in range(DEPTH):
            PATH.append(list(map(int, sys.stdin.readline().split())))
            CACHE.append([-1 for n in range(i + 1)])
            PATH_CACHE.append([-1 for n in range(i + 1)])

        print(count(0, 0))
        PATH_CACHE.clear()
        PATH.clear()
        CACHE.clear()