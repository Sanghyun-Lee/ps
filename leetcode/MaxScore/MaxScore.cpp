class Solution {
public:
    int maxScore(string s) {
        int ret = 0;
        int rightSum = 0;
        int leftSum = 0;
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '1')
                rightSum++;
        }

        for(int i = 0; i < s.size() - 1; i++) {
            int val = s[i] - '0';
            
            if(val == 0)
                leftSum++;
            else
                rightSum--;

            if(leftSum + rightSum > ret)
                ret = leftSum + rightSum;
        }
        
        return ret;
    }
};