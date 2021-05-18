import os
import time
import sys

CACHE = []
MOD = 1000000007

def check(solves):
    f = open(os.path.join(os.getcwd(), 'TILING2', 'answer.txt'), 'r')
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


def tiling(n):
    if n <= 1:
        return 1

    ret = CACHE[n]
    if ret != -1:
        return ret

    ret = (tiling(n - 1) + tiling(n - 2)) % MOD
    CACHE[n] = ret
    return ret


if __name__ ==  "__main__":
    f = open(os.path.join(os.getcwd(), 'TILING2', 'input.txt'), 'r')
    test_case = int(f.readline())
    answer = []

    for i in range(test_case):
        count = int(f.readline())
        CACHE = [-1 for i in range(count + 1)]
        answer.append(tiling(count))
 
    f.close()
    print(check(answer))