import os
import time

CACHE = []
DEPTH = -1
DAYS = -1

def check(solves):
    f = open(os.path.join(os.getcwd(), 'SNAIL', 'answer.txt'), 'r')
    answer = []
    for a in f:
        answer.append(a.rstrip('\n'))

    for i in range(len(solves)):
        print(i, ' - answer = ', answer[i], ' solves = ', solves[i])
        if abs(float(answer[i]) - float(solves[i])) > 0.0001:
            f.close()
            return False
    
    f.close()
    return True


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
    f = open(os.path.join(os.getcwd(), 'SNAIL', 'input.txt'), 'r')
    test_case = int(f.readline())
    answer = []

    for i in range(test_case):
        DEPTH, DAYS = map(int, f.readline().split())
        CACHE = [[-1 for i in range(DEPTH * 2 + 1)] for j in range(DEPTH)]

        answer.append(climb(0, 0))
 
    f.close()
    print(check(answer))