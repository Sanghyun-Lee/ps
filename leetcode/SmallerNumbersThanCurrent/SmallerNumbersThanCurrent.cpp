class Solution {
    int cache[101] = {0, };
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans;
        vector<int> temp = nums;
        
        sort(temp.begin(), temp.end());
        for(int i = temp.size() - 1; i >= 0; i--) {
            cache[temp[i]] = i;
        }
        
        for(int i = 0; i < nums.size(); i++) {
            ans.push_back(cache[nums[i]]);
        }
        return ans;
    }
};