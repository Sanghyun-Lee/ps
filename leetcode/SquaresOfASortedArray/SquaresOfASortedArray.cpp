class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ret;
        int count[10001] = {0};
        
        for(int i = 0; i < nums.size(); i++) {
            int val = nums[i];
            if(val < 0)
                val = -val;
            count[val]++;
        }
        
        for(int i = 0; i < 10001; i++) {
            for(int j = 0; j < count[i]; j++) {
                ret.push_back(i * i);
            }
        }
        
        return ret;
    }
};