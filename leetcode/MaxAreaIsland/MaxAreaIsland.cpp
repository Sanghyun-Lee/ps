class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // 방문했는지를 확인하는 2차원 배열
        vector<vector<bool> > check(grid.size(), vector<bool>(grid[0].size(), false));
        
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int> > q;
        int max_count = INT_MIN;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int count = 0;
                // 방문하지 않은 지점이 나오면 queue에 x, y 좌표를 넣는다.
                // 그리고 방문 했으니 check를 true로 변경하고 count를 증가한다.
                if(grid[i][j] && check[i][j] == false) {
                    check[i][j] = true;
                    q.push(make_pair(i, j));
                    count++;
                }

                // 탐색할 좌표가 있다면
                while(q.size()) {
                    // x, y좌표를 꺼내고, queue에서 pop
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();

                    // 기준 좌표 x, y에서 상/하/좌/우 탐색.
                    // 탐색하면 check를 true로 바꾸고 count를 증가 시킨다.

                    // x, y기준 위쪽 방향 탐색
                    if(y > 0 && grid[y - 1][x] && check[y - 1][x] == false) {
                        q.push(make_pair(y - 1, x));
                        check[y - 1][x] = true;
                        count++;
                    }

                    // x, y기준 아래쪽 방향 탐색
                    if(y < m - 1 && grid[y + 1][x] && check[y + 1][x] == false) {
                        q.push(make_pair(y + 1, x));
                        check[y + 1][x] = true;
                        count++;
                    }

                    // x, y기준 왼쪽 방향 탐색
                    if(x > 0 && grid[y][x - 1] && check[y][x - 1] == false) {
                        q.push(make_pair(y, x - 1));
                        check[y][x - 1] = true;
                        count++;
                    }

                    // x, y기준 오른쪽 방향 탐색
                    if(x < n - 1 && grid[y][x + 1] && check[y][x + 1] == false) {
                        q.push(make_pair(y, x + 1));
                        check[y][x + 1] = true;
                        count++;
                    }
                }

                // queue를 다 탐색했으면 최대 크기를 비교해 max_count에 저장
                if(count > max_count)
                    max_count = count;
            }
        }

        return max_count;
    }
};