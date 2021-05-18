import os
import time

BOARD = []
CACHE = []
SIZE = -1

def check(solves):
    f = open(os.path.join(os.getcwd(), 'JUMPGAME', 'answer.txt'), 'r')
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


def solution(x, y):
    if x >= SIZE or y >= SIZE:
        return 0
    if (x == SIZE - 1) and (y == SIZE - 1):
        return 1
    
    ret = CACHE[y][x]

    if ret != -1:
        return ret
    
    jump_size = BOARD[y][x]
    CACHE[y][x] = solution(x, y + jump_size) or solution(x + jump_size, y)
    return CACHE[y][x]
        

def recursive(x, y):
    if x >= SIZE or y >= SIZE:
        return False
    if (x == SIZE - 1) and (y == SIZE - 1):
        return True
    
    jump_size = BOARD[y][x]
    return recursive(x, y + jump_size) or recursive(x + jump_size, y)


if __name__ ==  "__main__":
    f = open(os.path.join(os.getcwd(), 'JUMPGAME', 'input.txt'), 'r')
    test_case = int(f.readline())
    answer = []

    for i in range(test_case):
        SIZE = int(f.readline().rstrip('\n'))
        CACHE = [[-1 for i in range(SIZE)] for j in range(SIZE)]

        for i in range(SIZE):
            BOARD.append(list(map(int, f.readline().rstrip('\n').split())))
        #ret = recursive(0, 0)
        ret = solution(0, 0)

        if ret:
            answer.append('YES')
        else:
            answer.append('NO')

        BOARD.clear()

    f.close()
    print(check(answer))