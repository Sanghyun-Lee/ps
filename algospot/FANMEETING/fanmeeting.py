import sys


def charToBin(lists):
    new_list = ''
    count = 0
    for c in lists:
        if c == 'M':
            new_list += '0'
        else:
            new_list += '1'
            count += 1

    return int(new_list), count


def karatsuba(x, y):
    x_l, y_l = len(str(x)), len(str(y))

    if (x_l < y_l):
        return karatsuba(y, x)
    
    if x_l <= 50:
        multiply(x, y)

    m = max(x_l, y_l)

    if x_l == 1 or y_l == 1:
        return x * y

    b = x >> m
    a = x - (b << m)
    d = y >> m
    c = y - (d << m)

    ac = karatsuba(a, c)
    bd = karatsuba(b, d)
    abcd = karatsuba(a + b, c + d)

    return ac + (abcd - ac - bd << m) + (bd << 2 * m)


def multiply(x, y):
    x, y = str(x), str(y)

    z = [0 for i in range(len(x) + len(y) + 1)]
    for i in range(len(x)):
        for j in range(len(y)):
            z[i + j] += int(x[i]) * int(y[j])

    return z


def solution(member, fan, mc, fc):
    num = str(karatsuba(member, fan))
    complete_num = min(mc, fc)

    ret = 0
    for i in range(len(num)):
        if int(num[i]) == complete_num:
            ret += 1

    return ret


if __name__ ==  "__main__":
    test_case = int(sys.stdin.readline())

    for i in range(test_case):
        member, mc = charToBin(list(sys.stdin.readline()))
        fan, fc = charToBin(list(sys.stdin.readline()))
        print(solution(member, fan, mc, fc))