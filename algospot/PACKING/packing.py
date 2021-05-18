import sys


def pack(capacity, item):
    if item == N:
        return 0
    
    ret = CACHE[capacity][item]
    if ret != -1:
        return ret
    
    ret = pack(capacity, item + 1)

    if capacity >= VOLUME[item]:
        ret = max(ret, pack(capacity - VOLUME[item], item + 1) + NEED[item])

    CACHE[capacity][item] = ret
    return ret


def reconstruct(capacity, item, picked):
    if item == N:
        return

    if pack(capacity, item) == pack(capacity, item + 1):
        reconstruct(capacity, item + 1, picked)
    else:
        picked.append(ITEMS[item])
        reconstruct(capacity - VOLUME[item], item + 1, picked)


if __name__ ==  "__main__":
    test_case = int(sys.stdin.readline())

    for i in range(test_case):
        N, CAPA = map(int, sys.stdin.readline().split())
        ITEMS = []
        NEED = []
        VOLUME = []
        CACHE = [[-1 for _ in range(N)] for _ in range(CAPA + 1)]

        for _ in range(N):
            line = sys.stdin.readline().split()
            ITEMS.append(line[0])
            VOLUME.append(int(line[1]))
            NEED.append(int(line[2]))

        needs = pack(CAPA, 0)
        picked = []
        reconstruct(CAPA, 0, picked)
        print(needs, len(picked))

        for pick in picked:
            print(pick)