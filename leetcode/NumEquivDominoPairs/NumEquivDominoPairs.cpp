class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> freq;
        // [1, 1] -> 11 
        // [1, 2] -> 12
        for(const vector<int>& d: dominoes)
            freq[min(d[0], d[1]) * 10 + max(d[0], d[1])]++;

        int res = 0;
        for(const pair<int, int>& p: freq) {
            // calc pair
            // a, b, c dominoes
            // a, b | a, c | b, c
            res += p.second * (p.second - 1) / 2;
        }
        return res;
    }
};