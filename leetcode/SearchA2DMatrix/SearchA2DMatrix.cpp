class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i = 0; i < matrix.size(); i++) {
            if ((i == matrix.size() - 1) ||
                ((matrix[i][0] <= target) && (target <= matrix[i + 1][0]))) {
                for (int j = 0; j < matrix[i].size(); j++) {
                    if (target == matrix[i][j])
                        return true;
                }
            }
        }
        return false;
    }
};