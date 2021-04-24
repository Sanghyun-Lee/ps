import sys
import copy

MAP = []
DEG = []
PATH = []
CACHE = []
TEMP_CACHE = []

TOWN = -1
DAYS = -1
JAIL = -1
DESTINATION = -1


def calcDEG(deg, m):
    for i in range(TOWN):
        deg.append(sum(m[i]))


def numb3rs(here, days):
    if days == DAYS:
        if here == DESTINATION:
            return 1.0
        else:
            return 0.0

    ret = CACHE[here][days]
    if ret > -0.5:
        return ret
    
    ret = 0.0
    for i in range(TOWN):
        if MAP[here][i]:
            ret += (numb3rs(i, days + 1))

    ret /= DEG[here]
    CACHE[here][days] = ret
    return ret

if __name__ ==  "__main__":
    test_case = int(sys.stdin.readline())

    for i in range(test_case):
        TOWN, DAYS, JAIL = map(int, sys.stdin.readline().split())
        TEMP_CACHE = [[-1.0 for i in range(DAYS + 1)] for j in range(TOWN + 1)]
        for j in range(TOWN):
            MAP.append(list(map(int, sys.stdin.readline().split())))
        calcDEG(DEG, MAP)

        count = int(sys.stdin.readline())
        calc_towns = list(map(int, sys.stdin.readline().split()))
        answer = []

        for t in calc_towns:
            DESTINATION = t
            CACHE = copy.deepcopy(TEMP_CACHE)
            answer.append(str(numb3rs(JAIL, 0)))
        print(' '.join(answer))
        
        DEG.clear()
        MAP.clear()
        answer.clear()