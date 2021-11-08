class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {       
        for(int i = 0; i < matrix.size(); i++) {
            int start = 0;
            int end = matrix[i].size() - 1;
            int mid;
            
            while(end - start >= 0) {
                mid = (start + end) / 2;
                if(matrix[i][mid] == target)
                    return true;
                else if(matrix[i][mid] > target)
                    end = mid - 1;
                else
                    start = mid + 1;
            }
        }
        return false;
    }
};