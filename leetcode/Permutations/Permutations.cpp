class Solution {
public:
    bool isUsed[21] = {false, };

    void permute(vector<int> nums, vector<vector<int>>& ret, vector<int>& temp, int n) {
        if(nums.size() == temp.size()) {
            ret.push_back(temp);
            return;
        }

        for(int i = 0; i < n; i++) {
            if(!isUsed[i]) {
                temp.push_back(nums[i]);
                isUsed[i] = true;
                permute(nums, ret, temp, n);
                isUsed[i] = false;
                temp.erase(temp.begin() + (temp.size() - 1));
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> temp;
        permute(nums, ret, temp, nums.size());
        
        return ret;
    }
};