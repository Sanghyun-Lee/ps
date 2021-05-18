import os
import time
import sys

NUMS = []
CACHE = []
INF = 987654321

def check(solves):
    f = open(os.path.join(os.getcwd(), 'PI', 'answer.txt'), 'r')
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


def classify(start, end):
    a = NUMS[start : end + 1]

    if a == (a[0] * len(a)):
        return 1

    isProgress = True

    for i in range(len(a) - 1):
        if (int(a[i + 1]) - int(a[i])) != (int(a[1]) - int(a[0])):
            isProgress = False

    if isProgress and abs(int(a[1]) - int(a[0])) == 1:
        return 2

    isAlternating = True
    for i in range(len(a)):
        if int(a[i]) != int(a[i % 2]):
            isAlternating = False

    if isAlternating:
        return 4

    if isProgress:
        return 5

    return 10


def memorize(idx):
    if idx >= len(NUMS):
        return 0

    ret = CACHE[idx]

    if ret != -1:
        return ret

    ret = INF
    for i in range(3, 6):
        if idx + i <= len(NUMS):
            ret = min(ret, memorize(idx + i) + classify(idx, idx + i - 1))
            CACHE[idx] = ret
    return ret


def classify_3(a, b, c):  # 3자리씩 끊어 읽기
    if a == b == c:  # 모든 숫자가 같음
        return 1
    if a-b == b-c == 1 or a-b == b-c == -1:  # 단조증가/감소
        return 2
    if a == c != b:  # 숫자가 번갈아 출현
        return 4
    if a-b == b-c:  # 등차수열
        return 5
    return 10
 
 
def classify_4(a, b, c, d):  # 4자리씩 끊어 읽기
    if a == b == c == d:
        return 1
    if a-b == b-c == c-d == 1 or a-b == b-c == c-d == -1:
        return 2
    if a == c and b == d and a != b:
        return 4
    if a-b == b-c == c-d:
        return 5
    return 10
 
 
def classify_5(a, b, c, d, e):  # 5자리씩 끊어 읽기
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
    N = len(arr)  # 리스트의 길이
    CACHE = [-1 for i in range(N + 1)]
    CACHE[3] = classify_3(arr[0], arr[1], arr[2])  # 0~2번까지 3개 읽음
    CACHE[4] = classify_4(arr[0], arr[1], arr[2], arr[3])  # 0~3번까지 4개 읽음
    CACHE[5] = classify_5(arr[0], arr[1], arr[2], arr[3], arr[4])  # 0~4번까지 5개 읽음

    for i in range(6, N+1):
        cand = []
        if CACHE[i-3] != -1:
            cand.append(CACHE[i-3] + classify_3(arr[i-3], arr[i-2], arr[i-1]))
        if CACHE[i-4] != -1:
            cand.append(CACHE[i-4] + classify_4(arr[i-4], arr[i-3], arr[i-2], arr[i-1]))
        if CACHE[i-5] != -1:
            cand.append(CACHE[i-5] + classify_5(arr[i-5], arr[i-4], arr[i-3], arr[i-2], arr[i-1]))
        CACHE[i] = min(cand)  # 최소값을 cache에 넣는다
    return CACHE[-1]
 
 
if __name__ ==  "__main__":
    f = open(os.path.join(os.getcwd(), 'PI', 'input.txt'), 'r')
    test_case = int(f.readline())
    answer = []

    for i in range(test_case):
        #NUMS = f.readline().rstrip('\n')
        number = list(map(int, list(f.readline().strip())))
        #print(pi(number))
        #CACHE = [-1 for i in range(len(NUMS) + 2)]
        answer.append(pi(number))
        #answer.append(memorize(0))
 
    f.close()
    print(check(answer))