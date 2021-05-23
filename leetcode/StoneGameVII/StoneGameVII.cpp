class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int N = stones.size();
        vector<int> sum(N + 1);

        for(int i = 0; i < N; ++i)
            sum[i + 1] = sum[i] + stones[i];

        vector<vector<int>> dp(N, vector<int>(N));

        for(int len = 2; len <= N; ++len) {
            for(int left = 0; left <= N - len; ++left) {
                int right = left + len - 1;
                dp[left][right] = 
                    max(sum[right + 1] - sum[left + 1] - dp[left + 1][right], 
                        sum[right] - sum[left] - dp[left][right - 1]);
            }
        }

        return dp[0][N - 1];
    }
};