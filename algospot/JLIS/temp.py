import os
import time
import sys

A = []
B = []
A_SIZE = 0
B_SIZE = 0
CACHE = []

def check(solves):
    f = open(os.path.join(os.getcwd(), 'JLIS', 'answer.txt'), 'r')
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


def jlis(a_idx, b_idx):
    ret = CACHE[a_idx + 1][b_idx + 1]
    if ret != -1:
        return ret

    ret = 2
    if a_idx == -1:
        a = -(sys.maxsize + 1)
    else:
        a = A[a_idx]

    if b_idx == -1:
        b = -(sys.maxsize + 1)
    else:
        b = B[b_idx]
    max_val = max(a, b)

    for i in range(a_idx + 1, A_SIZE):
        if max_val < A[i]:
            ret = max(ret, jlis(i, b_idx) + 1)
            CACHE[a_idx + 1][b_idx + 1] = ret

    for i in range(b_idx + 1, B_SIZE):
        if max_val < B[i]:
            ret = max(ret, jlis(a_idx, i) + 1)
            CACHE[a_idx + 1][b_idx + 1] = ret

    return ret


if __name__ ==  "__main__":
    f = open(os.path.join(os.getcwd(), 'JLIS', 'input.txt'), 'r')
    test_case = int(f.readline())
    answer = []

    for i in range(test_case):
        A_SIZE, B_SIZE = map(int, f.readline().rstrip('\n').split())
        size = max(A_SIZE, B_SIZE) + 1
        A = list(map(int, f.readline().rstrip('\n').split()))
        B = list(map(int, f.readline().rstrip('\n').split()))
        CACHE = [[-1 for i in range(size)] for j in range(size)]
        print(A_SIZE, B_SIZE)
        print(A, B)

        answer.append(jlis(-1, -1) - 2)
 
    f.close()
    print(check(answer))