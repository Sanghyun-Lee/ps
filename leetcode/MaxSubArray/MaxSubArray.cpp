class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret = nums[0];
        int temp = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            temp = max(nums[i], nums[i] + temp);
            ret = max(ret, temp);
        }

        return ret;
    }
};