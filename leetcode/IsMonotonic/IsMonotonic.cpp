class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int isIncreasing;
        if(nums.size() == 1)
            return true;

        if(nums[0] > nums[1])
            isIncreasing = 0;
        else if(nums[0] < nums[1])
            isIncreasing = 1;
        else
            isIncreasing = -1;
        
        
        for(int i = 2; i < nums.size(); i++) {
            if(isIncreasing == -1) {
                if(nums[i - 1] > nums[i])
                    isIncreasing = 0;
                else if(nums[i - 1] < nums[i])
                    isIncreasing = 1;
            } else if(isIncreasing == 0) {
                if(nums[i - 1] < nums[i])
                    return false;
            } else if(isIncreasing == 1) {
                if(nums[i - 1] > nums[i])
                    return false;
            }
        }
        
        return true;
    }
};