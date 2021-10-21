class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> results;
        
        for(int i = 0; i < nums.size() - 1; i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if(target == (nums[i] + nums[j])) {
                    results.push_back(i);
                    results.push_back(j);
                    break;
                }
            }
        }
        return results;
    }
};