import sys

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

    ret = -1
    for left, right in args:
        if left == right:
            ret = max(ret, fence[left])
        else:
            center = left + right >> 1
            low = center
            high = center + 1
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

    return ret 

def solution(fence, left, right):
    if left == right:
        return fence[left]

    center = (left + right) >> 1
    low = center
    high = center + 1
    l = solution(fence, left, low)
    r = solution(fence, high, right)

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
    test_case = int(sys.stdin.readline())

    for i in range(test_case):
        fence_num = int(sys.stdin.readline())
        fence = list(map(int, sys.stdin.readline().split()))
        #print(solution(fence, 0, fence_num - 1))
        print(solve(fence, 0, fence_num - 1))