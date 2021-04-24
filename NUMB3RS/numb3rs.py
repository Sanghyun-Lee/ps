import sys
import copy

CACHE = []

TOWN = -1
DAYS = -1
JAIL = -1
DESTINATION = -1


def numb3rs(here, days):
    if days == 0:
        if here == JAIL:
            return 1.0
        else:
            return 0.0

    ret = CACHE[here][days]
    if ret > -0.5:
        return ret
    
    ret = 0.0
    for i in range(TOWN):
        if MAP[here][i]:
            ret += (numb3rs(i, days - 1)) / DEG[i]

    CACHE[here][days] = ret
    return ret

if __name__ ==  "__main__":
    test_case = int(sys.stdin.readline())

    for i in range(test_case):
        TOWN, DAYS, JAIL = map(int, sys.stdin.readline().split())
        CACHE = [[-1.0 for i in range(DAYS + 1)] for j in range(TOWN)]
        MAP = []
        DEG = []

        for j in range(TOWN):
            line = list(map(int, sys.stdin.readline().split()))
            MAP.append(line)
            DEG.append(sum(line))

        count = int(sys.stdin.readline())
        calc_towns = list(map(int, sys.stdin.readline().split()))
        answer = []

        for t in calc_towns:
            answer.append(str(numb3rs(t, DAYS)))
        print(' '.join(answer))

        answer.clear()