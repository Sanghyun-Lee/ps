class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> hash;

        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            
            if (hash.count(n) == 1) {
                return true;
            } else {
                hash.insert(make_pair(n, 1));
            }
        }

        return false;
    }
};