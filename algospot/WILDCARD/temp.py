import os
import time

WORDS = []
CACHE = []
SIZE = 101
WILDCARD = ''
WORD = ''

def check(solves):
    f = open(os.path.join(os.getcwd(), 'WILDCARD', 'answer.txt'), 'r')
    answer = []
    for a in f:
        answer.append(a.rstrip('\n'))

    for i in range(len(solves)):
        print(i, ' - answer = ', answer[i], ' solves = ', solves[i])
        if answer[i] != solves[i]:
            f.close()
            return False
    
    f.close()
    return True


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


def match(wildcard, word):
    pos = 0

    while pos < len(wildcard) and pos < len(word) and (wildcard[pos] == '?' or wildcard[pos] == word[pos]):
        pos += 1

    if pos == len(wildcard):
        return pos == len(word)

    if wildcard[pos] == '*':
        for i in range(len(word) - pos + 1):
            if match(wildcard[pos + 1:], word[pos + i:]):
                return True

    return False


if __name__ ==  "__main__":
    f = open(os.path.join(os.getcwd(), 'WILDCARD', 'input.txt'), 'r')
    test_case = int(f.readline())
    answer = []

    for i in range(test_case):
        WILDCARD = f.readline().rstrip('\n')
        print(WILDCARD)
        count = int(f.readline().rstrip('\n'))

        ret = []
        for i in range(count):
            CACHE = [[-1 for i in range(SIZE)] for j in range(SIZE)]
            WORD = f.readline().rstrip('\n')

            r = matchMemoized(0, 0)
            if r:
                ret.append(WORD)

        ret.sort()
        for r in ret:
            answer.append(r)
        ret.clear()

        '''
        ret = []
        for i in range(count):
            WORD = f.readline().rstrip('\n')

            if match(WILDCARD, WORD):
                ret.append(WORD)

        ret.sort()
        for r in ret:
            answer.append(r)
        ret.clear()
        '''

    f.close()
    print(check(answer))