class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxV = 0;
        int minV = 999999;
        
        for(int i = 0; i < prices.size(); i++) {
            if(minV > prices[i])
                minV = prices[i];
            else if(minV < prices[i]) {
                maxV = max(maxV, prices[i] - minV);
            }
        }
        
        return maxV;
    }
};