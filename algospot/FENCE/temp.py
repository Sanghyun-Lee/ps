import os
import time


def check(solves):
    f = open(os.path.join(os.getcwd(), 'FENCE', 'answer.txt'), 'r')
    answer = []
    for a in f:
        answer.append(int(a))

    for i in range(len(solves)):
        print(i, ' - answer = ', answer[i], ' solves = ', solves[i])
        if answer[i] != solves[i]:
            f.close()
            return False
    
    f.close()
    return True


def getArgs(length, l, r):
    args = []
    idx = 1

    while True:
        if length <= idx:
            args.append((l, r))
            return args

        for i in range(0, length, idx):
            if (i + idx) < length:
                args.append((i, i + idx - 1))
            elif idx == 1 or i != length - 1:
                args.append((i, length - 1))
        idx *= 2
    return args


def solve(fence, l, r):
    args = getArgs(len(fence), l, r)
    print(args, len(args))

    ret = -1
    for left, right in args:
        if left == right:
            ret = max(ret, fence[left])
        else:
            center = left + right >> 1
            low = center
            high = center + 1
            #l = solution(fence, left, low)
            #r = solution(fence, high, right)

            #ret = max(l, r)
            height = min(fence[low], fence[high])
            

            while ((left < low) or (high < right)):
                if high < right and (left == low or fence[low - 1] < fence[high + 1]):
                    high += 1
                    height = min(height, fence[high])
                else:
                    low -= 1
                    height = min(height, fence[low])

                ret = max(ret, (high - low + 1) * height)
            ret = max(ret, height << 1)
            print(ret)

    return ret 



def solution(fence, left, right):
    if left == right:
        return fence[left]

    center = int(left + right) >> 1
    low = center
    high = center + 1
    l = solution(fence, left, low)
    r = solution(fence, high, right)

    #ret = max(l, r)
    height = min(fence[low], fence[high])
    ret = max(l, r, height << 1)

    while ((left < low) or (high < right)):
        if high < right and (left == low or fence[low - 1] < fence[high + 1]):
            high += 1
            height = min(height, fence[high])
        else:
            low -= 1
            height = min(height, fence[low])

        ret = max(ret, (high - low + 1) * height)

    return ret 


if __name__ ==  "__main__":
    f = open(os.path.join(os.getcwd(), 'FENCE', 'input.txt'), 'r')
    test_case = int(f.readline())
    answer = []

    for i in range(test_case):
        start = time.time()
        fence_num = int(f.readline())
        fence = list(map(int, f.readline().split()))
        #answer.append(solve(fence, 0, fence_num - 1))
        answer.append(solution(fence, 0, fence_num - 1))
        #print('time =', time.time() - start)

    f.close()
    print(check(answer))