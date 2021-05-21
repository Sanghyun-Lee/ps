class Solution {
public:
    bool check(vector<int>& nums) {
        int size = nums.size();
        int index = 0;
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        
        for(int i = 1; i < size; i++) {
            if(nums[i - 1] > nums[i]) {
                index = i;
                break;
            }
        }
        
        if(index == 0)
            return true;

        for(int i = 0; i < size; i++) {
            if(temp[i] != nums[(index + i) % size])
                return false;
        }

        return true;
    }
};