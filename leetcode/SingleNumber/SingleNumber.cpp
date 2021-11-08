class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int shift = 30000;
        int count[60001] = {0};
        
        for(int i = 0; i < nums.size(); i++)
            count[nums[i] + shift]++;
        
        for(int i = 0; i < nums.size(); i++) {
            if(count[nums[i] + shift] == 1)
                return nums[i];
        }
        
        return -1;
    }
};