import sys

BOARD = []
CACHE = []
SIZE = -1


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


if __name__ ==  "__main__":
    test_case = int(sys.stdin.readline())

    for i in range(test_case):
        SIZE = int(sys.stdin.readline())
        CACHE = [[-1 for i in range(SIZE)] for j in range(SIZE)]

        for i in range(SIZE):
            BOARD.append(list(map(int, sys.stdin.readline().split())))
        ret = solution(0, 0)

        if ret:
            print('YES')
        else:
            print('NO')

        BOARD.clear()