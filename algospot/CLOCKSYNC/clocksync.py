switch_list = [[0, 1, 2],
              [3, 7, 9, 11],
              [4, 10, 14, 15],
              [0, 4, 5, 6, 7],
              [6, 7, 8, 10, 12],
              [0, 2, 14, 15],
              [3, 14, 15],
              [4, 5, 7, 14, 15],
              [1, 2, 3, 4, 5],
              [3, 4, 5, 9, 13]]
INF = 9999
LEN = len(switch_list)


def checkClock(clocks):
    for c in clocks:
        if c != 12:
            return INF
    
    return 0


def push(clocks, switch):
    for s in switch:
        if clocks[s] == 12:
            clocks[s] = 3
        else:
            clocks[s] += 3


def clockSync(clocks, switch_num):
    if switch_num == LEN:
        return checkClock(clocks)


    ret = INF
    for i in range(4):
        ret_count = i + clockSync(clocks, switch_num + 1)
        push(clocks, switch_list[switch_num])
        ret = min(ret, ret_count)

    return ret


if __name__ ==  "__main__":
    test_case = int(input())

    for i in range(test_case):
        clocks = list(map(int, input().split()))

        if (clocks[14] != clocks[15]) or (clocks[8] != clocks[12]):
            ret = -1
        else:
            ret = clockSync(clocks, 0)

            if ret >= INF:
                ret = -1

        print(ret)