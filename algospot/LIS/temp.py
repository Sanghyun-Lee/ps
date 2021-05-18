import os
import time

SEQUENCE = []
CACHE = []
CHOISE = []
SIZE = 0

def check(solves):
    f = open(os.path.join(os.getcwd(), 'LIS', 'answer.txt'), 'r')
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


def makeSequence(seq):
    if len(seq) == 0:
        return 0

    ret = 0

    for i in range(len(seq)):
        temp = []
        for j in range(i + 1, len(seq)):
            if seq[i] < seq[j]:
                temp.append(seq[j])
        ret = max(ret, 1 + makeSequence(temp))

    return ret


def makeSequence2(index):
    ret = CACHE[index]
    
    if ret != -1:
        return ret

    ret = 1
    for i in range(index + 1, SIZE):
        if SEQUENCE[index] < SEQUENCE[i]:
            ret = max(ret, 1 + makeSequence2(i))
            CACHE[i] = ret

    return ret


def makeSequence3(index):
    ret = CACHE[index + 1]

    if ret != -1:
        return ret

    ret = 1

    for i in range(index + 1, SIZE):
        if index == -1 or SEQUENCE[index] < SEQUENCE[i]:
            ret = max(ret, 1 + makeSequence3(i))
            CACHE[index + 1] = ret
    return ret

def makeSequence4(index):
    ret = CACHE[index + 1]

    if ret != -1:
        return ret

    ret = 1
    bestNext = -1

    for i in range(index + 1, SIZE):
        if index == -1 or SEQUENCE[index] < SEQUENCE[i]:
            cand = makeSequence4(i) + 1
            if cand > ret:
                ret = cand
                bestNext = i
    CHOISE[index + 1] = bestNext
    CACHE[index + 1] = ret
    return ret


def reconstruct(index, seq):
    if start != -1:
        seq.append(SEQUENCE[index])

    next = CHOISE[index + 1]
    if next != -1:
        reconstruct(next, seq)

if __name__ ==  "__main__":
    f = open(os.path.join(os.getcwd(), 'LIS', 'input.txt'), 'r')
    test_case = int(f.readline())
    answer = []

    for i in range(test_case):
        SIZE = int(f.readline().rstrip('\n'))
        SEQUENCE = list(map(int, f.readline().rstrip('\n').split()))
        CACHE = [-1 for n in range(SIZE + 1)]
        CHOISE = [-1 for n in range(SIZE + 1)]

        answer.append(makeSequence4(-1) - 1)
 
    f.close()
    print(check(answer))