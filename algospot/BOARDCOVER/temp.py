coverType = [[[0, 0], [1, 0], [0, 1]],
             [[0, 0], [0, 1], [1, 1]],
             [[0, 0], [1, 0], [1, 1]],
             [[0, 0], [1, 0], [1, -1]]]

def check(solves):
    f = open('/users/sanghyun/ps_python/BOARDCOVER/answer.txt', 'r')
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


def set_f(b, x, y, ty, delta):
    is_ok = True
    print(ty)
    for i in range(3):
        nx = x + ty[i][1]
        ny = y + ty[i][0]

        if (ny < 0) or (ny >= len(b)):
            is_ok = False
        elif (nx < 0) or (nx >= len(b[0])):
            is_ok = False
        else:
            b[ny][nx] += delta
            if b[ny][nx] > 1:
                is_ok = False


    return is_ok


def cover(b, h, w):
    x = -1
    y = -1

    for i in range(h):
        for j in range(w):
            if board[i][j] == 0:
                x = j
                y = i
                break
        if y != -1:
            break
    
    if y == -1:
        return 1

    ret = 0

    for ty in coverType:
        if set_f(b, x, y, ty, 1):
            ret += cover(b, h, w)
        set_f(b, x, y, ty, -1)

    return ret
    

if __name__ ==  "__main__":
    f = open('/Users/sanghyun/ps_python/BOARDCOVER/input.txt', 'r')
    test_case = int(f.readline())
    answer = []

    for i in range(test_case):
        h, w = map(int, f.readline().split())
        board = [[0 for j in range(w)] for i in range(h)]
        count = 0

        for i in range(h):
            lines = f.readline()
            for j in range(len(lines)):
                a = lines[j]
                if a == '#':
                    count += 1
                    board[i][j] = 1

        print(board)
        answer.append(cover(board, h, w))

    f.close()
    print(check(answer))