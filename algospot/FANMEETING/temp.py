import os
import time


def check(solves):
    f = open(os.path.join(os.getcwd(), 'FANMEETING', 'answer.txt'), 'r')
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


def normalize(z):
    z.append(0)
    for i in range(len(z) - 1):
        if z[i] < 0:
            borrow = abs(z[i] + 9) // 10
            z[i + 1] -= borrow
            z[i] += borrow * 10
        else:
            z[i + 1] += z[i] / 10
            z[i] %= 10



def multiply(x, y):
    x, y = str(x), str(y)
    z = [0 for i in range(len(x) + len(y) + 1)]
    for i in range(len(x)):
        for j in range(len(y)):
            z[i + j] += int(x[i]) * int(y[j])

    return z


def karatsuba(x, y):
    str_x, str_y = str(x), str(y)
    xl = len(str_x)
    yl = len(str_y)

    # Initialize
    if xl == 1 or yl == 1:
        return x * y

    # Divide
    half = min(xl, yl) // 2
    a, b = int(str_x[:half]), int(str_x[half:])
    c, d = int(str_y[:half]), int(str_y[half:])

    # Conquer
    ac = karatsuba(a, c)
    bd = karatsuba(b, d)
    ad_bc = karatsuba(a + b, c + d) - ac - bd
    print(ac, bd, ad_bc)

    z1 = (a * c) - ac - bd
    return ac + z1 * pow(10, half) + bd * pow(10, (half * 2))
    # Combine
    #return 10 ** (2 * half) * ac + 10 ** half * ad_bc + bd


def kara(x, y):
    x_l, y_l = len(str(x)), len(str(y))

    if (x_l < y_l):
        return kara(y, x)
    
    if x_l <= 50:
        multiply(x, y)

    m = max(x_l, y_l)

    if x_l == 1 or y_l == 1:
        return x * y

    b = x >> m
    a = x - (b << m)
    d = y >> m
    c = y - (d << m)

    ac = kara(a, c)
    bd = kara(b, d)
    abcd = kara(a + b, c + d)

    return ac + (abcd - ac - bd << m) + (bd << 2 * m)


def solution(member, fan, mc, fc):
    num = kara(member, fan)
    num = str(num)
    complete_num = min(mc, fc)

    ret = 0
    for i in range(len(num)):
        if int(num[i]) == complete_num:
            ret += 1

    return ret


if __name__ ==  "__main__":
    f = open(os.path.join(os.getcwd(), 'FANMEETING', 'input.txt'), 'r')
    test_case = int(f.readline())
    answer = []

    for i in range(test_case):
        member, mc = charToBin(list(f.readline().rstrip('\n')))
        fan, fc = charToBin(list(f.readline().rstrip('\n')))
        answer.append(solution(member, fan, mc, fc))

    f.close()
    print(check(answer))