import os
import time


def check(solves):
    f = open(os.path.join(os.getcwd(), 'QUADTREE', 'answer.txt'), 'r')
    answer = []
    for a in f:
        answer.append(a[: -1])

    for i in range(len(solves)):
        print(i, ' - answer = ', answer[i], ' solves = ', solves[i])
        if answer[i] != solves[i]:
            f.close()
            return False
    
    f.close()
    return True

def decompress(q, idx):
    if q[idx] == 'w':
        return 'w'
    elif q[idx] == 'b':
        return 'b'
    else:
        idx += 1
        lt = decompress(q, idx)
        idx += len(lt)
        rt = decompress(q, idx)
        idx += len(rt)
        lb = decompress(q, idx)
        idx += len(lb)
        rb = decompress(q, idx)
        
        return 'x' + lb + rb + lt + rt


if __name__ ==  "__main__":
    f = open(os.path.join(os.getcwd(), 'QUADTREE', 'input.txt'), 'r')
    test_case = int(f.readline())
    answer = []

    for i in range(test_case):
        start = time.time()
        quad = list(f.readline())
        ret = decompress(quad, 0)

        print('time = ', time.time() - start)
        answer.append(ret)

    f.close()
    print(check(answer))