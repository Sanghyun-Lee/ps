class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> left(size, nums[0]);
        vector<int> right(size, nums[size - 1]);
        vector<int> ret(size, 1);
        
        for(int i = 1; i < size; i++) {
            left[i] = left[i - 1] * nums[i];
            right[size - 1 - i] = right[size - i] * nums[size - i - 1];
        }

        for(int i = 0; i < size; i++) {
            if(0 <= i - 1 && i + 1 < size)
                ret[i] = left[i - 1] * right[i + 1];
            else if(0 > i - 1)
                ret[i] = right[i + 1];
            else
                ret[i] = left[i - 1];
        }

        return ret;
    }
};