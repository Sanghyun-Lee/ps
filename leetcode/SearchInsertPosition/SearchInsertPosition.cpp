class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(target < nums[0])
            return 0;
        
        if(target > nums[nums.size() - 1])
            return nums.size();

        int i = 0;
        for(i = 0; i < nums.size(); i++) {
            if(target == nums[i])
                return i;
            else if((i > 0) && (target > nums[i - 1]) && (target < nums[i])) {
                return i;
            }
        }
        return i;
    }
};