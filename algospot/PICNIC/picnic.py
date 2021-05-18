def solution(s, p):
    not_pair_student_index = -1
    for i in range(len(s)):
        if s[i] == False:
            not_pair_student_index = i
            break

    if not_pair_student_index == -1:
        return 1

    ret = 0
    for j in range(not_pair_student_index + 1, len(s)):
        if (s[j] == False) and (p[not_pair_student_index][j] == True):
            s[j] = True
            s[not_pair_student_index] = True
            ret += solution(s, p)
            s[j] = False
            s[not_pair_student_index] = False

    return ret


if __name__ ==  "__main__":
    test_case = int(input())
    answer = []
    student = []

    for i in range(test_case):
        student_n, pair_n = map(int, input().split())
        student = [False for i in range(student_n)]
        pair = [[False for j in range(student_n)] for i in range(student_n)]

        q = list(map(int, input().split()))

        temp = []
        for j in range(0, pair_n * 2, 2):
            temp.append((q[j], q[j + 1]))

        for t in temp:
            min_v = min(t[0], t[1])
            max_v = max(t[0], t[1])
            pair[min_v][max_v] = True

        print(solution(student, pair))
        student.clear()
        pair.clear()