class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret(1, vector<int>(1, 1));

        if (numRows == 1)
            return ret;

        ret.push_back(vector<int>(2, 1));
        
        for(int i = 3; i <= numRows; i++) {
            vector<int> temp(1, 1);
            for(int j = 0; j < i - 2; j++) {
                int sum = ret[i - 2][j] + ret[i - 2][j + 1];
                temp.push_back(sum);
            }
            temp.push_back(1);
            ret.push_back(temp);
        }

        return ret;
    }
};