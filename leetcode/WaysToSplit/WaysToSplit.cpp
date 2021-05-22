class Solution {
public:
    int dp[100001];
    int waysToSplit(vector<int>& nums) {
        dp[0] = nums[0];
        for(int i = 1 ; i < nums.size(); i++) {
            dp[i] = dp[i - 1] + nums[i];
        }

        int cnt = 0;
        for(int i = 0; i < nums.size(); i++) {
            int lower, upper;
            int left, right;
            left = i + 1;
            right = nums.size() - 1;

            while(left < right) {
                int mid = left + (right - left) / 2;

                if(dp[mid] >= dp[i] * 2) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            lower = left;

            left = i + 1;
            right = nums.size() - 1;
            while(left < right) {
                int mid = left + (right - left) / 2;

                if((dp[nums.size() - 1] + dp[i]) / 2 < dp[mid]) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            upper = left;

            cnt += max(0, min(upper, (int)nums.size() - 1) - max(i + 1, lower));
            cnt %= 1000000007;
        }
        return cnt % 1000000007;
    }
};

// https://i-never-stop-study.tistory.com/141?category=1011136