class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size() + 1;
        vector<int> ans;
        ans.push_back(0);

        for (int i = 1; i <= n; ++i) {
            ans[0] ^= i;
            if (i % 2 == 0) {
                ans[0] ^= encoded[i - 1];
            }
        }

        for (const int &v : encoded)
            ans.push_back(ans.back() ^ v);
        return ans;
    }
};