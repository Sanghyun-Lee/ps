class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        uint32_t mask = 1;
        
        while(n > 0) {
            if(n & mask)
                count++;
            n = n >> 1;
        }
        
        return count;
    }
};