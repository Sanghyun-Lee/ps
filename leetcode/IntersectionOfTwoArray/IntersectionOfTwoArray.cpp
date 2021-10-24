class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        int count[1001] = {0};
        
        for(int i = 0; i < nums2.size(); i++) {
            count[nums2[i]]++;
        }
        
        for(int i = 0; i < nums1.size(); i++) {
            if(count[nums1[i]] > 0) {
                ret.push_back(nums1[i]);
                count[nums1[i]]--;
            }
        }
        
        return ret;
    }
};