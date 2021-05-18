import os
import time

PATH = []
CACHE = []
DEPTH = -1


def check(solves):
    f = open(os.path.join(os.getcwd(), 'TRIANGLEPATH', 'answer.txt'), 'r')
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

def pathMemoized(y, x):
    if y >= DEPTH - 1:
        return PATH[y][x]

    ret = CACHE[y][x]
    if ret == -1:
        CACHE[y][x] = PATH[y][x] + max(pathMemoized(y + 1, x), pathMemoized(y + 1, x + 1))
        return CACHE[y][x]
    return CACHE[y][x]


def pathSum(y, x, s):
    if y >= DEPTH - 1:
        return s + PATH[y][x]
    return max(pathSum(y + 1, x, s + PATH[y][x]), pathSum(y + 1, x + 1, s + PATH[y][x]))


if __name__ ==  "__main__":
    f = open(os.path.join(os.getcwd(), 'TRIANGLEPATH', 'input.txt'), 'r')
    test_case = int(f.readline())
    answer = []

    for i in range(test_case):
        DEPTH = int(f.readline().rstrip('\n'))

        for i in range(DEPTH):
            PATH.append(list(map(int, f.readline().rstrip('\n').split())))
            CACHE.append([-1 for n in range(i + 1)])

        answer.append(pathSum(0, 0, 0))
        PATH.clear()
        CACHE.clear()
 
    f.close()
    print(check(answer))