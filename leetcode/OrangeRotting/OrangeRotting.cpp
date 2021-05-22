class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        vector<pair<int, int> > q;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    q.push_back(make_pair(i, j));
                } else if(grid[i][j] == 1) {
                    count++;
                }
            }
        }

        if(count == 0)
            return 0;

        int ret = 0;
        while(q.size() > 0) {
            bool isRot = false;
            vector<pair<int, int> > temp;

            for(int i = 0; i < q.size(); i++) {
                int y = q[i].first;
                int x = q[i].second;
                
                // left
                if((x - 1 >= 0) && (grid[y][x - 1] == 1)) {
                    grid[y][x - 1] = 2;
                    temp.push_back(make_pair(y, x - 1));
                    count--;
                    isRot = true;
                }
                // right
                if((x + 1 < n) && (grid[y][x + 1] == 1)) {
                    grid[y][x + 1] = 2;
                    temp.push_back(make_pair(y, x + 1));
                    count--;
                    isRot = true;
                }
                // up
                if((y - 1 >= 0) && (grid[y - 1][x] == 1)) {
                    grid[y - 1][x] = 2;
                    temp.push_back(make_pair(y - 1, x));
                    count--;
                    isRot = true;
                }
                // down
                if((y + 1 < m) && (grid[y + 1][x] == 1)) {
                    grid[y + 1][x] = 2;
                    temp.push_back(make_pair(y + 1, x));
                    count--;
                    isRot = true;
                }
            }

            if(isRot)
                ret++;
                
            q = temp;
        }

        if(count != 0)
            return -1;
        return ret;
    }
};