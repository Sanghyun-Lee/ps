import sys

CACHE = []
DEPTH = -1
DAYS = -1

def climb(days, climbed):
    if days == DAYS:
        if climbed >= DEPTH:
            return 1
        else:
            return 0
    
    ret = CACHE[days][climbed]
    if ret != -1:
        return ret

    CACHE[days][climbed] = 0.25 * climb(days + 1, climbed + 1) + 0.75 * climb(days + 1, climbed + 2)
    return CACHE[days][climbed]


if __name__ ==  "__main__":
    test_case = int(sys.stdin.readline())

    for i in range(test_case):
        DEPTH, DAYS = map(int, sys.stdin.readline().split())
        CACHE = [[-1 for i in range(DEPTH * 2 + 1)] for j in range(DEPTH)]

        print(climb(0, 0))