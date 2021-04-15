import sys

CACHE = []


def classify_3(a, b, c):
    if a == b == c:
        return 1
    if a-b == b-c == 1 or a-b == b-c == -1:
        return 2
    if a == c != b:
        return 4
    if a-b == b-c:
        return 5
    return 10
 
 
def classify_4(a, b, c, d):
    if a == b == c == d:
        return 1
    if a-b == b-c == c-d == 1 or a-b == b-c == c-d == -1:
        return 2
    if a == c and b == d and a != b:
        return 4
    if a-b == b-c == c-d:
        return 5
    return 10
 
 
def classify_5(a, b, c, d, e):
    if a == b == c == d == e:
        return 1
    if a-b == b-c == c-d == d-e == 1 or a-b == b-c == c-d == d-e == -1:
        return 2
    if a == c == e and b == d and a != b:
        return 4
    if a-b == b-c == c-d == d-e:
        return 5
    return 10
 
 
def pi(arr):
    N = len(arr) + 1
    CACHE = [-1 for i in range(N)]
    CACHE[3] = classify_3(arr[0], arr[1], arr[2])
    CACHE[4] = classify_4(arr[0], arr[1], arr[2], arr[3])
    CACHE[5] = classify_5(arr[0], arr[1], arr[2], arr[3], arr[4])

    for i in range(6, N):
        cand = []
        if CACHE[i-3] != -1:
            cand.append(CACHE[i-3] + classify_3(arr[i-3], arr[i-2], arr[i-1]))
        if CACHE[i-4] != -1:
            cand.append(CACHE[i-4] + classify_4(arr[i-4], arr[i-3], arr[i-2], arr[i-1]))
        if CACHE[i-5] != -1:
            cand.append(CACHE[i-5] + classify_5(arr[i-5], arr[i-4], arr[i-3], arr[i-2], arr[i-1]))
        CACHE[i] = min(cand)
    return CACHE[-1]
 
 
if __name__ ==  "__main__":
    test_case = int(sys.stdin.readline())

    for i in range(test_case):
        number = list(map(int, list(sys.stdin.readline().strip()))
        print(pi(number))
