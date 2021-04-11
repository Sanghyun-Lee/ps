import sys

WORDS = []
CACHE = []
SIZE = 101
WILDCARD = ''
WORD = ''


def matchMemoized(w, s):
    ret = CACHE[w][s]
    ori_w = w
    ori_s = s

    if ret != -1:
        return ret

    if w < len(WILDCARD) and s < len(WORD) and (WILDCARD[w] == '?' or WILDCARD[w] == WORD[s]):
        CACHE[ori_w][ori_s] = matchMemoized(w + 1, s + 1)
        return CACHE[ori_w][ori_s]

    if w == len(WILDCARD):
        if s == len(WORD):
            CACHE[ori_w][ori_s] = 1
        else:
            CACHE[ori_w][ori_s] = 0
        return CACHE[ori_w][ori_s]

    if WILDCARD[w] == '*':
        if matchMemoized(w + 1, s) or (s < len(WORD) and matchMemoized(w, s+ 1)):
            CACHE[ori_w][ori_s] = 1
            return 1

    CACHE[ori_w][ori_s] = 0
    return 0


if __name__ ==  "__main__":
    test_case = int(sys.stdin.readline().rstrip('\n'))

    for i in range(test_case):
        WILDCARD = sys.stdin.readline().rstrip('\n')
        count = int(sys.stdin.readline().rstrip('\n'))

        ret = []
        for i in range(count):
            CACHE = [[-1 for i in range(SIZE)] for j in range(SIZE)]
            WORD = sys.stdin.readline().rstrip('\n')

            if matchMemoized(0, 0):
                ret.append(WORD)

        ret.sort()
        for r in ret:
            print(r)
        ret.clear()