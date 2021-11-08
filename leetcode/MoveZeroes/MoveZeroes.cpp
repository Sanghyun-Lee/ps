class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int temp;
        int start = 0;
        int end = 0;
        
        while((start <= end) && (end < nums.size())) {
            if(nums[start] == 0) {
                if(nums[end] == 0) {
                    end++;
                } else {
                    temp = nums[start];
                    nums[start] = nums[end];
                    nums[end] = temp;
                    start++;
                }
            } else {
                start++;
                end++;
            }
        }
    }
};