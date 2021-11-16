class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0;
        uint32_t zero_mask = ~1;
        uint32_t one_mask = 1;
        int count = 0;

        while(count < 32) {
            ret = (ret << 1);
            if(n & 1)
                ret = ret | one_mask;
            else
                ret = ret & zero_mask;
            n = n >> 1;
            count++;
        }
        
        return ret;
    }
};