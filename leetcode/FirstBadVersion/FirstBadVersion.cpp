// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        unsigned int start = 0;
        unsigned int end = n;
        unsigned int mid;
        int ret = -1;
        
        while(end - start >= 0) {
            mid = (start + end) >> 1;
            bool mid_ret = isBadVersion(mid);
            
            if(!mid_ret && isBadVersion(mid + 1)) {
                ret = mid + 1;
                break;
            } else if(!mid_ret) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ret;
    }
};