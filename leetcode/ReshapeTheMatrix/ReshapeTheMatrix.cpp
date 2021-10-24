class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        int size = m * n;
        vector<vector<int>> reshape(r, vector<int>(c));
        
        if(size / r != c)
            return mat;
        
        for(int i = 0; i < size; i++) {
            reshape[i / c][i % c] = mat[i / n][i % n];
        }
        return reshape;
    }
};