import os
import time
import sys
import copy

PATH = []
CACHE = []

TOWN = -1
DAYS = -1
JAIL = -1
DESTINATION = -1

def check(solves):
    f = open(os.path.join(os.getcwd(), 'NUMB3RS', 'answer.txt'), 'r')
    answer = []
    for a in f:
        answer.append(list(map(float, a.rstrip('\n').split())))

    for i in range(len(solves)):
        for j in range(len(solves[i])):
            print(j, ' - answer = ', answer[i][j], ' solves = ', solves[i][j])
            if abs(float(answer[i][j]) - float(solves[i][j])) > 0.00000001:
                f.close()
                return False
    
    f.close()
    return True


def numb3rs(path):
    if len(path) == DAYS + 1:
        if path[-1] != DESTINATION:
            return 0.0

        ret = 1.0
        for i in range(len(path) - 1):
            ret /= DEG[path[i]]
        return ret

    ret = 0.0
    for pos in range(TOWN):
        if MAP[path[-1]][pos]:
            path.append(pos)
            ret += numb3rs(path)
            path.pop()
    return ret


def numb3rs2(here, days):
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
            ret += (numb3rs2(i, days + 1))
    ret /= DEG[here]

    CACHE[here][days] = ret
    return ret


def numb3rs3(here, days):
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
            ret += (numb3rs3(i, days - 1)) / DEG[i]

    CACHE[here][days] = ret
    return ret


if __name__ ==  "__main__":
    f = open(os.path.join(os.getcwd(), 'NUMB3RS', 'input.txt'), 'r')
    test_case = int(f.readline())
    answer = []

    for i in range(test_case - 1):
        TOWN, DAYS, JAIL = map(int, f.readline().split())
        CACHE = [[-1.0 for i in range(DAYS + 1)] for j in range(TOWN)]
        MAP = []
        DEG = []

        for j in range(TOWN):
            line = list(map(int, f.readline().split()))
            MAP.append(line)
            DEG.append(sum(line))

        count = int(f.readline())
        calc_towns = list(map(int, f.readline().split()))
        temp = []

        for t in calc_towns:
            #DESTINATION = t
            #PATH.append(JAIL)
            #CACHE = copy.deepcopy(TEMP_CACHE)
            temp.append(str(numb3rs3(t, DAYS)))
            #PATH.clear()

        print(' '.join(temp))
        answer.append(' '.join(temp))
 
    f.close()
    print(check(answer))