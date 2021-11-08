class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;
        int sum;
        vector<int> ret;
        
        while(l < r) {
            sum = numbers[l] + numbers[r];
            if(sum == target) {
                ret.push_back(l + 1);
                ret.push_back(r + 1);
                break;
            } else if (sum < target) {
                l++;
            } else {
                r--;
            }
        }
        return ret;
    }
};