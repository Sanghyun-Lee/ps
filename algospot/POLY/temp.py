import os
import time
import sys

CACHE = []
MOD = 10000000

def check(solves):
    f = open(os.path.join(os.getcwd(), 'POLY', 'answer.txt'), 'r')
    answer = []
    for a in f:
        answer.append(a.rstrip('\n'))

    for i in range(len(solves)):
        print(i, ' - answer = ', answer[i], ' solves = ', solves[i])
        if int(answer[i]) != int(solves[i]):
            f.close()
            return False
    
    f.close()
    return True


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
    f = open(os.path.join(os.getcwd(), 'POLY', 'input.txt'), 'r')
    test_case = int(f.readline())
    answer = []

    for i in range(test_case):
        count = int(f.readline())
        #print(count)
        CACHE = [[-1 for i in range(count + 1)] for j in range(count + 1)]
        ret = 0
        for n in range(1, count + 1):
            ret += poly(count, n)
            ret %= MOD
        answer.append(ret)
 
    f.close()
    print(check(answer))