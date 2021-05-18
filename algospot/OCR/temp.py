import os
import time
import sys


def check(solves):
    f = open(os.path.join(os.getcwd(), 'OCR', 'answer.txt'), 'r')
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


def pack(capacity, item):
    if item == N:
        return 0
    
    ret = CACHE[capacity][item]
    if ret != -1:
        return ret
    
    ret = pack(capacity, item + 1)

    if capacity >= VOLUME[item]:
        ret = max(ret, pack(capacity - VOLUME[item], item + 1) + NEED[item])

    CACHE[capacity][item] = ret
    return ret


def reconstruct(capacity, item, picked):
    if item == N:
        return

    if pack(capacity, item) == pack(capacity, item + 1):
        reconstruct(capacity, item + 1, picked)
    else:
        picked.append(ITEMS[item])
        reconstruct(capacity - VOLUME[item], item + 1, picked)


if __name__ ==  "__main__":
    f = open(os.path.join(os.getcwd(), 'OCR', 'input.txt'), 'r')

    M, Q = map(int, f.readline().split())
    words = f.readline().split()
    first = list(map(float, f.readline().split()))

    print(words)
    print(first)

    T_MATRIX = []
    M_MATRIX = []
    for _ in range(M):
        T_MATRIX.append(list(map(float, f.readline().split())))

    for _ in range(M):
        M_MATRIX.append(list(map(float, f.readline().split())))

    WORD_COUNT = []
    SENTENCE = []
    for _ in range(Q):
        line = f.readline().split()
        WORD_COUNT.append(int(line[0]))
        SENTENCE.append(line[1:])

    print(WORD_COUNT)
    print(SENTENCE)

 
    f.close()
    #print(check(answer))