class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(int i = 1; i < nums.size();) {
            if(nums[i - 1] == nums[i]) {
                nums.erase(nums.begin() + i - 1);
            } else {
                i++;
            }
        }
        return nums.size();
    }
};