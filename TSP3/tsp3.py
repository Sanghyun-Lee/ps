def shortestPath(cities, dist, path, visited, currentLen):
    if (len(path) == cities):
        return currentLen
    
    ret = 987654321
    for i in range(cities):
        if visited[i] == True:
            continue

        visited[i] = True
        here = path[-1]
        path.append(i)
        new_d = shortestPath(cities, dist, path, visited, currentLen + dist[here][i])
        ret = min(ret, new_d)
        visited[i] = False
        path.pop()

    return ret


if __name__ ==  "__main__":
    test_case = int(input())

    for i in range(test_case):
        cities = int(input())
        visited = [False for i in range(cities)]
        path = [-1]

        dist = [[0 for j in range(cities)] for i in range(cities)]

        for i in range(cities):
            input_d = list(map(float, input().split()))
            for j, d in enumerate(input_d):
                dist[i][j] = d

        result = []
        for i in range(cities):
            path[0] = i
            visited[i] = True
            result.append(shortestPath(cities, dist, path, visited, 0.0))
            path[0] = -1
            visited[i] = False

        print(min(result))