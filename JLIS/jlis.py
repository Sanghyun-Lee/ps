import sys

A = []
B = []
A_SIZE = 0
B_SIZE = 0
CACHE = []
NEGINF = -(sys.maxsize + 1)


def jlis(a_idx, b_idx):
    ret = CACHE[a_idx + 1][b_idx + 1]
    if ret != -1:
        return ret

    ret = 2
    if a_idx == -1:
        a = NEGINF
    else:
        a = A[a_idx]

    if b_idx == -1:
        b = NEGINF
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
    test_case = int(sys.stdin.readline())

    for i in range(test_case):
        A_SIZE, B_SIZE = map(int, sys.stdin.readline().split())
        size = max(A_SIZE, B_SIZE) + 1
        A = list(map(int, sys.stdin.readline().split()))
        B = list(map(int, sys.stdin.readline().split()))
        CACHE = [[-1 for i in range(size)] for j in range(size)]

        print(jlis(-1, -1) - 2)
