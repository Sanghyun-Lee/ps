import sys


def check(solves):
    f = open('/users/sanghyun/ps_python/PICNIC/answer.txt', 'r')
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


def solution(s, p):
    not_pair_student_index = -1
    print('11111   ', s)
    #print(p)
    for i in range(len(s)):
        if s[i] == False:
            not_pair_student_index = i
            print('pick!!!! not pair student index = ', not_pair_student_index)
            break


    if not_pair_student_index == -1:
        print('npsi = -1')
        return 1

    ret = 0
    for j in range(not_pair_student_index + 1, len(s)):
        print('j = ', j, ' not_pair = ', not_pair_student_index)
        if (s[j] == False) and (p[not_pair_student_index][j] == True):
            s[j] = True
            s[not_pair_student_index] = True
            print('input = ', s)
            ret += solution(s, p)
            print('solution ret = ', ret)
            s[j] = False
            s[not_pair_student_index] = False
            print('----------    ', s)

    print('ret = ', ret)
    return ret


if __name__ ==  "__main__":
    f = open('/Users/sanghyun/ps_python/PICNIC/input.txt', 'r')
    test_case = int(f.readline())
    answer = []
    student = []

    for i in range(test_case - 1):
        student_n, pair_n = map(int, f.readline().split())
        student = [False for i in range(student_n)]
        pair = [[False for j in range(student_n)] for i in range(student_n)]

        q = list(map(int, f.readline().split()))

        temp = []
        for j in range(0, pair_n * 2, 2):
            temp.append((q[j], q[j + 1]))
        print(temp)

        for t in temp:
            pair[t[0]][t[1]] = True

        #print(pair)
        answer.append(solution(student, pair))
        student.clear()
        pair.clear()


    f.close()
    print(check(answer))