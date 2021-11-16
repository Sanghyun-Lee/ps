class Solution {
public:
    bool isUsed[21] = {false, };

    void getCombine(int n, int k, int start, vector<vector<int>>& ret, vector<int>& temp) {
        if(k == 0) {
            ret.push_back(temp);
            return;
        }

        for(int i = start; i <= n; i++) {
            if(!isUsed[i]) {
                temp.push_back(i);
                isUsed[i] = true;
                getCombine(n, k - 1, i + 1, ret, temp);
                isUsed[i] = false;
                temp.erase(temp.begin() + (temp.size() - 1));
            }
        }
    }

    vector<vector<int>> combine(int n, int k) {   
        vector<vector<int>> ret;
        vector<int> temp;
        getCombine(n, k, 1, ret, temp);
        
        return ret;
    }
};