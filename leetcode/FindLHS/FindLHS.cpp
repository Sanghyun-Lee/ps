class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> counts;

        for(int i = 0; i < nums.size(); i++) {
            counts[nums[i]]++;
        }

        int index = 0;
        int ret = 0;

        map<int, int>::iterator iter;
        int prevNum, prevCount;
        for(iter = counts.begin(); iter != counts.end(); iter++) {
            if(index == nums.size())
                break;
            
            if((index != 0) && (prevNum + 1 == iter->first)) {
                ret = max(ret, prevCount + iter->second);
            }
            prevNum = iter->first;
            prevCount = iter->second;
            index++;
        }

        return ret;
    }
};