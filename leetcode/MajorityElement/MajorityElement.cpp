class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
        int max = INT_MIN;
        int ret = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            if(m.count(nums[i]) == 0)
                m.insert(make_pair(nums[i], 1));
            else
                m[nums[i]]++;
        }

        for(auto iter = m.begin(); iter != m.end(); iter++) {
            if(max < iter->second) {
                max = iter->second;
                ret = iter->first;
            }
        }
        
        return ret;
    }
};