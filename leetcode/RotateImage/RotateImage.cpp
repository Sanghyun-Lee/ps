class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> ret = {matrix.begin(), matrix.end()};
        int sy = matrix.size() - 1;

        for(int y = 0; y <= sy; y++) {
            int sx = matrix[y].size() - 1;
            for(int x = 0; x <= sx; x++) {
                matrix[x][sx - y] = ret[y][x];
            }
        }
    }
};