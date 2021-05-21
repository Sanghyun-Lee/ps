class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int> > newGrid = grid;
        int m = newGrid.size();
        int n = newGrid[0].size();

        if(k >= m * n) {
            k = k % (m * n);
        }

        if(k == 0)
            return grid;

        int x, y;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(j + k >= n) {
                    y = (j + k) % n;
                    x = i + (j + k) / n;
                    if(x >= m)
                        x = x % m;
                } else {
                    x = i;
                    y = j + k;
                }
                newGrid[x][y] = grid[i][j];
            }
        }

        return newGrid;
    }
};