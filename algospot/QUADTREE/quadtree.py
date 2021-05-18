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
    test_case = int(input())

    for i in range(test_case):
        quad = list(input())
        print(decompress(quad, 0))