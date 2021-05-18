def check(solves):
    f = open('/users/sanghyun/ps_python/TSP3/answer.txt', 'r')
    answer = []
    for a in f:
        answer.append(float(a))

    for i in range(len(solves)):
        print(i, ' - answer = ', answer[i], ' solves = ', solves[i])
        if round(answer[i], 7) != round(solves[i], 7):
            f.close()
            return False
    
    f.close()
    return True


def shortestPath(cities, dist, path, visited, currentLen):
    if (len(path) == cities):
        #return currentLen + dist[0][path[-1]]
        return currentLen
    
    ret = 987654321
    for i in range(cities):
        if visited[i] == True:
            continue

        visited[i] = True
        here = path[-1]
        path.append(i)
        #print('curr = ', currentLen, ' dist[', here, '][', i, '] = ', dist[here][i])
        new_d = shortestPath(cities, dist, path, visited, currentLen + dist[here][i])
        #print(i, ret, new_d)
        ret = min(ret, new_d)
        visited[i] = False
        path.pop()


    return ret

if __name__ ==  "__main__":
    f = open('/Users/sanghyun/ps_python/TSP3/input.txt', 'r')
    test_case = int(f.readline())
    answer = []

    for i in range(test_case):
        cities = int(f.readline())
        visited = [False for i in range(cities)]
        path = [-1]

        dist = [[0 for j in range(cities)] for i in range(cities)]

        for i in range(cities):
            input_d = list(map(float, f.readline().split()))
            for j, d in enumerate(input_d):
                dist[i][j] = d

        result = []
        for i in range(cities):
            path[0] = i
            visited[i] = True
            result.append(shortestPath(cities, dist, path, visited, 0.0))
            path[0] = -1
            visited[i] = False

        print(result)
        answer.append(min(result))


    f.close()
    print(check(answer))